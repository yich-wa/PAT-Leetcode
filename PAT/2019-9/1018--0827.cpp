//14:55——
///先通过DFS拿到路径。然后从起点到终点逐步看，判断要带多少去，
//和带多少回。可以设一个未知数，
//表明出发时，要带多少车辆
//第一次做完23分。 后来发现是一个细节错误，少了个加号。对手上有多少
//车数量，进行更新时。犯的低级错误。 

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;
int G[maxn][maxn] = {0};
const int INF = 1000000000;
int cMax,n,sp,m;
int bNum[maxn];
int d[maxn];
bool isVis[maxn]={false};
vector<int>pre[maxn];
vector<int>tempPath,bestPath;
int tSend,tBring;
int send = INF;
int bring = INF;
void calBS(){
	int len = tempPath.size();
	int hand = 0; 
	int take =0;
	for(int i=len-2;i>=0;i--){
		int tId = tempPath[i];
		if(bNum[tId]>=cMax/2){
			hand += bNum[tId]-cMax/2;	
		}else{
			if(hand+bNum[tId]>=cMax/2)
			{
				hand = hand+bNum[tId]-cMax/2;
			}else
			{
				take += cMax/2 - hand - bNum[tId];
				hand = 0;
			}
		}
	}
	tSend = take;
	tBring = hand;
//	printf("%d ==== %d\n",tSend,tBring); 
}
void DFS(int s){
	if(s==0)
	{
		calBS();
		if(tSend<send){
			bestPath = tempPath;
			send = tSend;
			bring = tBring;
		}else if(tSend==send&&tBring<bring){
			bestPath = tempPath;
			bring = tBring;
		}
		return;
	}
	for(int i=0;i<pre[s].size();i++){
		tempPath.push_back(pre[s][i]);
		DFS(pre[s][i]);
		tempPath.pop_back();
	}
}
int main(){
	scanf("%d%d%d%d",&cMax,&n,&sp,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&bNum[i]);
	}
	int si,sj,tij;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&si,&sj,&tij);
		G[si][sj] = G[sj][si] = tij;
	}
	fill(d,d+maxn,INF);
	d[0] = 0;
	for(int i=0;i<=n;i++){
		int min = INF;
		int u =-1;
		for(int j=0;j<=n;j++){
			if(isVis[j]==false&&d[j]<min){
				min = d[j];
				u =j;
			}
		}
		if(u==-1)
			return 0;
		isVis[u]=true;
		for(int v= 0;v<=n;v++){
			if(isVis[v]==false&&G[u][v]>0){
				if(d[u]+G[u][v]<d[v]){
					pre[v].clear();
					pre[v].push_back(u);
					d[v] = d[u]+G[u][v];
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}	
			}
		}
	}
	tempPath.push_back(sp);
	DFS(sp);		
	printf("%d 0",send);
	int bLen = bestPath.size();
	for(int i=bLen-2;i>=0;i--){
		printf("->%d",bestPath[i]);
	}
	printf(" %d\n",bring);
	return 0;	
}



////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 505;
//const int inf = 1000000000;
//int g[maxn][maxn];
//bool isvisit[maxn]={false};
//int d[maxn];
//int minsend=inf;
//int tempsend;
//int tempreturn;
//int minreturn=inf; 
//int c,n,sp,m;
//vector<int>temppath;
//vector<int>bestpath;
//vector<int>pre[maxn]; 
//int stanum[maxn];
//bool isupdate;
//void CMP()  //这个是要模拟当时的情景。 
//{
//	tempsend=0;
//	tempreturn =0;
//	int handnum=0;
//	//下面temppath最后一位存的是起点"0";不用计算 
//	for(int i=temppath.size()-2;i>=0;i--)
//	{
//		int temp = temppath[i];
//		int dis = handnum+stanum[temp]-c;
//		if(dis>=0)
//		{
//			handnum=dis;
//		}
//		else
//		{
//			tempsend+= 0-dis;
//			handnum=0; 
//		}
//	}
//	tempreturn =handnum;
//	//printf("%d %d--\n",tempsend,tempreturn);
//	if(bestpath.size()==0)
//	{
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;	
//	}
//	else if(tempsend<minsend)
//	{
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;
//	}
//	else if(tempsend==minsend&&tempreturn<minreturn)
//	{
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;
//	}	
//}
//void DFS(int a)
//{
//	if(a==0)
//	{
//		CMP();
//		return;
//	}
//	for(int i=0;i<pre[a].size();i++)
//	{
//		int temppre = pre[a][i];
//		temppath.push_back(temppre);
//		DFS(temppre);
//		temppath.pop_back();
//	}
//}
//int main()
//{
//	int bikeinhand=0;
//	stanum[0]=0;
//	scanf("%d%d%d%d",&c,&n,&sp,&m);
//	c=c/2;
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&stanum[i]);
//	}
//	fill(g[0],g[0]+maxn*maxn,inf);
//	int s1,s2;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&s1,&s2);
//		scanf("%d",&g[s1][s2]);
//		g[s2][s1]=g[s1][s2];
//	}
//	fill(d,d+maxn,inf);
//	d[0]=0;
//	for(int i=0;i<=n;i++)
//	{
//		int mind = inf;
//		int u=-1;
//		for(int j=0;j<=n;j++)
//		{
//			if(isvisit[j]==false&&d[j]<mind)
//			{
//				mind=d[j];
//				u=j;
//			}
//		}
//		if(u==-1)
//			break;
//		isvisit[u]=true;
//		for(int v = 0;v<=n;v++)
//		{
//			if(isvisit[v]==false&&g[u][v]!=inf)
//			{
//				if(d[u]+g[u][v]<d[v])
//				{
//					pre[v].clear();
//					d[v]=d[u]+g[u][v];	
//					pre[v].push_back(u); 	
//				}
//				//这种情况，如果是中间节点，那么你的pre[v]到底更新不？ 
//				else if(d[u]+g[u][v]==d[v])    
//				{
//					pre[v].push_back(u);
//				}
//			}
//		}
//	}
//	temppath.push_back(sp);
//	DFS(sp);
//	printf("%d 0",minsend);
//	for(int i=bestpath.size()-2;i>=0;i--)
//	{
//		printf("->%d",bestpath[i]);
//	}
//	printf(" %d\n",minreturn);
//	return 0;	
//} 

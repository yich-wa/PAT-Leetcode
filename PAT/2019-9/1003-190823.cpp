#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int INF= 1000000000;
int sumRes;
int finSum = -1;
int c1,c2;
int res[maxn];
vector<int>pre[maxn];
void DFS(int c){
	if(c==c1){
		if(sumRes>finSum){
			finSum = sumRes;
		}
		return;
	}
	for(int i=0;i<pre[c].size();i++){
		int tempId = pre[c][i];
		sumRes+=res[tempId];
		DFS(tempId);
		sumRes-=res[tempId];	
	}
}
int main() {
	int n,m;
	int d[maxn];
	int G[maxn][maxn];
	bool isVis[maxn] = {false};
	int num[maxn]={0};	
	fill(d,d+maxn,INF);
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&res[i]);
	}
	int r1,r2;
	for(int i=0;i<m;i++){
		scanf("%d%d",&r1,&r2);
		scanf("%d",&G[r1][r2]);
		G[r2][r1]=G[r1][r2];
	}
	d[c1]=0;
	num[c1]=1;
	int minDis = INF;
	int u=-1;
	for(int i=0;i<n;i++){
		u =-1;
		minDis = INF;
		for(int j=0;j<n;j++){
			if(isVis[j]==false&&d[j]<minDis){
				minDis = d[j];
				u = j; 
			}
		}
		if(u==-1)
			break;
		isVis[u]=true;
		for(int v=0;v<n;v++){
			if(d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
				num[v]=num[u];
			}
			else if(d[u]+G[u][v]==d[v]){
				pre[v].push_back(u);
				num[v]+=num[u];
			}
		}
	}
	sumRes = res[c2];
	DFS(c2);
	printf("%d %d",num[c2],finSum);
	return 0;	
}

//以前的做法：
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn =505;
//const int inf = 1000000000;
//bool isvisit[maxn]={false};
//int g[maxn][maxn];
//int d[maxn];
//int rescue[maxn];
//int mrescue[maxn]={0};  //表示到这个城市时，可以聚集的最大营救人员数量。 
//int main()
//{
//	int n,m;
//	int st,ed;
//	int c1,c2,len;
//	scanf("%d%d%d%d",&n,&m,&st,&ed);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&rescue[i]);
//	}
//	//开始忘记填充下面，导致10分钟的耗费。 
//	fill(g[0],g[0]+maxn*maxn,inf);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d%d",&c1,&c2,&len);
//		g[c1][c2]=len;
//		g[c2][c1]=len;
//	}
//	fill(d,d+maxn,inf);
//	d[st]=0;
//	//printf("%d %d %d** **\n",d[1],d[2],d[4]);
//	mrescue[st]=rescue[st];
//	int shortnum[maxn];
//	shortnum[st]=1; 
//	for(int i=0;i<n;i++)
//	{
//		int u =-1;
//		int min =inf;
//		for(int j=0;j<n;j++)
//		{
//			if(isvisit[j]==false&&d[j]<min)
//			{
//				min = d[j];
//				u=j;
//			}
//		}
//		if(u==-1)
//		break;
//		isvisit[u]=true;
//		//printf("%d**%d\n",u,d[u]);
//		for(int v=0;v<n;v++)
//		{
//			if(isvisit[v]==false&&g[u][v]!=inf)
//			{
//				if(d[u]+g[u][v]<d[v])
//				{
//					d[v]=d[u]+g[u][v];
//					mrescue[v]=mrescue[u]+rescue[v];
//					shortnum[v]=shortnum[u];
//				}
//				//开始下面写错
//				//相等时，就可以更新最短数量了
//				//相等且，营救队伍更大时，才更新最大营救队伍。	
//				else if(d[u]+g[u][v]==d[v])
//				{
//					shortnum[v]+=shortnum[u];
//					if(mrescue[u]+rescue[v]>mrescue[v]) 
//					{
//						mrescue[v]=mrescue[u]+rescue[v];
//					}
//						
//				}
//			}
//		}
//	}		
//	printf("%d %d\n",shortnum[ed],mrescue[ed]);
//	return 0;	
// }

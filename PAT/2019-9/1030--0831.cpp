//22:48--23:41  30分
//犯了几个常规的错误。如手误：把c1,写成c2;
//以及忘记对minCost进行minCost=inf的初始化。或者初始化放错位置。
//尽量写的稳一点。即使出了常规错误，用printf查出，问题出在哪一行。或者
//哪一个模块中。然后排查。 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int inf = 1000000000;
int G[maxn][maxn];
int C[maxn][maxn];
bool isVis[maxn];
int s;
vector<int>tempPath,bestPath;
vector<int>pre[maxn];
int minCost;
void DFS(int s0,int c){
	if(s0==s){
		if(c<minCost){
			minCost = c;
			bestPath = tempPath; 
		}
	}
	for(int i=0;i<pre[s0].size();i++){
		int temp = pre[s0][i];
		tempPath.push_back(temp);
		DFS(temp,c+C[s0][temp]);
		tempPath.pop_back();
	}	
}
int main(){
	int n,m,des;
	int d[maxn];
	scanf("%d%d%d%d",&n,&m,&s,&des);
	int c1,c2,dis,cost;
	fill(G[0],G[0]+maxn*maxn,0);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		G[c1][c2]=G[c2][c1] = dis; 
		C[c1][c2]=C[c2][c1] = cost;
	}
	fill(d,d+maxn,inf);
	fill(isVis,isVis+maxn,false);
	d[s] = 0;
//	printf("G[0][3]--%d\n",G[0][3]);
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(isVis[j]==false&&d[j]<min){
				min = d[j];
				u=j;
//				printf("%d---%d\n",j,d[j]);
			}
		}
		if(u==-1)
			return 0;
		isVis[u]=true;
		for(int v =0;v<n;v++){
			if(isVis[v]==false&&G[u][v]>0)
			{
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u]+G[u][v];
//					printf("%d---%d---%d---%d\n",u,v,d[u],d[v]);
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}	
			}
		}
	}
//	printf("%d****%d*****\n",des,d[des]);
	minCost = inf;
	tempPath.push_back(des);
	DFS(des,0);
	int len = bestPath.size();
	for(int i=len-1;i>=0;i--){
		printf("%d ",bestPath[i]);
	}
	printf("%d %d",d[des],minCost);
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
//int cost[maxn][maxn];
//bool isvisit[maxn]={false};
//int dis[maxn];
//int c[maxn];
//int pre[maxn];
//void output(int temp)
//{
//	if(pre[temp]!=temp)
//		output(pre[temp]);
//	printf("%d ",temp);
//}
//int main()
//{
//	int n,m,s,d;
//	scanf("%d%d%d%d",&n,&m,&s,&d);
//	int c1,c2;
//	fill(g[0],g[0]+maxn*maxn,inf);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&c1,&c2);
//		scanf("%d%d",&g[c1][c2],&cost[c1][c2]);
//		g[c2][c1]=g[c1][c2];
//		cost[c2][c1]=cost[c1][c2];
//	}
//	fill(dis,dis+maxn,inf);
//	dis[s]=0;
//	c[s]=0;
//	pre[s]=s;
//	for(int i=0;i<n;i++)
//	{
//		int mindis = inf;
//		int u =-1;
//		for(int j=0;j<n;j++)
//		{
//			if(isvisit[j]==false&&dis[j]<mindis)
//			{
//				u=j;
//				mindis=dis[j];
//			}
//		}
//		if(u==-1)
//		break;
//		isvisit[u]=true;
//		for(int v=0;v<n;v++)
//		{
//			if(isvisit[v]==false&&g[u][v]!=inf)
//			{	
//				if(dis[u]+g[u][v]<dis[v])
//				{
//					dis[v]=dis[u]+g[u][v];
//					c[v]=c[u]+cost[u][v];
//					pre[v]=u;
//				}
//				else if(dis[u]+g[u][v]==dis[v]&&c[u]+cost[u][v]<c[v])
//				{
//					c[v]=c[u]+cost[u][v];
//					pre[v]=u;
//				}
//			}
//		}	
//	}
//	int temp =d;
//	output(temp);
//	printf("%d %d\n",dis[d],c[d]);
//	return 0;
// }  

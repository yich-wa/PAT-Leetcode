//15:19——
//开始忘记了给g[maxn][maxn]初始化。 dijstra算法的细节。 
//要清楚的知道如何打印路径。以及dijstra方法的细节。 
//要知道二维数组和一维数组初始化的方式。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int inf = 1000000000;
int g[maxn][maxn];
int cost[maxn][maxn];
bool isvisit[maxn]={false};
int dis[maxn];
int c[maxn];
int pre[maxn];
void output(int temp)
{
	if(pre[temp]!=temp)
		output(pre[temp]);
	printf("%d ",temp);
}
int main()
{
	int n,m,s,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int c1,c2;
	//二维数组初始化的方式。 
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&c1,&c2);
		scanf("%d%d",&g[c1][c2],&cost[c1][c2]);
		g[c2][c1]=g[c1][c2];
		cost[c2][c1]=cost[c1][c2];
	}
	fill(dis,dis+maxn,inf);
	dis[s]=0;
	c[s]=0;
	pre[s]=s;
	for(int i=0;i<n;i++)
	{
		int mindis = inf;
		int u =-1;
		for(int j=0;j<n;j++)
		{
			if(isvisit[j]==false&&dis[j]<mindis)
			{
				u=j;
				mindis=dis[j];
			}
		}
		if(u==-1)
		break;
		isvisit[u]=true;
		for(int v=0;v<n;v++)
		{
			//开始忘记加g[u][v]!=inf这个细节了。 
			if(isvisit[v]==false&&g[u][v]!=inf)
			{	
				if(dis[u]+g[u][v]<dis[v])
				{
					dis[v]=dis[u]+g[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
				else if(dis[u]+g[u][v]==dis[v]&&c[u]+cost[u][v]<c[v])
				{
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
			}
		}	
	}
	int temp =d;
	output(temp);
	printf("%d %d\n",dis[d],c[d]);
	return 0;
 } 

//16:01
//整体做法为Dijstra +DFS(输出临时路径，与最优路径比较) 
//答案19分。有11分答案错误。
//开始那种写法是有问题的。中间节点的最短路径相同时，无法保存pre 
//以前的写法，是建立vector<int>pre[maxn]将每个节点的可能前缀都记录下来。
//用答案写法对了。。本题很经典。
//特别点，在于采用vector<int>pre[maxn]去记录，多个前驱节点。
//以及在DFS()到顶端时，及时更新最优路径。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int inf = 1000000000;
int g[maxn][maxn];
bool isvisit[maxn]={false};
int d[maxn];
int minsend=inf;
int tempsend;
int tempreturn;
int minreturn=inf; 
int c,n,sp,m;
vector<int>temppath;
vector<int>bestpath;
vector<int>pre[maxn]; 
int stanum[maxn];
bool isupdate;
void CMP()  //这个是要模拟当时的情景。 
{
	tempsend=0;
	tempreturn =0;
	int handnum=0;
	//下面temppath最后一位存的是起点"0";不用计算 
	for(int i=temppath.size()-2;i>=0;i--)
	{
		int temp = temppath[i];
		int dis = handnum+stanum[temp]-c;
		if(dis>=0)
		{
			handnum=dis;
		}
		else
		{
			tempsend+= 0-dis;
			handnum=0; 
		}
	}
	tempreturn =handnum;
	//printf("%d %d--\n",tempsend,tempreturn);
	if(bestpath.size()==0)
	{
		bestpath=temppath;
		minsend=tempsend;
		minreturn=tempreturn;	
	}
	else if(tempsend<minsend)
	{
		bestpath=temppath;
		minsend=tempsend;
		minreturn=tempreturn;
	}
	else if(tempsend==minsend&&tempreturn<minreturn)
	{
		bestpath=temppath;
		minsend=tempsend;
		minreturn=tempreturn;
	}	
}
void DFS(int a)
{
	if(a==0)
	{
		CMP();
		return;
	}
	for(int i=0;i<pre[a].size();i++)
	{
		int temppre = pre[a][i];
		temppath.push_back(temppre);
		DFS(temppre);
		temppath.pop_back();
	}
}
int main()
{
	int bikeinhand=0;
	stanum[0]=0;
	scanf("%d%d%d%d",&c,&n,&sp,&m);
	c=c/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&stanum[i]);
	}
	fill(g[0],g[0]+maxn*maxn,inf);
	int s1,s2;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&s1,&s2);
		scanf("%d",&g[s1][s2]);
		g[s2][s1]=g[s1][s2];
	}
	fill(d,d+maxn,inf);
	d[0]=0;
	for(int i=0;i<=n;i++)
	{
		int mind = inf;
		int u=-1;
		for(int j=0;j<=n;j++)
		{
			if(isvisit[j]==false&&d[j]<mind)
			{
				mind=d[j];
				u=j;
			}
		}
		if(u==-1)
			break;
		isvisit[u]=true;
		for(int v = 0;v<=n;v++)
		{
			if(isvisit[v]==false&&g[u][v]!=inf)
			{
				if(d[u]+g[u][v]<d[v])
				{
					pre[v].clear();
					d[v]=d[u]+g[u][v];	
					pre[v].push_back(u); 	
				}
				//这种情况，如果是中间节点，那么你的pre[v]到底更新不？ 
				else if(d[u]+g[u][v]==d[v])    
				{
					pre[v].push_back(u);
				}
			}
		}
	}
	temppath.push_back(sp);
	DFS(sp);
	printf("%d 0",minsend);
	for(int i=bestpath.size()-2;i>=0;i--)
	{
		printf("->%d",bestpath[i]);
	}
	printf(" %d\n",minreturn);
	return 0;	
} 
 
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
//int pre[maxn];
//int stanum[maxn];
//bool isupdate;
//void DFS(int a)
//{
//	if(pre[a]!=a)
//		DFS(pre[a]);
//	temppath.push_back(a);
//}
//void CMP()  //这个是要模拟当时的情景。 
//{
//	tempsend=0;
//	tempreturn =0;
//	int handnum=0;
//	for(int i=1;i<temppath.size();i++)
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
//	if(bestpath.size()==0)
//	{
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;	
//	}
//	else if(tempsend<minsend)
//	{
//		isupdate=true;
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;
//	}
//	else if(tempsend==minsend&&tempreturn<minreturn)
//	{
//		isupdate=true;
//		bestpath=temppath;
//		minsend=tempsend;
//		minreturn=tempreturn;
//	}
//	temppath.clear();	
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
//	pre[0]=0;
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
//					d[v]=d[u]+g[u][v];	
//					pre[v]=u;
//					if(v==sp)
//					{
//						DFS(v); 
//						CMP();
//						//存入路径。 
//					}	
//				}
//				//这种情况，如果是中间节点，那么你的pre[v]到底更新不？ 
//				else if(d[u]+g[u][v]==d[v])    
//				{
//					 //假定其是一条更优路径。
//					int tempu = pre[v];  
//					if(v==sp)
//					{
//						isupdate=false;
//						pre[v]=u;
//						DFS(v);
//						CMP();
//						//没有更新，并不是更优路径
//						if(isupdate==false)    
//						{
//							pre[v]=tempu;
//						}
//					} 
//				}
//			}
//		}
//	}
//	printf("%d 0",minsend);
//	for(int i=1;i<bestpath.size();i++)
//	{
//		printf("->%d",bestpath[i]);
//	}
//	printf(" %d\n",minreturn);
//	return 0;	
// } 
// 
 
// 去年写法 
// 
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int maxn=505;
//const int INF=1000000000;
//int c,n,sp,m;
//int p;
//bool visit[maxn]={false};
//int G[maxn][maxn]={0};
//vector<int> pre[maxn];
//int bike[maxn];
//int d[maxn];
//int weight[maxn];
//int minneed=INF;
//int minremain=INF;
//vector<int>tempath,path;
//void dijkstra(int s)
//{
//	fill(d,d+maxn,INF);     //一开始初始化，使用的是fill(d,d+n,INF)，这样其实d[3]无法初始化，依旧为0;所以昨晚到现在
//	//昨晚到现在的大部分的debug都是因为：一我以为两者十一摸一样的。而，不了解fill(d,d+n,INF)初始化的范围。
//	d[s]=0;
//	int min;
//	int u;
//	for(int i=0;i<=n;i++)
//	{
//		u=-1;
//		min=INF;
//		for(int j=0;j<=n;j++)
//		{
//			if(visit[j]==false&&d[j]<min)
//			{
//				u=j;
//				min=d[j];
//			}
//		}
//		if(u==-1)
//			return ;
//		visit[u]=true;
//		for(int v=0;v<=n;v++)
//		{
//			if(visit[v]==false&&G[u][v]!=0)
//			{
//				if(d[u]+G[u][v]<d[v])
//				{
//					d[v]=d[u]+G[u][v];
//					pre[v].clear();
//					pre[v].push_back(u);
//				}
//				else if(d[u]+G[u][v]==d[v])
//				{
//					pre[v].push_back(u);
//				}
//			}
//		}
//	}
//}
//void DFS(int a)
//{
//	if(a==0)
//	{
//		tempath.push_back(a);
//		int remain=0;
//		int need=0;
//		for(int i=tempath.size()-1;i>=0;i--)
//		{
//			int id=tempath[i];
//			if(weight[id]>0)
//			{
//				remain+=weight[id];
//			}
//			else 
//			{
//				if(remain>abs(weight[id]))
//				{
//					remain-=abs(weight[id]);
//				}
//				else
//				{
//					need+=abs(weight[id])-remain;
//					remain=0;
//				}
//			}
//		}
//		if(need<minneed)
//		{
//			minremain=remain;
//			minneed=need;
//			path=tempath;
//		}
//		else if(need==minneed&&remain<minremain)
//		{
//			minremain=remain;
//			path=tempath;
//		}
//		tempath.pop_back();
//		return ;
//	}
//	tempath.push_back(a);
//	for(int i=0;i<pre[a].size();i++)
//	{
//		DFS(pre[a][i]);
//	}
//	tempath.pop_back();
//}
//void output()
//{
//	for(int i=path.size()-1;i>0;i--)
//	{
//		printf("%d->",path[i]);
//	}
//	printf("%d",path[0]);
//}
//int main()
//{
//	scanf("%d %d %d %d",&c,&n,&sp,&m);
//	p=c/2;
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&bike[i]);
//		weight[i]=bike[i]-p;
//	}
//	int s1,s2;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d %d",&s1,&s2);
//		scanf("%d",&G[s1][s2]);
//		G[s2][s1]=G[s1][s2];
//	}
//	dijkstra(0);
//	DFS(sp);
//	printf("%d ",minneed);
//	output();
//	printf(" %d",minremain);
//	return 0;
//}
 

//16:01
//��������ΪDijstra +DFS(�����ʱ·����������·���Ƚ�) 
//��19�֡���11�ִ𰸴���
//��ʼ����д����������ġ��м�ڵ�����·����ͬʱ���޷�����pre 
//��ǰ��д�����ǽ���vector<int>pre[maxn]��ÿ���ڵ�Ŀ���ǰ׺����¼������
//�ô�д�����ˡ�������ܾ��䡣
//�ر�㣬���ڲ���vector<int>pre[maxn]ȥ��¼�����ǰ���ڵ㡣
//�Լ���DFS()������ʱ����ʱ��������·���� 
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
void CMP()  //�����Ҫģ�⵱ʱ���龰�� 
{
	tempsend=0;
	tempreturn =0;
	int handnum=0;
	//����temppath���һλ��������"0";���ü��� 
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
				//���������������м�ڵ㣬��ô���pre[v]���׸��²��� 
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
//void CMP()  //�����Ҫģ�⵱ʱ���龰�� 
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
//						//����·���� 
//					}	
//				}
//				//���������������м�ڵ㣬��ô���pre[v]���׸��²��� 
//				else if(d[u]+g[u][v]==d[v])    
//				{
//					 //�ٶ�����һ������·����
//					int tempu = pre[v];  
//					if(v==sp)
//					{
//						isupdate=false;
//						pre[v]=u;
//						DFS(v);
//						CMP();
//						//û�и��£������Ǹ���·��
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
 
// ȥ��д�� 
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
//	fill(d,d+maxn,INF);     //һ��ʼ��ʼ����ʹ�õ���fill(d,d+n,INF)��������ʵd[3]�޷���ʼ��������Ϊ0;������������
//	//�������ڵĴ󲿷ֵ�debug������Ϊ��һ����Ϊ����ʮһ��һ���ġ��������˽�fill(d,d+n,INF)��ʼ���ķ�Χ��
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
 

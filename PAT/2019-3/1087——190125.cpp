//21:09——
//20:02   30分哈哈，是有一些细节在里面。比如数最短路径的条数。
//比较多条最短路径的最优两个标尺。 
//套路还是Dijstra +DFS(); 
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
const int maxn = 202;
const int inf = 1000000000;
int n,k;
int hap[maxn];
int g[maxn][maxn];
vector<int>pre[maxn];
vector<int>temppath;
vector<int>bestpath;
bool isvisit[maxn];
int d[maxn];
int routenum[maxn];
int maxhap=-1;
int maxave=-1;
void DFS(int dcity,int sumhap,int cnum)
{
	
	if(dcity==0)
	{
		cnum=cnum-1;
		int tempave = sumhap/cnum;
		if(sumhap>maxhap)
		{
			bestpath=temppath;
			maxhap=sumhap;
			maxave=tempave;
		}
		else if(sumhap==maxhap&&tempave>maxave)
		{
			bestpath=temppath;
			maxave=tempave;
		 }
		 return;
	}
	for(int i=0;i<pre[dcity].size();i++)
	{
		int tempid = pre[dcity][i];
		temppath.push_back(tempid);
		DFS(tempid,sumhap+hap[tempid],cnum+1);
		temppath.pop_back();
	}
}
void Dijstra(int s)
{
	fill(routenum,routenum+maxn,1);
	fill(isvisit,isvisit+maxn,false);
	fill(d,d+maxn,inf);
	d[s]=0;
	routenum[s]=1;
	for(int i=0;i<n;i++)
	{
		int mindis = inf;
		int u=-1;
		for(int j=0;j<n;j++)
		{
			if(isvisit[j]==false&&d[j]<mindis)
			{
				mindis=d[j];
				u=j;
			}
		}
		if(u==-1)
			break;
		isvisit[u]=true;
		for(int v=0;v<n;v++)
		{
			if(isvisit[v]==false&&g[u][v]!=inf)
			{
				if(d[v]>d[u]+g[u][v])
				{
					d[v]=d[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					routenum[v]=routenum[u];
				}
				else if(d[v]==d[u]+g[u][v])
				{
					pre[v].push_back(u);
					routenum[v]+=routenum[u];
				}	
			}
		}
	}
}
int main()
{
	int cityid=0;
	int romid;
	map<string,int>mp1;
	map<int,string>mp2;
	string start;
	cin>>n>>k>>start;
	mp1[start]=cityid;
	mp2[cityid]=start;
	cityid++;
	string tempc;
	int temphap;
	fill(hap,hap+maxn,0);
	//下面只需要输入n-1个城市的快乐值即可，一开始写成n个 
	for(int i=0;i<n-1;i++)
	{
		cin>>tempc>>temphap;
		mp2[cityid]=tempc;
		if(tempc=="ROM")
			romid=cityid;
		hap[cityid]=temphap;
		mp1[tempc]=cityid++;
	}
	string tempc1,tempc2;
	int tempcost;
	fill(g[0],g[0]+maxn*maxn,inf);
	//printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		cin>>tempc1>>tempc2>>tempcost;
		//cout<<tempc1<<tempc2<<tempcost<<endl;
		int fir=mp1[tempc1];
		int sec=mp1[tempc2];
		g[fir][sec]=g[sec][fir]=tempcost;
	}
	Dijstra(0);
	temppath.push_back(romid);
	DFS(romid,hap[romid],1);
	printf("%d %d %d %d\n",routenum[romid],d[romid],maxhap,maxave);
	for(int i=bestpath.size()-1;i>=0;i--)
	{
		//常用做法，现将编号表示出来。 
		int tempi = bestpath[i];
		cout<<mp2[tempi];
		if(i>0)
		cout<<"->";
	}
	return 0;
}

 

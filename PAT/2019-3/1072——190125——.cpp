//19:37

//开始忘记给g[maxn][maxn]初始化了。结果查了10多分钟。
//——20:30只有2分。题中样例是过了。 

//你是不是傻，题中让你求的离房屋尽可能远的加油站，这才是第一标尺。
//其次才是编号。
//所以手足无措时，再看看题意。再看看你的代码。 
//改完后是10分

//再度审题，发现：题中说加油站和任一居民楼的距离的《最短距离》尽可能远，
//则第一标尺，应该是加油站和所有居民楼的"最短距离"最长。
//第一段话细节很多。 准确理解 

//仔细看看第一段话，又发现一个细节，第二标尺才是平均距离尽可能短
//然后第三标尺是编号最小。 

//改完后30分。你也是真够可以，3个度标尺，被你看成一个，还给看错了。
//前面的最短路径部分并不是难点。难点在于将三个标尺理得清清楚楚。 
//——21:08 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int inf = 1000000000;
const int maxn = 1012;
const int maxm = 12;
int g[maxn][maxn];
bool isvisit[maxn];
int d[maxn];
bool ischeck[maxm];
double gasmindis[maxm];
double gasavedis[maxm];
int n,m,k,ds;
void Dijstra(int s)
{
	fill(isvisit,isvisit+maxn,false);
	fill(d,d+maxn,inf);
	//printf("%d  %d\n",d[1],d[2]);
	d[s]=0;
	for(int i=1;i<=n+m;i++)
	{
		int mind = inf;
		int u=-1;
		for(int j=1;j<=n+m;j++)
		{
			if(isvisit[j]==false&&d[j]<mind)
			{
				mind= d[j];
				u = j;
			}
		}
		if(u==-1)
			break;
		isvisit[u]=true;
		for(int v=1;v<=n+m;v++)
		{
			if(isvisit[v]==false&&g[u][v]!=inf&&d[u]+g[u][v]<d[v])
				d[v]=d[u]+g[u][v];
		}
	}
}
int main()
{	
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	string p1,p2,tempp;
	int d1,d2;
	int tempdis;
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<k;i++)
	{
		cin>>p1>>p2>>tempdis;
		if(p1[0]=='G')
		{
			int len =p1.length(); 
			tempp=p1.substr(1,len);
			sscanf(tempp.c_str(),"%d",&d1);
			d1+=n;
		}
		else
			sscanf(p1.c_str(),"%d",&d1);
		if(p2[0]=='G')
		{
			int len =p2.length(); 
			tempp=p2.substr(1,len);
			sscanf(tempp.c_str(),"%d",&d2);
			d2+=n;
		}
		else
			sscanf(p2.c_str(),"%d",&d2);
		g[d1][d2]=tempdis;
		g[d2][d1]=tempdis;
		//printf("%d %d\n",d1,d2);
	}
	fill(ischeck,ischeck+maxm,true);
	for(int i=n+1;i<=n+m;i++)
	{
		Dijstra(i);
		double sum =0;
		double min =inf;
		for(int j=1;j<=n;j++)
		{
			//printf("%d ",d[j]);
			sum+=d[j];
			if(d[j]<min)
				min=d[j];	
			if(d[j]>ds)
			{
				ischeck[i-n]=false;
				break;
			}
		}
		//printf("\n");
		if(ischeck[i-n]==true)
		{
			//printf("%.2f %.2f\n",sum,min);
			gasmindis[i-n]=min;
			gasavedis[i-n]=sum/(1.0*n);
		}
	}
	int mindis =-1;
	int minsta=-1; 
	int minave;
	for(int i=1;i<=m;i++)
	{
		if(ischeck[i]==true)
		{
			if(gasmindis[i]>mindis)
			{
				mindis=gasmindis[i];
				minsta=i;
				minave=gasavedis[i];
			}
			else if(gasmindis[i]==mindis&&gasavedis[i]<minave)
			{
				minsta=i;
				minave=gasavedis[i];
			}	
		}
	}
	if(minsta!=-1)
	{
		printf("G%d\n",minsta);
		printf("%.1f %.1f\n",gasmindis[minsta],gasavedis[minsta]);
	}
	else
		printf("No Solution\n");
	return 0;	
 } 

//08:48  ——09：46  25分。
//题不难。哪怕剩半个小时，也要把题意理解透彻。看清题意理解透彻。 
//简单 TS是每个都访问，但是都访问一次。
///非简单，也是每个都访问，且是回路。但是并不是每个都访问一次。
//题属于图论，难点在于清晰的界定，每种情况的边界条件。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 205;
int G[maxn][maxn]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v,d;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&d);
		G[u][v]=d;
		G[v][u]=d;
	}
	int k;
	int n2;
	int path[maxn];
	int isvisit[maxn]={false};
	scanf("%d",&k);
	int minDist = -1;
	int minIndex=0;
	for(int i=1;i<=k;i++)
	{
		fill(isvisit,isvisit+maxn,false);
		bool isSimple = true;
		bool isCycle = true;
		scanf("%d",&n2);
		for(int j=0;j<n2;j++)
		{
			scanf("%d",&path[j]);
			isvisit[path[j]]=true;
		}
		printf("Path %d: ",i);
		if(n2!=n+1)
			isSimple = false;
		if(path[n2-1]!=path[0])
		{
			isCycle = false;
			isSimple = false;
		}
		if(isSimple==true||isCycle==true)
		{
			for(int j=1;j<=n;j++)
			{
				if(isvisit[j]==false)
				{
					isSimple = false;
					isCycle = false;
					break;
				}
			}
		}
		int totalDist = 0;
		for(int j=0;j<n2-1;j++)
		{
			if(G[path[j]][path[j+1]]!=0)
			{
				totalDist+=G[path[j]][path[j+1]];
			}
			else
			{
				isSimple = false;
				isCycle = false;
				totalDist = 0;
				break;
			}
		}
		if(isCycle==true&&minDist == -1)
		{
			minDist = totalDist;
			minIndex= i;
		}
		else if(isCycle==true&&minDist>0&&totalDist<minDist)
		{
			minDist = totalDist;
			minIndex= i;
		}
		if(isSimple == true)
		{
			printf("%d (TS simple cycle)\n",totalDist);
		}
		else if(isCycle==true)
		{
			printf("%d (TS cycle)\n",totalDist);
		}
		else if(totalDist>0)
		{
			printf("%d (Not a TS cycle)\n",totalDist);
		}
		else
		{
			printf("NA (Not a TS cycle)\n");
		}		
	}
	printf("Shortest Dist(%d) = %d\n",minIndex,minDist);
	return 0;
}

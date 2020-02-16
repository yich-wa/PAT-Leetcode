//20:45——
//——21:04
//题的实际意义在于求图的连通分量个数。不过要选好存储方式。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
int g[maxn][maxn]={0}; 
vector<int>adjust[maxn];
int flag[maxn]={false};
int n,m,k;
void DFS(int a)
{
	flag[a]=true;
	for(int i=0;i<adjust[a].size();i++)
	{
		int temp =adjust[a][i];
		if(flag[temp]==false)
			DFS(temp);
	}
	return ;
}
int main()
{
	
	int c1,c2;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&c1,&c2);
		adjust[c1].push_back(c2);
		adjust[c2].push_back(c1);
	}
	int dcity;
	for(int i=0;i<k;i++)
	{
		fill(flag+1,flag+n+1,false);
		int num=0;
		scanf("%d",&dcity);
		flag[dcity]=true;
		for(int j=1;j<=n;j++)
		{
			if(flag[j]==false)
			{
				DFS(j);
				num++;
			}
		}
		printf("%d\n",num-1);	
	}
	return 0;	
}

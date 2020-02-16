//21:06——

//21:32——25分。
//考察数连通分量的个数。 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;
vector<int>g[maxn];
bool flag[maxn]={false};
int deepest[maxn]={0};
void DFS(int a)
{
	flag[a]=true;
	for(int i=0;i<g[a].size();i++)
	{
		int temp = g[a][i];
		if(flag[temp]==false)
		{
			DFS(temp);
		 } 
	}
}
void Depth(int a,int level,int seq)
{
	if(level>deepest[seq])
		deepest[seq]=level;
	flag[a]=true;
	for(int i=0;i<g[a].size();i++)
	{
		int temp =g[a][i];
		if(flag[temp]==false)
		{
			Depth(temp,level+1,seq);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int c1,c2;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&c1,&c2);
		g[c1].push_back(c2);
		g[c2].push_back(c1);
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==false)
		{
			DFS(i);
			num++;
		}
	}
	if(num>1)
	{
		printf("Error: %d components\n",num);
	}
	else
	{
		int maxdepth=0;
		vector<int>out;
		for(int i=1;i<=n;i++)
		{
			fill(flag+1,flag+n+1,false);
			Depth(i,1,i);
			if(deepest[i]>maxdepth)
			{
				maxdepth=deepest[i];
				out.clear();
				out.push_back(i);
			}
			else if(deepest[i]==maxdepth)
			{
				out.push_back(i);
			}
		}
		for(int i=0;i<out.size();i++)
		{
			printf("%d\n",out[i]);	
		}
	}
	return 0;
}

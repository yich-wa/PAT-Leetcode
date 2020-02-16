//20:59——21:18
//25分。用向量去表示儿子，在加深度优先遍历 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=101;
vector<int>child[maxn];
int maxl=-1;
int gnumber[maxn]={0};
void DFS(int a,int level)
{
	if(child[a].size()==0)
	{
		gnumber[level]++;
		if(level>maxl)
		{
			maxl=level;
		}
		return ;
	}
	else
	{
		gnumber[level]++;
		for(int i=0;i<child[a].size();i++)
		{
			DFS(child[a][i],level+1);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int id,k,tempid;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&id,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&tempid);
			child[id].push_back(tempid);
		}
	}
	DFS(1,1);
	int maxnum =0;
	int maxg;
	for(int i=1;i<=maxl;i++)
	{
		if(gnumber[i]>maxnum)
		{
			maxnum=gnumber[i];
			maxg=i;
		}	
	}
	printf("%d %d\n",maxnum,maxg);
	return 0;
 } 
 

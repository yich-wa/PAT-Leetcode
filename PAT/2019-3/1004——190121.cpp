//21:44——//21:59
//30分。读懂题意。细节稳住。 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int>child[maxn]; 
int nochild[maxn]={0};
int maxlevel=-1;
void DFS(int a,int level)
{
	if(child[a].size()==0)
	{
		nochild[level]++;
		if(level>maxlevel)
		{
			maxlevel=level;
		}
	}
	else
	{
		for(int i=0;i<child[a].size();i++)
		DFS(child[a][i],level+1);
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	if(n==0)
		return 0;
	else
	{
		scanf("%d",&m);
	}
	int id ,k,tempid;
	for(int i=0;i<m;i++) 
	{
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempid);
			child[id].push_back(tempid);
		}
	}
	DFS(1,0);
	for(int i=0;i<=maxlevel;i++)
	{
		printf("%d",nochild[i]);
		if(i<maxlevel)
		printf(" ");
		else
		printf("\n");
	 } 
	 return 0;
}

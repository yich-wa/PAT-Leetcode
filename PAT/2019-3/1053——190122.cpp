//21:00——
//21:24  30分。题不难，稳住，细节要注意。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 105;
vector<int>path;
int n,m,s;
int weight[maxn];
vector<int>child[maxn];
bool cmp(int a,int b)
{
	return weight[a]>weight[b];
}
void out(vector<int>a)
{
	int len =a.size();
	for(int i=0;i<len;i++)
	{
		printf("%d",weight[a[i]]);
		if(i<len-1)
		printf(" ");
		else
		printf("\n");
	}
}
void DFS(int a,int w)
{
	if(w>s)  //提前截断，没必要继续往下搜素。 
		return ;
	if(child[a].size()==0)
	{
		if(w==s)
		{
			out(path);
		}
		return;
	}
	else
	{
		for(int i=0;i<child[a].size();i++)
		{
			int temp =child[a][i];
			path.push_back(temp);
			DFS(temp,w+weight[temp]);
			path.pop_back();
		}
	}
}
int main()
{	
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	int tempid,k,tempchild;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&tempid,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempchild);
			child[tempid].push_back(tempchild);
		}
		sort(child[tempid].begin(),child[tempid].end(),cmp);
	 } 
	 path.push_back(0);
	 DFS(0,weight[0]);
	 return 0;
 } 

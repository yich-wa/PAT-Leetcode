//19:45——
//
//——20:06  25分
//题不难，但细节要非常稳 ，思路要清晰。 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int maxn = 100010;
vector<int>tree[maxn];
int amount[maxn];
double sum =0;
double p,r;
void DFS(int a,int level)
{
	if(tree[a].size()==0)
	{
		sum+=1.0*amount[a]*p*pow(r,level*1.0);
		return;
	}
	else
	{
		for(int i=0;i<tree[a].size();i++)
		{
			DFS(tree[a][i],level+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d%lf%lf",&n,&p,&r);
	r=1+r/(1.0*100);
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		int temp;
		if(k==0)
		{
			scanf("%d",&amount[i]);
		}
		else
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temp);
			tree[i].push_back(temp);
		}
	}
	DFS(0,0);
	printf("%.1f\n",sum);
	return 0; 
 } 


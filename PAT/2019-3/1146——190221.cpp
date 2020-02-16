//09:43——10:02 25分。拓扑排序。注意问题解决的思路。
//经典问题的解决思路要非常清晰。 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int>G[maxn];
int indegree[maxn]={0};
int tempindegree[maxn]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		tempindegree[v]++;

	}
	int k;
	scanf("%d",&k);
	vector<int>output;
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=n;j++)
			indegree[j]=tempindegree[j];
		bool flag=true;
		int temp;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			if(flag==true)
			{
				if(indegree[temp]!=0)
				{
					flag=false;
					output.push_back(i);
				}
					
				else
				{
					int len = G[temp].size();
					for(int h=0;h<len;h++)
					{
						indegree[G[temp][h]]--;
					}
				}
			}
		}		
	}
	for(int i=0;i<output.size();i++)
	{
		printf("%d",output[i]);
		if(i<output.size()-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10005;
const int maxm = 10005;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v;
	vector<int> V[maxn];
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int color[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&color[j]);
		}
		bool flag=true; 
		for(int j=0;j<n;j++)
		{
			if(flag==true) 
				for(int h=0;h<V[j].size();h++)
				{
					int u= V[j][h];
					if(color[j]==color[u]) 
					{
						flag=false;
						break;
					}
				} 
			if(flag==false)
			{
				printf("No\n");
				break;	
			 } 
		}
		if(flag==true)
		{
			int count=0;
			int pre =-1;
			sort(color,color+n);
			for(int j=0;j<n;j++)
				if(color[j]!=pre)
				{
					pre =color[j];
					count++;
				}	
			printf("%d-coloring\n",count);
		}	
	}
	return 0; 
}

//09:16——09:43搞定 25分。
//第一遍写完有些问题，每个氧化剂会和多个氧化物匹配，所以应该用邻接表法
//去存储。 这道题，应该用数据区检验思路，样例数据即可，就会发现应该
//采用邻接表去记录之间的关系。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
const int maxg = 100005;
bool isDanger[maxg]={false};
vector<int>partner[maxg];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		isDanger[u]=true;
		isDanger[v]=true;
		partner[u].push_back(v);
		partner[v].push_back(u);
	}
	int k,tempG;
	for(int i=0;i<m;i++)
	{
		bool flag=true;
		bool isforbid[maxg]={false};
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempG);
			if(isforbid[tempG]==false)
			{
				if(isDanger[tempG]==true)
				{
					//printf("%d&&&%d\n",tempG,partner[tempG]);
					int len = partner[tempG].size();
					for(int h=0;h<len;h++)
					{
						int temp = partner[tempG][h];
						isforbid[temp]=true;
					}
					
				}
			}
			else if(flag==true)
			{
				printf("No\n");
				flag=false;
			}
		}
		if(flag==true)
			printf("Yes\n");
	}
	return 0;
 } 

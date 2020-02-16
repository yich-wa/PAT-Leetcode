//15:54——16:09
//25分。题不难，思路要很清晰。 
//初选数据、筛选数据。 步骤想清楚。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 10005;
struct edge{
	int u;
	int v;
}E[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&E[i].u,&E[i].v);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		bool isvisit[maxn]={false};
		int flag=true;
		int nv ,temp;
		scanf("%d",&nv);
		for(int j=0;j<nv;j++)
		{
			scanf("%d",&temp);
			isvisit[temp]=true;
		}
		for(int j=0;j<m;j++)
		{
			if(isvisit[E[j].u]==false&&isvisit[E[j].v]==false)
			{
				printf("No\n");
				flag=false;
				break;
			}
		}
		if(flag==true)
			printf("Yes\n");
	}
	return 0;
}
 

//09:07 ——09:25 15分  第23测试点段错误。 10分的段错误
// 经检查，是将maxn少打了一个 "0"; 
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
const int maxn = 10005;
struct edge{
	int u,v;
}temp;
int main()
{
	int color[maxn];
	vector<edge>e;
	set<int>s; 
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&temp.u,&temp.v);
		e.push_back(temp);
	}
	int k;
	int tempu,tempv;
	bool flag;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		flag = true;
		s.clear();
		for(int j=0;j<n;j++)
		{
			scanf("%d",&color[j]);
			s.insert(color[j]);
		}
		int len = e.size();
		for(int j=0;j<len;j++)
		{
			tempu = e[j].u;
			tempv = e[j].v;
			if(color[tempu]==color[tempv])
			{
				printf("No\n");
				flag=false;
				break;
			}
		}
		if(flag==true) 
		{
			printf("%d-coloring\n",s.size());
		}
	}
	return 0;
}

//21:19—— 21:42

//本身题很简单，考察深度优先遍历，
//但是你犯了低级错误。
//双层嵌套循环都用的是i作为指针，结果出现难以预计的
//该低级错误好费时间约10分钟。 
 
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 100010;
double p,r;
vector<int>dis[maxn];
int minlevel = maxn;
int minnum;
void DFS(int a,int level)
{
	if(dis[a].size()==0)
	{
		if(level<minlevel)
		{
			minlevel = level;
			minnum=1;
			//printf("%d %d \n",a,level);
		}
		else if(level==minlevel)
		{
			//printf("%d %d \n",a,level);
			minnum++;
		}		
	}
	else
	{
		for(int i=0;i<dis[a].size();i++)
			DFS(dis[a][i],level+1);
	}
}
int main()
{
	int n;
	scanf("%d%lf%lf",&n,&p,&r);
	r=1+r/100;
	int k;
	int temp;
	//开始下面的双层嵌套循环都用的是i作为指针，结果出现难以预计的
	//错误
	 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temp);
			dis[i].push_back(temp);
		}
	 } 
	 DFS(0,0);
	 p=p*pow(r,minlevel*1.0);
	 printf("%.4f %d",p,minnum);
	 return 0;
}

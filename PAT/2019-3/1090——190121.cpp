//20:08
//——20:41 
//——20:23  13分，12分 5个答案错误。

//看答案后发现，自己记录的是double型的最高价格，等累计次数过多
//会出现误差，所以还是先记录最大深度 
//改成记录最大深度，还是12分的答案错误。

//低级错误 
//开始下面的r=1+1/r;写成了"r=r+1/100",刚好样例r就等于1.00所以
//又是低级错误。 所以。慢就是稳，稳就是快，一定要稳住。
//清楚准确的表达自己的思路和逻辑。 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int maxn = 100010;
double p,r;
vector<int>dis[maxn];
double hprice=-1;
int hdepth=-1;
int highnum=0;
void DFS(int a,int level)
{
	if(dis[a].size()==0)
	{
		if(level>hdepth)
		{
			hdepth=level;
			highnum =1;
		}
		else if(level==hdepth)
		{
			highnum++;
		}
	}
	else
	{
		for(int i=0;i<dis[a].size();i++)
		{
			DFS(dis[a][i],level+1);
		}
	}
}
int main()
{
	int n;
	int root;
	scanf("%d%lf%lf",&n,&p,&r);
	//开始下面的写成了"r=r+1/100",刚好样例r就等于1.00所以
	//又是低级错误。 
	r=1+r/100;
	int temp;
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&temp);
		if(temp==-1)
		{
			root=i;	
		}
		else
		{
			dis[temp].push_back(i);
		}
	}
	DFS(root,0);
	hprice = p*pow(r,hdepth*1.0);
	printf("%.2f %d\n",hprice,highnum);
	return 0;
}


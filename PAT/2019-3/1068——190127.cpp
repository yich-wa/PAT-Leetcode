//19:14
//01背包问题，价值和质量等同。 
//先选大的，直接导致了。最后序列变小。
//故先将其从大到小排序 
//因为质量和价值是一样的。质量的最大值就是装满，所以价值的最大值，也是
//dp[m]=m这是内在的逻辑，01背包问题的内在逻辑。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn =10010;
const int maxm =105;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	int value[maxn];
	int dp[maxm];
	//记录每种情况下的抉择情况。 
	//默认是不选的。 
	int choice[maxn][maxn]={0};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&value[i]);
	}
	sort(value+1,value+n+1,cmp);
	for(int i=0;i<=m;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		//01背包问题，倒着枚举。 
		for(int v = m;v>=value[i];v--)
		{ 
			if(dp[v]<=dp[v-value[i]]+value[i])
			{
				dp[v]=dp[v-value[i]]+value[i];
				choice[i][v]=1;
			}
		}
	}
	if(dp[m]!=m)
		printf("No Solution\n");
	else
	{
		bool flag[maxn]={false};
		int num=0;
		int k=n;
		int v=m;
		//最终v是考虑了，n个物件后得总价值。
		//故应该从k应该从N开始。倒着考虑。 
		while(k>=0) //k可以等于0吗？ 
		{
			if(choice[k][v]==1)
			{
				flag[k]=true;
				v=v-value[k];  //这句也是关键。 
				num++;
			}
			else
				flag[k]=false;
			k--;
		} 
		int count =0;
		for(int i=0;i<=n;i++)
		{
			if(flag[i]==true)
			{
				printf("%d",value[i]);
				if(count<num)
					printf(" ");
				else
				{
					printf("\n");
					break;	
				}
				count++;	
			}
		}	
	}
	return 0;  
} 

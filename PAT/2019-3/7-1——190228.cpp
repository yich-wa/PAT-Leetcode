//第一次16分，忘记考虑前面有很多零的情况。 
//出了 好多问题，最后经过自己试数据，发现，自己因该输出
//具体数的时候，却输出了序号。 
//实质是动态规划的问题 
#include<stdio.h>
const int maxn = 10005;
int main()
{
	int k;
	int seq[maxn];
	int dp[maxn];
	int st[maxn];
	bool isNeg = true;
	int ans =-1;
	int tag;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&seq[i]);
		if(isNeg==true&&seq[i]>=0)
			isNeg=false;
		if(i==0)
		{
			dp[0]=seq[0];
			st[0]=0;
		}
		else
		{
			
			if(dp[i-1]>=0)
			{
				dp[i]=dp[i-1]+seq[i];
				st[i]=st[i-1];
			}
			else
			{
				dp[i]=seq[i];
				st[i]=i;
			}
		}
		if(dp[i]>ans)
		{
			ans = dp[i];
			tag = i;
		}
	}
	if(isNeg==true)
		printf("0 %d %d\n",seq[0],seq[k-1]);
	else
		printf("%d %d %d\n",ans,seq[st[tag]],seq[tag]);
	return 0;
 } 

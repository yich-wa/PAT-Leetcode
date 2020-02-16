//14：59——

///15:22   21分，4分答案错误。
//中间的sum数组用的非常好。解决了尽量让和相等的序列长度向前延伸。
//发现全负数的情况，自己想到了写的时候出现低级失误导致错误
//改过后是25分。 

//20190226修改
//用动态规划的方法
//用sum[i]记录以seq[i]结尾的的最大连续子序列和。然后start[i]记录
//该序列的起点序号。
//如果sum[i-1]<0的话。sum[i]=seq[i]; 以及start[i]=i;
//否则sum[i]=sum[i-1]+seq[i]; start[i]=start[i-1]; 
//经测试 25分。 
 
#include<stdio.h>
const int maxn = 10010;
int main()
{
	int k;
	int seq[maxn];
	int sum[maxn]={0};
	int start[maxn];
	int dp[maxn]; 
	scanf("%d",&k);
	bool flag =false;
	for(int i=0;i<k;i++)
	{
		scanf("%d",&seq[i]);
		//用sum数组去确定连续序列的起点是正确的方式，这样
		//即使j确定，i尽可能小的方式。 
		if(i>0&&sum[i-1]>0)
		{
			sum[i]=sum[i-1]+seq[i];
			start[i]=start[i-1];
		}
		else
		{
			start[i]=i;
			sum[i]=seq[i];	
		}
		if(flag==false&&seq[i]>=0)
			flag =true;
	}
	if(flag==false)
	{
		printf("0 %d %d\n",seq[0],seq[k-1]);
		return 0;
	}
	int maxdp = sum[0];
	int index = 0;
	for(int i=1;i<k;i++)
	{
		if(sum[i]>maxdp)
		{
			maxdp=sum[i];
			index=i;
		}		
	}
	printf("%d %d %d\n",maxdp,seq[start[index]],seq[index]);
	return 0;
}

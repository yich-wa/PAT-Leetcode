//09:07——

//long long 的输入输出都是%lld; 

//——09:43   21分
//前面出了极端低级的错误。大概耗费10分钟。 
//经数据检查，发现没有照顾到数字本身是素数的情况。
//那种情况，即其因子数为0,特判输出； 
//与其比较类似的情况是1=1； 
///——09:47   25分。
 
//尽管答案是对了，但是像2*1291这样的数据依旧输出错误。因为你没考虑到
//大于sqrt的素数因子。
 
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int maxn = 1000000000;
vector<int>p;
vector<int>k;
bool prime[maxn]={false};
int main()
{
	LL n;
	scanf("%lld",&n);
	//fill(prime,prime+maxn,true);
	int sqn = (int)sqrt(1.0*n);
	for(int i=2;i<=sqn;i++)
	{
		//printf("%d %lld\n",i,n);
		for(int j=i*2;j<=sqn;j=j+i)
		{
			prime[j]=true;
		}
	}
	int temp;
	int temk;
	LL temn =n;
	//printf("%lld\n",n);
	for(int i= 2;i<=sqn;i++)
	{
		//开始下面有个低级错误。数字是i,而不是prime[i],所以
		//prime[i]是bool型变量。属于低级错误。 
		//所以尽量稳一些。 写代码问一些。；稳住。你可以的。 
		if(prime[i]==false&&n%i==0)
		{
			temp = i;
			temk = 0;
			while(n%temp==0)
			{
				temk++;
				n=n/temp;
			}
			p.push_back(temp);
			k.push_back(temk);	
		}
		if(n==1)
		{
			break;
		}
	}
	//有可能会剩下一个大于sqn的素数因子 如2*1291;
	//虽答案没有测出，应加上下面的：
	if(n!=1)
	{
		p.push_back(n);
		k.push_back(1);	
	} 
	printf("%lld=",temn);
	if(p.size()==0)
	{
		printf("%lld\n",temn);
	}
	else
	for(int i=0;i<p.size();i++)
	{
		if(k[i]==1)
		printf("%d",p[i]);
		else
		printf("%d^%d",p[i],k[i]);
		if(i<p.size()-1)
		printf("*");
		else
		printf("\n");
	}
	return 0;
}

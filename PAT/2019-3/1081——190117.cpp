//09:18——09:50  20分。基础知识要扎实。分数的加减乘除
//分数的简化，表达。求最大公约数。 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 104;
typedef long long LL;  //题目已经提示要用长整数。 
struct fraction{
	LL nu;
	LL de;
}fra[maxn],sum,temp;
LL gcd(LL a,LL b)   //求最大公约数 
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b); 
} 
fraction reduct(fraction a)
{
	if(a.nu==0)   //分数的简化 
	{
		a.de=1;
		return a;
	}				//注意求最大公约数是绝对值。 
	LL g =gcd(abs(a.nu),abs(a.de));  
	a.nu = a.nu/g;
	a.de = a.de/g;
	return a;
}
fraction f_add(fraction a,fraction b)
{
	temp.de = a.de*b.de;
	temp.nu = a.nu*b.de+b.nu*a.de;
	temp =reduct(temp);
	return temp;
}
int main()
{
	int n;
	sum.nu=0;//求和分数的分母初试化应该为0 而非为1； 
	sum.de=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld/%lld",&fra[i].nu,&fra[i].de);
		sum = f_add(sum,fra[i]);
	 } 
	 if(sum.de==1)
	 	printf("%lld",sum.nu);
	else if(abs(sum.nu)>sum.de)
	{
		printf("%lld %lld/%lld\n",sum.nu/sum.de,abs(sum.nu%sum.de),sum.de);
	}
	else
	{
		printf("%lld/%lld\n",sum.nu,sum.de);
	}
	return 0;	
 } 

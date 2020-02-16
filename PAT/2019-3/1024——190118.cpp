//10:56——
// 

//细节bug
//翻转时j<len/2;不能是j<=len/2。想想只有2位你就很清晰了。
// 即len = 2;
//
 
//20分。5分的非零返回。
//翻转可以用reverse()函数，reverse(n,n+len); 

//优化代码，两个大整数相加，结果直接寄存在其中一个里面即可。 
//结果还是20分。

//原因是因为你在main函数里用了，return true ; 而不是return 0;
//改完后25分。 这个属于低级错误。 
 
  
#include<stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
const int maxn = 120;
bool ispalind(char a[])
{
	int len = strlen(a);
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-1-i])
		{
			return false;
		}
	}
	return true;
}
void out(char a[])
{
	int len =strlen(a);
	for(int i=len-1;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return ;
 } 
int main()
{
	char n[maxn];
	char n2[maxn];
	char n3[maxn];
	int k;
	int numk=0;
	scanf("%s %d",n,&k);
	if(ispalind(n)==true)
	{
		printf("%s\n",n);
		printf("%d",numk);
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		strcpy(n2,n);
		int len = strlen(n2);
		//下面是j<len/2；不能是j<=len/2
		//否则，假如只有两位，(0,1)交换。(1,0)在交换，等于无效。
		//临界条件要非常清晰。 
		reverse(n2,n2+len); 
//		for(int j=0;j<len/2;j++)  //翻转 
//		{
//			swap(n2[j],n2[len-1-j]);
//		}
		int carry =0;
		int result;
		int num3=0;
		for(int j=0;j<len;j++)   //相加 
		{
			result = n[j]-'0'+n2[j]-'0'+carry;
			carry = result/10;
			result=result%10;
			n[num3++]='0'+result;
		}
		if(carry!=0)
		{
			n[num3++]='0'+carry;
		}
		n[num3]='\0';
		if(ispalind(n)==true)
		{
			printf("%s\n",n);
			printf("%d",i);
			return 0;
		}
	}
	out(n);
	printf("%d",k);
	return 0;	
 } 

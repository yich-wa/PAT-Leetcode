//09:18����09:50  20�֡�����֪ʶҪ��ʵ�������ļӼ��˳�
//�����ļ򻯣��������Լ���� 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 104;
typedef long long LL;  //��Ŀ�Ѿ���ʾҪ�ó������� 
struct fraction{
	LL nu;
	LL de;
}fra[maxn],sum,temp;
LL gcd(LL a,LL b)   //�����Լ�� 
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b); 
} 
fraction reduct(fraction a)
{
	if(a.nu==0)   //�����ļ� 
	{
		a.de=1;
		return a;
	}				//ע�������Լ���Ǿ���ֵ�� 
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
	sum.nu=0;//��ͷ����ķ�ĸ���Ի�Ӧ��Ϊ0 ����Ϊ1�� 
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

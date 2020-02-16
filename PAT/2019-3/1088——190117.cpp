//09:53����10:40 
//17�֡�������Ҫ��ʵ�� 3�ִ𰸴��� 

//ϸ��**** 
//�Է�������ֹ�Ƿ�ĸΪ��������Ϊ�������з�ĸΪ��������ҲΪ��


//���������������20�֡� 
//�����д�ɺ�������ȷ������ 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long LL;
struct fraction{
	LL up;
	LL down;
}a,b,sum ,dif,pro,quo,temp;
LL gcd(LL a ,LL b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
fraction reduction(fraction a)
{
	if(a.up==0)
	{
		a.down =1;
		return a;
	}
	//�Է�������ֹ�Ƿ�ĸΪ��������Ϊ�������з�ĸΪ��������ҲΪ�� 
	else if(a.down<0)
	{
		a.up=-a.up;
		a.down = -a.down;
	}
	LL g =gcd(abs(a.up),abs(a.down));
	a.up = a.up/g;
	a.down = a.down/g;
	return a;
}
fraction f_add(fraction a,fraction b)
{
	temp.up = a.up*b.down+b.up*a.down;
	temp.down = a.down*b.down;
	temp = reduction(temp);
	return temp;
}
fraction f_minus(fraction a,fraction b)
{
	temp.down =a.down*b.down;
	temp.up = a.up*b.down-b.up*a.down;
	temp = reduction(temp);
	return temp;
}
fraction f_product(fraction a,fraction b)
{
	temp.down =a.down*b.down;
	temp.up = a.up*b.up;
	temp = reduction(temp);
	return temp;
}
fraction f_quotient(fraction a,fraction b)
{
	temp.down =a.down*b.up;
	temp.up = a.up*b.down;
	temp = reduction(temp);
	return temp;
}
void f_pri(fraction a)
{
	if(a.up==0)
	{
		printf("0");
		return ;
	}	
	if(a.up<0)
		printf("(");
	if(a.down==1)
		printf("%lld",a.up);
	else if(abs(a.up)>abs(a.down))
	{
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);	
	}
	else
	{
		printf("%lld/%lld",a.up,a.down);
	}
	if(a.up<0)
		printf(")");
	return ;
}
int main()
{
	scanf("%lld/%lld",&a.up,&a.down);
	scanf("%lld/%lld",&b.up,&b.down);
	a = reduction(a);
	b = reduction(b);
	char sym[4]={'+','-','*','/'};
	for(int i=0;i<4;i++)
	{
		if(i==0)
		temp = f_add(a,b);
		else if(i==1)
		temp = f_minus(a,b);
		else if(i ==2)
		temp = f_product(a,b);
		else if(i==3&&b.up!=0)
		temp = f_quotient(a,b);
		f_pri(a);
		if(i==3&&b.up==0)
		{
			printf(" / 0 = Inf");
		}
		else
		{
			printf(" %c ",sym[i]);
			f_pri(b);
			printf(" = ");
			f_pri(temp); 
		}
		printf("\n");
	}
	return 0;
 } 

//double�����õ���   %lf�� ��һ����2�ִ𰸴��� 
//������������ά�ȶ��ĳ�double֮���õ�ȫ�֡���������double�� 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1005;
struct moon
{
	double ton;
	double tprice;
}M[maxn];
bool cmp(moon a,moon b)
{
	double pricea =a.tprice/a.ton;
	double priceb =b.tprice/b.ton;
	return pricea>priceb;
}
int main()
{
	int n;
	double m;
	scanf("%d %lf",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&M[i].ton);
	}
	for(int i=0;i<n;i++)
		scanf("%lf",&M[i].tprice);
	sort(M,M+n,cmp);
	double profit=0;
	for(int i=0;i<n;i++)
	{
		if(M[i].ton<m)
		{
			profit+=M[i].tprice;
			m = m-M[i].ton;	
		}
		else 
		{
			profit+=(double)m*(M[i].tprice/M[i].ton);
			break;
		}	
	}
	printf("%.2f\n",profit);
	return 0;
}

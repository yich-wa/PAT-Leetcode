//09:30¡ª¡ª09:43
#include<stdio.h>
#include<math.h>
const int maxn = 100010;
int main()
{
	int n;
	double seq[maxn];
	scanf("%d",&n);
	double sum =0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&seq[i]);
		sum+=seq[i]*(n-i)*(i+1);
	}
	printf("%.2f\n",sum);
	return 0;
 } 

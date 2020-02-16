//注意大整数的定义和输入，以及正负溢出。
//正溢出小于0.负溢出，有可能大于等于0 
//要单独将a+b先存到一个大整数res中。直接用a+b去比是会出问题的。 
#include<stdio.h>
const int maxn =12;
int main()
{
	int n;
	scanf("%d",&n);
	long long a,b,c;
	long long res;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		res = a+b;
		printf("Case #%d: ",i+1);
		if((a>0)&&(b>0)&&(res<0))
			printf("true\n");
		else if((a<0)&&(b<0)&&(res>=0))//***这个是有等于号的 
			printf("false\n");
		else if(res>c)
			printf("true\n");
		else
			printf("false\n");	
	}
	return 0; 
}

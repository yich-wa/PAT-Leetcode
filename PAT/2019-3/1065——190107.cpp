//ע��������Ķ�������룬�Լ����������
//�����С��0.��������п��ܴ��ڵ���0 
//Ҫ������a+b�ȴ浽һ��������res�С�ֱ����a+bȥ���ǻ������ġ� 
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
		else if((a<0)&&(b<0)&&(res>=0))//***������е��ںŵ� 
			printf("false\n");
		else if(res>c)
			printf("true\n");
		else
			printf("false\n");	
	}
	return 0; 
}

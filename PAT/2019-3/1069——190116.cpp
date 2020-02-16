//8:53——9:28
//思维要很清晰 ，准确翻译题意找准界线点。
//界限准确清晰。 
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp( char a,char b)
{
	return a>b;
}
int main()
{
	char a1[6];
	char a2[6];
	int num1,num2,num;
	scanf("%s",a1);
	int len1 =strlen(a1);
	if(len1==4)
	{
		bool flag=true;
		for(int i=1;i<len1;i++)
			if(a1[i]!=a1[i-1])
			{
				flag=false;
				break;
			}
		if(flag==true)
		{
			printf("%s - %s = 0000\n",a1,a1);
			return 0;
		}		
	}
	num=0;
	while(num!=6174)
	{
		int len1 =strlen(a1);
		sort(a1,a1+len1);	
		sscanf(a1,"%d",&num1); 
		sort(a1,a1+len1,cmp);
		sscanf(a1,"%d",&num2);
		//有可能小于4位数。 
		while(num2<1000)
			num2=num2*10; 
		num =num2-num1;
		printf("%04d - %04d = %04d\n",num2,num1,num);
		sprintf(a1,"%d",num);
	}
	return 0;
 } 

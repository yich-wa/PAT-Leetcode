//09:51—— 
//——10:07，13分 
//想清楚计算某一pos位为1 的数有多少个。
//若此位为">1",则分两部分来计算。左边总计数left乘pow(10,右边位数)
//若此位为"=1" ,则 左边总计数(left-1)乘 pow(10,右边位数)+ 右边总计数right
//若此位为"=0" ,则  左边总计数(left-1)乘 pow(10,右边位数)

//——10:40 
//经过上面的分类讨论，得30分。 
//分类讨论思路要非常清晰。 
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	char a[15];
	scanf("%s",a);
	int len =strlen(a);
	sscanf(a,"%d",&n);
	int sum =0;
	int left =0;
	int right =0;
	int pos;
	int temp;
	for(int i=0;i<len;i++)
	{
		temp = n;
		right = temp%(int)(pow(10.0,i*1.0))+1;
		temp = temp/pow(10.0,i);
		pos = temp%10;
		left = temp/10+1;
		if(pos==0)
		{
			left=left-1;
			right =(int)(pow(10.0,i*1.0)); 
		}
		else if(pos ==1)
		{
			sum+=right;
			left=left-1;
			right =(int)(pow(10.0,i*1.0));
		}
		else
		{
			right =(int)(pow(10.0,i*1.0));
		} 
		sum+=left*right;		
	}
	printf("%d\n",sum);
	return 0;
}
	
	


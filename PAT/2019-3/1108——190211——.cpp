//09:48——
//——10:20  18分，2分的运行时错误
//有效的特点搞清楚。组成是0——9，".","-" 就这三个部分
//"-"只能出现在首位，"."只能出现一次。 

//我猜运行时错误 是因为，将不是数字的字符串
//通过sscanf转变成数字时发生的 比如：  90.
//或者   -.90 

//改完还是有2分运行时错误。 
//暂时放弃，综合收益最大化。 

//这道题可参考柳诺的做法，先用sscanf将字符串转化为数字，然后再将
//数字通过sprintf转化为字符串，比较前后两个字符串是否相等。
//这个思路非常巧妙。
 
#include<stdio.h>
#include<math.h>
#include<string.h>
const int maxn = 102; 
bool isCheck(char a[])
{
	int len =strlen(a);
	bool existPoint=false;
	if((a[0]!='-')&&(a[0]<'0')&&(a[0]>'9'))
		return false;
//	int i=0;
//	if(a[i]=='-')
//		i++;
	for(int i=1;i<len;i++)
	{
		if(a[i]=='.')
		{
			if(i==1&&a[0]=='-')
				return false; 
			else if(existPoint==true)
			{
				return false;
			}
			else
			{
				//开始没有加:"len-i>0"部分。 
				if(len-i<=3&&len-i>0)
					existPoint=true;
				else
					return false;
			}	
		}
		else if((a[i]>'9')||(a[i]<'0'))
			return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	char temp[12];
	int checkNum = 0;
	double sum =0;
	double tempNum;
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		//printf("%s**\n",temp);
		if(isCheck(temp))
		{
			sscanf(temp,"%lf",&tempNum);
			if(tempNum<=1000&&tempNum>=-1000)
			{
				checkNum++;
				sum+=tempNum;
			}
			else
			{
				printf("ERROR: %s is not a legal number\n",temp);
			}
		}
		else
		{
			printf("ERROR: %s is not a legal number\n",temp);
		}
	}
	if(checkNum==0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(checkNum==1)
	{
		printf("The average of 1 number is %.2f\n",sum);
	}
	else
	{
		printf("The average of %d numbers is %.2f\n",checkNum,sum/(1.0*checkNum));
	}
	return 0;
}

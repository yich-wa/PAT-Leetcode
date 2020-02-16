//数字转化为特定字符。字符转化为特定数字。 
//注意不要犯低级错误。所以第一遍写的时候就要稳。慢就是稳，稳就是
//快。开始写的时候就要稳。 
//写完后，有4分未知错误：经过与答案对比发现答案最终输出结果的
//长度与a,b中的最长长度相等。并不是与b的长度一样。最终解决
//有些题的特性需要一试。 
#include<stdio.h>
#include<string.h>
const int maxn= 105;
int main()
{
	char a[maxn];
	char b[maxn];
	char c[3]={'J','Q','K'};
	scanf("%s %s",a,b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int even_odd=1;
	int i,j; 
	int number;
	for(i=lena-1,j =lenb-1;i>=0&&j>=0;i--,j--)
	{
		if(even_odd%2==1)
		{
			number =b[j]-'0'+a[i]-'0';
			number =number%13;
			if(number<10)
				b[j]='0'+number;
			else
				b[j]=c[number%10];		
		}
		else
		{
			number = b[j]-a[i];
			if(number<0)
				b[j]='0'+10+number;
			else
				b[j]='0'+number;
		 } 
		 even_odd++;
	}
	//若a比b长的话，长度与a一致，将b的剩余位看做零。 
	if(i>=0)
	{
		char rest[maxn];
		rest[i+1]='\0';
		while(i>=0)
		{
			if(even_odd%2==1)
			{
				rest[i]=a[i];
			}
			else
			{
				number = '0'-a[i];
				if(number<0)
					rest[i]='0'+number+10;
				else
					rest[i]='0'+number;	
			}
			i--;
			even_odd++;
		}
		printf("%s",rest);
	}
	
	printf("%s\n",b);
	return 0;
}

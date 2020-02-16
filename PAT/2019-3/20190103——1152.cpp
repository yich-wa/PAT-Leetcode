//pat1152 
//首先整体的思路应该是从左到右依次截取段，然后将其转换为数字在判断其是否为
//素数 ;有“%s",与"%c"的注意点： 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxl = 1005;
const int maxk = 10;
char text[maxl];
bool isprime(int number){
	for(int i=2;i*i<=number;i++ )
		if(number%i==0)
			return false;
	return true;			
}
int Digit(int number){
	int num =0;
	while(number!=0)
	{
		number=number/10;
		num++;
	 } 
	 return num;
}
int main()
{
	int L,K;
	scanf("%d%d",&L,&K);
//用下面的输入输出，必定会将空格和换行输入其中。所以才会出错。 
//	for(int i=0;i<L;i++)
//	{
//		scanf("%c",&text[i]); 
//	}
	scanf("%s",text);	
	char str[maxk];
	int number;
	for(int i=0;i<L-K+1;i++)
	{
		int j;
		int count =0;
		for(j=i;j<i+K;j++)
		{
			str[count++]=text[j];
		}
		str[count++]='\0';
		sscanf(str,"%d",&number);
		if(isprime(number)==true)
		{
			int digits =K-Digit(number);
			while(digits>0)
			{
				printf("0");
				digits--;
			}	
			printf("%d",number);
			return 0;
		}		
	}
	printf("404");
	return 0;
}

//14：30
//了解，reverse函数是如何使用的  
//15:10得 16分3个测试点。4分错误。
//当做完四道题，反过来完善时，通过特殊数据试出。如果一开始就是
//回文数字，结果是错误的。 改正后20分。 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1020;
bool isPalind(char a[])
{
	int len = strlen(a);
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-i-1])
			return false;	
	}
	return true;	
}
//char[] reverse(char a[])
//{
//	char b[];
//	int len = strlen(a);
//	for(int i=0;i<len;i++)
//	{
//		b[i]=a[len-1-i];
//	}
//	b[len]='\0';
//	return b;
//}
int main()
{
	char str[maxn];
	scanf("%s",str);
	int count =0;
	bool flag=false;
	if(isPalind(str))
		flag=true; 
	while(flag==false&&count<10)
	{
		char strB[maxn],strC[maxn];
		int len = strlen(str);
		for(int i=0;i<len;i++)
		{
			strB[i]=str[len-1-i];
		}
		strB[len]='\0';
		int carry =0;
		int num=0;
		for(int i=len-1;i>=0;i--)
		{
			int temp =(str[i]-'0')+(strB[i]-'0')+carry;
			carry = temp/10;
			temp = temp%10;
			strC[num++]='0'+temp;
		}
		if(carry!=0)
			strC[num++]='0'+carry;
		strC[num]='\0';
		int lenC = strlen(strC);
		for(int i=0;i<lenC/2;i++)
		{
			swap(strC[i],strC[lenC-1-i]);
		}
		printf("%s + %s = %s\n",str,strB,strC);
		strcpy(str,strC);
		count++;
		if(isPalind(str))
			flag=true;
	}
	if(flag==true)
		printf("%s is a palindromic number.\n",str);
	else
		printf("Not found in 10 iterations.\n");
	return 0;	
}

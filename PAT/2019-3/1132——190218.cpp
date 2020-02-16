//08:18——08:30
//14分 ，6分的浮点错误。用除法保证除数不为0； 改正后为20分。 
#include<stdio.h> 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string str,str1,str2;
	int n1,n2;
	int ori;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		int len = str.length();
		str1 = str.substr(0,len/2);
		str2 = str.substr(len/2,len/2);
		sscanf(str.c_str(),"%d",&ori);
		sscanf(str1.c_str(),"%d",&n1);
		sscanf(str2.c_str(),"%d",&n2);
		int n3 = n1*n2;
		if(n3==0)
		{
			printf("No\n");
			continue;
		 } 
		if(ori%n3==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;	
}

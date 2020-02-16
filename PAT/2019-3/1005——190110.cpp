//注意考虑到0的特判。 
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
	char output[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char a[105];
	scanf("%s",a);
	vector<int>v; 
	int len =strlen(a);
	int sum =0;
	for(int i=0;i<len;i++)
	{
		sum = sum+a[i]-'0';
	}
	if(sum==0)
	{
		printf("zero\n");
	}
	else
	{
		while(sum!=0)
		{
			v.push_back(sum%10);
			sum =sum/10;
		}
		for(int i=v.size()-1;i>=0;i--)
		{
			printf("%s",output[v[i]]);
			if(i>0)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;	
 } 

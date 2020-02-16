#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
const int maxn  =1005;
const int maxk = 260;
int main()
{
	char str1[maxn];
	char str2[maxn];
	int hashtable[maxk]={0};
	scanf("%s %s",str1,str2);
	int len1 =strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len1;i++)
	{
		hashtable[str1[i]]++;
	}
	bool flag=true;
	int miss =0;
	for(int i=0;i<len2;i++)
	{
		if(hashtable[str2[i]]==0)
		{
			flag=false;
			miss++;
		}
		else
		{
			hashtable[str2[i]]--;
		}
	}
	if(flag==true)
	{
		printf("Yes %d\n",len1-len2);
	}
	else
	{
		printf("No %d\n",miss);
	}
	return 0;
 } 

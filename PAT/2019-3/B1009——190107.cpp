#include<stdio.h>
#include<string.h>
const int maxn = 90;
int main()
{
	int num =0;
	char senten[maxn][maxn];
	while(scanf("%s",senten[num])!=EOF)
	{
		num++; 
	}
	for(int i=num-1;i>=0;i--)
	{
		printf("%s",senten[i]);
		if(i>0)
		printf(" ");
	}
	return 0;
 } 

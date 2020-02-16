//string.h头文件的 strlen(str);要会用。 
#include<stdio.h>
#include<string.h>
const int maxn = 85;
int main()
{
	char ch[maxn];
	scanf("%s",ch);
	int len = strlen(ch);
	int n1 = (len+2)/3;
	int n3 =n1;
	int n2 = len+2-n1-n3;
	int st =0;
	int ed = len-1;
	for(int i=1;i<n1;i++)
	{
		printf("%c",ch[st++]);
		for(int j=1;j<=n2-2;j++)
		{
			printf(" ");
		}
		printf("%c\n",ch[ed--]);
	}
	for(int i=st;i<=ed;i++)
		printf("%c",ch[i]);
	printf("\n");
	return 0;
}

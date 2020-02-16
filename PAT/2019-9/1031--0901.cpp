///简单模拟，清楚，审题、做题、答题思路都很清晰。 
#include<stdio.h>
#include<string.h>
const int maxn = 85;
int main(){
	int n1,n2,n3;
	char str[maxn];
	scanf("%s",str);
	int len = strlen(str);
	n1 = (len+2)/3;
	n3 = len+2-n1*2;
	int p1= 0;
	int p2= len-1;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[p1++]);
		for(int j=0;j<n3-2;j++)
			printf(" ");
		printf("%c\n",str[p2--]);
	}
	for(int i=p1;i<=p2;i++){
		printf("%c",str[i]);
	}
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<string.h>
//const int maxn = 85;
//int main()
//{
//	char ch[maxn];
//	scanf("%s",ch);
//	int len = strlen(ch);
//	int n1 = (len+2)/3;
//	int n3 =n1;
//	int n2 = len+2-n1-n3;
//	int st =0;
//	int ed = len-1;
//	for(int i=1;i<n1;i++)
//	{
//		printf("%c",ch[st++]);
//		for(int j=1;j<=n2-2;j++)
//		{
//			printf(" ");
//		}
//		printf("%c\n",ch[ed--]);
//	}
//	for(int i=st;i<=ed;i++)
//		printf("%c",ch[i]);
//	printf("\n");
//	return 0;
//} 

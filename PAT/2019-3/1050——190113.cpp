//与前面的有一道gets出错类似。这道题也会因为gets而编译错误。 
// 如果gets出错的话试着用c语言提交下。这个是可以对的。 
#include<stdio.h>
#include<string.h>
const int maxn = 10005;
int main()
{
	char str1[maxn];
	char str2[maxn];
	int hashtable[260]={0};
	gets(str1);
	//getchar();
	//getchar一般是用来接收整数后面的空格或者换行符 别乱用
	//这里属于你想多了 
	gets(str2);
	int len1 =strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len2;i++)
	{
		hashtable[str2[i]]=1;
	} 
	 for(int i=0;i<len1;i++)
	 {
	 	if(hashtable[str1[i]]==0)
	 	{
	 		printf("%c",str1[i]);
		 }
	 }
	 printf("\n");
	 return 0;
}

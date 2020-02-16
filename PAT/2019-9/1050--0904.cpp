//09:48——
//不能在原字符串上去擦除。 因为擦除后，原字符串长度会改变，定位会不一致。 
//采用拷出来的方法。 题目不难。构造好思路。
//拷出来是要能想到的关键。 
#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn = 10005;
int main(){
	char s1[maxn];
	char s2[maxn];
	char s3[maxn];
	cin.getline(s1,maxn);
	cin.getline(s2,maxn);
	bool flag[maxn]={false};
	for(int i=0;i<strlen(s2);i++){
		flag[s2[i]]=true;
	}
	int num =0;
	for(int i=0;i<strlen(s1);i++){
		if(flag[s1[i]]==false){
			s3[num++] = s1[i];
		}
	}
	s3[num]='\0'; 
	printf("%s",s3);
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<string.h>
//const int maxn = 10005;
//int main()
//{
//	char str1[maxn];
//	char str2[maxn];
//	int hashtable[260]={0};
//	gets(str1);
//	//getchar();
//	//getchar一般是用来接收整数后面的空格或者换行符 别乱用
//	//这里属于你想多了 
//	gets(str2);
//	int len1 =strlen(str1);
//	int len2 = strlen(str2);
//	for(int i=0;i<len2;i++)
//	{
//		hashtable[str2[i]]=1;
//	} 
//	 for(int i=0;i<len1;i++)
//	 {
//	 	if(hashtable[str1[i]]==0)
//	 	{
//	 		printf("%c",str1[i]);
//		 }
//	 }
//	 printf("\n");
//	 return 0;
//} 

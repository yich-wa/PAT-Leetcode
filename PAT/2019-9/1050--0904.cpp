//09:48����
//������ԭ�ַ�����ȥ������ ��Ϊ������ԭ�ַ������Ȼ�ı䣬��λ�᲻һ�¡� 
//���ÿ������ķ����� ��Ŀ���ѡ������˼·��
//��������Ҫ���뵽�Ĺؼ��� 
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

////��ǰд��
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
//	//getcharһ��������������������Ŀո���߻��з� ������
//	//��������������� 
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

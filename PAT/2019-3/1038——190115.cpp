//13:25����13:47

//��������ڼ����⣬
//����һ����ν������򣬶���string a,b�����ĸ�С��
//���ԱȽ�a+b ��b+a�ĸ���

//���ɶ�����stringת��Ϊchar[]����strcpy(a,b.c_str()); 

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
const int maxn = 10010;
const int maxc = 80010;
bool cmp(string a ,string b)
{
	string str1=a+b;
	string str2=b+a;
	return str1<str2;
}
int main()
{
	int n;
	string str[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	sort(str,str+n,cmp);
	string output =str[0];
	for(int i=1;i<n;i++)
	{
		output=output+str[i];
	}
	char coutput[maxc];
	strcpy(coutput,output.c_str());
	int len = strlen(coutput);
	int k =0;
	while(k<len&&coutput[k]=='0')
		k++;
	if(k==len)
	{
		printf("0\n");
	 } 
	 else
	 {
	 	for(int i=k;i<len;i++)
	 		printf("%c",coutput[i]);
	 	printf("\n");
	 }	
}
 

//��ǰ�����һ��gets�������ơ������Ҳ����Ϊgets��������� 
// ���gets����Ļ�������c�����ύ�¡�����ǿ��ԶԵġ� 
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
	//getcharһ��������������������Ŀո���߻��з� ������
	//��������������� 
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

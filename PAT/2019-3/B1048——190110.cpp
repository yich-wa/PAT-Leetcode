//����ת��Ϊ�ض��ַ����ַ�ת��Ϊ�ض����֡� 
//ע�ⲻҪ���ͼ��������Ե�һ��д��ʱ���Ҫ�ȡ��������ȣ��Ⱦ���
//�졣��ʼд��ʱ���Ҫ�ȡ� 
//д�����4��δ֪���󣺾�����𰸶Աȷ��ִ�������������
//������a,b�е��������ȡ���������b�ĳ���һ�������ս��
//��Щ���������Ҫһ�ԡ� 
#include<stdio.h>
#include<string.h>
const int maxn= 105;
int main()
{
	char a[maxn];
	char b[maxn];
	char c[3]={'J','Q','K'};
	scanf("%s %s",a,b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int even_odd=1;
	int i,j; 
	int number;
	for(i=lena-1,j =lenb-1;i>=0&&j>=0;i--,j--)
	{
		if(even_odd%2==1)
		{
			number =b[j]-'0'+a[i]-'0';
			number =number%13;
			if(number<10)
				b[j]='0'+number;
			else
				b[j]=c[number%10];		
		}
		else
		{
			number = b[j]-a[i];
			if(number<0)
				b[j]='0'+10+number;
			else
				b[j]='0'+number;
		 } 
		 even_odd++;
	}
	//��a��b���Ļ���������aһ�£���b��ʣ��λ�����㡣 
	if(i>=0)
	{
		char rest[maxn];
		rest[i+1]='\0';
		while(i>=0)
		{
			if(even_odd%2==1)
			{
				rest[i]=a[i];
			}
			else
			{
				number = '0'-a[i];
				if(number<0)
					rest[i]='0'+number+10;
				else
					rest[i]='0'+number;	
			}
			i--;
			even_odd++;
		}
		printf("%s",rest);
	}
	
	printf("%s\n",b);
	return 0;
}

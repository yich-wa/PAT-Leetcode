//10:56����
// 

//ϸ��bug
//��תʱj<len/2;������j<=len/2������ֻ��2λ��ͺ������ˡ�
// ��len = 2;
//
 
//20�֡�5�ֵķ��㷵�ء�
//��ת������reverse()������reverse(n,n+len); 

//�Ż����룬������������ӣ����ֱ�ӼĴ�������һ�����漴�ɡ� 
//�������20�֡�

//ԭ������Ϊ����main���������ˣ�return true ; ������return 0;
//�����25�֡� ������ڵͼ����� 
 
  
#include<stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
const int maxn = 120;
bool ispalind(char a[])
{
	int len = strlen(a);
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-1-i])
		{
			return false;
		}
	}
	return true;
}
void out(char a[])
{
	int len =strlen(a);
	for(int i=len-1;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return ;
 } 
int main()
{
	char n[maxn];
	char n2[maxn];
	char n3[maxn];
	int k;
	int numk=0;
	scanf("%s %d",n,&k);
	if(ispalind(n)==true)
	{
		printf("%s\n",n);
		printf("%d",numk);
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		strcpy(n2,n);
		int len = strlen(n2);
		//������j<len/2��������j<=len/2
		//���򣬼���ֻ����λ��(0,1)������(1,0)�ڽ�����������Ч��
		//�ٽ�����Ҫ�ǳ������� 
		reverse(n2,n2+len); 
//		for(int j=0;j<len/2;j++)  //��ת 
//		{
//			swap(n2[j],n2[len-1-j]);
//		}
		int carry =0;
		int result;
		int num3=0;
		for(int j=0;j<len;j++)   //��� 
		{
			result = n[j]-'0'+n2[j]-'0'+carry;
			carry = result/10;
			result=result%10;
			n[num3++]='0'+result;
		}
		if(carry!=0)
		{
			n[num3++]='0'+carry;
		}
		n[num3]='\0';
		if(ispalind(n)==true)
		{
			printf("%s\n",n);
			printf("%d",i);
			return 0;
		}
	}
	out(n);
	printf("%d",k);
	return 0;	
 } 

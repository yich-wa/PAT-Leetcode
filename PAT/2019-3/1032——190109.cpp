//ע��� "%d %c %d"�����룬����%c����ʶ��ո����Բ���
//д��"%d%c%d" xд�����1�ֶδ���
//�ο���д���ܼ�Щ
///ֱ���ڵ�һ�����ʱ���ʱ��Ϊÿ����ĸ���ñ�ǩ��
//���ǩ�վ���hashtable�ķ����� 
//�ڶ������ʱ���ʱ����������б�ǩ����ĸ����˵��Ϊ��ͬ��׺��
//��ʼ��㡣 "
#include<stdio.h>
#include<stack>
using namespace std;
const int maxn = 100005;
struct node{
	int address;
	char data;
	int next;
	bool flag;
}N[maxn]; 
int main()
{
	stack<int>s1,s2;
	int fadd1,fadd2,n;
	scanf("%d%d%d",&fadd1,&fadd2,&n);
	int tempadd,tempnext;
	char tempdata;
	for(int i=0;i<n;i++)
	{
		scanf("%d %c %d",&tempadd,&tempdata,&tempnext);
		N[tempadd].data =tempdata;
		N[tempadd].next =tempnext;
		N[tempadd].flag =false;
	}
	if(fadd1==fadd2)
	{
		printf("%05d\n",fadd1);
		return 0;
	}
	while(fadd1!=-1)
	{
		s1.push(fadd1);
		
		//��ʼ�����"="д����"=="���³������ͼ����� 
		N[fadd1]. flag=true;   
		fadd1 = N[fadd1].next;
	}
	int last=-1;
	while(fadd2!=-1)
	{
		s2.push(fadd2);
		if(N[fadd2].flag==true)
		{
			last =fadd2;
			break;
		}
		fadd2 = N[fadd2].next;
	}
	if(last!=-1)
		printf("%05d\n",last);
	else
		printf("-1\n");
	return 0;
 } 

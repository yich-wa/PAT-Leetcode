//09��00����09:17

//12�֡����˼���򵥵ķ�ʽ�����Ǵ�Ӧ������˼�������η�ת��
//���ˣ�����12�֡� 

//һ��ʼû��ע�⵽n,m֮��Ĵ�С�Ƚϣ� ˭������mһ����С��n
//��Ҫ����Լ��൱ȻĬ��
//�Ĺ������3�֡� 

//reverse �����в�Ҫ�뵱ȻĬ��left<right 
//������5�֡� 
 
#include<stdio.h>
#include<math.h>
#include<algorithm> 
using namespace std;
const int maxn=105;
int a[maxn];
void reverse(int left,int right)
{
	if(left>=right)   //��ʼȱ���д��� 
	return ; 
	int mid = (left+right)/2;
	while(left<=mid)
	{
		swap(a[left],a[right]);
		left++;
		right--;
	 }  
	 return ;
 } 
int main()
{
	int n,m;
	
	scanf("%d%d",&n,&m);
	if(m>n)    //��ʼȱ���д��� 
		m=m%n; 
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int count =0;
	reverse(0,n-1);
	reverse(0,m-1);
	reverse(m,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i<n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
 } 
 
// #include<stdio.h>
//#include<math.h>
//const int maxn=105;
//int main()
//{
//	int n,m;
//	int a[maxn];
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	scanf("%d",&a[i]);
//	int count =0;
//	int num = n-m;
//	for(int i=0;i<n;i++)
//	{
//		printf("%d",a[num]);
//		if(i<n-1)
//			printf(" ");
//		else
//			print
//			f("\n");
//		num++;
//		num = num%n;
//	}
//	return 0;
// } 

//11:27����11:50
//��ʼ���Ż�Ҫ�÷ֿ�˼�룬�³�ʱ�������������˼���в�ͨ��
//��Ϊ�����������λ���������λ�����������ظ��ġ����û�취����
//�鵽��С���֡����ǽϴ� ���֡�

//�����û��ǲ���sort��������Ȼû�г�ʱ����ֱ�ˡ� 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
//const int sq = 335;
//int block [sq]={0};
//int table[maxn]={0};
int data[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
//		table[data[i]]++;
//		block[data[i]/sq]++;
	}
	int mid = n/2;
	sort(data,data+n);
	int num =0;
	int s1=0;
	int s2=0;
	while(num<mid)
	{
		s1+=data[num++];
	 }
	while(num<n)
	{
		s2+=data[num++];
	 } 
	printf("%d %d\n",n%2,s2-s1);
	return 0;
 } 
 
//	int num =0;
//	int b_id= 0;
//	while(num+block[b_id]<mid)
//	{
//		num=num+block[b_id];
//		b_id++;
//	}
//	int numid = b_id*sq;
//	while(num+table[numid]<mid)
//	{
//		num+=table[numid];
//		numid++;
//	}

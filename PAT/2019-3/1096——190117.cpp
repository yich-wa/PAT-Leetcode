//20:50����
//����21:24  18�� 
//һ�ִ���һ�ֳ�ʱ��
// 
//ԭ��������û����ǰ����������ͨ�������������ݷ��ִ���
//����˼·�Ǵ�ͷ�����������һ�����ӣ�Ȼ�󿴿����������ٸ�
//���ϸ�����������������֪����Ҫ�жϵķ�Χ�� 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
bool isprime(int a)
{
	if(a==1)
	return false;
	int temp= (int)sqrt(1.0*a);
	for(int i=2;i<=temp;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	//����Ǳ�������������ע��㡣 
	if(isprime(n)==true) 
	{
		printf("1\n");
		printf("%d",n);
		return 0; 
	}
	int up =n;
	int down =2; 
	int max_num=0;
	int min_seq_f;
	while(down<=up)
	{
		//printf("%d\n",down);
		int temp =n;
		int td = down;
		int count=0;
		while(temp%td==0)
		{
			//printf("%d  ",td);
			//��ʼ��������ʽ��˳��д���ˡ��� 
			temp = temp/td;
			td++;
			//printf(" *%d* ",temp);
			count++;
		}
		//printf("\n");
		if(count>max_num)
		{
			max_num=count;
			min_seq_f = down;
			//�������ܹؼ��� 
			up=(int)pow(1.0*n,1.0/(count*1.0));
		}
		down++;
	}
	printf("%d\n",max_num);
	printf("%d",min_seq_f);
	min_seq_f++; 
	for(int i=1;i<max_num;i++)
	{
		printf("*%d",min_seq_f);
		min_seq_f++;
	}
	return 0;
}

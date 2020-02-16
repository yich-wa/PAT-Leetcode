//13:50����14:22  ���г�ʱ����3�֡� 

//������ֻ����seq[j]>=temp�ĵ�һ����ʱ����ʱ��Ӧ��ʹ��
//���ַ���������lower_bound(first ,last ,val); 
//ע�� lower/upper_bound��ʹ�÷����� �䷵�ص�Ϊһ��ָ�롣 
// int j=lower_bound(seq,seq+i+1,temp)-seq;

//����һ������Ҫ��˼�롣 
//���� M/pȡ������Ҳ�Ǽ򻯵�˼·������������ʹ��long long 


#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 100010;
int main()
{
	int n;
	double p;
	int seq[maxn];
	scanf("%d %lf",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+n);
	int max_num=-1;
	int m,M;
	int temp;
	for(int i=n-1;i>=0;i--)
	{
		temp =ceil((double)seq[i]/p);
		//������ʹ�ö��ַ����ҵ�
		int j=lower_bound(seq,seq+i+1,temp)-seq; 
//		for( j=0;j<n;j++)
//			if(seq[j]>=temp)
//				break; 
		int tempnum = i-j+1;
		if(tempnum>max_num)
			max_num=tempnum;
		if(j==0)
			break;			
	}
	printf("%d\n",max_num);
	return 0;	
}

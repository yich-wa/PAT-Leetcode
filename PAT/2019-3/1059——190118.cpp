//09:07����

//long long �������������%lld; 

//����09:43   21��
//ǰ����˼��˵ͼ��Ĵ��󡣴�źķ�10���ӡ� 
//�����ݼ�飬����û���չ˵����ֱ����������������
//�������������������Ϊ0,��������� 
//����Ƚ����Ƶ������1=1�� 
///����09:47   25�֡�
 
//���ܴ��Ƕ��ˣ�������2*1291�����������������������Ϊ��û���ǵ�
//����sqrt���������ӡ�
 
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int maxn = 1000000000;
vector<int>p;
vector<int>k;
bool prime[maxn]={false};
int main()
{
	LL n;
	scanf("%lld",&n);
	//fill(prime,prime+maxn,true);
	int sqn = (int)sqrt(1.0*n);
	for(int i=2;i<=sqn;i++)
	{
		//printf("%d %lld\n",i,n);
		for(int j=i*2;j<=sqn;j=j+i)
		{
			prime[j]=true;
		}
	}
	int temp;
	int temk;
	LL temn =n;
	//printf("%lld\n",n);
	for(int i= 2;i<=sqn;i++)
	{
		//��ʼ�����и��ͼ�����������i,������prime[i],����
		//prime[i]��bool�ͱ��������ڵͼ����� 
		//���Ծ�����һЩ�� д������һЩ������ס������Եġ� 
		if(prime[i]==false&&n%i==0)
		{
			temp = i;
			temk = 0;
			while(n%temp==0)
			{
				temk++;
				n=n/temp;
			}
			p.push_back(temp);
			k.push_back(temk);	
		}
		if(n==1)
		{
			break;
		}
	}
	//�п��ܻ�ʣ��һ������sqn���������� ��2*1291;
	//���û�в����Ӧ��������ģ�
	if(n!=1)
	{
		p.push_back(n);
		k.push_back(1);	
	} 
	printf("%lld=",temn);
	if(p.size()==0)
	{
		printf("%lld\n",temn);
	}
	else
	for(int i=0;i<p.size();i++)
	{
		if(k[i]==1)
		printf("%d",p[i]);
		else
		printf("%d^%d",p[i],k[i]);
		if(i<p.size()-1)
		printf("*");
		else
		printf("\n");
	}
	return 0;
}

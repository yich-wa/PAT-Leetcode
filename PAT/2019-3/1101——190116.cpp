///8:21���� 8:52 
//����8:32 16�֡� ����ͨ���򷽷���

//����8:47 �ĳɿ�������14�֣�3�����Ե㳬ʱ�� //�Լ�д�Ŀ���
//�ƺ���ϸ�ڴ��� 

//���𰸣�����
//�����ֻ���Կ�������Ϊ����������ʵ���Ƕ�̬�滮
//��¼һ������ߵ����ֵ���ұߵ���Сֵ��ֻҪ��ֵ�����м䣬
//�����Ѿ��������յ�λ������ 
//����õ�25�֡� 


#include<stdio.h> 
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
const int inf = 1000000001;
int a[maxn];
int main()
{
	int n;
	vector<int>output;
	scanf("%d",&n);
	int ori[maxn];
	int leftmax[maxn];
	int rightmin[maxn];
	leftmax[0]=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]);
		if(ori[i]>leftmax[i])
			leftmax[i+1]=ori[i];
		else
			leftmax[i+1]=leftmax[i];			
	}
	rightmin[n-1]=inf;
	for(int i=n-1;i>0;i--)
	{
		if(ori[i]<rightmin[i])
		{
			rightmin[i-1]=ori[i];
		}
		else
		{
			rightmin[i-1]=rightmin[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ori[i]>leftmax[i]&&ori[i]<rightmin[i])
		{
			output.push_back(ori[i]);
		}
	}
	printf("%d\n",output.size());
	if(output.size()==0)
	{
		printf("\n");
		return 0;	
	}
	sort(output.begin(),output.end());		
	for(int i=0;i<output.size();i++)
	{
		printf("%d",output[i]);
		if(i<output.size()-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
}

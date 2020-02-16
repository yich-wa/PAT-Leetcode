//19:14
//01�������⣬��ֵ��������ͬ�� 
//��ѡ��ģ�ֱ�ӵ����ˡ�������б�С��
//���Ƚ���Ӵ�С���� 
//��Ϊ�����ͼ�ֵ��һ���ġ����������ֵ����װ�������Լ�ֵ�����ֵ��Ҳ��
//dp[m]=m�������ڵ��߼���01��������������߼��� 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn =10010;
const int maxm =105;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	int value[maxn];
	int dp[maxm];
	//��¼ÿ������µľ�������� 
	//Ĭ���ǲ�ѡ�ġ� 
	int choice[maxn][maxn]={0};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&value[i]);
	}
	sort(value+1,value+n+1,cmp);
	for(int i=0;i<=m;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		//01�������⣬����ö�١� 
		for(int v = m;v>=value[i];v--)
		{ 
			if(dp[v]<=dp[v-value[i]]+value[i])
			{
				dp[v]=dp[v-value[i]]+value[i];
				choice[i][v]=1;
			}
		}
	}
	if(dp[m]!=m)
		printf("No Solution\n");
	else
	{
		bool flag[maxn]={false};
		int num=0;
		int k=n;
		int v=m;
		//����v�ǿ����ˣ�n���������ܼ�ֵ��
		//��Ӧ�ô�kӦ�ô�N��ʼ�����ſ��ǡ� 
		while(k>=0) //k���Ե���0�� 
		{
			if(choice[k][v]==1)
			{
				flag[k]=true;
				v=v-value[k];  //���Ҳ�ǹؼ��� 
				num++;
			}
			else
				flag[k]=false;
			k--;
		} 
		int count =0;
		for(int i=0;i<=n;i++)
		{
			if(flag[i]==true)
			{
				printf("%d",value[i]);
				if(count<num)
					printf(" ");
				else
				{
					printf("\n");
					break;	
				}
				count++;	
			}
		}	
	}
	return 0;  
} 

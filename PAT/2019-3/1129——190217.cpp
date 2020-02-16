//15:29
//���������Լ�ɢ�е�hashtable��˼�롣 
//����15:57 ��16�֣���9�����г�ʱ��

//�Լ�д�����㷨��Ȼ����ð�������˼�롣 
//�����ĸ����ĸ���ǰð�ݡ�����ס���������
//�Ƽ�ʱ�����������η��ʡ�
//�ĳ��Լ�д�������㷨��Ҳ���С�
//������9�ֳ�ʱ�� 

//����Ҳ�ǳ��õ��Ƽ�ϵͳ���ں��㷨��

//��ʵֻҪǰk������ȫ���Բ���ĩλ��̭�ƶȡ�ÿ����һ�Σ�
//��������Ʒû����ǰk�������С���ô����������͵�K�����жԱȡ�
//���Լ���ǰK�Ļ����������k������λ�á�

//Ȼ��ֻ��ǰK���������򼴿ɡ� 
//��������˼����������9�ֳ�ʱ��

//�����ǣ�ÿ��ȷ��ÿ��������Ʒ����������λ�ã���������n��ʱ�䡣 

//����·��ʵ���Ʒ�ķ��������ڵ���(ǰK��)���һ���ķ�������
//���д���ֻ���������п���Ӱ�쵽��ε���������
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 50005;
int hashtable[maxn]={0};
bool cmp(int a,int b)
{
	if(hashtable[a]!=hashtable[b])
	{
		return hashtable[a]>hashtable[b];
	}
	else
		return a<b;
 } 
int main()
{
	int n;
	int k;
	int input[maxn];
	int temp,lasttemp;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		input[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(i>0)
		{
			printf("%d:",temp);
			//����·��ʵ���Ʒ�ķ��������ڵ������һ���ķ�������
			//���Ĵ���ֻ���������п���Ӱ�쵽��ε��������� 
			if(hashtable[lasttemp]>=hashtable[input[k]]) 
			{
				int lastId;
				for(int j=1;j<=n;j++)
				{
					if(input[j]==lasttemp)
					{
						lastId = j;
						break;
					}	
				}
				if(lastId>k)
				{
					if(hashtable[input[lastId]]>hashtable[input[k]])
						swap(input[lastId],input[k]);
					else if(hashtable[input[lastId]]==hashtable[input[k]]&&input[lastId]<input[k])
						swap(input[lastId],input[k]);
				}
				sort(input+1,input+k+1,cmp);
			}
			for(int j=1;j<=i&&j<=k;j++)
			{
				printf(" %d",input[j]);
			}
			printf("\n");
		}
		hashtable[temp]++;
		lasttemp = temp;
	}
	return 0;
 } 

////�Լ�д��ð�������㷨��
//// 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 50005;
//int hashtable[maxn]={0};
//int main()
//{
//	int n;
//	int k;
//	int input[maxn];
//	int temp,lasttemp;
//	scanf("%d%d",&n,&k);
//	for(int i=1;i<=n;i++)
//	{
//		input[i]=i;
//	}
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&temp);
//		if(i>0)
//		{
//			printf("%d:",temp);
//			//sort(input+1,input+1+n,cmp);
//			int lastId;
//			for(int j=1;j<=n;j++)
//			{
//				if(input[j]==lasttemp)
//				{
//					lastId = j;
//					break;
//				}	
//			}
//			for(int j=lastId-1;j>=1;j--)
//			{
//				if(hashtable[input[j]]<hashtable[input[j+1]])
//				{
//					swap(input[j],input[j+1]);
//				}
//				else if(hashtable[input[j]]==hashtable[input[j+1]]&&input[j]>input[j+1])
//				{
//					swap(input[j],input[j+1]);
//				}
//				else
//				break;
//			}
//			for(int j=1;j<=i&&j<=k;j++)
//			{
//				printf(" %d",input[j]);
//			}
//			printf("\n");
//		}
//		hashtable[temp]++;
//		lasttemp = temp;
//	}
//	return 0;
// } 

//20:52����
// 21:36 23�ִ𰸴���
//ֱ�ӴӰ��м�ȥ�����������ġ��������ù���������⣬���Ч�ʡ�
//���д𰸸������ݲ����Ǵ���ġ��ϻ��ֲ�334ҳ
//���ж��Ƿ��ǲ�������ʱ�����ǴӺ���ǰ�ȣ�������ԭ���в�ͬ�Ľڵ㣬
//Ȼ���жϸýڵ㼰֮ǰ�Ƿ��Ѿ����� 
//����ʼ�Ͳ������ж��� 3 4 2 1 ���������ˡ��Ҳ�����ͬ�Ľڵ㡣
//����������������д���֮��25�֡�
//������������ͬʱ�����ǰ���д���2λ���������γɲ�������
//��Ϊ��ֻ����һ���֡����Աض��д���2λ������ 

//�жϲ���������ԴӺ���ǰ�ȣ�����ǰ������Ĳ��֡����ں��������
//���֣�ʹ֮��ԭ������Ƚϣ���ͬ���ǣ����롣�����Ƚ�ͳһһЩ��

//�������֪ʶ��Ҫ����������Ҫ���Լ�����ס�
//ɾ����ɾ�Ѷ������µ���  ;�������Ȳ������Ȼ�����ϵ����� 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 102;
int now[maxn];
void downadjust(int a,int len)
{
	int i;
	while(2*a<=len)
	{
		i=2*a;
		if(2*a+1<=len&&now[2*a+1]>now[i])
			i=2*a+1;
		if(now[a]<now[i])
		{
			swap(now[a],now[i]);
			a=i;
		}
		else
			break;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int ori[maxn];
	int tempori[maxn];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ori[i]);
		tempori[i]=ori[i];
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&now[i]);
	int k;
	for(k=n;k>=1;k--)
	{
		if(now[k]!=ori[k])
		break;
	}
	if(k==0)
	{
		k=1;
		while(now[k]<now[k+1])
			k++;
	 } 
	int tempk= k;
	bool isinsert=true;
	if(k<2)   //���������ǰ����һ��������ġ� 
		isinsert=false;
	else	
		for(int i=2;i<=k;i++)
		{
			if(now[i]<now[i-1])
			{
				isinsert = false;
				break;
			}
		}
	if(isinsert==true)
	{
		printf("Insertion Sort\n");
		sort(now+1,now+k+2);
		for(int i=1;i<=n;i++)
		{
			printf("%d",now[i]);
			if(i<n)
			printf(" ");
			else
			printf("\n");
		}
		return 0;
	}
	printf("Heap Sort\n");
	//������Ĵ洢�Ǵ�1��ʼ�ġ� 
	sort(tempori+1,tempori+n+1);
	for(k=n;k>=1;k--)
	{
		if(tempori[k]!=now[k])
		{
			break;
		}
	}
	swap(now[1],now[k]);
	downadjust(1,k-1);
	for(int i=1;i<=n;i++)
	{
		printf("%d",now[i]);
		if(i<n)
		printf(" ");
	} 
	return 0;	
}

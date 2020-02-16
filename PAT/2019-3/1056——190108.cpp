//���ǵ��ڲ��ֿգ�һ����һ��ֱ�ӽ�����
//�Լ��������н���ʹ�ã�
//�Լ�������ʽ�� 
#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
const int maxq =12;
struct mouse{
	int level;
	int id;
	int rank;
}M[maxn];
bool cmp1(mouse a,mouse b)
{
	return a.level>b.level;
}
bool cmp2(mouse a,mouse b)
{
	return a.id<b.id;
}
int main()
{
	queue<int>playqueue[2];
	int weight[maxn];
	int rank[maxn]={0};
	int np,ng;
	scanf("%d%d",&np,&ng); 
	for(int i=0;i<np;i++)
	{
		scanf("%d",&weight[i]);
		M[i].id =i;
		M[i].level =1;
	}
	int order;
	int num =0;
	int othernum=1;
	for(int i=0;i<np;i++)
	{
		scanf("%d",&order);
		playqueue[num].push(order);
	}
	int levelnum=2;
	while(playqueue[num].size()>1)  //ȷ��ÿֻ�����ֵ��ڼ��㡣 
	{	
		//�������һ����һ��ģ��ֿգ�ֱ�ӽ����� 
		while(playqueue[num].size()>=1)   
		{
			int maxweight=-1;
			int maxid;
			for(int i=0;i<ng&&(!playqueue[num].empty());i++)
			{
				int f = playqueue[num].front();
				playqueue[num].pop();
				if(weight[f]>maxweight)
				{
					maxweight = weight[f];
					maxid =f;
				}
			}
			playqueue[othernum].push(maxid);
			M[maxid].level=levelnum;
		}
		swap(num,othernum);   //�������н���ʹ�á� 
		levelnum++; 
	}
	sort(M,M+np,cmp1);
	int lastrank;
	int lastlevel=-1;
	for(int i=0;i<np;i++)
	{
		if(M[i].level!=lastlevel)
		{
			lastlevel = M[i].level;
			M[i].rank = i+1;
			lastrank =i+1;
		}
		else
		{
			M[i].rank=lastrank;	
		}	
	}
	sort(M,M+np,cmp2);
	for(int i=0;i<np;i++)
	{
		printf("%d",M[i].rank);
		if(i<np-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
} 

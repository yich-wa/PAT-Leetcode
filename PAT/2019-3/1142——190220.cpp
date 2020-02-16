//09:58 ����10:30 
// ���ⲻ�ѣ��ɽ�ͼ��������Ȼ��ȥ�����Ŀ����
//��Ŀ�ĺ����������������ͷǳ������ˡ� 
//���ж��ǲ���Clique�����ж��ǲ���MaxClique ע����ʱ��break 
//��continue; 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 205;
int G[maxn][maxn]={0};
bool isvisit[maxn]={false};
int main()
{
	int nv,ne;
	scanf("%d%d",&nv,&ne);
	int u,v;
	for(int i=0;i<ne;i++)
	{
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	int m,k;
	scanf("%d",&m);
	int tempClique[maxn];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&k);
		fill(isvisit,isvisit+maxn,false);
		bool isClique = true;
		bool isMax = true;
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempClique[j]);
			isvisit[tempClique[j]]=true;
		}
		for(int j=0;j<k;j++)
		{
			for(int h=0;h<k;h++)
			{
				if(j!=h&&G[tempClique[j]][tempClique[h]]==0)
				{
					isClique=false;
					break;
				}
			}
			if(isClique==false)
				break;
		}
		if(isClique==false)
		{
			printf("Not a Clique\n");
			continue;
		}	
		for(int j=1;j<=nv;j++)
		{
			bool isExist = true;
			if(isvisit[j]==false)
			{
				for(int h=0;h<k;h++)
				{
					if(G[j][tempClique[h]]==0)
					{
						isExist=false;
						break;
					}	
				}
				if(isExist==true)
				{
					printf("Not Maximal\n");
					isMax=false;
					break;
				}
			}	
		}
		if(isMax==true)
		{
			printf("Yes\n"); 
		}		
	}
	return 0;
}

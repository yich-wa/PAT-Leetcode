//15:36���� 
//����16:28   13������𰸴���
//�������·������������͸������Ӫ�ȶ��������������һ����
//��������Ҳ��һ�¡�
 
//��ʼ����д��
//���ʱ���Ϳ��Ը������������
//����ң�Ӫ�ȶ������ʱ���Ÿ������Ӫ�ȶ��顣
 
//ԭ�㵽ԭ��������������󣬵�16�֡� 

//���˴𰸷��֣����·�������ĸ��·����Լ�д�������⡣
//��� d[u]+g[u][v]<d[v] �򵽴�v�����·�����������ڵ���u�����·������
//��� d[u]+g[u][v]==d[v] ��num[v]+=num[u]; 

//�������������25��
 

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =505;
const int inf = 1000000000;
bool isvisit[maxn]={false};
int g[maxn][maxn];
int d[maxn];
int rescue[maxn];
int mrescue[maxn]={0};  //��ʾ���������ʱ�����Ծۼ������Ӫ����Ա������ 
int main()
{
	int n,m;
	int st,ed;
	int c1,c2,len;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&rescue[i]);
	}
	//��ʼ����������棬����10���ӵĺķѡ� 
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&c1,&c2,&len);
		g[c1][c2]=len;
		g[c2][c1]=len;
	}
	fill(d,d+maxn,inf);
	d[st]=0;
	//printf("%d %d %d** **\n",d[1],d[2],d[4]);
	mrescue[st]=rescue[st];
	int shortnum[maxn];
	shortnum[st]=1; 
	for(int i=0;i<n;i++)
	{
		int u =-1;
		int min =inf;
		for(int j=0;j<n;j++)
		{
			if(isvisit[j]==false&&d[j]<min)
			{
				min = d[j];
				u=j;
			}
		}
		if(u==-1)
		break;
		isvisit[u]=true;
		//printf("%d**%d\n",u,d[u]);
		for(int v=0;v<n;v++)
		{
			if(isvisit[v]==false&&g[u][v]!=inf)
			{
				if(d[u]+g[u][v]<d[v])
				{
					d[v]=d[u]+g[u][v];
					mrescue[v]=mrescue[u]+rescue[v];
					shortnum[v]=shortnum[u];
				}
				//��ʼ����д��
				//���ʱ���Ϳ��Ը������������
				//����ң�Ӫ�ȶ������ʱ���Ÿ������Ӫ�ȶ��顣	
				else if(d[u]+g[u][v]==d[v])
				{
					shortnum[v]+=shortnum[u];
					if(mrescue[u]+rescue[v]>mrescue[v]) 
					{
						mrescue[v]=mrescue[u]+rescue[v];
					}
						
				}
			}
		}
	}		
	printf("%d %d\n",shortnum[ed],mrescue[ed]);
	return 0;	
 } 

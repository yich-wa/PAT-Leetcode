//19:37

//��ʼ���Ǹ�g[maxn][maxn]��ʼ���ˡ��������10����ӡ�
//����20:30ֻ��2�֡����������ǹ��ˡ� 

//���ǲ���ɵ��������������뷿�ݾ�����Զ�ļ���վ������ǵ�һ��ߡ�
//��β��Ǳ�š�
//���������޴�ʱ���ٿ������⡣�ٿ�����Ĵ��롣 
//�������10��

//�ٶ����⣬���֣�����˵����վ����һ����¥�ľ���ġ���̾��롷������Զ��
//���һ��ߣ�Ӧ���Ǽ���վ�����о���¥��"��̾���"���
//��һ�λ�ϸ�ںܶࡣ ׼ȷ��� 

//��ϸ������һ�λ����ַ���һ��ϸ�ڣ��ڶ���߲���ƽ�����뾡���ܶ�
//Ȼ���������Ǳ����С�� 

//�����30�֡���Ҳ���湻���ԣ�3���ȱ�ߣ����㿴��һ�������������ˡ�
//ǰ������·�����ֲ������ѵ㡣�ѵ����ڽ�������������������� 
//����21:08 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int inf = 1000000000;
const int maxn = 1012;
const int maxm = 12;
int g[maxn][maxn];
bool isvisit[maxn];
int d[maxn];
bool ischeck[maxm];
double gasmindis[maxm];
double gasavedis[maxm];
int n,m,k,ds;
void Dijstra(int s)
{
	fill(isvisit,isvisit+maxn,false);
	fill(d,d+maxn,inf);
	//printf("%d  %d\n",d[1],d[2]);
	d[s]=0;
	for(int i=1;i<=n+m;i++)
	{
		int mind = inf;
		int u=-1;
		for(int j=1;j<=n+m;j++)
		{
			if(isvisit[j]==false&&d[j]<mind)
			{
				mind= d[j];
				u = j;
			}
		}
		if(u==-1)
			break;
		isvisit[u]=true;
		for(int v=1;v<=n+m;v++)
		{
			if(isvisit[v]==false&&g[u][v]!=inf&&d[u]+g[u][v]<d[v])
				d[v]=d[u]+g[u][v];
		}
	}
}
int main()
{	
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	string p1,p2,tempp;
	int d1,d2;
	int tempdis;
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<k;i++)
	{
		cin>>p1>>p2>>tempdis;
		if(p1[0]=='G')
		{
			int len =p1.length(); 
			tempp=p1.substr(1,len);
			sscanf(tempp.c_str(),"%d",&d1);
			d1+=n;
		}
		else
			sscanf(p1.c_str(),"%d",&d1);
		if(p2[0]=='G')
		{
			int len =p2.length(); 
			tempp=p2.substr(1,len);
			sscanf(tempp.c_str(),"%d",&d2);
			d2+=n;
		}
		else
			sscanf(p2.c_str(),"%d",&d2);
		g[d1][d2]=tempdis;
		g[d2][d1]=tempdis;
		//printf("%d %d\n",d1,d2);
	}
	fill(ischeck,ischeck+maxm,true);
	for(int i=n+1;i<=n+m;i++)
	{
		Dijstra(i);
		double sum =0;
		double min =inf;
		for(int j=1;j<=n;j++)
		{
			//printf("%d ",d[j]);
			sum+=d[j];
			if(d[j]<min)
				min=d[j];	
			if(d[j]>ds)
			{
				ischeck[i-n]=false;
				break;
			}
		}
		//printf("\n");
		if(ischeck[i-n]==true)
		{
			//printf("%.2f %.2f\n",sum,min);
			gasmindis[i-n]=min;
			gasavedis[i-n]=sum/(1.0*n);
		}
	}
	int mindis =-1;
	int minsta=-1; 
	int minave;
	for(int i=1;i<=m;i++)
	{
		if(ischeck[i]==true)
		{
			if(gasmindis[i]>mindis)
			{
				mindis=gasmindis[i];
				minsta=i;
				minave=gasavedis[i];
			}
			else if(gasmindis[i]==mindis&&gasavedis[i]<minave)
			{
				minsta=i;
				minave=gasavedis[i];
			}	
		}
	}
	if(minsta!=-1)
	{
		printf("G%d\n",minsta);
		printf("%.1f %.1f\n",gasmindis[minsta],gasavedis[minsta]);
	}
	else
		printf("No Solution\n");
	return 0;	
 } 

//21:19���� 21:42

//������ܼ򵥣�����������ȱ�����
//�����㷸�˵ͼ�����
//˫��Ƕ��ѭ�����õ���i��Ϊָ�룬�����������Ԥ�Ƶ�
//�õͼ�����÷�ʱ��Լ10���ӡ� 
 
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 100010;
double p,r;
vector<int>dis[maxn];
int minlevel = maxn;
int minnum;
void DFS(int a,int level)
{
	if(dis[a].size()==0)
	{
		if(level<minlevel)
		{
			minlevel = level;
			minnum=1;
			//printf("%d %d \n",a,level);
		}
		else if(level==minlevel)
		{
			//printf("%d %d \n",a,level);
			minnum++;
		}		
	}
	else
	{
		for(int i=0;i<dis[a].size();i++)
			DFS(dis[a][i],level+1);
	}
}
int main()
{
	int n;
	scanf("%d%lf%lf",&n,&p,&r);
	r=1+r/100;
	int k;
	int temp;
	//��ʼ�����˫��Ƕ��ѭ�����õ���i��Ϊָ�룬�����������Ԥ�Ƶ�
	//����
	 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temp);
			dis[i].push_back(temp);
		}
	 } 
	 DFS(0,0);
	 p=p*pow(r,minlevel*1.0);
	 printf("%.4f %d",p,minnum);
	 return 0;
}

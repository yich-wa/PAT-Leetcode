//20:08
//����20:41 
//����20:23  13�֣�12�� 5���𰸴���

//���𰸺��֣��Լ���¼����double�͵���߼۸񣬵��ۼƴ�������
//����������Ի����ȼ�¼������ 
//�ĳɼ�¼�����ȣ�����12�ֵĴ𰸴���

//�ͼ����� 
//��ʼ�����r=1+1/r;д����"r=r+1/100",�պ�����r�͵���1.00����
//���ǵͼ����� ���ԡ��������ȣ��Ⱦ��ǿ죬һ��Ҫ��ס��
//���׼ȷ�ı���Լ���˼·���߼��� 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int maxn = 100010;
double p,r;
vector<int>dis[maxn];
double hprice=-1;
int hdepth=-1;
int highnum=0;
void DFS(int a,int level)
{
	if(dis[a].size()==0)
	{
		if(level>hdepth)
		{
			hdepth=level;
			highnum =1;
		}
		else if(level==hdepth)
		{
			highnum++;
		}
	}
	else
	{
		for(int i=0;i<dis[a].size();i++)
		{
			DFS(dis[a][i],level+1);
		}
	}
}
int main()
{
	int n;
	int root;
	scanf("%d%lf%lf",&n,&p,&r);
	//��ʼ�����д����"r=r+1/100",�պ�����r�͵���1.00����
	//���ǵͼ����� 
	r=1+r/100;
	int temp;
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&temp);
		if(temp==-1)
		{
			root=i;	
		}
		else
		{
			dis[temp].push_back(i);
		}
	}
	DFS(root,0);
	hprice = p*pow(r,hdepth*1.0);
	printf("%.2f %d\n",hprice,highnum);
	return 0;
}


//09:57����11:16 25��

//��ʼ�н��й������ʱ�ĳ�ʼ���������ˣ��ڼ��������ʱ������
//�׸�����BFS���ݵ�ͳ���ˣ���������б�ǡ�

//����ͨ���������ݷ��֣��Լ�ֻ�����������ݣ���������ĸ�ĸ���ӱ��
//û�н��з���ı�ǣ��������ݳ����Ľ���25�֡�

//������������ֻ��ȷ�ϣ�Ni�ĺ��Ӻ͸�ĸ����Ҫ���з������������ܶ��
//ȷ�Ϻ��Ӻ͸�ĸ��ϵ������Ҳ�������ڽӾ���洢������G[maxn][maxn]
//�����ܻᳬʱ�� Ӧ�����ڽ������洢�� 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 10001;
struct person{
	double estate;
	double area;
	vector<int>child;
	vector<int>parent;
}P[maxn];
struct out{
	int MinId;
	int Number;
	double AveEstate;
	double AveArea;
}tempOut;
bool isvisit[maxn]={false};
bool isEstate[maxn]={false};
int minId=maxn;
int totalnumber=0;
double sumnumber=0;
double sumarea=0;
vector<out>output;
void BFS(int s)
{
	for(int i=0;i<P[s].child.size();i++)
	{
		int nowId = P[s].child[i];
		if(isvisit[nowId]==false)
		{
			if(isEstate[nowId]==true)
			{
				sumnumber+=P[nowId].estate;
				sumarea+=P[nowId].area;
			}
			totalnumber++;
			if(nowId<minId)
				minId= nowId;
			isvisit[nowId]=true;
			BFS(nowId);		
		}
	}
	for(int i=0;i<P[s].parent.size();i++)
	{
		int nowId = P[s].parent[i];
		if(isvisit[nowId]==false)
		{
			if(isEstate[nowId]==true)
			{
				sumnumber+=P[nowId].estate;
				sumarea+=P[nowId].area;
			}
			totalnumber++;
			if(nowId<minId)
				minId= nowId;
			isvisit[nowId]=true;
			BFS(nowId);	
		 } 
	}
}
bool cmp(out a,out b)
{
	if(a.AveArea!=b.AveArea)
		return a.AveArea>b.AveArea;
	else
		return a.MinId<b.MinId;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>input;
	int tempId,tempP1,tempP2,k;
	int tempChild;
	double tempEstate,tempArea;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&tempId,&tempP1,&tempP2,&k);
		if(tempP1!=-1)
		{
			P[tempId].parent.push_back(tempP1);
			P[tempP1].child.push_back(tempId);
		}
			
		if(tempP2!=-1)
		{
			P[tempId].parent.push_back(tempP2);
			P[tempP2].child.push_back(tempId); 
		}
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempChild);
			P[tempId].child.push_back(tempChild);
			P[tempChild].parent.push_back(tempId); 
		}
		scanf("%lf%lf",&P[tempId].estate,&P[tempId].area);
		input.push_back(tempId);
		isEstate[tempId]=true;
	}
	for(int i=0;i<input.size();i++)
	{
		tempId=input[i];
		if(isvisit[tempId]==false)
		{
			//��ʼ��ʱ���ʼ������Ӧ����BFS�׸���ȥ���˵ĸ�����ֵ��
			//������0֮��ĳ�ʼֵ�� 
			//���������д��� 
			totalnumber=1;
			sumnumber=P[tempId].estate;
			sumarea=P[tempId].area;
			minId = tempId;
			isvisit[tempId]=true;
			BFS(tempId);
			tempOut.MinId = minId;
			tempOut.AveArea = sumarea/(1.0*totalnumber);
			tempOut.AveEstate = sumnumber/(1.0*totalnumber);
			tempOut.Number=totalnumber;
			output.push_back(tempOut);
		}
	}
	sort(output.begin(),output.end(),cmp);
	printf("%d\n",output.size());
	for(int i=0;i<output.size();i++)
	{
		printf("%04d %d %.3f %.3f\n",output[i].MinId,output[i].Number,output[i].AveEstate,output[i].AveArea);
	}
	return 0;		
}



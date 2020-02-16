//09:57——11:16 25分

//开始有进行广度优先时的初始化出问题了，在计算各参数时，忘记
//首个进行BFS数据的统计了，详见代码中标记。

//后来通过题中数据发现，自己只根据输入数据，进行正向的父母儿子标记
//没有进行反向的标记，导致数据出错，改进后25分。

//根据输入数据只能确认，Ni的孩子和父母，你要进行反向推理，尽可能多的
//确认孩子和父母关系。或者也可以用邻接矩阵存储方法。G[maxn][maxn]
//但可能会超时。 应该用邻接向量存储。 
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
			//开始的时候初始化错误，应该是BFS首个进去的人的各项数值。
			//而不是0之类的初始值。 
			//即下面四行代码 
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



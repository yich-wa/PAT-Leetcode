//19��55 ����20:52  29�֣���һ�ִ𰸴��󡣿���һ�������������
//��һ��ʼd �ʹ���42.5 ���޸���� Ϊ 30�֡�
//һ��ʼ����bug,�ȹ�һ����룬ȷ��������ʵ��������߼�˼·��
//ǰ������ȷ�������������ǶԵġ� 
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 102;
const int inf = 1000000000;
struct coor{
	int x;
	int y;
	double dis;
}C[maxn];
bool cmp(int a,int b)
{
	return C[a].dis<C[b].dis;
}
bool isvisit[maxn]={false};
int n;
double d;
vector<int>tempPath,bestPath;
int minJump = inf;
void DFS(int id,int step)
{
	//��ʼֻд��һ�룬������б�ʽ����ʼ��Ȼֻд��һ�룬
	//���Ѱ��Сʱ���ҳ����⡣ 
	if(50-abs(C[id].x)<=d||50-abs(C[id].y)<=d)
	{
		if(step<minJump)
		{
			minJump = step;
			bestPath = tempPath;
			//printf("%d hucle \n",minJump); 
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(isvisit[i]==false)
		{
			double tempdis = sqrt(pow(C[id].x-C[i].x,2.0)+pow(C[id].y-C[i].y,2.0));
			if(tempdis<=d)
			{
				tempPath.push_back(i);
				isvisit[i]=true;
				//printf("%d____****8 %d\n",C[i].x,C[i].y);
				DFS(i,step+1);
				isvisit[i]=false;
				tempPath.pop_back();
			}
		}
	}
}
int main()
{
	
	scanf("%d%lf",&n,&d);
	vector<int>first;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&C[i].x,&C[i].y);
		C[i].dis = sqrt(1.0*(C[i].x*C[i].x+C[i].y*C[i].y))-7.5;
		if(C[i].dis<=1.0*d)
		{
			first.push_back(i);
			isvisit[i]=true;
		}		
	}
	if(d>=42.5)
	{
		printf("1\n");
		return 0;
	} 
	sort(first.begin(),first.end(),cmp);
	int len = first.size();
	for(int i=0;i<len;i++)
	{
		tempPath.push_back(first[i]);
		DFS(first[i],1);
		tempPath.pop_back();
	}
	len = bestPath.size();
//	double a = pow(4.0,2.0);
//	printf("%f***\n",a);
	if(minJump==inf)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n",minJump+1);
		for(int i=0;i<len;i++)
		{
			int temp = bestPath[i];
			printf("%d %d\n",C[temp].x,C[temp].y);
		}
	}
	return 0;	
}

//19：55 ——20:52  29分，有一分答案错误。可以一步跳到的情况。
//即一开始d 就大于42.5 ；修改完后 为 30分。
//一开始出现bug,先过一遍代码，确保代码是实现了你的逻辑思路。
//前提是你确认你的题意理解是对的。 
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
	//开始只写了一半，下面的判别式。开始居然只写了一半，
	//花费半个小时才找出问题。 
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

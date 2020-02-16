//15:27——
//15:50   的15分  10分的段错误。
// 开始以为是maxn给开大了，其实是开小了。两个系数范围在0到1000
//相加就是0到2000；改完多了5分，， 还有5分答案错误。
// 
//经过检查发现，自己忘记给结果系数排序了。 输出，应该是系数大的项
//先输出。 
//改完后5分。 
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm> 
using namespace std;
//下面数值开错5分段错误 
const int maxn = 2005;
int main()
{
	int n1,n2;
	vector<int>ex1,ex2;
	vector<double>co1,co2;
	scanf("%d",&n1);
	int tempex;
	double tempco;
	for(int i=0;i<n1;i++)
	{
		scanf("%d%lf",&tempex,&tempco);
		ex1.push_back(tempex);
		co1.push_back(tempco);
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d%lf",&tempex,&tempco);
		ex2.push_back(tempex);
		co2.push_back(tempco);
	}
	vector<int>exout,exout2;
	double co[maxn]={0};
	bool flag[maxn]={false}; 
	for(int i=0;i<ex1.size();i++)
	{
		for(int j=0;j<ex2.size();j++)
		{
			tempex = ex1[i]+ex2[j];
			tempco = co1[i]*co2[j];
			co[tempex]+=tempco;
			exout.push_back(tempex);
		}	
	}
 	for(int i=0;i<exout.size();i++)
 	{
 		tempex= exout[i];
 		if(co[tempex]!=0&&flag[tempex]==false)
 		{
 			exout2.push_back(tempex);
 			flag[tempex]=true;
		 }
	 }
	 printf("%d",exout2.size());
	 //发现自己忘记给系数排序了。 
	 sort(exout2.begin(),exout2.end()); 
	 for(int i=exout2.size()-1;i>=0;i--)
	 {
	 	printf(" %d %.1f",exout2[i],co[exout2[i]]);
	 }
	 return 0;
}

 

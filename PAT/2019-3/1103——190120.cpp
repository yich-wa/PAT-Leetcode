//21:50——
//——22:27  
//30分。深度优先，注意临时向量和最佳向量的替换
//题不难。但是注意添加元素，是从大到小，还是从小到大。
//还有就是for循环中，i到底是++，还是-- 
//思路要非常清晰。 
//这道题，考察DFS+剪枝。 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int>temp;
vector<int>best;
int maxfac=-1;
int n,k,p;
int cmp(vector<int>a,vector<int>b)
{
	for(int i=0;i<a.size()&&i<b.size();i++)
	{
		if(a[i]>b[i])
			return 1;
		else if(a[i]<b[i])
			return -1;
	}
}
void DFS(int a ,int sumvalue,int sumfac,int numk)
{
	if(sumvalue>n)
		return;
	if(numk==k)
	{
		if(sumvalue==n)
		{
			if(sumfac>maxfac)
			{
				maxfac = sumfac;
				best =temp;
			}
			else if(sumfac==maxfac)
			{
				if(cmp(temp,best)>0)
				{
					best=temp;
				}
			}
		}
		return ;
	}	
	for(int i =a;i>=1;i--)
	{
		int ivalue =(int)pow(i*1.0,p*1.0); 
		temp.push_back(i);
		DFS(i,sumvalue+ivalue,sumfac+i,numk+1);
		temp.pop_back();
	}
	return ;	
}
int main()
{
	
	scanf("%d%d%d",&n,&k,&p);
	int tmax =(int)pow(1.0*n,1.0/(p*1.0));
	//printf("%d\n",tmax);
	for(int i=tmax;i>=1;i--)
	{
		int ivalue = (int)pow(i,p*1.0);
		temp.push_back(i);
		DFS(i,ivalue,i,1);
		temp.pop_back();
	} 
	if(best.size()==0)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d = %d^%d",n,best[0],p);
		for(int i=1;i<best.size();i++)
		{
			printf(" + %d^%d",best[i],p);
		}
		printf("\n");
	}
	return 0;
 } 

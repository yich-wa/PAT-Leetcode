//20:00——
//——20:30时19分，6分超时。
//经过优化两个for循环的内部for循环提前结束得21分。4分超时。
// 

//经过优化，将两个for循环编程while循环，并对不同情况分类
//改变i,j  在度优化——拿到25分。
//——20:49 
 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
int main()
{
	int n,m;
	int d[maxn];
	int dp[maxn]={0}; 
	vector<int>vi,vj;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		dp[i]=dp[i-1]+d[i];
	}
	int temp;
	int mincost = maxn;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			temp =dp[j]-dp[i-1]-m;
//			//printf("%d %d %d\n",i,j,temp);
//			if(temp>=0)
//			{
//				if(temp>mincost)
//					break; 
//				else if(temp<mincost)
//				{
//					mincost =temp; 
//					vi.clear();
//					vj.clear();
//					vi.push_back(i);
//					vj.push_back(j);
//				}
//				else if(temp==mincost)
//				{
//					vi.push_back(i);
//					vj.push_back(j);
//				}
//			}	
//		}
//		i++;
//	}
	int i=1;int j=1;
	while(i<=n&&j<=n)
	{
		temp =dp[j]-dp[i-1]-m;
		//printf("%d %d %d\n",i,j,temp);
		if(temp>=0)
		{
			if(temp>mincost)
				i++;
			else if(temp<mincost)
			{
				mincost =temp; 
				vi.clear();
				vj.clear();
				vi.push_back(i);
				vj.push_back(j);
				if(temp==0)
				{
					i++;
					j++;
				}
				else
				{
					i++;
				}	
			}
			else 
			{	
				vi.push_back(i);
				vj.push_back(j);
				if(temp==0)
				{
					i++;
					j++;
				}
				else
				{
					i++;
				}
			}
		}
		else
			j++;
	}
	int len =vi.size();
	for(int i=0;i<len;i++)
	{
		printf("%d-%d\n",vi[i],vj[i]);
	}
	return 0;
}

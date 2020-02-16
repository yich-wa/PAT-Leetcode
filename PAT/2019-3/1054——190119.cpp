//20:10——

//——20:21  18分  可能是因为数据都没输入完，你就得出结果了
//得出结果没问题，但是不应该return 0; 
//修改完后还是18分，2分的答案错误。
//用map去建立int到int的映射非常关键。非常省空间。 

//最后自己试了下 只有一个元素的情况。发现出现错误。
//give thanks to god; 
//——20:31 改完后 20分。  
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int n,m;
	map<int,int>mp;
	scanf("%d%d",&n,&m);
	int mid = n*m/2;
	int color;
	int s_color=-1;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&color);
			if(s_color>=0)
				continue;
			if(mp.find(color)==mp.end())
			{
				mp[color]=1;
				if(mp[color]>mid)
				{
					s_color = color;
				}
			}
			else
			{
				mp[color]++;
				if(mp[color]>mid)
				{
					s_color = color;
				}
			}
		}
	printf("%d\n",s_color);
	return 0;		
 } 

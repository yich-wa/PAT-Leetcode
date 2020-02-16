//15:29
//考察排序、以及散列的hashtable的思想。 
//——15:57 得16分，有9分运行超时。

//自己写排序算法。然后用冒泡排序的思想。 
//访问哪个将哪个往前冒泡。但记住访问这个。
//推荐时，不包括本次访问。
//改成自己写的排序算法，也不行。
//还是有9分超时。 

//此题也是常用的推荐系统的内核算法。

//其实只要前k名，完全可以采用末位淘汰制度。每访问一次，
//如果这个物品没有在前k的排名中。那么将其访问量和第K名进行对比。
//可以挤进前K的话，将其与第k名调换位置。

//然后只对前K名进行排序即可。 
//按照这种思想改造后还是有9分超时。

//估计是：每次确定每个访问物品所处的排名位置，还花费了n的时间。 

//如果新访问的物品的访问量大于等于(前K名)最后一名的访问量才
//进行处理，只有这样才有可能影响到这次的输出结果。
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 50005;
int hashtable[maxn]={0};
bool cmp(int a,int b)
{
	if(hashtable[a]!=hashtable[b])
	{
		return hashtable[a]>hashtable[b];
	}
	else
		return a<b;
 } 
int main()
{
	int n;
	int k;
	int input[maxn];
	int temp,lasttemp;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		input[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(i>0)
		{
			printf("%d:",temp);
			//如果新访问的物品的访问量大于等于最后一名的访问量才
			//尽心处理，只有这样才有可能影响到这次的输出结果。 
			if(hashtable[lasttemp]>=hashtable[input[k]]) 
			{
				int lastId;
				for(int j=1;j<=n;j++)
				{
					if(input[j]==lasttemp)
					{
						lastId = j;
						break;
					}	
				}
				if(lastId>k)
				{
					if(hashtable[input[lastId]]>hashtable[input[k]])
						swap(input[lastId],input[k]);
					else if(hashtable[input[lastId]]==hashtable[input[k]]&&input[lastId]<input[k])
						swap(input[lastId],input[k]);
				}
				sort(input+1,input+k+1,cmp);
			}
			for(int j=1;j<=i&&j<=k;j++)
			{
				printf(" %d",input[j]);
			}
			printf("\n");
		}
		hashtable[temp]++;
		lasttemp = temp;
	}
	return 0;
 } 

////自己写的冒泡排序算法。
//// 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 50005;
//int hashtable[maxn]={0};
//int main()
//{
//	int n;
//	int k;
//	int input[maxn];
//	int temp,lasttemp;
//	scanf("%d%d",&n,&k);
//	for(int i=1;i<=n;i++)
//	{
//		input[i]=i;
//	}
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&temp);
//		if(i>0)
//		{
//			printf("%d:",temp);
//			//sort(input+1,input+1+n,cmp);
//			int lastId;
//			for(int j=1;j<=n;j++)
//			{
//				if(input[j]==lasttemp)
//				{
//					lastId = j;
//					break;
//				}	
//			}
//			for(int j=lastId-1;j>=1;j--)
//			{
//				if(hashtable[input[j]]<hashtable[input[j+1]])
//				{
//					swap(input[j],input[j+1]);
//				}
//				else if(hashtable[input[j]]==hashtable[input[j+1]]&&input[j]>input[j+1])
//				{
//					swap(input[j],input[j+1]);
//				}
//				else
//				break;
//			}
//			for(int j=1;j<=i&&j<=k;j++)
//			{
//				printf(" %d",input[j]);
//			}
//			printf("\n");
//		}
//		hashtable[temp]++;
//		lasttemp = temp;
//	}
//	return 0;
// } 

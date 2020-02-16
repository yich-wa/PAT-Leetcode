//15：07
//——15:41 25分。注意如何判断该序列是不是插入排序的中间序列。
//注意自己merge sort时，对片段进行sort时，不要让右端点超过n; 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 105;
int parts[maxn];
int n;
void out()
{
	for(int i=0;i<n;i++)
	{
		printf("%d",parts[i]);
		if(i<n-1)
		printf(" ");
		else
		printf("\n"); 
	}
}
int main()
{
	
	scanf("%d",&n);
	int ori[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&parts[i]);
	}
	int k=0;
	while(parts[k+1]>=parts[k])
	{
		k++;
	}
	bool isinsert=true;
	for(int i=k+1;i<n;i++)
	{
		if(ori[i]!=parts[i])
		{
			isinsert=false;
			break;
		}
	}
	if(isinsert==true)
	{
		sort(parts,parts+k+2);
		printf("Insertion Sort\n");
		out();
		return 0;
	}
	else
	{
		printf("Merge Sort\n");
		int i;
		for(i=2;i<n;i=i*2)
		{
			for(int j=0;j<n;j=j+i)
			{
				if(j+i<=n)
				sort(ori+j,ori+j+i);
				else
				sort(ori+j,ori+n);
			}
			bool flag= true;
			for(int h =0;h<n;h++)
			{
				if(ori[h]!=parts[h])
				{
					flag=false;
					break;
				}
			}
			if(flag ==true)
			{
				i=i*2;
				for(int j=0;j<n;j=j+i)
				{
					if(j+i<=n)
					sort(parts+j,parts+j+i);
					else
					sort(parts+j,parts+n);
				}	
				out();	
				return 0;
			}
		}
	}
 } 

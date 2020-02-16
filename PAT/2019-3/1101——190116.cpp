///8:21—— 8:52 
//——8:32 16分。 用普通排序方法。

//——8:47 改成快速排序14分，3个测试点超时。 //自己写的快排
//似乎有细节错误。 

//看答案！！！
//这道题只是以快速排序为背景，但是实质是动态规划
//记录一个数左边的最大值，右边的最小值，只要该值在其中间，
//则其已经在其最终的位置上了 
//最后拿到25分。 


#include<stdio.h> 
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
const int inf = 1000000001;
int a[maxn];
int main()
{
	int n;
	vector<int>output;
	scanf("%d",&n);
	int ori[maxn];
	int leftmax[maxn];
	int rightmin[maxn];
	leftmax[0]=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]);
		if(ori[i]>leftmax[i])
			leftmax[i+1]=ori[i];
		else
			leftmax[i+1]=leftmax[i];			
	}
	rightmin[n-1]=inf;
	for(int i=n-1;i>0;i--)
	{
		if(ori[i]<rightmin[i])
		{
			rightmin[i-1]=ori[i];
		}
		else
		{
			rightmin[i-1]=rightmin[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ori[i]>leftmax[i]&&ori[i]<rightmin[i])
		{
			output.push_back(ori[i]);
		}
	}
	printf("%d\n",output.size());
	if(output.size()==0)
	{
		printf("\n");
		return 0;	
	}
	sort(output.begin(),output.end());		
	for(int i=0;i<output.size();i++)
	{
		printf("%d",output[i]);
		if(i<output.size()-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
}

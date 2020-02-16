//10:03  ——10:25 
// 30分。注意堆是从1开始存储的。这样方便定位左子树和右子树。 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int>postorder;
int m,n;
int level[maxn];
void postTranverse(int a)
{
	if(a>n)
		return;
	postTranverse(2*a);
	postTranverse(2*a+1);
	postorder.push_back(level[a]);
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		postorder.clear();
		for(int j=1;j<=n;j++)
			scanf("%d",&level[j]);
		postTranverse(1);
		bool ismax =true;
		bool ismin = true;
		for(int j=1;j<=n/2;j++)
		{
			if(2*j<=n&&level[j]<level[2*j])
			{
				ismax =false;
				break;
			}
			if(2*j+1<=n&&level[j]<level[2*j+1])
			{
				ismax =false;
				break;
			}
		}
		if(ismax==true)
			printf("Max Heap\n");
		else
		{
			for(int j=1;j<=n/2;j++)
			{
				if(2*j<=n&&level[j]>level[2*j])
				{
					ismin =false;
					break;
				}
				if(2*j+1<=n&&level[j]>level[2*j+1])
				{
					ismin =false;
					break;
				}
			}
			if(ismin==true)
				printf("Min Heap\n");
			else
				printf("Not Heap\n");
		}
		for(int j=0;j<postorder.size();j++)
		{
			printf("%d",postorder[j]);
			if(j<postorder.size()-1)
				printf(" ");
			else
				printf("\n");
		 } 
	}
	return 0;
 } 

//09:27 ¡ª¡ª09:49  30·Ö¡£ 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int>path,tempPath;
int n;
int level[maxn];
bool isMax = true;
bool isMin = true;
void DFS(int a)
{
	if(2*a>n)
	{
		int len = tempPath.size();
		for(int i = 0;i<len;i++)
		{
			printf("%d",tempPath[i]);
			if(i<len-1)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	if(2*a+1<=n)
	{
		if(isMax == true&&level[a]<level[2*a+1])
			isMax = false;
		if(isMin == true&&level[a]>level[2*a+1])
			isMin = false;
		tempPath.push_back(level[2*a+1]);
		DFS(2*a+1);
		tempPath.pop_back();
	}
	if(2*a<=n)
	{
		if(isMax == true&&level[a]<level[2*a])
			isMax = false;
		if(isMin == true&&level[a]>level[2*a])
			isMin = false;
		tempPath.push_back(level[2*a]);
		DFS(2*a);
		tempPath.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&level[i]);	
	}
	tempPath.push_back(level[1]);
	DFS(1);
	if(isMax==true)
		printf("Max Heap\n");
	else if(isMin == true)
		printf("Min Heap\n");
	else
		printf("Not Heap\n");
	return 0;	
}

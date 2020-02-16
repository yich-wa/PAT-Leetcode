//pat  1155�ⲻ�ѡ�����һ��Ҫ�ȣ��������Ϊʲô�� 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =1005;
const int maxv =505;
int count1 = 0;
vector<int>V[maxv];
vector<int>temp;
bool ismaxheap = true;
bool isminheap = true;
int n;
int bitree[maxn];
void DFS(int a)
{
	if(a>n)
	{
		V[count1++]=temp;
		return; 
	}
	else
	{
		temp.push_back(a);
		if(ismaxheap||isminheap)
		{
			if(2*a+1<=n)
				if(bitree[a]<bitree[2*a+1])
					ismaxheap=false;
				else if(bitree[a]>bitree[2*a+1])
					isminheap=false;
			if(2*a<=n)
				if(bitree[a]<bitree[2*a])
					ismaxheap=false;
				else if(bitree[a]>bitree[2*a])
					isminheap=false;
		}
		if(2*a+1>n)   //ֻҪ��������������ô��ֻ��һ��·�� 
			DFS(2*a);
		else 
		{ 
			DFS(2*a+1);
			DFS(2*a);
		}
		temp.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&bitree[i]);
	}
	DFS(1);
	for(int i=0;i<count1;i++)
	{
		printf("%d",bitree[V[i][0]]);
		for(int j=1;j<V[i].size();j++)
		{
			printf(" %d",bitree[V[i][j]]);
		}
		printf("\n");	
	}
	if(isminheap)
		printf("Min Heap\n");
	else if(ismaxheap)
		printf("Max Heap\n");
	else
		printf("Not Heap\n");
	return 0;	 
}

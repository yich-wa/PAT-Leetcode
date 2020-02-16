//11:04——11:31 并查集思路，
//初始化、找爸爸路径压缩、联合起来。
//三个套路要很清晰。 

#include<stdio.h>
#include<set>
using namespace std;
const int maxn = 10005;
int father[maxn];
void init()
{
	for(int i=1;i<maxn;i++)
		father[i]=i;
}
int findfather(int a)
{
	int x= a;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[a]!=x)
	{
		int b = father[a];
		father[a]=x;
		a=b;
	}
	return x;	
}
void join(int a,int b)
{
	int fa = findfather(a);
	int fb = findfather(b);
	if(fa!=fb)
		father[fa]=fb;
}
int main()
{
	int n;
	scanf("%d",&n);
	int k;
	init();//初始化，不能忘记。 
	int maxNum = 0;
	int tempindex;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		int last=-1;
		for(int i=0;i<k;i++)
		{
			scanf("%d",&tempindex);
			maxNum = max(tempindex,maxNum);
			if(last==-1)
			{
				last = tempindex;
			}
			else
			{
				join(last,tempindex);
			}
		}
	}
	bool isfather[maxn]={false};
	int numfather=0;
	for(int i=1;i<=maxNum;i++)
	{
		int tempfather=findfather(i);
		if(isfather[tempfather]==false)
		{
			numfather++;
			isfather[tempfather]=true;
		}	
	}
	printf("%d %d\n",numfather,maxNum);
	int q,s1,s2;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&s1,&s2);
		int f1 = findfather(s1);
		int f2 = findfather(s2);
		if(f1==f2)
		printf("Yes\n");
		else
		printf("No\n"); 
	}
	return 0;
}

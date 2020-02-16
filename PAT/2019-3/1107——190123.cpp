//19:39
//—— 
//20:30   30分

//有两个注意点：
//是以爱好为单位，聚集人群，所以可以，将一个爱好的人集合到一个向量中
//set<int>s;  插入 s.insert();遍历元素值是*it。 *在前面。
//找爸爸与路径压缩要很熟悉。 
 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn =1005;
int father[maxn];
vector<int>hobby[maxn];
set<int>s;
int findfather(int a)
{
	int x =a;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[a]!=x)
	{
		int n = father[a];
		father[a]=x;
		a=n;
	}
	return x;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		father[i]=i;
	int k;
	int temphobby;	
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		int lastfather = father[i];
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temphobby);
			hobby[temphobby].push_back(i);
			s.insert(temphobby);
		}
	}
	for(set<int>::iterator it = s.begin();it!=s.end();it++)
	{
		//开始写成it*，细节记忆要清晰。 
		int temp =*it;
		int last = hobby[temp][0];
		for(int i=1;i<hobby[temp].size();i++)
		{
			int fa= findfather(hobby[temp][i]);
			int fb = findfather(last);
			if(fa!=fb)
			{
				father[fa]=fb;
			}
			last = hobby[temp][i];
		}
	}
	int cluster[maxn]={0};
	int cnum=0;
	for(int i=1;i<=n;i++)
	{
		int temp = findfather(i);
		if(cluster[temp]==0)
		{
			cluster[temp]=1;
			cnum++;
		}
		else
			cluster[temp]++;
	}
	printf("%d\n",cnum);
	sort(cluster,cluster+maxn,cmp);
	for(int i=0;i<cnum;i++)
	{
		printf("%d",cluster[i]);
		if(i<cnum-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
}

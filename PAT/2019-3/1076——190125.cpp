//14：19
//期间犯了些低级错误。不过靠printf找出来了。
//数组下标错误。
//又犯了两个嵌套for循环中用的指针一样的错误。
//25分，还有5分答案错误。 

//经过看答案，发现可能是自己层序遍历，截断过早的缘故。 
//仔细想想似乎是队列没有清空的缘故！因为你是提前break了。 
//一次层序，用一个队列，不要公用一个队列
//尤其是存在中途break;的情况。 改完30分。哈哈 
//——15：13 
#include<stdio.h> 
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1005; 
vector<int>follow[maxn];
int l;
int isvisit[maxn]={false};
int level[maxn];
int BFS(int r)
{
	queue<int>q;
	int sum =0;
	q.push(r);
	isvisit[r]=true;
	level[r]=0;
	while(!q.empty())
	{
		int temp =q.front();
		q.pop();
	//	printf("%d**\n",temp);
		int templevel= level[temp]+1;
		if(templevel>l)
			break;
		for(int i=0;i<follow[temp].size();i++)
		{
			int tempId= follow[temp][i];
			//printf("%d****\n",tempId);
			if(isvisit[tempId]==false)
			{
				sum++;
				isvisit[tempId]=true;
				level[tempId]=templevel;
				q.push(tempId);
			}
		}
		
	 } 
	return sum;
}
int main()
{
	int n;
	scanf("%d%d",&n,&l);
	//又犯了两个嵌套for循环中用的指针一样的错误。 
	for(int i=1;i<=n;i++)
	{
		int m;
		int user;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&user);
			follow[user].push_back(i);
		}	
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int queryId;
		fill(isvisit,isvisit+maxn,false);
		scanf("%d",&queryId);
		isvisit[queryId]=true;
		int tempsum = BFS(queryId);
		printf("%d\n",tempsum);
	}
	return 0;
}

//15:02  
//——15:26 完全二叉树，用起始为编号1 的数组表示，层序即是顺序递增。
// 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1005;
int n;
int cbst[maxn];
int inorder[maxn];
int innum=0;
void inorder_tra(int a)
{
	if(a>n)
		return ;
	inorder_tra(a*2);
	inorder[innum++]=a;
	inorder_tra(2*a+1);
}
int main()
{	
	scanf("%d",&n);
	int ori[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]); 
	}
	sort(ori,ori+n);
	inorder_tra(1);
	for(int i=0;i<n;i++)
	{
		int seq = inorder[i];
		cbst[seq]=ori[i];		
	}
//	queue<int>q;
//	int level[maxn];
//	int levelnum=0;
//	q.push(1);
//	while(!q.empty())
//	{
//		int temp = q.front();
//		q.pop();
//		level[num++]=temp;
//		if(2*temp<=n)
//			q.push(2*temp);
//		if(2*temp+1<=n)
//			q.push(2*temp+1);
//	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",cbst[i]);
		if(i<n)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	 
}

//15:29
//——15:33
//二叉树的静态表示方法。 
//——15:50 
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 105;
int n;
struct node{
	int left;
	int right;
	int key;
}N[maxn];
int inorder[maxn];
int innum=0;
void inorder_tra(int a)
{
	if(a>=n)
		return ;
	if(N[a].left!=-1)
		inorder_tra(N[a].left);
	inorder[innum++]=a;
	if(N[a].right!=-1)
		inorder_tra(N[a].right);	
}
int main()
{	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&N[i].left,&N[i].right);
	}
	int ori[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]); 
	}
	sort(ori,ori+n);
	inorder_tra(0);
	for(int i=0;i<n;i++)
	{
		int temp =inorder[i];
		N[temp].key = ori[i];
	}
	queue<int>q;
	q.push(0);
	int level[maxn];
	int levelnum=0;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		level[levelnum++]=temp;
		if(N[temp].left!=-1)
			q.push(N[temp].left);
		if(N[temp].right!=-1)
			q.push(N[temp].right);	
	}
	for(int i=0;i<n;i++)
	{
		int temp = level[i];
		printf("%d",N[temp].key);
		if(i<n-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
 } 
 

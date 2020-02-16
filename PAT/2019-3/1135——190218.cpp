//16:10 ——16:54
// 30分。。其实红黑树你没深入了解过。但是光看题意，是完全可以写出来的
//  建树，翻译题意，可以搞定 
//利用该全局变量，来判断每个路径上的黑节点数一样。 
#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
const int maxn = 32;
struct node{
	node* lchild;
	node* rchild;
	int data;
	int tag;
};
node* newnode(int a)
{
	node* r= new node;
	r->lchild = r->rchild = NULL;
	r->data = abs(a);
	if(a<0)
		r->tag = 1;
	else
		r->tag = 0;
	return r; 
}
int preOrder[maxn];
node* build(int preLeft,int preRight)
{
	if(preLeft>preRight)
		return NULL;
	node* a =newnode(preOrder[preLeft]);
	int k=preLeft+1;
	for(;k<=preRight;k++)
	{
		if(abs(preOrder[k])>=abs(preOrder[preLeft]))
			break;
	}
	a->lchild = build(preLeft+1,k-1);
	a->rchild = build(k,preRight);
	return a;
}
bool isB = true;
int blackNum ;
void DFS(node* root,int tempNum)
{
	if(root==NULL)
	{
		if(blackNum==-1)
		{
			blackNum=tempNum;
		}
		else if(blackNum!=tempNum)
		{
			isB=false;
			return;
		}
		return ;
	}
	if(isB==false)
		return;
	if(root->tag==0)
	{
		DFS(root->lchild,tempNum+1);
		DFS(root->rchild,tempNum+1);
	}
	else
	{
		DFS(root->lchild,tempNum);
		DFS(root->rchild,tempNum);
	}	
}
bool isBlackOrRed(node* root)
{
	if(root->tag==1)
		return false;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if(temp->tag==1)
		{
			if(temp->lchild!=NULL&&temp->lchild->tag==1)
				return false;
			if(temp->rchild!=NULL&&temp->rchild->tag==1)
				return false;
		}
		blackNum = -1;
		isB = true;
		DFS(temp,0);
		if(isB==false)
			return false;
		if(temp->lchild!=NULL)
			q.push(temp->lchild);
		if(temp->rchild!=NULL)
			q.push(temp->rchild);
	}
	return true;	
}
int main()
{
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&preOrder[j]);
		}
		node* root=NULL;
		root = build(0,n-1);
		if(isBlackOrRed(root))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

//11:27——11:47
//开始将scanf写成了printf,出错。 
//改完后30分。 
//用BFS+level数组去记录比较简单。记住根节点开始的时候是：
//node* root = NULL;
//以及插入节点的函数要很清晰。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int level[maxn]={0};
struct node{
	node* lchild;
	node* rchild;
	int data;
};
node* newnode(int a)
{
	node* temp = new node;
	temp->data = a;
	temp->lchild =NULL;
	temp->rchild = NULL;
	return temp;
}
void insert(node* &root,int a)
{
	if(root==NULL)
	{
		root=newnode(a);
	}
	else
	{
		if(a<=root->data)
			insert(root->lchild,a);
		else
			insert(root->rchild,a);	
	}
}
int maxlevel= 0;
void BFS(node* r,int lev)
{
	if(lev>maxlevel)
	{
		maxlevel=lev;
	}
	if(r->lchild!=NULL)
	{
		level[lev+1]++;
		BFS(r->lchild,lev+1);
	}
	if(r->rchild!=NULL)
	{
		level[lev+1]++;
		BFS(r->rchild,lev+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node* r =NULL;
	int temp;
	for(int i=0;i<n;i++)
	{
		//开始居然把下面的scanf写成printf了。 
		scanf("%d",&temp);
		insert(r,temp);
	}
	level[0]++;
	BFS(r,0);
	int sum = level[maxlevel]+level[maxlevel-1];
	printf("%d + %d = %d\n",level[maxlevel],level[maxlevel-1],sum);
	return 0;
}

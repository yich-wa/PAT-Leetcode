//08:56——09:17 25分。
//再次回忆下，后序遍历非递归的算法。 
#include<stdio.h>
using namespace std;
const int maxn = 50005;
int preOrder[maxn];
int inOrder[maxn];
struct node{
	node* lchild;
	node* rchild;
	int key;
};
node* newnode(int k)
{
	node* a = new node;
	a->key = k;
	a->lchild = a->rchild = NULL;
	return a;
}
node* build(int preL,int preR,int inL,int inR)
{
	if(preL>preR)
		return NULL;
	node* r = newnode(preOrder[preL]);
	int k;
	for(k = inL;k<=inR;k++)
	{
		if(inOrder[k]==preOrder[preL])
			break;
	}
	int len =k-1-inL;
	r->lchild = build(preL+1,preL+1+len,inL,k-1);
	r->rchild = build(preL+len+2,preR,k+1,inR);
	return r;
}
int firPost;
bool flag= false;
void postTrans(node* root)
{
	if(root==NULL)
		return;
	postTrans(root->lchild);
	postTrans(root->rchild);
	if(flag==false)
	{
		firPost = root->key;
		flag=true;
	}
	else
		return;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preOrder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inOrder[i]);
	}
	node* root = NULL;
	root = build(0,n-1,0,n-1);
	postTrans(root);
	printf("%d\n",firPost);
	return 0;
} 


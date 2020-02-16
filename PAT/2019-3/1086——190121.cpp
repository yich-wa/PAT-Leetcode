//18:42——
//——19:12  25分
//分清楚先序、中序、后序、层序 
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int maxn = 33;
int preorder[maxn];
int inorder[maxn];
int postorder[maxn];
int postnum = 0;
struct Node{
	Node* left;
	Node* right;
	int key;
};
Node* newnode(int k)
{
	Node* a = new Node;
	a->key = k;
	a->left = NULL;
	a->right = NULL;
	return a;
}
Node* build(int inleft,int inright,int preleft,int preright)
{
	if(inleft>inright)
		return NULL;
	Node* r = newnode(preorder[preleft]);
	int k;
	for(k = inleft;k<=inright;k++)
	{
		if(inorder[k]==preorder[preleft])
		{
			break;
		}
	}
	int len = k-1-inleft;
	r->left = build(inleft,k-1,preleft+1,preleft+1+len);
	r->right = build(k+1,inright,preleft+2+len,preright);
	return r;
}
void post_tra(Node* a)
{
	if(a==NULL)
	{
		return;
	}
	post_tra(a->left);
	post_tra(a->right);
	postorder[postnum++]=a->key;
}
int main()
{
	int n;
	char temp[6];
	int innum=0;
	int prenum=0;
	int tempnum;
	stack<int>s;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
	{
		scanf("%s",temp);
		if(temp[1]=='u')
		{
			scanf("%d",&tempnum);
			s.push(tempnum);
			preorder[prenum++]=tempnum;
		}
		else
		{
			tempnum = s.top();
			s.pop();
			inorder[innum++]=tempnum;
		}
	 }
	Node* root = build(0,n-1,0,n-1);
	post_tra(root);
	for(int i=0;i<n;i++)
	{
		printf("%d",postorder[i]);
		if(i<n-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;
}

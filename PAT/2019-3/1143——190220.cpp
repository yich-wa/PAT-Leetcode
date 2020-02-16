//10:33——11；22 
//17分 用深度优先搜索是可以记录祖先节点的。但是有13分没拿到手
//2测试单段错误。3测试点答案错误。45测试点运行超时。 

//经过反思，题中指明了是搜索二叉树，所以深度优先搜索时，
//可以确定进入左支或者右支；
//改完后是： 2/3段错误。4/5运行超时。

//网上答案有提到，可以两个一块搜索。 

//正确的思路是辨别uv大小。两个一块搜索，先搜到哪个，哪个就是另一个的
//根节点。两个都不等的话，
//如果都小于或者都大于等于，那么继续搜索向某一支去搜索。
//一个小于另一个大于等于：该节点就是u/v的共同的根节点。 
//这种做法根本就不需要记录路径。更加简便。

//现在19分，1、3/5测试点答案错误。2测试点，段错误。所以
//问题是在哪？ 

//可能是你找到u/v共同顶点后，万一你一开始将u/v内容交换过，
//那你再用 LCA of U and V is A. 就是错误的。所以记录
//原先的 u/v，此种情况输出时，用原来的u和v. 
//改完后25分。

//第2测试点：段错误。第三测试点：答案错误。 
//下面这版经过优化的，。 还是25分。

//考虑当给出u/v一样，且存在于树中。应该回答： LCA of U and V is A.
//但是A应该是其父节点。
//如果uv都一样，且与树的根节点一样。那该怎么输出呢？ 
//改完还是25分。 

//段错误的原因可能是，一开始判断uv是否存在于树中，如果是负数
//作为角标是不是会出问题。 也就是你一开始忽略了uv小于0的存在。
//可是样例中有负数，但是没有报错。
//负数这个点改过来后29分 ，还差第2个测试点段错误。1分。 

//这道题，你考场上少看了这是搜索二叉树的前提。 
//柳诺做法，根本无需建树。遍历《搜索二叉树的前序序列》足够解决这个问题 
#include<stdio.h>
const int maxn =10005;
struct node{
	node* lchild;
	node* rchild;
	int key;
}; 
int preorder[maxn];
node* newnode(int k)
{
	node* a =new node;
	a->lchild = a->rchild = NULL;
	a->key = k;
	return a;
}
node* build(int preL,int preR)
{
	if(preL>preR)
		return NULL;
	node* r = newnode(preorder[preL]);
	int k;
	for(k=preL+1;k<=preR;k++)
	{
		if(preorder[k]>=preorder[preL])
			break;
	}
	r->lchild = build(preL+1,k-1);
	r->rchild = build(k,preR);
	return r; 
}
void DFS(node* r,int u,int v)
{
	if(r==NULL)
		return;
	if(r->key==u&&r->key!=v)
	{
		printf("%d is an ancestor of %d.\n",u,v);
		return;
	}
	else if(r->key==v&&r->key!=u)
	{
		printf("%d is an ancestor of %d.\n",v,u);
		return;
	}
	else if(u<r->key&&v<r->key)
	{
		DFS(r->lchild,u,v);
	}
	else if(u>r->key&&v>r->key)
	{
		DFS(r->rchild,u,v);	
	}	
	else
	{
		printf("LCA of %d and %d is %d.\n",u,v,r->key);
		return;
	}
}
void DFS2(node* root ,int u)
{
	if(root==NULL)
		return ;
	if(root->key==u)
	{
		printf("LCA of %d and %d is %d.\n",u,u,u);
		return;
	}
	else if(u<root->key)
	{
		if(root->lchild->key==u)
		{
			printf("LCA of %d and %d is %d.\n",u,u,root->key);
			return ;
		}
		else
		{
			DFS2(root->lchild,u);
		}
	}
	else
	{
		if(root->rchild->key==u)
		{
			printf("LCA of %d and %d is %d.\n",u,u,root->key);
			return ;
		}
		else
		{
			DFS2(root->rchild,u);
		}
	}
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	bool isExist[maxn]={false};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preorder[i]);
		isExist[preorder[i]]=true;
	}
	node* root =NULL;
	root = build(0,n-1);
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		if(isExist[u]==false||u<0) 
		{
			if(isExist[v]==false||v<0)
				printf("ERROR: %d and %d are not found.\n",u,v);
			else 
				printf("ERROR: %d is not found.\n",u);
		}
		else if(isExist[v]==false||v<0)
			printf("ERROR: %d is not found.\n",v);
		else 
		{
			if(u!=v)
				DFS(root,u,v);
			else
				DFS2(root,u);
		}	
	}
	return 0;
}


//下面这版25分，将但是将无用的去掉后就变成10分了，苦恼。 
//经测试，只要将 根本都没用到的  stack<int>s;删掉，就从
//25分变成10分。 神奇
 
//#include<stdio.h>
//#include<vector>
//#include<stack>
//using namespace std;
//const int maxn =10005;
//struct node{
//	node* lchild;
//	node* rchild;
//	int key;
//}; 
//int preorder[maxn];
//int preU,preV; //记录原先的u/v
//node* newnode(int k)
//{
//	node* a =new node;
//	a->lchild = a->rchild = NULL;
//	a->key = k;
//	return a;
//}
//node* build(int preL,int preR)
//{
//	if(preL>preR)
//		return NULL;
//	node* r = newnode(preorder[preL]);
//	int k;
//	for(k=preL+1;k<=preR;k++)
//	{
//		if(preorder[k]>=preorder[preL])
//			break;
//	}
//	r->lchild = build(preL+1,k-1);
//	r->rchild = build(k,preR);
//	return r; 
//}
//void DFS(node* r,int u,int v)
//{
//	if(r==NULL)
//		return;
//	if(r->key==u)
//	{
//		printf("%d is an ancestor of %d.\n",u,v);
//		return;
//	}
//	else if(r->key==v)
//	{
//		printf("%d is an ancestor of %d.\n",v,u);
//		return;
//	}
//	else if(u<r->key&&v<r->key)
//	{
//		DFS(r->lchild,u,v);
//	}
//	else if(u>r->key&&v>r->key)
//	{
//		DFS(r->rchild,u,v);	
//	}	
//	else
//	{
//		printf("LCA of %d and %d is %d.\n",preU,preV,r->key);
//		return;
//	}
//}
//int main()
//{
//	int m,n;
//	scanf("%d%d",&m,&n);
//	bool isExist[maxn]={false};
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&preorder[i]);
//		isExist[preorder[i]]=true;
//	}
//	node* root =NULL;
//	root = build(0,n-1);
//	int u,v;
//	stack<int>s;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&u,&v);
//		if(isExist[u]==false)
//		{
//			if(isExist[v]==false)
//				printf("ERROR: %d and %d are not found.\n",u,v);
//			else 
//				printf("ERROR: %d is not found.\n",u);
//		}
//		else if(isExist[v]==false)
//			printf("ERROR: %d is not found.\n",v);
//		else
//		{
//			preU = u;
//			preV = v;
//			if(u>v)
//				swap(u,v); 
//			DFS(root,u,v);
//		}
//	}
//	return 0;
//}

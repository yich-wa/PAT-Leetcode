//11:32——12:35 
//不会判断什么时候是唯一的。大框架写的差不多了
//若是考试的话，默认全部是唯一的，直至其可以成功建立树。
//题中已经提示你，树并不唯一，你要做的是建立其中一颗树即可。 
//但关于判断是否是唯一。对于任何一颗子树，前序的第一个，和
///后序的最后一个是一样的。 
//如果一棵树是单支树，那么一般是不唯一的。
//像 1 2 3 4 // 2 4 3 1 对于1 的右子树 3 4 //4 3就是一颗单支二叉树。
//还是一开始对树的先序和后序不够清晰。两者的联系要很清晰。
//要清晰的知道为什么，先序和后序不能确定一颗二叉树，因为有单支情况
//的存在。 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 32;
int preorder[maxn];
int postorder[maxn];
vector<int>inorder;
bool isunique = true;
int count =0;
struct node{
	node* lchild;
	node* rchild;
	int data;
};
node* newnode(int a)
{
	node* r = new node;
	r->data = a; 
	r->lchild = r->rchild = NULL;
	return = r;
}
node* build(int preleft,int preright,int postleft,int postright)
{
	if(preorder[preleft]!=postorder[postright])
	{
		inunique=false;
		return NULL;
	}
	node* r = newnode(preorder[preleft]);
	int k=preleft+1;
	for(int i = k;k<=preright;k++)
	{
		
		if(//两个序列阶段相等相等)
		{
			isunique= true;
			int len = k-preleft-1;
			r->lchild = build(preleft+1,k,postleft,postleft+len);
			r->rchild = build(k+1,preright,postleft+len+1,postright-1);
			if(isunique==true)
			{
				
			 }
				
		 } 
		 
	}
	r->lchild = 
	r->rchild = 
}
void out()
{
	int len = inorder.size();
	for(int i=0;i<len;i++)
	{
		if(i<len-1)
			printf("%d ",inorder[i]);
		else
			printf("%d\n",inorder[i]);
	}
}
void intraverse(node* root)
{
	if(root=NULL)
		return ;
	intraverse(root->lchild);
	inorder.push_back(root->data);
	intraverse(root->rchild);
}
int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(int i=0;i<n;i++)
		scanf("%d",&postorder[i]);
	int j;
	bool isout = false;
	for(j=1;;j++)
	{
		isunique=true;
		node* root = build(0,n-1,0,n-1,j);
		if(isunique==true)
		{
			if(isout==false	)
			{
				//存储中序序列
				intraverse(root);
				isout=true; 
			}
		}
		else
			break;
	}
	if(j==2)
		printf("Yes\n");
	else
		printf("No\n");
	out();
	return 0;
}


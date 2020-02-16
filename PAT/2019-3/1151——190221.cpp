//10:40 ——11：22  得26分。有4分运行超时。 

//不用建树，柳诺的做法和思路可以借鉴。 
//由两个节点在中序遍历中的位置与根节点的位置关系可以确定。
//看其是在。而前序序列的作用，是确定中序序列中，根节点的位置。
//建树是一种比较笨的做法。 
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
const int maxn = 10005;
struct node{
	node* lchild;
	node* rchild;
	int key;
};
node* newnode(int a)
{
	node* r = new node;
	r->lchild = r->rchild = NULL;
	r->key = a;
	return r;
}
int inorder[maxn];
int preorder[maxn];
node* build(int inL,int inR,int preL,int preR)
{
	if(inL>inR)
		return NULL;
	node* root = newnode(preorder[preL]);
	int k;
	
	for(k = inL;k<=inR;k++)
	{
		if(inorder[k]==preorder[preL])
			break;
	}
	//printf("%d**kkk\n",k);
	int len =k-1-inL;
	root->lchild = build(inL,k-1,preL+1,preL+1+len);
	root->rchild = build(k+1,inR,preL+len+2,preR);
	return root;
}
vector<int>ans,tempans,ans1;
bool flag=false;
void DFS(node* root,int a)
{
	if(root==NULL)
		return;
	if(root->key == a)
	{
		flag= true;
		ans = tempans;
		//printf("%d__\n",a);
		return ;
	}
	if(flag==true)
		return;	
	if(root->lchild !=NULL)
	{
		tempans.push_back(root->lchild->key);
		DFS(root->lchild,a);
		tempans.pop_back();
	}
	
	if(flag==true)
		return;	
	if(root->rchild!=NULL)
	{
		tempans.push_back(root->rchild->key);
		DFS(root->rchild,a);
		tempans.pop_back();
	}
}
int main()
{
	int m,n;
	map<int,bool>mp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
		mp[inorder[i]]=true;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preorder[i]);
	}
	node* root = NULL;
	root = build(0,n-1,0,n-1);
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		if(mp[u]!=true)
		{
			if(mp[v]!=true)
				printf("ERROR: %d and %d are not found.\n",u,v);
			else 
				printf("ERROR: %d is not found.\n",u);
		}
		else if(mp[v]!=true)
			printf("ERROR: %d is not found.\n",v);
		else
		{
			//printf("%d%d**\n",u,v);
			bool isout=false;
			tempans.clear();
			flag=false;
			tempans.push_back(root->key);
			DFS(root,u);
			ans1 = ans;
			int len1 = ans1.size();
			//printf("%d**%d\n",len1,ans.size());
			for(int j=len1-1;j>=0;j--)
			{
				if(ans1[j]==v)
				{
					printf("%d is an ancestor of %d.\n",v,u);
					isout=true;
					break;
				}		
			}
			if(isout==true)
				continue;
			tempans.clear();
			flag=false;
			tempans.push_back(root->key);
			DFS(root,v);
			int len = ans.size();
			for(int j=len-1;j>=0;j--)
			{
				if(ans[j]==u)
				{
					printf("%d is an ancestor of %d.\n",u,v);
					isout=true;
					break;
				}		
			}
			if(isout==true)
				continue;
			for(int j=len-2;j>=0;j--)
			{
				for(int h =len1-2;h>=0;h--)
				{
					if(ans[j]==ans1[h])
					{
						printf("LCA of %d and %d is %d.\n",u,v,ans[j]);
						isout= true;
						break;
					}	
				}
				if(isout==true)
					break;
			}		
		}
	}
	return 0;
}

//15:55  
//16:51——
//AVL树，建立的框架和细节，都要记忆的很健壮。 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
	node* left;
	node* right;
	int height;
	int key;
};
node* newnode(int a)
{
	//printf("%d**\n",a);
	node* r =new node;
	r->key =a;
	r->height = 1;
	r->left = r->right = NULL;
	return r;
}
int getheight(node* r)
{
	
	if(r==NULL)
		return 0;
	else
		return r->height;
}
void updateheight(node* r)
{
	r->height = max(getheight(r->left),getheight(r->right))+1;
}
int getbalancefactor(node* r)
{
	return getheight(r->left)-getheight(r->right);
}
void R(node* &root)
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
 }
void L(node* &root)
{
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root ;
	updateheight(root);
	updateheight(temp);
	root = temp;
 }  
void insert(node* &root,int a)
{
	if(root==NULL)
	{
		root = newnode(a);
		return ;
	}
	if(a<root->key)
	{
		insert(root->left,a);
		updateheight(root->left);
		if(getbalancefactor(root)==2)
		{
			if(getbalancefactor(root->left)==1)
				R(root);
			else 
			{
				L(root->left);
				R(root);	
			}
		}
	}
	else 
	{
		insert(root->right,a);
		updateheight(root->right);
		if(getbalancefactor(root)==-2)
		{
			if(getbalancefactor(root->right)==-1)
				L(root);
			else 
			{
				R(root->right);
				L(root);	
			}
		}
		
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node* root;
	root=NULL;  //这句必须有 
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		//printf("%d**--\n",temp);
		insert(root,temp);
	}
	printf("%d\n",root->key);
	return 0;
}

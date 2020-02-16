//16:28——
//——17:00  25分。 
#include<stdio.h>
#include<queue>
using namespace std;
const int maxn = 31;
int inorder[maxn];
int postorder[maxn];
int level[maxn];
struct Node{
	Node* left;
	Node* right;
	int key;
};
Node* newnode(int k)   
{
	Node* a =new Node;
	a->left = a->right =NULL;
	a->key = k;
	//printf("%d\n",k);
	//开始写的时候忘记下面这句，然后就耗费能有10分钟。检查要仔细。 
	return a;
 } 
 Node* build(int pleft,int pright,int inleft,int inright)
 {
 	//printf("%d\n",pleft);
 	//开始下面的判断符号写成"<"最终通过节点插入输出找到。
	 //智障级别的低级错误。最好写成preL,preR 
 	if(pleft>pright)
 	return NULL;
 	Node* r = newnode(postorder[pright]);
 	int k ;
 	for(k=inleft;k<=inright;k++)
	 {
	 	if(inorder[k]==postorder[pright])
	 	break;
	  } 
	//printf("%d\n",k);
	int lenth = k-1-inleft;
	r->left = build(pleft,pleft+lenth,inleft,k-1);
	r->right = build(pleft+lenth+1,pright-1,k+1,inright);
	return r;
 }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&postorder[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&inorder[i]);
	Node* root = build(0,n-1,0,n-1);
	queue<Node*>q;
	q.push(root);
	int num =0;
	while(!q.empty())
	{
		Node* temp =q.front();
		q.pop();
		level[num++]=temp->key;
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",level[i]);
		if(i<n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}


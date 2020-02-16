#include<stdio.h>
#include<queue>
using namespace std;
const int maxn = 35;
struct node{
	int value;
	node* left;
	node* right;
};
int posOrder[maxn];
int inOrder[maxn];
int leOrder[maxn]; 
node* newnode(int k){
	node* r = new node;
	r->value = k;
	r->left = r->right = NULL;
	return r;
}
node* build(int pLeft,int pRight,int iLeft,int iRight){
	if(pLeft>pRight){
		return NULL;
	}
	node* r = newnode(posOrder[pRight]);
	int temp = posOrder[pRight];
	int k;
	for(k = iLeft;k<=iRight;k++){
		if(inOrder[k]==temp){
			break;
		}
	}
	int len = k-1-iLeft;
	r->left = build(pLeft,pLeft+len,iLeft,k-1);
	r->right = build(pLeft+len+1,pRight-1,k+1,iRight);
	return r;
}
int main(){
	int n;
	vector<int>level;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&posOrder[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&inOrder[i]);
	}
	node* root = build(0,n-1,0,n-1);
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		level.push_back(temp->value);
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
	for(int i=0;i<level.size();i++){
		if(i>0)
			printf(" ");
		printf("%d",level[i]);
	}
	return 0;
} 
//
////以前做的
//#include<stdio.h>
//#include<queue>
//using namespace std;
//const int maxn = 31;
//int inorder[maxn];
//int postorder[maxn];
//int level[maxn];
//struct Node{
//	Node* left;
//	Node* right;
//	int key;
//};
//Node* newnode(int k)   
//{
//	Node* a =new Node;
//	a->left = a->right =NULL;
//	a->key = k;
//	//printf("%d\n",k);
//	//开始写的时候忘记下面这句，然后就耗费能有10分钟。检查要仔细。 
//	return a;
// } 
// Node* build(int pleft,int pright,int inleft,int inright)
// {
// 	//printf("%d\n",pleft);
// 	//开始下面的判断符号写成"<"最终通过节点插入输出找到。
//	 //智障级别的低级错误。 
// 	if(pleft>pright)
// 	return NULL;
// 	Node* r = newnode(postorder[pright]);
// 	int k ;
// 	for(k=inleft;k<=inright;k++)
//	 {
//	 	if(inorder[k]==postorder[pright])
//	 	break;
//	  } 
//	//printf("%d\n",k);
//	int lenth = k-1-inleft;
//	r->left = build(pleft,pleft+lenth,inleft,k-1);
//	r->right = build(pleft+lenth+1,pright-1,k+1,inright);
//	return r;
// }
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	scanf("%d",&postorder[i]);
//	for(int i=0;i<n;i++)
//	scanf("%d",&inorder[i]);
//	Node* root = build(0,n-1,0,n-1);
//	queue<Node*>q;
//	q.push(root);
//	int num =0;
//	while(!q.empty())
//	{
//		Node* temp =q.front();
//		q.pop();
//		level[num++]=temp->key;
//		if(temp->left!=NULL)
//			q.push(temp->left);
//		if(temp->right!=NULL)
//			q.push(temp->right);
//	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%d",level[i]);
//		if(i<n-1)
//			printf(" ");
//		else
//			printf("\n");
//	}
//	return 0;
//} 

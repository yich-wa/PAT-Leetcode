//07:33 ——08:12
//思路要清晰。其实考PAT某种程度是考，像下棋一样的战略思维。
//要在动手之前掌握全局思维。但是也不要一条道走到黑。生活往往是
//先做在想。 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 1005;
int preOrder[maxn];
vector<int>postOrder;
bool isBst = true;
bool isMbst = true;
struct node{
	node* left;
	node* right;
	int value;
};
node* newnode(int k){
	node* r = new node;
	r->value = k;
//	printf("%d**\n",k);
	r->left = r->right = NULL;
	return r;
}
node* buildBst(int left,int right){
	if(left>right)
		return NULL;
	node* root = newnode(preOrder[left]);
	int k;
	for(k =left+1;k<=right;k++){
		if(preOrder[k]>=preOrder[left]){
			break;
		}
	}
	if(k>right){
		root->right = NULL;
	}else{
		for(int i =k;i<=right;i++){
			if(preOrder[i]<preOrder[left]){
				isBst = false;
				return NULL;
			}
		}
		root->right = buildBst(k,right);
	}
	root->left = buildBst(left+1,k-1);
	return root;
}
node* buildMbst(int left,int right){
	if(left>right)
		return NULL;
	node* root = newnode(preOrder[left]);
	int k;
	for(k =left+1;k<=right;k++){
		if(preOrder[k]<preOrder[left]){
			break;
		}
	}
	if(k>right){
		root->right = NULL;
	}else{
		for(int i =k;i<=right;i++){
			if(preOrder[i]>=preOrder[left]){
				isMbst = false;
				return NULL;
			}
		}
		root->right = buildMbst(k,right);
	}
	root->left = buildMbst(left+1,k-1);
	return root;
}
void postTra(node* r){
	if(r->left!=NULL)
		postTra(r->left);
	if(r->right!=NULL)
		postTra(r->right);
	postOrder.push_back(r->value);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&preOrder[i]);
//		printf("%d***\n",preOrder[i]);
	}
	node* root = buildBst(0,n-1);
	if(isBst==false){
		root = buildMbst(0,n-1);
	}
	if(isMbst ==true||isBst==true){
		postTra(root);
		printf("YES\n");
		for(int i=0;i<postOrder.size();i++){
			if(i!=0)
				printf(" ");
			printf("%d",postOrder[i]);
		}
	}else{
		printf("NO");
	}
	return 0;
}


////以前写的
//#include<stdio.h>
//const int maxn = 1005;
//int n;
//int pre[maxn];
//int post[maxn];
//bool isbst=true;
//bool ismbst = true;
//struct node
//{
//	node* lchild;
//	node* rchild;
//	int key;
//}temp;
//node* newnode(int a)
//{
//	node* r = new node;
//	r->key = a;
//	r->lchild = r->rchild = NULL;
//	return r; 
//}
//int nump=0;
//void post_tra(node* r)
//{
//	if(r==NULL)
//		return ;
//	post_tra(r->lchild);
//	post_tra(r->rchild);
//	post[nump++]=r->key;
//}
//void out()
//{
//	//printf("888\n");
//	for(int i=0;i<n;i++)
//	{
//		printf("%d",post[i]);
//		if(i<n-1)
//		printf(" ");
//		else
//		printf("\n");
//	}
//}
//node* BST(int left,int right)
//{
//	if(left>right)
//		return NULL;
//	node* r = newnode(pre[left]);
//	int k;
//	for(k=left+1;k<=right;k++)
//	{
//		if(pre[k]>=pre[left])
//		{	
//			break;
//		}	
//	}
//	for(int i=k;i<=right;i++)
//	{
//		if(pre[i]<pre[left])
//		{
//			//printf("%d%d*%d%d\n",left,right,pre[i],k);
//			isbst=false;
//			break;
//		}
//	}
//	if(isbst==false)
//		return r;
//	r->lchild=BST(left+1,k-1);
//	r->rchild= BST(k,right);
//	return r;
//}
//node* MBST(int left,int right)
//{
//	if(left>right)
//	return NULL;
//	node* r = newnode(pre[left]);
//	//printf("%d**\n",r->key);
//	int k;
//	for(k=left+1;k<=right;k++)
//	{
//		if(pre[k]<pre[left])
//		{
//			break;
//		}
//	}
//	//printf("%d**\n",k);
//	for(int i = k;i<=right;i++)
//	{
//		if(pre[i]>=pre[left])
//		{
//			ismbst=false;
//			break;
//		}
//	}
//	if(ismbst==false)
//		return r;
//	r->lchild=MBST(left+1,k-1);
//	r->rchild= MBST(k,right);
//	return r;
//}
//int main()
//{
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&pre[i]);
//	}
//	node* r = BST(0,n-1);
//	if(isbst==true)
//	{
//		post_tra(r);
//		printf("YES\n"); 
//		out();
//		return 0;
//	}
//	else
//	{
//		node* r = MBST(0,n-1);
//		if(ismbst==false)
//		{
//			printf("NO\n");
//			return 0;
//		}
//		else
//		{
//			post_tra(r);
//			printf("YES\n");
//			out();
//			return 0;
//		}	
//	}
// }  

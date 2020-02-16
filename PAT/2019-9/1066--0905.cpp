//14:36--
//开始把大部分都写出来了。不过插入函数中if(r==NULL)在一开始不能通过。
//后发现：定义root时。应该：node* root = NULL;而不是仅仅：node* root;
//修改过之后居然满分。看来细节还是很多的。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 22;
struct node{
	node* left;
	node* right;
	int value;
	int height;
};
node* newnode(int k){
	node* r = new node;
	r->value = k;
	r->left = r->right = NULL;
	r->height = 1;
//	printf("%d****kkk\n",k); 
	return r;
}
int getHeight(node* r){
	if(r==NULL)
		return 0;
	return r->height;
}
int getBalanceFactor(node* r){
	return getHeight(r->left)-getHeight(r->right);
}
void updateHeight(node* r){
	r->height = max(getHeight(r->left),getHeight(r->right))+1;
}
void R(node* &r){
	node* temp = r->left;
	r->left = temp->right;
	temp->right = r;
	updateHeight(r);
	updateHeight(temp);
	r = temp;
}
void L(node* &r){
	node* temp = r->right;
	r->right = temp->left;
	temp->left = r;
	updateHeight(r);
	updateHeight(temp);
	r = temp;
}
void insert(node* &r,int k){
	if(r==NULL){
		r=newnode(k);
		return;
	}
	if(k<r->value){
		insert(r->left,k);
		updateHeight(r->left);
		if(getBalanceFactor(r)==2){
			if(getBalanceFactor(r->left)==1){
				//LL型
				R(r); 
			}else{
				L(r->left);
				R(r);
			}
		}
	}else{
		insert(r->right,k);
		updateHeight(r->right);
		if(getBalanceFactor(r)==-2){
			if(getBalanceFactor(r->right)==-1){
				//LL型
				L(r); 
			}else{
				R(r->right);
				L(r);
			}
		}
	}
}
int main(){
	int n;
	//下面这个写错了。一开始写成node* root;后面的NULL不能少。。 
	node* root =NULL;
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d",root->value);
	return 0;
} 


////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//struct node{
//	node* left;
//	node* right;
//	int height;
//	int key;
//};
//node* newnode(int a)
//{
//	//printf("%d**\n",a);
//	node* r =new node;
//	r->key =a;
//	r->height = 1;
//	r->left = r->right = NULL;
//	return r;
//}
//int getheight(node* r)
//{
//	if(r==NULL)
//		return 0;
//	else
//		return r->height;
//}
//void updateheight(node* r)
//{
//	r->height = max(getheight(r->left),getheight(r->right))+1;
//}
//int getbalancefactor(node* r)
//{
//	return getheight(r->left)-getheight(r->right);
//}
//void R(node* &root)
//{
//	node* temp = root->left;
//	root->left = temp->right;
//	temp->right = root;
//	updateheight(root);
//	updateheight(temp);
//	root = temp;
// }
//void L(node* &root)
//{
//	node* temp = root->right;
//	root->right = temp->left;
//	temp->left = root ;
//	updateheight(root);
//	updateheight(temp);
//	root = temp;
// }  
//void insert(node* &root,int a)
//{
//	if(root==NULL)
//	{
//		root = newnode(a);
//		return ;
//	}
//	if(a<root->key)
//	{
//		insert(root->left,a);
//		updateheight(root->left);
//		if(getbalancefactor(root)==2)
//		{
//			if(getbalancefactor(root->left)==1)
//				R(root);
//			else 
//			{
//				L(root->left);
//				R(root);	
//			}
//		}
//	}
//	else 
//	{
//		insert(root->right,a);
//		updateheight(root->right);
//		if(getbalancefactor(root)==-2)
//		{
//			if(getbalancefactor(root->right)==-1)
//				L(root);
//			else 
//			{
//				R(root->right);
//				L(root);	
//			}
//		}
//		
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	node* root;
//	root=NULL; 
//	int temp;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&temp);
//		//printf("%d**--\n",temp);
//		insert(root,temp);
//	}
//	printf("%d\n",root->key);
//	return 0;
//} 

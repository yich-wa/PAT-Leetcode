//10:33����11��22 
//17�� ��������������ǿ��Լ�¼���Ƚڵ�ġ�������13��û�õ���
//2���Ե��δ���3���Ե�𰸴���45���Ե����г�ʱ�� 

//������˼������ָ���������������������������������ʱ��
//����ȷ��������֧������֧��
//������ǣ� 2/3�δ���4/5���г�ʱ��

//���ϴ����ᵽ����������һ�������� 

//��ȷ��˼·�Ǳ��uv��С������һ�����������ѵ��ĸ����ĸ�������һ����
//���ڵ㡣���������ȵĻ���
//�����С�ڻ��߶����ڵ��ڣ���ô����������ĳһ֧ȥ������
//һ��С����һ�����ڵ��ڣ��ýڵ����u/v�Ĺ�ͬ�ĸ��ڵ㡣 
//�������������Ͳ���Ҫ��¼·�������Ӽ�㡣

//����19�֣�1��3/5���Ե�𰸴���2���Ե㣬�δ�������
//���������ģ� 

//���������ҵ�u/v��ͬ�������һ��һ��ʼ��u/v���ݽ�������
//�������� LCA of U and V is A. ���Ǵ���ġ����Լ�¼
//ԭ�ȵ� u/v������������ʱ����ԭ����u��v. 
//�����25�֡�

//��2���Ե㣺�δ��󡣵������Ե㣺�𰸴��� 
//������澭���Ż��ģ��� ����25�֡�

//���ǵ�����u/vһ�����Ҵ��������С�Ӧ�ûش� LCA of U and V is A.
//����AӦ�����丸�ڵ㡣
//���uv��һ�����������ĸ��ڵ�һ�����Ǹ���ô����أ� 
//���껹��25�֡� 

//�δ����ԭ������ǣ�һ��ʼ�ж�uv�Ƿ���������У�����Ǹ���
//��Ϊ�Ǳ��ǲ��ǻ�����⡣ Ҳ������һ��ʼ������uvС��0�Ĵ��ڡ�
//�����������и���������û�б���
//���������Ĺ�����29�� �������2�����Ե�δ���1�֡� 

//����⣬�㿼�����ٿ�������������������ǰ�ᡣ 
//��ŵ�������������轨����������������������ǰ�����С��㹻���������� 
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


//�������25�֣������ǽ����õ�ȥ����ͱ��10���ˣ����ա� 
//�����ԣ�ֻҪ�� ������û�õ���  stack<int>s;ɾ�����ʹ�
//25�ֱ��10�֡� ����
 
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
//int preU,preV; //��¼ԭ�ȵ�u/v
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

//11:32����12:35 
//�����ж�ʲôʱ����Ψһ�ġ�����д�Ĳ����
//���ǿ��ԵĻ���Ĭ��ȫ����Ψһ�ģ�ֱ������Գɹ���������
//�����Ѿ���ʾ�㣬������Ψһ����Ҫ�����ǽ�������һ�������ɡ� 
//�������ж��Ƿ���Ψһ�������κ�һ��������ǰ��ĵ�һ������
///��������һ����һ���ġ� 
//���һ�����ǵ�֧������ôһ���ǲ�Ψһ�ġ�
//�� 1 2 3 4 // 2 4 3 1 ����1 �������� 3 4 //4 3����һ�ŵ�֧��������
//����һ��ʼ����������ͺ��򲻹����������ߵ���ϵҪ��������
//Ҫ������֪��Ϊʲô������ͺ�����ȷ��һ�Ŷ���������Ϊ�е�֧���
//�Ĵ��ڡ� 
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
		
		if(//�������н׶�������)
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
				//�洢��������
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


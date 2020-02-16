//11:27����11:47
//��ʼ��scanfд����printf,���� 
//�����30�֡� 
//��BFS+level����ȥ��¼�Ƚϼ򵥡���ס���ڵ㿪ʼ��ʱ���ǣ�
//node* root = NULL;
//�Լ�����ڵ�ĺ���Ҫ�������� 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int level[maxn]={0};
struct node{
	node* lchild;
	node* rchild;
	int data;
};
node* newnode(int a)
{
	node* temp = new node;
	temp->data = a;
	temp->lchild =NULL;
	temp->rchild = NULL;
	return temp;
}
void insert(node* &root,int a)
{
	if(root==NULL)
	{
		root=newnode(a);
	}
	else
	{
		if(a<=root->data)
			insert(root->lchild,a);
		else
			insert(root->rchild,a);	
	}
}
int maxlevel= 0;
void BFS(node* r,int lev)
{
	if(lev>maxlevel)
	{
		maxlevel=lev;
	}
	if(r->lchild!=NULL)
	{
		level[lev+1]++;
		BFS(r->lchild,lev+1);
	}
	if(r->rchild!=NULL)
	{
		level[lev+1]++;
		BFS(r->rchild,lev+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node* r =NULL;
	int temp;
	for(int i=0;i<n;i++)
	{
		//��ʼ��Ȼ�������scanfд��printf�ˡ� 
		scanf("%d",&temp);
		insert(r,temp);
	}
	level[0]++;
	BFS(r,0);
	int sum = level[maxlevel]+level[maxlevel-1];
	printf("%d + %d = %d\n",level[maxlevel],level[maxlevel-1],sum);
	return 0;
}

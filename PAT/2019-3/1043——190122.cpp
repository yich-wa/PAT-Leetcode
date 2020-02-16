//21:26����
//��ʼ�����⣬������ڽ���BST����MBSTʱ��ϸ�ڳ��˼�������
//�������������״�������ϸ��Ҫע��
//���о��ǣ�ȫ�ֱ������������ڲ��ı������岻Ҫ�ظ�����������
//˭�����ĸ���Χ���塣��β�Ҫ�ظ��� ��ͬ����Ƕ��forѭ���������
//ָ����� ��Ҫ�ظ��� 
//ע�⼰ʱ��printfȥdebug 

#include<stdio.h>
const int maxn = 1005;
int n;
int pre[maxn];
int post[maxn];
bool isbst=true;
bool ismbst = true;
struct node
{
	node* lchild;
	node* rchild;
	int key;
}temp;
node* newnode(int a)
{
	node* r = new node;
	r->key = a;
	r->lchild = r->rchild = NULL;
	return r; 
}
int nump=0;
void post_tra(node* r)
{
	if(r==NULL)
		return ;
	post_tra(r->lchild);
	post_tra(r->rchild);
	post[nump++]=r->key;
}
void out()
{
	//printf("888\n");
	for(int i=0;i<n;i++)
	{
		printf("%d",post[i]);
		if(i<n-1)
		printf(" ");
		else
		printf("\n");
	}
}
node* BST(int left,int right)
{
	if(left>right)
		return NULL;
	node* r = newnode(pre[left]);
	int k;
	for(k=left+1;k<=right;k++)
	{
		if(pre[k]>=pre[left])
		{	
			break;
		}	
	}
	for(int i=k;i<=right;i++)
	{
		if(pre[i]<pre[left])
		{
			//printf("%d%d*%d%d\n",left,right,pre[i],k);
			isbst=false;
			break;
		}
	}
	if(isbst==false)
		return r;
	r->lchild=BST(left+1,k-1);
	r->rchild= BST(k,right);
	return r;
}
node* MBST(int left,int right)
{
	if(left>right)
	return NULL;
	node* r = newnode(pre[left]);
	//printf("%d**\n",r->key);
	int k;
	for(k=left+1;k<=right;k++)
	{
		if(pre[k]<pre[left])
		{
			break;
		}
	}
	//printf("%d**\n",k);
	for(int i = k;i<=right;i++)
	{
		if(pre[i]>=pre[left])
		{
			ismbst=false;
			break;
		}
	}
	if(ismbst==false)
		return r;
	r->lchild=MBST(left+1,k-1);
	r->rchild= MBST(k,right);
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	node* r = BST(0,n-1);
	if(isbst==true)
	{
		post_tra(r);
		printf("YES\n"); 
		out();
		return 0;
	}
	else
	{
		node* r = MBST(0,n-1);
		if(ismbst==false)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			post_tra(r);
			printf("YES\n");
			out();
			return 0;
		}	
	}
 } 
 

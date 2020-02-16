//09:05——09:25 25分。 
#include<stdio.h>
#include<string.h>
const int maxn = 22;
struct node{
	char data[12];
	int lchild;
	int rchild;
}Node[maxn];
void inorder(int r)
{
	if(r==-1)
		return;
	if(Node[r].lchild!=-1||Node[r].rchild!=-1)
	{
		printf("(");
		inorder(Node[r].lchild);
		printf("%s",Node[r].data);
		inorder(Node[r].rchild);
		printf(")");
	}
	else
	{
		printf("%s",Node[r].data);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	bool isroot[maxn]={false};
	for(int i=1;i<=n;i++)
	{
		scanf("%s %d %d",Node[i].data,&Node[i].lchild,&Node[i].rchild); 
		if(Node[i].lchild!=-1)
			isroot[Node[i].lchild]=true;
		if(Node[i].rchild!=-1)
			isroot[Node[i].rchild]=true;
	}
	int root;
	//找根节点。 
	for(int i=1;i<=n;i++)
	{
		if(isroot[i]==false)
		{
			root=i;
			break;
		}
	}
	inorder(Node[root].lchild);
	printf("%s",Node[root].data);
	inorder(Node[root].rchild);
	return 0;
 } 

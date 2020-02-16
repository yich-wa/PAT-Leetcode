//10£º54¡ª¡ª11:11 25·Ö¡£ 
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
const int maxn = 15;
struct node{
	int left;
	int right;
}Node[maxn]; 
vector<int>inorderOut;
vector<int>levelorderOut;
void inorder(int r)
{
	if(r==-1)
		return;
	inorder(Node[r].left);
	inorderOut.push_back(r);
	inorder(Node[r].right);
}
void levelorder(int r)
{
	queue<int>q; 
	q.push(r);
	while(!q.empty())
	{
		int temp =q.front();
		levelorderOut.push_back(temp);
		q.pop();
		if(Node[temp].left!=-1)
			q.push(Node[temp].left);
		if(Node[temp].right!=-1)
			q.push(Node[temp].right);
	}
}
void out()
{
	int len1 = levelorderOut.size();
	for(int i=0;i<len1;i++)
	{
		if(i<len1-1)
		printf("%d ",levelorderOut[i]); 
		else
		printf("%d\n",levelorderOut[i]);
	}
	int len = inorderOut.size();
	for(int i=0;i<len;i++)
	{
		if(i<len-1)
		printf("%d ",inorderOut[i]); 
		else
		printf("%d\n",inorderOut[i]);
	}
 } 
int main()
{
	int n;
	char u,v;
	scanf("%d",&n);
	bool isvisit[maxn]={false};
	for(int i=0;i<n;i++)
	{
		getchar();
		scanf("%c %c",&u,&v);
		if(u=='-')
		Node[i].right = -1;
		else
		{
			Node[i].right = u-'0';
			isvisit[u-'0']=true;
		}
		
		if(v=='-')
		Node[i].left = -1;
		else
		{
			Node[i].left = v- '0';
			isvisit[v-'0']=true;
		}
		
	}
	int root;
	for(int i=0;i<n;i++)
	{
		if(isvisit[i]==false)
		{
			root=i;
			break;
		}
	}
	inorder(root);
	levelorder(root);
	out();
	return 0;
 } 

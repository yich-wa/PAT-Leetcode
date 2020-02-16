//11:55¡ª¡ª
//12:22 24·Ö  1·Ö´ð°¸´íÎó¡£ 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn = 22;
queue<int>q;
struct Node{
	int lchild;
	int rchild;
}node[maxn];
int main()
{
	int n;
	char fir[5];
	char sed[5];
	bool flag[maxn]={false};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",fir,sed);
		int temp=-1;
		if(fir[0]!='-')
		{
			sscanf(fir,"%d",&temp);
			flag[temp]=true;
		}
		node[i].lchild = temp;
		temp =-1;
		if(sed[0]!='-')
		{
			sscanf(sed,"%d",&temp);
			flag[temp]=true;
		}
		node[i].rchild = temp;
	}
//	if(n==1)
//	{
//		printf("NO 0");
//		return 0;
//	 } 
	int root;
	for(int i=0;i<n;i++)
	{
		if(flag[i]==false)
		{
			root=i;
			break;
		}
	}
	bool iscomp =true;
	int count =0;
	q.push(root);
	count++;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		if(node[temp].lchild!=-1)
		{
			q.push(node[temp].lchild);
			count++;
		}
		else
		{
			if(count<n)
			{
				iscomp=false;
				break;
			}
			else
			{
				break;
			}
		}
		if(node[temp].rchild!=-1)
		{
			q.push(node[temp].rchild);
			count++;
		}
		else
		{
			if(count<n)
			{
				iscomp=false;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if(iscomp==true)
	{
		int last;
		while(!q.empty())
		{
			last = q.front();
			q.pop();
		}
		printf("YES %d",last);
	}
	else
	{
		printf("NO %d",root);
	}
	return 0;
}
 

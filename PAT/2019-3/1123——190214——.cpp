//17:46——19:00
///AVl树的函数大致能够写出来，但是并不能写全对
//暂时不知道问题出在哪。

//经过查书，找出问题： 
//开始旋转函数里面，应该先更新r高度，再更新temp高度。你写反了。
//因为temp最终才是根节点。 
//应该先更新下面的树的高度，再更新上面树的高度。你更新错了。
//记住。 
//要准确记忆，不要再给自己算法留不确定性。就是背的滚瓜烂熟。

//对照书，又发现一个函数里面的细节写错了。 
//插入节点的更新高度错了。应该是
//updateheight(r);
//而不是
//updateheight（r->lchild) 或者右子树。 
//下面写错了。应该是更新r的树高。你想一下，肯定是插到叶节点或者
//只有一个叶节点的根节点的另一侧。

//改完后，还是错误的。层序遍历的序列，一直和初始序列一样，为什么呢？
//完了，最终发现，getbalancefactor()函数写错了。写成左子树的高度
//减左子树高度了。又是一个傻逼问题。简直智障。
//所以一直没有旋转,树一直是单支二叉树。锁定问题要非常准。 

//改完后，样例一，通过了。样例二，没有过。
//发现是：旋转子树的代码超过去，左右子树没有变。

//这道题从一开始就是方向是对的，但是代码记忆不牢固。几个函数的记忆都出
//现偏差。
//其次是书写问题，这种问题本应通过，检查代码可以查出来。
//检查题意和检查代码，是最基本的debug的方法。

//改完后是30分。
 
 
 

 
#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 22;
struct node{
	node* lchild;
	node* rchild;
	int height;
	int data;
};
node* newnode(int a)
{
	node* r = new node;
	r->data = a;
	r->height = 1;
	r->lchild = NULL;
	r->rchild = NULL;
	return r;
}
int getheight(node* r)
{
	if(r==NULL)
		return 0;
	else
		return r->height;
}
void updateheight(node* &r)
{
	r->height = max(getheight(r->lchild),getheight(r->rchild))+1;
}
//开始旋转函数里面，应该先更新r高度，再更新temp高度。你写反了。 
void R(node* &r)
{
	//printf("%d向右旋转了\n",r->data);
	node* temp = r->lchild;
	r->lchild = temp->rchild;
	temp->rchild = r;
	updateheight(r);
	updateheight(temp);
	r=temp; 
}
void L(node* &r)
{
	//printf("%d向左旋转了\n",r->data);
	node* temp = r->rchild;
	r->rchild = temp->lchild;
	temp->lchild = r;
	updateheight(r);
	updateheight(temp);
	r=temp; 
}

//完了，最终发现，getbalancefactor()函数写错了。写成左子树的高度
//减左子树高度了。又是一个傻逼问题。简直智障。 
int getbalancefactor(node* r)
{
	return getheight(r->lchild)-getheight(r->rchild);
}
void insert(node* &r,int a)
{
	if(r==NULL)
		r=newnode(a);
	else if(a<r->data)
	{
		insert(r->lchild,a);
		//下面写错了。应该是更新r的树高。你想一下，肯定是插到叶节点或者
		//只有一个叶节点的根节点的另一侧。 
		updateheight(r);
		if(getbalancefactor(r)==2)
		{
			if(getbalancefactor(r->lchild)==1)
				R(r);
			//下面还要判断是否等于-1，不过我个人觉得似乎没必要。 
			else if(getbalancefactor(r->lchild)==-1)
			{
				L(r->lchild);
				R(r);
			}	
		}
	}
	else
	{
		insert(r->rchild,a);
		updateheight(r);
		if(getbalancefactor(r)==-2)  //开始这个-2写成了2；下面也是。 
		{
			if(getbalancefactor(r->rchild)==-1)
				L(r);
			else if(getbalancefactor(r->rchild)==1)
			{
				R(r->rchild);
				L(r);
			}
		}
	}
}
vector<int>levelorder;
queue<node*>q;  //队列里放的是结点的指针。 
int main()
{
	int n;
	int temp;
	node* root = NULL; //新建空根节点。 
	bool iscomplete=true;
	int num =0;
	//开始忘记输入n了。 
	scanf("%d",&n); 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		insert(root,temp);
	}
	q.push(root);
	num++;
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		levelorder.push_back(temp->data);
		//printf("%d***%d\n",temp->height,temp->data); 
		if(temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			num++;
		}
		else if(iscomplete==true&&num!=n)
		{
			iscomplete=false;
		}
		if(temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			num++;
		}
		else if(iscomplete==true&&num!=n)
		{
			iscomplete=false;
		}
	}
	int len = levelorder.size();
	for(int i=0;i<len;i++)
	{
		if(i<len-1)
		printf("%d ",levelorder[i]);
		else
		printf("%d\n",levelorder[i]);
	}
	if(iscomplete==false)
	{
		printf("NO\n");
	}
	else
		printf("YES\n");
	return 0;
}

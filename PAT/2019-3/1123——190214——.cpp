//17:46����19:00
///AVl���ĺ��������ܹ�д���������ǲ�����дȫ��
//��ʱ��֪����������ġ�

//�������飬�ҳ����⣺ 
//��ʼ��ת�������棬Ӧ���ȸ���r�߶ȣ��ٸ���temp�߶ȡ���д���ˡ�
//��Ϊtemp���ղ��Ǹ��ڵ㡣 
//Ӧ���ȸ�����������ĸ߶ȣ��ٸ����������ĸ߶ȡ�����´��ˡ�
//��ס�� 
//Ҫ׼ȷ���䣬��Ҫ�ٸ��Լ��㷨����ȷ���ԡ����Ǳ��Ĺ������졣

//�����飬�ַ���һ�����������ϸ��д���ˡ� 
//����ڵ�ĸ��¸߶ȴ��ˡ�Ӧ����
//updateheight(r);
//������
//updateheight��r->lchild) ������������ 
//����д���ˡ�Ӧ���Ǹ���r�����ߡ�����һ�£��϶��ǲ嵽Ҷ�ڵ����
//ֻ��һ��Ҷ�ڵ�ĸ��ڵ����һ�ࡣ

//����󣬻��Ǵ���ġ�������������У�һֱ�ͳ�ʼ����һ����Ϊʲô�أ�
//���ˣ����շ��֣�getbalancefactor()����д���ˡ�д���������ĸ߶�
//���������߶��ˡ�����һ��ɵ�����⡣��ֱ���ϡ�
//����һֱû����ת,��һֱ�ǵ�֧����������������Ҫ�ǳ�׼�� 

//���������һ��ͨ���ˡ���������û�й���
//�����ǣ���ת�����Ĵ��볬��ȥ����������û�б䡣

//������һ��ʼ���Ƿ����ǶԵģ����Ǵ�����䲻�ι̡����������ļ��䶼��
//��ƫ�
//�������д���⣬�������ⱾӦͨ������������Բ������
//�������ͼ����룬���������debug�ķ�����

//�������30�֡�
 
 
 

 
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
//��ʼ��ת�������棬Ӧ���ȸ���r�߶ȣ��ٸ���temp�߶ȡ���д���ˡ� 
void R(node* &r)
{
	//printf("%d������ת��\n",r->data);
	node* temp = r->lchild;
	r->lchild = temp->rchild;
	temp->rchild = r;
	updateheight(r);
	updateheight(temp);
	r=temp; 
}
void L(node* &r)
{
	//printf("%d������ת��\n",r->data);
	node* temp = r->rchild;
	r->rchild = temp->lchild;
	temp->lchild = r;
	updateheight(r);
	updateheight(temp);
	r=temp; 
}

//���ˣ����շ��֣�getbalancefactor()����д���ˡ�д���������ĸ߶�
//���������߶��ˡ�����һ��ɵ�����⡣��ֱ���ϡ� 
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
		//����д���ˡ�Ӧ���Ǹ���r�����ߡ�����һ�£��϶��ǲ嵽Ҷ�ڵ����
		//ֻ��һ��Ҷ�ڵ�ĸ��ڵ����һ�ࡣ 
		updateheight(r);
		if(getbalancefactor(r)==2)
		{
			if(getbalancefactor(r->lchild)==1)
				R(r);
			//���滹Ҫ�ж��Ƿ����-1�������Ҹ��˾����ƺ�û��Ҫ�� 
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
		if(getbalancefactor(r)==-2)  //��ʼ���-2д����2������Ҳ�ǡ� 
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
queue<node*>q;  //������ŵ��ǽ���ָ�롣 
int main()
{
	int n;
	int temp;
	node* root = NULL; //�½��ո��ڵ㡣 
	bool iscomplete=true;
	int num =0;
	//��ʼ��������n�ˡ� 
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

//19:18����
//19:44  25��
//�������ķ�ת������һ��ʼ¼��ʱ���ͽ��еߵ���ÿ��������Ҫ��ת
// 
#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
const int maxn = 12;
int levelorder[maxn];
int levelnum=0;
int inorder[maxn];
int innum =0;
struct Node{
	int left;
	int right;
}node[maxn];
void inorder_tra(int k)
{
	if(k==-1)
	return ;
	inorder_tra(node[k].left);
	inorder[innum++]=k;
	inorder_tra(node[k].right);
	return;	
}
int main()
{
	int n;
	char fir,sec;
	bool isroot[maxn]={false};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		getchar();   //ע�����getchar()��λ�á� 
		scanf("%c %c",&fir,&sec);
		if(fir=='-')
			node[i].right=-1;
		else
		{
			int temp = fir-'0';
			node[i].right = temp;
			isroot[temp]=true;
		}
			
		if(sec=='-')
			node[i].left = -1;
		else
		{
			int temp = sec-'0';
			node[i].left = temp;
			isroot[temp]=true;
		}
	 } 
	 int r;
	 for(int i=0;i<n;i++)
	 {
	 	if(isroot[i]==false)
	 	{
	 		r=i;
	 		break;	
		 }
	 }
	 queue<int>q;
	 q.push(r);
	 while(!q.empty())
	 {
	 	int temp = q.front();
	 	q.pop();
	 	levelorder[levelnum++]=temp;
	 	if(node[temp].left!=-1)
	 	q.push(node[temp].left);
	 	if(node[temp].right!=-1)
	 	q.push(node[temp].right);
	 }
	 inorder_tra(r);
	 for(int i=0;i<n;i++)
	 {
	 	printf("%d",levelorder[i]);
	 	if(i<n-1)
	 	printf(" ");
	 	else
	 	printf("\n");
	 }
	 for(int i=0;i<n;i++)
	 {
	 	printf("%d",inorder[i]);
	 	if(i<n-1)
	 	printf(" ");
	 	else
	 	printf("\n");
	 }
	return 0;	 
 } 

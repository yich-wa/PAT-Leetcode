//09:08--09:36
// sort(va,va+n) ��sort(va,va+maxn)�ǲ�һ���ġ��������ʱ��������Ҫ����ǰ��
//��̬�ģ���ȫ������������������Ǳ������������������ڵ�Ǳ���1�� 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1005;
struct node{
	int left;
	int right;
	int value;
}N[maxn];
int va[maxn];
int num=0;
void inOrder(int s){
	if(s==-1)
		return;
	inOrder(N[s].left);
	N[s].value = va[num++];
//	printf("%d****%d\n",num,va[num]);
	inOrder(N[s].right);
}
int main(){	
	int n;
	scanf("%d",&n);
	int tempV;
	for(int i=0;i<n;i++){
		scanf("%d",&va[i]);
	}
	sort(va,va+n);
	for(int i=1;i<=n;i++){
		if(2*i<=n){
			N[i].left = 2*i;
		}else{
			N[i].left =-1;
		}
		if(2*i+1<=n){
			N[i].right = 2*i+1;
		}else{
			N[i].right = -1;
		}	
	}
	inOrder(1);
	for(int i=1;i<=n;i++){
		if(i!=1){
			printf(" ");
		}
		printf("%d",N[i].value);
		
	}
	return 0;	
}


////��ǰ����
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//#include<queue>
//using namespace std;
//const int maxn = 1005;
//int n;
//int cbst[maxn];
//int inorder[maxn];
//int innum=0;
//void inorder_tra(int a)
//{
//	if(a>n)
//		return ;
//	inorder_tra(a*2);
//	inorder[innum++]=a;
//	inorder_tra(2*a+1);
//}
//int main()
//{	
//	scanf("%d",&n);
//	int ori[maxn];
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&ori[i]); 
//	}
//	sort(ori,ori+n);
//	inorder_tra(1);
//	for(int i=0;i<n;i++)
//	{
//		int seq = inorder[i];
//		cbst[seq]=ori[i];		
//	}
////	queue<int>q;
////	int level[maxn];
////	int levelnum=0;
////	q.push(1);
////	while(!q.empty())
////	{
////		int temp = q.front();
////		q.pop();
////		level[num++]=temp;
////		if(2*temp<=n)
////			q.push(2*temp);
////		if(2*temp+1<=n)
////			q.push(2*temp+1);
////	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d",cbst[i]);
//		if(i<n)
//		printf(" ");
//		else
//		printf("\n");
//	}
//	return 0;	 
//} 

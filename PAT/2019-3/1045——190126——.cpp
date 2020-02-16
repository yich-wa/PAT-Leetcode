//15��15����
//2 2 1 5 5 6 3 1 1 5 6 
//16:03   �� 24�֣�6�ֳ�ʱ�� �Լ�д��ʱ����õ���������������㷨
//��û�������̬�滮�������� 

//�����еĶ�̬�滮�������˵�����21�֡�1���𰸴���2���δ���
//��֪dp�����С��С�ˡ�����27�ֻ���3�ִ𰸴���
 
//��������ֻ��һ����Ч��ɫʱ����Ӧ����1������0�� 
//��ʼ�����������ȣ������ڲ�forѭ���У�������ǵ�numΪ1ʱ��ans�޷�
//���£����±�Ӧ��1�Ľ����Ϊ0
//����ԭ����ôд���ǳ���Ч�� 
//

//��̬�滮��һ��Ҫע�⣺״̬����ơ�״̬ת�Ʒ��̵���ơ��߽� 
//������ж���˼·��
//��һ����½������� ����ֱ�۵ĵķ��� 
//�ڶ� �������������
//������DFS����ò���ȫ�֡� 

//����������е�д���� 
//����д����ע�⣺�������е���������Ǵ�1��ʼ��
// ��dp[i][j]�Ǵ�0��ʼ��ʼ���ģ���֤dp[0][j-1]��dp[i-1][0] ������ 

//������д����6��,��������Ϊ�����ѭ����˳��ŷ��ˡ�
//��������Ӧ�����ڶ�ά��Ӧ���ڲ�forѭ�����̵�����Ӧ������һά��
//�����forѭ�� 
//���ó���ľֲ���ԭ��
//�����30�֡��������������� 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn =202;
const int maxl = 10010;
bool isfav[maxn]={false};
int favorder[maxn];
int stripe[maxl];
int num =1;
int dp[maxl][maxl];//��ֹ��iλ�ã�����½������еĳ��ȡ�
//dp[i][j]������A����iλ�ã�B����jλ�� 

int main()
{
	int n,l,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&favorder[i]);
		isfav[favorder[i]]=true;
		dp[i][0]=0; 
	} 
	int tempc;
	scanf("%d",&l);
	for(int i=1;i<=l;i++)
	{
		scanf("%d",&tempc);
		if(isfav[tempc]==true)
		{
			dp[0][num]=0;
			stripe[num++]=tempc;
		}
	}
	dp[0][0]=0;
	num--;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=num;j++)
		{
			int tempmax = max(dp[i][j-1],dp[i-1][j]);
			if(stripe[j]==favorder[i])
			{
				dp[i][j]=tempmax+1;
			}
			else
			{
				dp[i][j]=tempmax;
			}
		}
	}
	printf("%d\n",dp[m][num]);
	return 0;
}

////����½������С� 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn =202;
//const int maxl = 10010;
//bool isfav[maxn]={false};
//int favorder[maxn];
//int favseq[maxn];
//int stripe[maxl];
//int num =0;
//int dp[maxl];//��ֹ��iλ�ã�����½������еĳ��ȡ� 
//int main()
//{
//	int n,l,m;
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&favorder[i]);
//		isfav[favorder[i]]=true;
//		favseq[favorder[i]]=i;//����ԽС��λ��Խ��ǰ�� 
//	}
//	int tempc;
//	scanf("%d",&l);
//	for(int i=0;i<l;i++)
//	{
//		scanf("%d",&tempc);
//		if(isfav[tempc]==true)
//		{
//			stripe[num++]=tempc;
//		}
//	}
//	fill(dp,dp+maxn,1);
//	int ans =0;
//	for(int i=0;i<num;i++)
//	{
//		for(int j=0;j<i;j++)
//		{
//			if(favseq[stripe[i]]>=favseq[stripe[j]]&&dp[i]<dp[j]+1)
//			{
//				dp[i]=dp[j]+1;	
//			}
//		}
//		//��ʼ���������ڲ�forѭ���У�������ǵ�numΪ1ʱ��ans�޷�
//		//���£����±�Ӧ��1�Ľ����Ϊ0
//		//����ԭ����ôд���ǳ���Ч�� 
//		ans = max(ans,dp[i]); 
//	}
//	printf("%d\n",ans);
//	return 0;
//}


//DFSд�� 
//#include<stdio.h>
//const int maxn =202;
//const int maxl = 10010;
//bool isfav[maxn]={false};
//int favorder[maxn];
//int favseq[maxn];
//int stripe[maxl];
//int preid=0;
//int tempnum=0;
//int num =0;
//int maxnum=-1;
//void DFS(int a,int tempnum,int preid)
//{
//	//printf("%d\n",a);
//	if(a==num)
//	{
//		if(tempnum>maxnum)
//			maxnum = tempnum;
//		return;
//	}
//	if(favseq[stripe[a]]==preid)
//	{
//		DFS(a+1,tempnum+1,preid);
//	}
//	else if(favseq[stripe[a]]>preid)
//	{
//		DFS(a+1,tempnum+1,favseq[stripe[a]]);//��������  
//		DFS(a+1,tempnum,preid);  //���������С� 
//	}
//	else
//	{
//		DFS(a+1,tempnum,preid);//������ 
//	}	
//}
//int main()
//{
//	int n,l,m;
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&favorder[i]);
//		isfav[favorder[i]]=true;
//		favseq[favorder[i]]=i;//����ԽС��λ��Խ��ǰ�� 
//	}
//	favseq[0]=0;
//	int tempc;
//	scanf("%d",&l);
//	for(int i=0;i<l;i++)
//	{
//		scanf("%d",&tempc);
//		if(isfav[tempc]==true)
//		{
//			stripe[num++]=tempc;
//		}
//	}
//	//printf("%d\n",num);
//	
//	DFS(0,0,0);
//	printf("%d\n",maxnum);
//	return 0;
//}

////��ǰд�� 
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn=10010;
//int fa[maxn];
//int given[maxn];
//int dp[maxn];
//int ad[maxn]={0};//��¼given[maxn]��ÿ��������fa[maxn]�еļ���λ�������ڵĻ�����Ϊ0��
//int n,m,l;
//int find(int ai,int i)
//{
//	int d=1;
//	if(i>1)
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(ad[given[j]]<=ad[ai]&&d<dp[j]+1)  //�˴�û��ӳ���Ϊ���ӡ�����ϸ���****
//				d=dp[j]+1;
//		}
//	}
//	return d;
//}
//int main()
//{
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d",&fa[i]);
//		ad[fa[i]]=i;   //��������ӳ�䣬******���е���ʾ,������ʱ���γ�ӳ�䡣
//	}
//	scanf("%d",&l);
//	int res=0;      //*****8****�տ�ʼ���ǳ�ʼ��Ϊ0�ˣ��������ֵΪ���ֵַ���ǳ��ǳ����һ��ֵ��
//	int num=1;
//	int g;
//	for(int i=1;i<=l;i++)
//	{
//		scanf("%d",&g);
//		if(ad[g]>0)  //Ҫ��ad[maxn]��ʼ��Ϊ0�����µ�ֵ���������ܹ�����ϲ������ɫ��
//		 {
//			given[num]=g;
//			dp[num]=find(g,num);
//			res=max(res,dp[num]);
//			num++;
//		}
//	}
//	printf("%d\n",res);
//	return 0;
//}

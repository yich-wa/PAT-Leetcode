//16:52����17:17 22��3�ֶδ���
//��������ͼ���о��õĿռ��е�࣬�ǲ��ǳ��ڴ��ˡ� 
//����飬��ʼfill����û�м��ء�algorithm"ͷ�ļ��� �������������
//���⡣

// �������⣺ 
//����֣�Ϊʲô��G[maxn][maxn]���嵽����������ͻ�δ���
//�ĵ�����������͹��ˡ�
//���ǲ��ú���ǰ�Ĵ𰸶��գ��Գ����ġ�����Ϊʲô�أ� 
//

//���������������õ���ջ�ռ������ڴ档 
//��ջ�ռ����ڽ��̴���ʱ��ʼ���ģ���С��ϵͳ�̶��ġ�
//���Զ���ռ�ýϴ��ڴ�ı�����������飩ʱ��
//�������ͨ���������в��ˡ�
//����������ջ�ڴ��У����ռ�������ڶ��ڴ���������java�� 
//�����ڶ������ջ�ڴ沿�֡�//��̬�������ӵ��ڶ��ڴ档 

//�������ǰѱ����Ķ�����ں���������ʱ��
//��������ڴ����������ݶΣ��ڴ��С������䣬
//�����������������Կ����ر��
//ȫ�ֱ������ھ�̬�洢���� 
#include<stdio.h>
#include<algorithm> 
using namespace std;
const int maxn = 202;
int main()
{
	int G[maxn][maxn]={0};
	int n,m;
	scanf("%d%d",&n,&m);
	int edge1,edge2;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&edge1,&edge2);
		G[edge1][edge2]=1;
		G[edge2][edge1]=1;
	}
	int k;
	scanf("%d",&k);
	int nv;
	int path[maxn];
	bool ischeck[maxn]={false};
	for(int i=0;i<k;i++)
	{
		scanf("%d",&nv);
		fill(ischeck,ischeck+maxn,false);
		bool isout=false; 
		for(int j=0;j<nv;j++)
		{
			scanf("%d",&path[j]);
			ischeck[path[j]]=true;
		}
		for(int j=1;j<=n;j++)
		{
			if(ischeck[j]==false)
			{
				isout=true;
				break;
			}
		}
		if(isout==true)
			printf("NO\n");
		else if(nv!=n+1)  //�������ˡ� 
			printf("NO\n");
		else if(path[0]!=path[nv-1]) //��β����ͬ�� 
			printf("NO\n");
		else
		{
			for(int j=0;j<n;j++)
			{
				if(G[path[j]][path[j+1]]==0)
				{
					printf("NO\n");
					isout=true;
					break;
				}
			}
			if(isout==false)
				printf("YES\n");
		}
	 } 
	 return 0;
}

//25��������

//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 205;
//int main()
//{
//	int G[maxn][maxn]={0};
//	int n,m;
//	bool present[maxn]={false};
//	scanf("%d%d",&n,&m);
//	int u,v;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&u,&v);
//		G[u][v]=1;
//		G[v][u]=1;
//	}
//	int k;
//	int query[maxn];
//	scanf("%d",&k);
//	int num;
//	for(int i=0;i<k;i++)
//	{
//		bool isham =true;
//		fill(present,present+maxn,false);
//		scanf("%d",&num);
//		for(int j=0;j<num;j++)
//		{
//			scanf("%d",&query[j]);
//			present[query[j]]=true;
//		}
//		for(int j=1;j<=n;j++)
//		{
//			if(present[j]==false)
//			isham =false;
//		}
//		if(isham==false)
//		printf("NO\n");	
//		else if(num!=n+1)
//		printf("NO\n");
//		else if(query[0]!=query[n])
//		printf("NO\n");
//		else
//		{
//			bool flag =true;
//			for(int j=0;j<num-1;j++)
//			{
//				if(G[query[j]][query[j+1]]==0)
//				{
//					printf("NO\n");
//					flag=false;
//					break;
//				}
//			}
//			if(flag==true)
//			{
//				printf("YES\n");
//			}
//		}
//	}
//	return 0;
//}

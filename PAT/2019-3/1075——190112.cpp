//ϸ�����⡣�����һ���鷳�����ܲ������������push��ȥ��
//������ŷ��档���sort����ʱ��ϸ�ڣ�ע����ʼ���ޡ� 
//�ύ��ֻ��6�֡�����һ�����Ƶ�ϸ�ں��ӵ��ˡ�
//û���ύ�óɼ������'-'���ύ��ʹû��������Ҳ��0�� 
//�ύ��ʹû�������� ��Ҳ���㡣
//�ò����߱������ǰ�����ύ���ɹ�ͨ�����������⡣ 
//���˶���22�֡��������һ�����Ե�3�ִ𰸴���
//����˵���һ�����Ե����һ�������ύ���� ��
//���黹���ȡ�����ûͨ�������ʼ������ʹǰ���¼��ʧ���¡�
//���Ծ�����Ҫ������������Ϊ����ʼ�����ض������������������Ϳ�
//��ʡʱ�䡣�����ز��ã���ʼ��������������ϵ������
//������ÿһ����Ϊ�����Ľ��޵�����ʲô�����ľ�������Ķ���������� 
//���������������޾����Ƿ����
//����ˣ��Լ������'-' 

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
struct testee{
	int id;
	int p[7];
	bool pcheck[7];  //���Ƹ���ɼ������� 
	int rank;
	int check;   //���Ƹò������䲻��� 
	int total;
	int count;
}T[maxn];
bool cmp1(testee a,testee b)
{
	if(a.check!=b.check)
		return a.check>b.check;
	else if(a.total!=b.total)
		return a.total>b.total;
	else if(a.count!=b.count)
		return a.count>b.count;
	else
		return a.id<b.id;		
}
int main(){
	int n,k,m;
	int pro_full[10];
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;i++)
		scanf("%d",&pro_full[i]);
	//��ʼ�������ŵ����棬���������ų�ʼ�����ܻ�����⡣ 
	for(int i=1;i<=n;i++)   
	{ 
		T[i].check=0;
		for(int j=1;j<=k;j++)
		{
			T[i].pcheck[j]=false;
			T[i].p[j]=0;
		}
		T[i].total =0;	
		T[i].count =0;
		T[i].id =i;
	} 
	for(int i=0;i<m;i++)
	{
		int tempid;
		int pid;
		int pscore;
		scanf("%d %d %d",&tempid,&pid,&pscore);
		if(pscore>=0)
		{
			
			T[tempid].check=1;	
			if(pscore>T[tempid].p[pid])
			{
				T[tempid].p[pid]=pscore;
			}
		}
		//ֻҪ�й��ύ���������Ϊtrue ��
		//�þ�Ҫ�ŵ���ʼ���󣬲�Ȼ�ֻᱻ�ĳ�false; 
		//�����û���һ���ύûͨ�����룬��Ȼ����ĳ���true;
		//�������û��ٴ��ύ�ɹ�ʱ���Ž��г�ʼ������Ѹոյ�true
		//��ʼ������false�����Ի��ǰѳ�ʼ�������ȥ�ȽϺá�
		//�ͻᵼ�����´��� 
		//		4 2 2
		//		10 20
		//		1 1 -1
		//		1 2 2
		//		1 00001 2 - 2 
		T[tempid].pcheck[pid]=true;	 	
	}
	for(int i=1;i<=n;i++)
	{
		//printf("%d\n",T[i].check);
		if(T[i].check==1)
		{
			for(int j=1;j<=k;j++)
			{
				T[i].total +=T[i].p[j];
				if(T[i].p[j]==pro_full[j])
					T[i].count++;
			}		
		}
	}
	//�����һ��ʼ i��ȡ��1-n���ģ�������������Ҫע�⡣
	//ϸ�����⡣ 
	sort(T+1,T+n+1,cmp1);
	int lastrank =-1;
	int lasttotal =-1;
	for(int i=1;i<=n;i++)
	{
		//printf("%d\n",T[i].check);
		if(T[i].check==0)
			break;
		if(T[i].total==lasttotal)
		{
			T[i].rank =lastrank;
		}
		else
		{
			T[i].rank =i;
			lastrank =i;
			lasttotal = T[i].total;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(T[i].check==0)
			break;
		printf("%d %05d %d",T[i].rank,T[i].id,T[i].total);
		for(int j=1;j<=k;j++)
		{
			if(T[i].pcheck[j]==false)
				printf(" -");
			else
				printf(" %d",T[i].p[j]);
		}
		printf("\n");
	}
	return 0;	
}


//����Ϊ21������ 
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 10010;
//struct testee{
//	int id;
//	int p[7];
//	bool pcheck[7];  //���Ƹ���ɼ������� 
//	int rank;
//	int check;   //���Ƹò������䲻��� 
//	int total;
//	int count;
//}T[maxn];
//bool cmp1(testee a,testee b)
//{
//	if(a.check!=b.check)
//		return a.check>b.check;
//	else if(a.total!=b.total)
//		return a.total>b.total;
//	else if(a.count!=b.count)
//		return a.count>b.count;
//	else
//		return a.id<b.id;		
//}
//int main(){
//	int n,k,m;
//	int pro_full[10];
//	scanf("%d%d%d",&n,&k,&m);
//	for(int i=1;i<=k;i++)
//		scanf("%d",&pro_full[i]);
//	for(int i=1;i<=n;i++)
//		T[i].check=0;
//	for(int i=0;i<m;i++)
//	{
//		int tempid;
//		int pid;
//		int pscore;
//		scanf("%d %d %d",&tempid,&pid,&pscore);
//		if(pscore>=0)
//		{
//			T[tempid].id =tempid;
			//��ʼ����Ч������ʼ���Ľ��޲�����Ӧ��Ӧ�ñ�����
			//������û���ύ��������û��ͨ���������� 
//			if(T[tempid].check==0)    
//			{
//				for(int j=1;j<=k;j++)
//				{
//					T[tempid].pcheck[j]=false;
//					T[tempid].p[j]=0;
//				}
//				T[tempid].total =0;	
//				T[tempid].count =0;
//				T[tempid].check=1;	
//			}
//			if(pscore>T[tempid].p[pid])
//			{
//				T[tempid].p[pid]=pscore;
//			}
//		}
//		//ֻҪ�й��ύ���������Ϊtrue ��
//		//�þ�Ҫ�ŵ���ʼ���󣬲�Ȼ�ֻᱻ�ĳ�false; 
//		//�����û���һ���ύûͨ�����룬��Ȼ����ĳ���true;
//		//�������û��ٴ��ύ�ɹ�ʱ���Ž��г�ʼ������Ѹոյ�true
//		//��ʼ������false�����Ի��ǰѳ�ʼ�������ȥ�ȽϺá�
//		//�ͻᵼ�����´��� 
////		4 2 2
////		10 20
////		1 1 -1
////		1 2 2
////		1 00001 2 - 2 
//		T[tempid].pcheck[pid]=true;	 	
//	}
//	for(int i=1;i<=n;i++)
//	{
//		//printf("%d\n",T[i].check);
//		if(T[i].check==1)
//		{
//			for(int j=1;j<=k;j++)
//			{
//				T[i].total +=T[i].p[j];
//				if(T[i].p[j]==pro_full[j])
//					T[i].count++;
//			}		
//		}
//	}
//	//�����һ��ʼ i��ȡ1-n�ģ�������������Ҫע�⡣
//	//ϸ�����⡣ 
//	sort(T+1,T+n+1,cmp1);
//	int lastrank =-1;
//	int lasttotal =-1;
//	for(int i=1;i<=n;i++)
//	{
//		//printf("%d\n",T[i].check);
//		if(T[i].check==0)
//			break;
//		if(T[i].total==lasttotal)
//		{
//			T[i].rank =lastrank;
//		}
//		else
//		{
//			T[i].rank =i;
//			lastrank =i;
//			lasttotal = T[i].total;
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(T[i].check==0)
//			break;
//		printf("%d %05d %d",T[i].rank,T[i].id,T[i].total);
//		for(int j=1;j<=k;j++)
//		{
//			if(T[i].pcheck[j]==false)
//				printf(" -");
//			else
//				printf(" %d",T[i].p[j]);
//		}
//		printf("\n");
//	}
//	return 0;	
//}

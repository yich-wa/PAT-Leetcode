//15:56--16:41 
// ��6�֡� ʣ�µĴ𰸴��� 
//���֣�ϸ�ڴ���û���ύ�������"-"���ύûͨ�����룬����ʾ����
//"-1"���������"0"��������"-1"�� ����Ľ�ָͷ��һ�룬��ô�������������
 //���� ������������Ĺ��ס� 
//--16:58 �õ�ȫ�֡� 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
struct user{
	int id;
	int s[6];
	int total;
	int rank; 
	int ps;
	int isOut;
	user(){
		total = 0;
		isOut = 0;
		ps= 0;
		for(int i=0;i<6;i++){
			s[i]=-2;
		}
	}
}U[maxn];
bool cmp(user a,user b){
	if(a.isOut!=b.isOut){
		return a.isOut>b.isOut;
	}else if(a.total!=b.total){
		return a.total>b.total;
	}else if(a.ps!=b.ps){
		return  a.ps>b.ps;
	}else{
		return a.id<b.id;
	}
}
int main(){
	int n,k,m;
	int p[10];
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&p[i]);
	}
	int uId,pId,tempS;	
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&uId,&pId,&tempS);
		if(U[uId].s[pId]<tempS){
			U[uId].s[pId]=tempS;
			if(p[pId]==tempS){
				U[uId].ps++;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		U[i].id = i;
		for(int j=1;j<=k;j++){
			if(U[i].s[j]>0)
				U[i].total+=U[i].s[j];
			if(U[i].isOut==0&&U[i].s[j]>-1){
				U[i].isOut = 1;
			}
		}
	}
	sort(U+1,U+n+1,cmp);
	int lastRank ;
	int lastTotal = -1;
	for(int i=1;i<=n;i++){
		if(U[i].total!=lastTotal){
			lastTotal = U[i].total;
			U[i].rank = i;
			lastRank = U[i].rank;
		}else{
			U[i].rank = lastRank;
		}
		if(U[i].isOut==1){
			printf("%d %05d %d",U[i].rank,U[i].id,U[i].total);
			for(int j=1;j<=k;j++){
				if(U[i].s[j]==-2){
					printf(" -");
				}else if(U[i].s[j]==-1){
					printf(" 0");
				}else{
					printf(" %d",U[i].s[j]);
				}
			}
			printf("\n");
		}else{
			break;
		}
	}
	return 0;
}

//
////��ǰд��
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
//	//��ʼ�������ŵ����棬���������ų�ʼ�����ܻ�����⡣ 
//	for(int i=1;i<=n;i++)   
//	{ 
//		T[i].check=0;
//		for(int j=1;j<=k;j++)
//		{
//			T[i].pcheck[j]=false;
//			T[i].p[j]=0;
//		}
//		T[i].total =0;	
//		T[i].count =0;
//		T[i].id =i;
//	} 
//	for(int i=0;i<m;i++)
//	{
//		int tempid;
//		int pid;
//		int pscore;
//		scanf("%d %d %d",&tempid,&pid,&pscore);
//		if(pscore>=0)
//		{
//			
//			T[tempid].check=1;	
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

//15:56--16:41 
// 得6分。 剩下的答案错误。 
//后发现，细节错误。没有提交过是输出"-"。提交没通过编译，输入示意是
//"-1"。但输出是"0"，而不是"-1"。 用你的脚指头想一想，怎么会输出，负数呢
 //考察 审题和理解题意的功底。 
//--16:58 拿到全分。 
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
////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 10010;
//struct testee{
//	int id;
//	int p[7];
//	bool pcheck[7];  //控制该项成绩输出输出 
//	int rank;
//	int check;   //控制该测试者输不输出 
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
//	//初始化尽量放到外面，与输入结合着初始化可能会出问题。 
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
//		//只要有过提交，该项即被设为true ；
//		//该句要放到初始化后，不然又会被改成false; 
//		//若该用户第一次提交没通过编译，虽然这个改成了true;
//		//待到该用户再次提交成功时，才进行初始化，则把刚刚的true
//		//初始化成了false；所以还是把初始化都提出去比较好。
//		//就会导致如下错误 
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
//	//这道题一开始 i是取1-n的，所以下面的序号要注意。
//	//细节问题。 
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

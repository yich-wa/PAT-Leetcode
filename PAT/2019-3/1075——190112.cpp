//细节问题。这道题一稍麻烦，不能采用向量逐个，push进去。
//采用序号方面。其次sort排序时有细节，注意起始界限。 
//提交后只有6分。发现一个很绕的细节忽视掉了。
//没有提交该成绩才输出'-'，提交即使没过编译器也是0； 
//提交即使没过编译器 ，也是零。
//该测试者被输出的前提是提交过成功通过编译器的题。 
//至此对了22分。还有最后一个测试点3分答案错误。
//网上说最后一个测试点存在一道题多次提交满分 ，
//经查还是先“编译没通过”后初始化，致使前面记录消失所致。
//所以尽量不要自作聪明，以为将初始化和特定的输入输出结合起来就可
//以省时间。。慎重采用：初始化和输入输出相结合的情况。
//《分清每一个行为发生的界限到底是什么》考的就是你的阅读理解能力。 
//。。本题两个界限就是是否输出
//这个人，以及输出：'-' 

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
struct testee{
	int id;
	int p[7];
	bool pcheck[7];  //控制该项成绩输出输出 
	int rank;
	int check;   //控制该测试者输不输出 
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
	//初始化尽量放到外面，与输入结合着初始化可能会出问题。 
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
		//只要有过提交，该项即被设为true ；
		//该句要放到初始化后，不然又会被改成false; 
		//若该用户第一次提交没通过编译，虽然这个改成了true;
		//待到该用户再次提交成功时，才进行初始化，则把刚刚的true
		//初始化成了false；所以还是把初始化都提出去比较好。
		//就会导致如下错误 
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
	//这道题一开始 i是取（1-n）的，所以下面的序号要注意。
	//细节问题。 
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


//下面为21分做法 
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
			//初始化有效化，初始化的界限并不是应不应该被排序
			//而是有没有提交，无论有没有通过编译器。 
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

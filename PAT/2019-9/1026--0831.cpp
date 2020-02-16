//16:18-- 17:46  的26分 
//有2个答案错误。4分。考虑性价比，先战略性放弃。
//时间比较复杂，仍旧是类似多窗口排队问题。选窗口和候选人。
//如果有类似于vip的特殊情况的话。那尽量：多用if语句分情况讨论。 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 10005;
const int maxt = 101;
struct player{
	int aTime;
	int pTime;
	int sTime;
	int tag;
	int wTime;
}tempP;
vector<player>P;
struct table{
	int cTime;
	int num;
	int isV;
	table(){
		cTime = 8*3600;
		num =0;
		isV = 0;
	}
}T[maxt];
bool cmp(player a, player b){
	return a.aTime<b.aTime;
}
bool cmp1(player a , player b){
	return a.sTime<b.sTime;
} 
int main(){
	int n;
	int hh,mm,ss,pt,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&pt,&t);
		tempP.aTime = hh*3600+mm*60+ss;
		if(pt>120)
			pt = 120;
		tempP.pTime = pt; 
		tempP.sTime = -1;
		tempP.tag = t;
		P.push_back(tempP);
	}
	sort(P.begin(),P.begin()+P.size(),cmp);
	int k,m;
	scanf("%d%d",&k,&m);
	int v_Id;
	for(int i=0;i<m;i++){
		scanf("%d",&v_Id);
		T[v_Id].isV = 1;
	}
	for(int i=0;i<n;i++){
		int num =0;
		while(P[num].sTime!=-1&&num<n){
			num++;
		}
		int now_t = P[num].aTime;
		int eTableTime = 24*3600; 
		int eTableId;
		for(int j= 1;j<=k;j++){
			if(eTableTime>T[j].cTime){
				eTableTime = T[j].cTime;
				eTableId = j;
			}
		}
		//来的时候有空桌子 
		if(eTableTime<=now_t){
			//这个还要判断这个球员是不是会员。是的话。看还有没有其他空闲
			//会员桌子。
			if(P[num].tag==1&&T[eTableId].isV==0){
				for(int j=1;j<=k;j++){
					if(T[i].cTime<now_t&&T[i].isV==1){
						eTableId = j;
						break;
					}
				}	
			}
			P[num].wTime = 0;
			P[num].sTime = now_t; 
			if(P[num].sTime<21*3600)
				T[eTableId].num++;
			T[eTableId].cTime = now_t+P[num].pTime*60;
		}else{
			//来的时候没有空桌子。以第一个有空的球桌为标准 
			//去找，对应的球员。
			//如果不是会员桌子 
			if(T[eTableId].isV ==0){
				P[num].wTime = eTableTime-now_t;
				P[num].sTime = eTableTime; 
				if(P[num].sTime<21*3600)
				{
					T[eTableId].num++;	
				}
				T[eTableId].cTime = eTableTime+P[num].pTime*60;
			}else{
				//如果是会员桌子。看看之前的队列里面有没有会员球员 
				//有的话更新处理会员的编号。 
				for(int j= num;j<n;j++){
					if(P[j].sTime==-1&&P[j].aTime<eTableTime&&P[j].tag==1){
						num =j;
						break;
					}
					if(P[j].aTime>eTableTime){
						break;
					}
				} 
				P[num].wTime = eTableTime-P[num].aTime;
				P[num].sTime = eTableTime; 
				if(P[num].sTime<21*3600){
					T[eTableId].num++;	
				}
				T[eTableId].cTime = eTableTime+P[num].pTime*60;
			} 
		} 
		//来的时候没有空桌子		
	}
	sort(P.begin(),P.begin()+P.size(),cmp1);
	for(int i=0;i<n;i++){
		if(P[i].sTime<21*3600){
			int hh1 = P[i].aTime/3600;
			int mm1 = P[i].aTime%3600/60;
			int ss1 = P[i].aTime%60;
			int hh2 = P[i].sTime/3600;
			int mm2 = P[i].sTime%3600/60;
			int ss2 = P[i].sTime%60;
			int wt = round(P[i].wTime*1.0/(60*1.0));
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",hh1,mm1,ss1,hh2,mm2,ss2,wt);
		}	
	} 
	for(int i=1;i<=k;i++){
		if(i!=1)
			printf(" ");
		printf("%d",T[i].num);
	}
	return 0;
}

////之前写的：
//#include<stdio.h>
//#include<algorithm>
//#include<queue>
//#include<vector>
//using namespace std;
//const int maxn =10005;
//const int maxk =105;
//struct player{
//	int atime;
//	int ptime;
//	int wtime;
//	int stime;
//	int tag;
//	bool served;
//}P[maxn]; 
//struct table{
//	int begintime;
//	int number;
//	int vtag;
//}T[maxk];
//bool cmp(player a,player b)
//{
//	return a.atime<b.atime;
//}
//bool cmp2(player a,player b)
//{
//	return a.stime<b.stime;
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int temph,tempm,temps,temp_p_time;
//	int temptag;
//	int tempa;
//	queue<int>vipq;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d:%d:%d %d %d",&temph,&tempm,&temps,&temp_p_time,&temptag);
//		tempa = temph*3600+tempm*60+temps;
//		if(temp_p_time>2*60)
//		{
//			temp_p_time =2*60;
//		 } 
//		P[i].atime = tempa;
//		P[i].ptime=temp_p_time;
//		P[i].tag=temptag;
//		P[i].served=false;
//	}
//	sort(P,P+n,cmp);
//	for(int i=0;i<n;i++)
//	{
//		if(P[i].tag==1)
//		vipq.push(i);
//	}
//	int m,k,tempvip;
//	scanf("%d%d",&k,&m);
//	for(int i=1;i<=k;i++)
//	{
//		T[i].begintime = 8*3600;
//		T[i].number=0;
//		T[i].vtag =0;
//	}
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d",&tempvip);
//		T[tempvip].vtag=1;
//	}
//	int count =0;//处理的人数 
//	int num=0;//正常队列轮到谁了。 
//	while(count<n)
//	{
//		int early_time=21*3600;
//		int early_id;
//		for(int i=1;i<=k;i++)  //挑出最早可以服务的台球桌。 
//		{
//			if(T[i].begintime<early_time)
//			{
//				early_time = T[i].begintime;
//				early_id=i;
//			}
//		}
//		if(early_time>=21*3600) //可以闭馆，不接待玩家了 
//			break;
//		bool ishandle =false;
//		if(T[early_id].vtag==1)
//		{
//			if(!vipq.empty())
//			{
//				int temp = vipq.front();
//				//即已经存在vip会员等在队列里。
//				//否则按顺序去处理将要来的玩家，普通玩家，和会员玩家都有可能	 
//				if(T[early_id].begintime>=P[temp].atime) 
//				{
//					P[temp].stime=T[early_id].begintime;
//					P[temp].wtime = P[temp].stime-P[temp].atime;
//					if(P[temp].wtime%60>=30)
//						P[temp].wtime = P[temp].wtime/60+1;
//					else
//						P[temp].wtime = P[temp].wtime/60; 
//					T[early_id].begintime +=P[temp].ptime*60;
//					P[temp].served=true;
//					vipq.pop(); 
//					count++;
//					ishandle=true;
//					T[early_id].number++;
//				}
//			} 
//			if(ishandle==false)
//			{
//				while(P[num].served==true)
//				{
//					num++;
//				}
//				if(P[num].tag==1)  //要处理的是vip玩家的话，处理会员队列 
//				{
//					vipq.pop();
//				} 		 
//			}	 
//		} 
//		else   //如果不是vip球桌。 
//		{
//			while(P[num].served==true)
//			{
//				num++;
//			}	
//			//要处理的是vip玩家的话，处理会员队列
//			//看等待的球桌里面有没有vip球桌。
//			//有、就有可能将球桌更新。 
//			if(P[num].tag==1)   
//			{
//				 vipq.pop();//单独的vip会员队列 ，弹出一个。 
//				for(int i=1;i<=k;i++)   
//				//若此刻有多个空闲球桌，且有一个是vip球桌。 
//				//此举可能会产生更新球桌的举动 
//				//看"此刻"除了该空闲球桌外，
//				//还有没有vip球桌。 
//				{
//					//如果有vip球桌和刚选出的最早空闲球桌同时空闲
//					//或者在该会员来之前，会有vip球桌空下来。
//					//则将vip球桌分配给他。 
//					//没有的话，还是将最早空闲球桌分配给该vip球员
//					if(T[i].vtag==1&&(T[i].begintime<=early_time||T[i].begintime<=P[num].atime))
//					{
//						early_time = T[i].begintime;
//						early_id=i;
//						break; 
//					}
//				}		 	
//			} 	
//		}
//		if(ishandle == false)
//		{
//			if(T[early_id].begintime<P[num].atime) //玩家不用等 
//			{
//				P[num].wtime=0;
//				P[num].stime = P[num].atime;	
//				T[early_id].begintime= P[num].atime+P[num].ptime*60;
//			}
//			else  //玩家还要等。 
//			{
//				P[num].stime = T[early_id].begintime;
//				P[num].wtime = T[early_id].begintime-P[num].atime;
//				if(P[num].wtime%60>=30)
//					P[num].wtime = P[num].wtime/60+1;
//				else
//					P[num].wtime = P[num].wtime/60; 
//				T[early_id].begintime +=P[num].ptime*60;
//			}
//			P[num].served=true;
//			num++;
//			count++;
//			T[early_id].number++;
//		 } 	
//	}
//	sort(P,P+n,cmp2);
//	for(int i=0;i<n;i++)
//	{
//		if(P[i].served==true)
//		{
//		printf("%02d:%02d:%02d ",P[i].atime/3600,P[i].atime/60%60,P[i].atime%60);
//		printf("%02d:%02d:%02d ",P[i].stime/3600,P[i].stime/60%60,P[i].stime%60);
//		printf("%d\n",P[i].wtime);
//		}
//	}
//	for(int i=1;i<=k;i++)
//	{
//		printf("%d",T[i].number);
//		if(i<k)
//		printf(" ");
//	}
//	return 0;
//} 

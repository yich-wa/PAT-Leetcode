//09:54
//灵活设置指标 ，要有面向对象的思想。
// 提交 后24分。 6分答案错误
//11:17
//面向对象的 语言是对的。起码是有玩家对象，和球桌对象。

//190227 通过看柳诺的答案，发现自己有一个思路给忘记了。
//当空闲桌子不是vip桌子时，如果队首的成员是普通人，那么
//将该桌分给他，
//如果是vip会员，找此时，还有没有空闲vip球桌。若有会有可能
//更新当下球桌。 
// 改完后28分。  第3测试点错误。 

//剩下2分暂时放弃，关键在于你将事件想的清清楚楚。 
///每个分叉口是怎么样的。
//这道题仍旧属于简单模拟。 对事件的还原模拟。清晰的就像自己在玩这件
//事一样。 
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn =10005;
const int maxk =105;
struct player{
	int atime;
	int ptime;
	int wtime;
	int stime;
	int tag;
	bool served;
}P[maxn]; 
struct table{
	int begintime;
	int number;
	int vtag;
}T[maxk];
bool cmp(player a,player b)
{
	return a.atime<b.atime;
}
bool cmp2(player a,player b)
{
	return a.stime<b.stime;
}
int main()
{
	int n;
	scanf("%d",&n);
	int temph,tempm,temps,temp_p_time;
	int temptag;
	int tempa;
	queue<int>vipq;
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d %d",&temph,&tempm,&temps,&temp_p_time,&temptag);
		tempa = temph*3600+tempm*60+temps;
		if(temp_p_time>2*60)
		{
			temp_p_time =2*60;
		 } 
		P[i].atime = tempa;
		P[i].ptime=temp_p_time;
		P[i].tag=temptag;
		P[i].served=false;
	}
	sort(P,P+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(P[i].tag==1)
		vipq.push(i);
	}
	int m,k,tempvip;
	scanf("%d%d",&k,&m);
	for(int i=1;i<=k;i++)
	{
		T[i].begintime = 8*3600;
		T[i].number=0;
		T[i].vtag =0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&tempvip);
		T[tempvip].vtag=1;
	}
	int count =0;//处理的人数 
	int num=0;//正常队列轮到谁了。 
	while(count<n)
	{
		int early_time=21*3600;
		int early_id;
		for(int i=1;i<=k;i++)  //挑出最早可以服务的台球桌。 
		{
			if(T[i].begintime<early_time)
			{
				early_time = T[i].begintime;
				early_id=i;
			}
		}
		if(early_time>=21*3600) //可以闭馆，不接待玩家了 
			break;
		bool ishandle =false;
		if(T[early_id].vtag==1)
		{
			if(!vipq.empty())
			{
				int temp = vipq.front();
				//即已经存在vip会员等在队列里。
				//否则按顺序去处理将要来的玩家，普通玩家，和会员玩家都有可能	 
				if(T[early_id].begintime>=P[temp].atime) 
				{
					P[temp].stime=T[early_id].begintime;
					P[temp].wtime = P[temp].stime-P[temp].atime;
					if(P[temp].wtime%60>=30)
						P[temp].wtime = P[temp].wtime/60+1;
					else
						P[temp].wtime = P[temp].wtime/60; 
					T[early_id].begintime +=P[temp].ptime*60;
					P[temp].served=true;
					vipq.pop(); 
					count++;
					ishandle=true;
					T[early_id].number++;
				}
			} 
			if(ishandle==false)
			{
				while(P[num].served==true)
				{
					num++;
				}
				if(P[num].tag==1)  //要处理的是vip玩家的话，处理会员队列 
				{
					vipq.pop();
				} 		 
			}	 
		} 
		else   //如果不是vip球桌。 
		{
			while(P[num].served==true)
			{
				num++;
			}	
			//要处理的是vip玩家的话，处理会员队列
			//看等待的球桌里面有没有vip球桌。
			//有、就有可能将球桌更新。 
			if(P[num].tag==1)   
			{
				 vipq.pop();//单独的vip会员队列 ，弹出一个。 
				for(int i=1;i<=k;i++)   
				//若此刻有多个空闲球桌，且有一个是vip球桌。 
				//此举可能会产生更新球桌的举动 
				//看"此刻"除了该空闲球桌外，
				//还有没有vip球桌。 
				{
					//如果有vip球桌和刚选出的最早空闲球桌同时空闲
					//或者在该会员来之前，会有vip球桌空下来。
					//则将vip球桌分配给他。 
					//没有的话，还是将最早空闲球桌分配给该vip球员
					if(T[i].vtag==1&&(T[i].begintime<=early_time||T[i].begintime<=P[num].atime))
					{
						early_time = T[i].begintime;
						early_id=i;
						break; 
					}
				}		 	
			} 	
		}
		if(ishandle == false)
		{
			if(T[early_id].begintime<P[num].atime) //玩家不用等 
			{
				P[num].wtime=0;
				P[num].stime = P[num].atime;	
				T[early_id].begintime= P[num].atime+P[num].ptime*60;
			}
			else  //玩家还要等。 
			{
				P[num].stime = T[early_id].begintime;
				P[num].wtime = T[early_id].begintime-P[num].atime;
				if(P[num].wtime%60>=30)
					P[num].wtime = P[num].wtime/60+1;
				else
					P[num].wtime = P[num].wtime/60; 
				T[early_id].begintime +=P[num].ptime*60;
			}
			P[num].served=true;
			num++;
			count++;
			T[early_id].number++;
		 } 	
	}
	sort(P,P+n,cmp2);
	for(int i=0;i<n;i++)
	{
		if(P[i].served==true)
		{
		printf("%02d:%02d:%02d ",P[i].atime/3600,P[i].atime/60%60,P[i].atime%60);
		printf("%02d:%02d:%02d ",P[i].stime/3600,P[i].stime/60%60,P[i].stime%60);
		printf("%d\n",P[i].wtime);
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d",T[i].number);
		if(i<k)
		printf(" ");
	}
	return 0;
}

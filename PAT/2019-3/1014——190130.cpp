//08:54

//经过题中给的样例数据，17:00时，就不可以在处理了。包括17:00 
//30分。
//09:50  30分 
//分清楚阶段：开始先入一批（n*m)队——挑队伍最早变少的窗口逐个入队——
//入队结束——一个队，一个队处理——

//逐个入队时，若最早变少的窗口的结束时间已经超过17点，则入队结束。 
//注意每处理一个人之前，要判断时间是否在17:00内。 
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxk = 1005; 
const int maxn = 22;
const int top =9*60;
struct customer{
	int ptime;
	int etime;
}C[maxk];
int main()
{
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&C[i].ptime);
		C[i].etime = -1; 
	}
	int w_s_time[maxn]={0};
	queue<int>window[maxn];
	int num=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			window[j].push(num++);
		}
	}
	if(num<=k)
	for(int i=n*m+1;i<=k;i++)
	{
		int early_window = 0;
		int early_time = top;
		int temp,fin_time;
		for(int j=1;j<=n;j++)
		{
			temp = window[j].front();
			fin_time = C[temp].ptime+w_s_time[j];
			if(fin_time<early_time)
			{
				early_time=fin_time;
				early_window = j;
			}
		}
		if(w_s_time[early_window]<top)
		{
			//处理一个顾客。 //处理时在判断开始时间是不是在17点内。 
			temp =window[early_window].front();
			w_s_time[early_window]+=C[temp].ptime;
			C[temp].etime = w_s_time[early_window];
			window[early_window].pop();
			window[early_window].push(i);//入队一个。
		} 
		//最早处理完一个顾客的窗口的结束时间超过17点
		//表明不能再入队了。提前结束再入队操作。 
		if(early_time>=top)  
		{
			break;
		}	 
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	int temp;
	 	if(w_s_time[i]<top)
		 	while(!window[i].empty())
		 	{
		 		temp = window[i].front();
		 		window[i].pop();
		 		if(w_s_time[i]<top)
		 		{
		 			w_s_time[i]+=C[temp].ptime;
					C[temp].etime = w_s_time[i];
				}
				else
				break;
			 }
	 } 
	 for(int i=0;i<q;i++)
	 {
	 	int qid;
	 	scanf("%d",&qid);
	 	if(C[qid].etime==-1)
	 	{
	 		printf("Sorry\n");
		 }
		else
		{
			printf("%02d:%02d\n",C[qid].etime/60+8,C[qid].etime%60);
		}
	 }
	 return 0;	 
}

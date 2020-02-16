//考察队列，和对流程事件的模拟；思路要清晰。注意边界条件 

//整体我是让每个顾客都被服务，服务时间超过17点输出sorry。但是你要
//考虑好多。 
// 但是如果你设定，上限是24*60的话，那么不一定所有客户都有离开时间。
//有些特殊测试点时间特别晚，本身进入时间，就大于24*60.得不到离开时间
//连，sorry都无法输出。 
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 22;
const int maxk = 1005; 
int main(){
	int n,m,k,q;
	int serveTime[maxk];
	int leaveTime[maxk];
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++){
		scanf("%d",&serveTime[i]);
	}
	int windowTime[maxn];
	fill(windowTime,windowTime+maxn,480);
	queue<int>w[maxn];
	//初始排队 
	int cId = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(cId<=k){  //不能超过总共顾客数量 
				w[j].push(cId++);
			} 
		}
	}
	//计算每个窗口的第一轮结束时间 
	for(int j=0;j<n;j++){
		//防止有些空窗户 
		if(!w[j].empty()){
			int tempId = w[j].front();
			windowTime[j]+=serveTime[tempId];
		}	
	}
	//一个一个顾客进行处理 
	for(int i=1;i<=k;i++){
		int eT = 24*60;
		int eW ;
		//挑选结束时间最早的 窗口 
		for(int j=0;j<n;j++){
			if(windowTime[j]>480&&windowTime[j]<eT){
				eT = windowTime[j];
				eW = j;
			}
		}
		int tempId = w[eW].front();
		w[eW].pop();
		//还有顾客就继续进队 
		if(cId<=k){
			w[eW].push(cId++);
		}
		leaveTime[tempId] = windowTime[eW];
		//更新该窗口的结束时间。 
		if(w[eW].size()>0){
			tempId = w[eW].front();
			windowTime[eW]+=serveTime[tempId];
		}else{
			//该窗口停用。 
			windowTime[eW] = 24*60;
		}
	}
	int qId;
	for(int i=0;i<q;i++){
		scanf("%d",&qId);
		//下面这个给离开时间加小于的范围。因为有些顾客没有被服务，就
		//没有离开时间。除了[8,17]之间的。所有都是Sorry。 
		if(leaveTime[qId]>17*60||leaveTime[qId]<=480){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",leaveTime[qId]/60,leaveTime[qId]%60);
		}
	}
	return 0;
}


////以前做的
//#include<stdio.h>
//#include<algorithm>
//#include<queue>
//#include<vector>
//using namespace std;
//const int maxk = 1005; 
//const int maxn = 22;
//const int top =9*60;
//struct customer{
//	int ptime;
//	int etime;
//}C[maxk];
//int main()
//{
//	int n,m,k,q;
//	scanf("%d%d%d%d",&n,&m,&k,&q);
//	for(int i=1;i<=k;i++)
//	{
//		scanf("%d",&C[i].ptime);
//		C[i].etime = -1; 
//	}
//	int w_s_time[maxn]={0};
//	queue<int>window[maxn];
//	int num=1;
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			window[j].push(num++);
//		}
//	}
//	if(num<=k)
//	for(int i=n*m+1;i<=k;i++)
//	{
//		int early_window = 0;
//		int early_time = top;
//		int temp,fin_time;
//		for(int j=1;j<=n;j++)
//		{
//			temp = window[j].front();
//			fin_time = C[temp].ptime+w_s_time[j];
//			if(fin_time<early_time)
//			{
//				early_time=fin_time;
//				early_window = j;
//			}
//		}
//		if(w_s_time[early_window]<top)
//		{
//			//处理一个顾客。 //处理时在判断开始时间是不是在17点内。 
//			temp =window[early_window].front();
//			w_s_time[early_window]+=C[temp].ptime;
//			C[temp].etime = w_s_time[early_window];
//			window[early_window].pop();
//			window[early_window].push(i);//入队一个。
//		} 
//		//最早处理完一个顾客的窗口的结束时间超过17点
//		//表明不能再入队了。提前结束再入队操作。 
//		if(early_time>=top)  
//		{
//			break;
//		}	 
//	 } 
//	 for(int i=1;i<=n;i++)
//	 {
//	 	int temp;
//	 	if(w_s_time[i]<top)
//		 	while(!window[i].empty())
//		 	{
//		 		temp = window[i].front();
//		 		window[i].pop();
//		 		if(w_s_time[i]<top)
//		 		{
//		 			w_s_time[i]+=C[temp].ptime;
//					C[temp].etime = w_s_time[i];
//				}
//				else
//				break;
//			 }
//	 } 
//	 for(int i=0;i<q;i++)
//	 {
//	 	int qid;
//	 	scanf("%d",&qid);
//	 	if(C[qid].etime==-1)
//	 	{
//	 		printf("Sorry\n");
//		 }
//		else
//		{
//			printf("%02d:%02d\n",C[qid].etime/60+8,C[qid].etime%60);
//		}
//	 }
//	 return 0;	 
//} 


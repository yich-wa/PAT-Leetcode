//������У��Ͷ������¼���ģ�⣻˼·Ҫ������ע��߽����� 

//����������ÿ���˿Ͷ������񣬷���ʱ�䳬��17�����sorry��������Ҫ
//���Ǻöࡣ 
// ����������趨��������24*60�Ļ�����ô��һ�����пͻ������뿪ʱ�䡣
//��Щ������Ե�ʱ���ر����������ʱ�䣬�ʹ���24*60.�ò����뿪ʱ��
//����sorry���޷������ 
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
	//��ʼ�Ŷ� 
	int cId = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(cId<=k){  //���ܳ����ܹ��˿����� 
				w[j].push(cId++);
			} 
		}
	}
	//����ÿ�����ڵĵ�һ�ֽ���ʱ�� 
	for(int j=0;j<n;j++){
		//��ֹ��Щ�մ��� 
		if(!w[j].empty()){
			int tempId = w[j].front();
			windowTime[j]+=serveTime[tempId];
		}	
	}
	//һ��һ���˿ͽ��д��� 
	for(int i=1;i<=k;i++){
		int eT = 24*60;
		int eW ;
		//��ѡ����ʱ������� ���� 
		for(int j=0;j<n;j++){
			if(windowTime[j]>480&&windowTime[j]<eT){
				eT = windowTime[j];
				eW = j;
			}
		}
		int tempId = w[eW].front();
		w[eW].pop();
		//���й˿;ͼ������� 
		if(cId<=k){
			w[eW].push(cId++);
		}
		leaveTime[tempId] = windowTime[eW];
		//���¸ô��ڵĽ���ʱ�䡣 
		if(w[eW].size()>0){
			tempId = w[eW].front();
			windowTime[eW]+=serveTime[tempId];
		}else{
			//�ô���ͣ�á� 
			windowTime[eW] = 24*60;
		}
	}
	int qId;
	for(int i=0;i<q;i++){
		scanf("%d",&qId);
		//����������뿪ʱ���С�ڵķ�Χ����Ϊ��Щ�˿�û�б����񣬾�
		//û���뿪ʱ�䡣����[8,17]֮��ġ����ж���Sorry�� 
		if(leaveTime[qId]>17*60||leaveTime[qId]<=480){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",leaveTime[qId]/60,leaveTime[qId]%60);
		}
	}
	return 0;
}


////��ǰ����
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
//			//����һ���˿͡� //����ʱ���жϿ�ʼʱ���ǲ�����17���ڡ� 
//			temp =window[early_window].front();
//			w_s_time[early_window]+=C[temp].ptime;
//			C[temp].etime = w_s_time[early_window];
//			window[early_window].pop();
//			window[early_window].push(i);//���һ����
//		} 
//		//���紦����һ���˿͵Ĵ��ڵĽ���ʱ�䳬��17��
//		//��������������ˡ���ǰ��������Ӳ����� 
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


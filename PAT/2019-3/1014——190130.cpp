//08:54

//�������и����������ݣ�17:00ʱ���Ͳ������ڴ����ˡ�����17:00 
//30�֡�
//09:50  30�� 
//������׶Σ���ʼ����һ����n*m)�ӡ���������������ٵĴ��������ӡ���
//��ӽ�������һ���ӣ�һ���Ӵ�����

//������ʱ����������ٵĴ��ڵĽ���ʱ���Ѿ�����17�㣬����ӽ����� 
//ע��ÿ����һ����֮ǰ��Ҫ�ж�ʱ���Ƿ���17:00�ڡ� 
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
			//����һ���˿͡� //����ʱ���жϿ�ʼʱ���ǲ�����17���ڡ� 
			temp =window[early_window].front();
			w_s_time[early_window]+=C[temp].ptime;
			C[temp].etime = w_s_time[early_window];
			window[early_window].pop();
			window[early_window].push(i);//���һ����
		} 
		//���紦����һ���˿͵Ĵ��ڵĽ���ʱ�䳬��17��
		//��������������ˡ���ǰ��������Ӳ����� 
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

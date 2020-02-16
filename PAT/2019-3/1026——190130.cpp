//09:54
//�������ָ�� ��Ҫ����������˼�롣
// �ύ ��24�֡� 6�ִ𰸴���
//11:17
//�������� �����ǶԵġ�����������Ҷ��󣬺���������

//190227 ͨ������ŵ�Ĵ𰸣������Լ���һ��˼·�������ˡ�
//���������Ӳ���vip����ʱ��������׵ĳ�Ա����ͨ�ˣ���ô
//�������ָ�����
//�����vip��Ա���Ҵ�ʱ������û�п���vip���������л��п���
//���µ��������� 
// �����28�֡�  ��3���Ե���� 

//ʣ��2����ʱ�������ؼ������㽫�¼������������� 
///ÿ���ֲ������ô���ġ�
//������Ծ����ڼ�ģ�⡣ ���¼��Ļ�ԭģ�⡣�����ľ����Լ��������
//��һ���� 
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
	int count =0;//��������� 
	int num=0;//���������ֵ�˭�ˡ� 
	while(count<n)
	{
		int early_time=21*3600;
		int early_id;
		for(int i=1;i<=k;i++)  //����������Է����̨������ 
		{
			if(T[i].begintime<early_time)
			{
				early_time = T[i].begintime;
				early_id=i;
			}
		}
		if(early_time>=21*3600) //���Աչݣ����Ӵ������ 
			break;
		bool ishandle =false;
		if(T[early_id].vtag==1)
		{
			if(!vipq.empty())
			{
				int temp = vipq.front();
				//���Ѿ�����vip��Ա���ڶ����
				//����˳��ȥ����Ҫ������ң���ͨ��ң��ͻ�Ա��Ҷ��п���	 
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
				if(P[num].tag==1)  //Ҫ�������vip��ҵĻ��������Ա���� 
				{
					vipq.pop();
				} 		 
			}	 
		} 
		else   //�������vip������ 
		{
			while(P[num].served==true)
			{
				num++;
			}	
			//Ҫ�������vip��ҵĻ��������Ա����
			//���ȴ�������������û��vip������
			//�С����п��ܽ��������¡� 
			if(P[num].tag==1)   
			{
				 vipq.pop();//������vip��Ա���� ������һ���� 
				for(int i=1;i<=k;i++)   
				//���˿��ж����������������һ����vip������ 
				//�˾ٿ��ܻ�������������ľٶ� 
				//��"�˿�"���˸ÿ��������⣬
				//����û��vip������ 
				{
					//�����vip�����͸�ѡ���������������ͬʱ����
					//�����ڸû�Ա��֮ǰ������vip������������
					//��vip������������� 
					//û�еĻ������ǽ�������������������vip��Ա
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
			if(T[early_id].begintime<P[num].atime) //��Ҳ��õ� 
			{
				P[num].wtime=0;
				P[num].stime = P[num].atime;	
				T[early_id].begintime= P[num].atime+P[num].ptime*60;
			}
			else  //��һ�Ҫ�ȡ� 
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

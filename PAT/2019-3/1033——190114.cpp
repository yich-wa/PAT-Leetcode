//0935����11:01 �������ִ𰸴���
// 
//���ֿ�������Ĵ���
//����վ�����г��ڵļ۸���͵�վ��������¸պ���ʹ����һ��
//����۸�͵�վ��Ŀ��վ��"���Լ��۸�͵ĵ�һ������վ" 
//������ʻ�����Լ��г̷�Χ�ڣ��۸���С��վ��

//���������ִ𰸴��󡣾���鷢���Լ���ʼ�ų�����վ���ں��ݺ�
//Ŀ�ĵ�֮���վʱû�иı�n��ֵ�� ����֮���õ�25�֡� 

//¼��ʱ���Ͱ�����վ���޳�������ҲҪ�޸�n 
//˼· ����
//�������������� 
//���������ݼ��˼· 
//�ܼ���ʱ������1h30���ӡ� 

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =505;
struct station{
	double price;
	double dis;
}sta[maxn];
bool cmp(station a,station b)
{
	return a.dis<b.dis;
}
int main()
{
	int n;
	double m_tank,t_dis,d_avg;
	scanf("%lf%lf%lf%d",&m_tank,&t_dis,&d_avg,&n);
	double once_max = m_tank*d_avg;
	int i=0;
	for(int j=0;j<n;j++)  //¼��ļ���վ�����ں��ݺ�Ŀ�ĵ�֮��� 
	{
		scanf("%lf %lf",&sta[i].price,&sta[i].dis);
		if(sta[i].dis<t_dis)
			i++;
	} 
	n=i;
	sort(sta,sta+n,cmp);
	if(sta[0].dis!=0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double t_cost=0;
	double max_dis=0;
	double r_tank =0; 
	double now_dis=0;
	int now_sta =0;
	int p_sta =now_sta; ///����ָ�롣 
//	double nowprice = sta[now_sta].price;
//	double l_price =nowprice;
	int next_sta; 
	while(now_dis<t_dis)
	{
		p_sta =now_sta;
		int l_sta=now_sta;
		//���г̷�Χ�ڣ���һ���ȱ�վ�۸�͵�վ 
		while(p_sta<n&&now_dis+once_max>=sta[p_sta].dis) 
		{
			if(sta[p_sta].price<sta[l_sta].price)
			{
				l_sta = p_sta;
				break; 
			}
			p_sta++;
		}
		if(l_sta==now_sta)//��վ�۸���ͣ��������ܵ���Զ�ļ���վ 
		{
			if(t_dis<=now_dis+once_max)//��һ���ͣ����Ե��յ�
			{
				t_cost+=sta[now_sta].price*((t_dis-now_dis)/d_avg);
				printf("%.2f\n",t_cost);
				return 0;
			}
			t_cost+=(m_tank-r_tank)*sta[now_sta].price; //���� 
			if(p_sta==now_sta+1) //��һ����վ��������г̡�
			{
				max_dis = sta[now_sta].dis+once_max;
				printf("The maximum travel distance = %.2f\n",max_dis);
			 	return 0;
			 } 
			 else //��ʹ����Զ�ļ���վ 
			 {
				next_sta=p_sta-1;
				r_tank =m_tank- ((sta[next_sta].dis-sta[now_sta].dis)/d_avg);
				now_sta=next_sta;
				now_dis = sta[now_sta].dis;
			 }  
		}
		//���͸պ��ܵ��۸���͵��Ǹ�վ��
		//���ֿ�������Ĵ���
		//����վ�����г��ڵļ۸���͵�վ��������¸պ���ʹ����һ��
		//����۸�͵�վ��
		//������ʻ�����Լ��г̷�Χ�ڣ��۸���С��վ�� 
		else  
		{
			t_cost+=sta[now_sta].price*(((sta[l_sta].dis-sta[now_sta].dis)/d_avg)-r_tank);
			now_sta =l_sta;
			now_dis = sta[l_sta].dis;
			r_tank =0; 	 
		}
	}
	return 0;	
 } 
 
 
// //��pat�������л�õģ���ǰ�Ĵ𰸣�


// #include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxc=510;
//const int INF=1000000;
//struct Station{
//	double price;
//	double dis;
//}sta[maxc];
//bool cmp(Station a,Station b)
//{
//	return a.dis<b.dis;
//}
//int main()
//{
//	double c;
//	double d;
//	double davg;
//	int n;
//	scanf("%lf %lf %lf %d",&c,&d,&davg,&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%lf%lf",&sta[i].price,&sta[i].dis);
//	}
//	sort(sta,sta+n,cmp);
//	double maxdis=0;
//	double retank=0;
//	double mincost=0;
//	double maxrange=c*davg;
//	double netank=0;
//	bool flag=true;
//	int i=0;                       //���������վ��
//	int nextsta=-1;
//	while(i<n)
//	{
//		nextsta=-1;               
//		netank=(sta[i].dis-maxdis)/davg;
//		if(retank>=netank)      //�ж��ܲ�����ʻ����Ŀ�ļ���վ������ܵĻ���
//		{
//			retank=retank-netank;        //��ʹ���ü���վ��
//			maxdis=sta[i].dis;
//			for(int j=i+1;j<n&&sta[j].dis<=maxdis+maxrange;j++)   //�����г̷�Χ�ڣ�����һ�������ͼ۵͵ļ���վ��š�
//			{
//				if(sta[j].price<=sta[i].price)
//				{
//					nextsta=j;
//					break;
//				}
//			}
//			if(nextsta==-1)//�г̷�Χ�ڣ�û�б����۸��͵ļ���վ�����Կ��ܷ񵽴�Ŀ�ĵأ����ܵ���Ļ��ͼ�������Σ������г��ڡ�
//			{
//				if(d<=maxdis+maxrange)  //���Ŀ�ĵ��ڴ�վ���г̰����ڣ���ӵ��ոտ�����ʹ��Ŀ�ĵؼ���
//				{
//					netank=(d-maxdis)/davg;
//					mincost+=(netank-retank)*sta[i].price;
//					i=n;
//				}
//				else     //Ŀ��վ�����г̷�Χ�ڡ������ܵ���ļ���վ�У��۸���͵ļ���վ��Ϊ��һվ��    
//				{
//					int minprice=INF;   //��ʼ��Ϊһ�����޴��ֵ��
//					for(int j=i+1;j<n&&sta[j].dis<=maxdis+maxrange;j++)
//					{
//						if(sta[j].price<minprice)
//						{
//							minprice=sta[j].price;
//							nextsta=j;
//						}
//					}
//					if(minprice==INF)  //˵���г̷�Χ��û�м���վ��˵��������Ŀ�ĵ���
//					{
//						mincost+=(c-retank)*sta[i].price;   //��������ʻ����Զ��
//						maxdis+=c*davg;
//						flag=false;
//						i=n;
//					}
//					else  //�г̷�Χ���м���վ  ,�����ͣ���ʹ�����վ��
//					{
//						mincost+=(c-retank)*sta[i].price;
//						retank=c;
//						i=nextsta;
//					}
//				}
//			}
//			else
//			{
//				
//				netank=(sta[nextsta].dis-sta[i].dis)/davg;
//				if(netank>retank)                                    //**********��ʼ�����ⲽ�����ʣ����ͱ���Ҫ���Ͷ�Ļ����Ͳ������ˡ�
//				{
//					mincost+=(netank-retank)*sta[i].price;           // ����Ҫ�Ӷ�����
//					retank=netank;   //��������
//				}
//				i=nextsta;         //������һ��Ҫȥ�ļ���վ
//			}
//		}
//		else                    //��ʾ��ʹ������һ������վ������ǰ������
//		{
//			maxdis+=retank*davg;
//			i=n;
//			flag=false; //��ʾ��ʻ����
//			break;
//		}
//	}
//	if(flag==true)
//		printf("%.2f\n",mincost);
//	else
//		printf("The maximum travel distance = %.2f",maxdis);
//	return 0;
//}
  

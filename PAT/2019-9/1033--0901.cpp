//09:56--16:40
//̰���㷨����ʼ˼·����
//����˼·����Ӧ��������һ������վ��Ȼ���ҷ�Χ�ڼ۸���͵ļ���վ��
//��Ӧ�ã�������һ������վ��
//�ҷ�Χ�ڣ���������ģ��ұ����۸�͵ļ���վ
//�Ҳ�����������ȥ��Χ���ͼ���͵ļ���վ�� 


//ɵ��˼·���˺ö�顣�� ����Ϲд����������15���ˡ�
//ǰ��˼·�ִ��ˡ�ɵ�ơ������úù����Լ���˼·��
//���Լ�˼·��û�����塣Ҳ��˵ʲô�����ģ�����һ��ʼ��˼·�ǿ������Եģ���ģ����
//ֻ֪����̰���㷨�����ֲ�֪�������ѡ��̰�ġ��� 
//�Ժ��������⣬��дα���롣����˼·���Լ�˼·�����壬�����Դ�֮�֡�ɵ�ơ� 

//debugҪһ��һ�еĸġ� 
//��23�֡�����һ��2�ִ��� 
//���ܴ���ȥ��Χ���ͼ���͵ļ���վʱ���費��Ҫ���������ۡ������Ҫ�ж��¡� 
// 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 505;
struct station{
	double price;
	double dis;
}S[maxn];
bool cmp(station a,station b){
	return a.dis<b.dis;
}
int main(){
	double cMax,d,avg;
	int n;
	scanf("%lf%lf%lf%d",&cMax,&d,&avg,&n);
	 for(int i=0;i<n;i++){
	 	scanf("%lf%lf",&S[i].price,&S[i].dis);
	 }
	sort(S,S+n,cmp); 
	if(S[0].dis!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double res = 0;
	double totalCost = 0;
	double past = 0;
	int posS = 0;
	double range; 
	double need = 0;
	//���뵽һ����վ֮��Ҫ�����¡� 
	bool isReach = true;
	while(past<d){ 
//		printf(" \n");	
//		printf("%.0f %.2f %d----%.0f---%.2f\n",S[posS].dis,S[posS].price,posS,past,res);
//		printf("%.2f***%.2f***\n",past,totalCost);
		//�ҷ�Χ���ͼ���͵ļ���վ�� 
		range = cMax*avg+past;
		int nextS = -1; 
		double minPrice = maxn; 
		for(int i=posS+1;i<n;i++){
			if(S[i].dis<=range&&S[i].price<minPrice){
				nextS = i;
				minPrice = S[i].price;
			}
			if(minPrice<S[posS].price){
				break;
			}
			if(S[i].dis>range)
				break; 
		}
		if(nextS==-1){
			//�г̷�Χ��û�м���վ��
			if(range>=d){
				totalCost+=((d-past)/avg-res)*S[posS].price;
				past = d; 
			}else{
				//���ܲ����յ㡣 
				totalCost+= (cMax-res)*S[posS].price;
				past = range;
				isReach = false;
				break; 
			}
		}else{
			//�м���վ�������
			if(S[nextS].price<S[posS].price){
				//���ʱ��ӵ����չ��ܵ��¸�����վ
				need = (S[nextS].dis-past)/avg-res;	
				if(need>0){
					res = 0;
					totalCost+= need*S[posS].price;
				}else{
					res = res-(S[nextS].dis-past)/avg;
				}
				
			}else{
				//��վ�������ܵ��¸�����վ�� 
				totalCost+= (cMax-res)*S[posS].price;
				res = cMax-(S[nextS].dis-S[posS].dis)/avg;
			} 
			posS = nextS;
			past = S[nextS].dis;
		}
	} 
	if(isReach==true){
		printf("%.2f",totalCost);
	}else{
		printf("The maximum travel distance = %.2f",past);
	}
	return 0;
}


////��ǰ���ģ�
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn =505;
//struct station{
//	double price;
//	double dis;
//}sta[maxn];
//bool cmp(station a,station b)
//{
//	return a.dis<b.dis;
//}
//int main()
//{
//	int n;
//	double m_tank,t_dis,d_avg;
//	scanf("%lf%lf%lf%d",&m_tank,&t_dis,&d_avg,&n);
//	double once_max = m_tank*d_avg;
//	int i=0;
//	for(int j=0;j<n;j++)  //¼��ļ���վ�����ں��ݺ�Ŀ�ĵ�֮��� 
//	{
//		scanf("%lf %lf",&sta[i].price,&sta[i].dis);
//		if(sta[i].dis<t_dis)
//			i++;
//	} 
//	n=i;
//	sort(sta,sta+n,cmp);
//	if(sta[0].dis!=0)
//	{
//		printf("The maximum travel distance = 0.00\n");
//		return 0;
//	}
//	double t_cost=0;
//	double max_dis=0;
//	double r_tank =0; 
//	double now_dis=0;
//	int now_sta =0;
//	int p_sta =now_sta; ///����ָ�롣 
////	double nowprice = sta[now_sta].price;
////	double l_price =nowprice;
//	int next_sta; 
//	while(now_dis<t_dis)
//	{
//		p_sta =now_sta;
//		int l_sta=now_sta;
//		while(p_sta<n&&now_dis+once_max>=sta[p_sta].dis)
//		{
//			if(sta[p_sta].price<sta[l_sta].price)
//			{
//				l_sta = p_sta;
//				break; 
//			}
//			p_sta++;
//		}
//		if(l_sta==now_sta)//��վ�۸���ͣ��������ܵ���Զ�ļ���վ 
//		{
//			if(t_dis<=now_dis+once_max)//��һ���ͣ����Ե��յ�
//			{
//				t_cost+=sta[now_sta].price*((t_dis-now_dis)/d_avg);
//				printf("%.2f\n",t_cost);
//				return 0;
//			}
//			t_cost+=(m_tank-r_tank)*sta[now_sta].price; //���� 
//			if(p_sta==now_sta+1) //��һ����վ��������г̡�
//			{
//				max_dis = sta[now_sta].dis+once_max;
//				printf("The maximum travel distance = %.2f\n",max_dis);
//			 	return 0;
//			 } 
//			 else //��ʹ����Զ�ļ���վ 
//			 {
//				next_sta=p_sta-1;
//				r_tank =m_tank- ((sta[next_sta].dis-sta[now_sta].dis)/d_avg);
//				now_sta=next_sta;
//				now_dis = sta[now_sta].dis;
//			 }  
//		}
//		//���͸պ��ܵ��۸���͵��Ǹ�վ��
//		//���ֿ�������Ĵ���
//		//����վ�����г��ڵļ۸���͵�վ��������¸պ���ʹ����һ��
//		//����۸�͵�վ��
//		//������ʻ�����Լ��г̷�Χ�ڣ��۸���С��վ�� 
//		else  
//		{
//			t_cost+=sta[now_sta].price*(((sta[l_sta].dis-sta[now_sta].dis)/d_avg)-r_tank);
//			now_sta =l_sta;
//			now_dis = sta[l_sta].dis;
//			r_tank =0; 	 
//		}
//	}
//	return 0;	
// }  

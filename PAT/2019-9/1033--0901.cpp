//09:56--16:40
//贪心算法，开始思路错误
//错误思路：不应该立足于一个加油站。然后找范围内价格最低的加油站。
//而应该：立足于一个加油站，
//找范围内，离它最近的，且比它价格低的加油站
//找不到，加满，去范围内油价最低的加油站！ 


//傻逼思路错了好多遍。。 叫你瞎写。现在下午15点了。
//前面思路又错了。傻逼。还不好好构建自己是思路。
//你自己思路都没有理清。也别说什么对与错的，所以一开始的思路是看起来对的，很模糊，
//只知道个贪心算法，但又不知道该如何选择贪心。。 
//以后像这种题，先写伪代码。理清思路，自己思路都理不清，何来对错之分。傻逼。 

//debug要一行一行的改。 
//答案23分。还有一个2分错误。 
//可能错误：去范围内油价最低的加油站时。需不需要加油另当别论。这个需要判断下。 
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
	//想想到一个车站之后要做的事。 
	bool isReach = true;
	while(past<d){ 
//		printf(" \n");	
//		printf("%.0f %.2f %d----%.0f---%.2f\n",S[posS].dis,S[posS].price,posS,past,res);
//		printf("%.2f***%.2f***\n",past,totalCost);
		//找范围内油价最低的加油站。 
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
			//行程范围内没有加油站。
			if(range>=d){
				totalCost+=((d-past)/avg-res)*S[posS].price;
				past = d; 
			}else{
				//且跑不到终点。 
				totalCost+= (cMax-res)*S[posS].price;
				past = range;
				isReach = false;
				break; 
			}
		}else{
			//有加油站，分情况
			if(S[nextS].price<S[posS].price){
				//这个时候加到，刚够跑到下个加油站
				need = (S[nextS].dis-past)/avg-res;	
				if(need>0){
					res = 0;
					totalCost+= need*S[posS].price;
				}else{
					res = res-(S[nextS].dis-past)/avg;
				}
				
			}else{
				//本站加满。跑到下个加油站。 
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


////以前做的：
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
//	for(int j=0;j<n;j++)  //录入的加油站都是在杭州和目的地之间的 
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
//	int p_sta =now_sta; ///遍历指针。 
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
//		if(l_sta==now_sta)//本站价格最低，加满，跑到最远的加油站 
//		{
//			if(t_dis<=now_dis+once_max)//加一次油，可以到终点
//			{
//				t_cost+=sta[now_sta].price*((t_dis-now_dis)/d_avg);
//				printf("%.2f\n",t_cost);
//				return 0;
//			}
//			t_cost+=(m_tank-r_tank)*sta[now_sta].price; //加满 
//			if(p_sta==now_sta+1) //下一加油站超过最大行程。
//			{
//				max_dis = sta[now_sta].dis+once_max;
//				printf("The maximum travel distance = %.2f\n",max_dis);
//			 	return 0;
//			 } 
//			 else //行使到最远的加油站 
//			 {
//				next_sta=p_sta-1;
//				r_tank =m_tank- ((sta[next_sta].dis-sta[now_sta].dis)/d_avg);
//				now_sta=next_sta;
//				now_dis = sta[now_sta].dis;
//			 }  
//		}
//		//加油刚好跑到价格最低的那个站。
//		//出现考虑问题的错误
//		//若本站并非行程内的价格最低的站，则加油致刚好行使到下一个
//		//比其价格低的站。
//		//而非行驶到，自己行程范围内，价格最小的站。 
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

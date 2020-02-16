//0935——11:01 还有两分答案错误；
// 
//出现考虑问题的错误
//若本站并非行程内的价格最低的站，则加油致刚好行使到下一个
//比其价格低的站。目标站："比自己价格低的第一个加油站" 
//而非行驶到，自己行程范围内，价格最小的站。

//至于那两分答案错误。经检查发现自己开始排除加油站不在杭州和
//目的地之间的站时没有改变n的值。 改完之后拿到25分。 

//录入时，就把无用站点剔除掉。但也要修改n 
//思路 清晰
//变量设置清晰。 
//用样例数据检查思路 
//总计用时过长：1h30分钟。 

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
	for(int j=0;j<n;j++)  //录入的加油站都是在杭州和目的地之间的 
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
	int p_sta =now_sta; ///遍历指针。 
//	double nowprice = sta[now_sta].price;
//	double l_price =nowprice;
	int next_sta; 
	while(now_dis<t_dis)
	{
		p_sta =now_sta;
		int l_sta=now_sta;
		//找行程范围内，下一个比本站价格低的站 
		while(p_sta<n&&now_dis+once_max>=sta[p_sta].dis) 
		{
			if(sta[p_sta].price<sta[l_sta].price)
			{
				l_sta = p_sta;
				break; 
			}
			p_sta++;
		}
		if(l_sta==now_sta)//本站价格最低，加满，跑到最远的加油站 
		{
			if(t_dis<=now_dis+once_max)//加一次油，可以到终点
			{
				t_cost+=sta[now_sta].price*((t_dis-now_dis)/d_avg);
				printf("%.2f\n",t_cost);
				return 0;
			}
			t_cost+=(m_tank-r_tank)*sta[now_sta].price; //加满 
			if(p_sta==now_sta+1) //下一加油站超过最大行程。
			{
				max_dis = sta[now_sta].dis+once_max;
				printf("The maximum travel distance = %.2f\n",max_dis);
			 	return 0;
			 } 
			 else //行使到最远的加油站 
			 {
				next_sta=p_sta-1;
				r_tank =m_tank- ((sta[next_sta].dis-sta[now_sta].dis)/d_avg);
				now_sta=next_sta;
				now_dis = sta[now_sta].dis;
			 }  
		}
		//加油刚好跑到价格最低的那个站。
		//出现考虑问题的错误
		//若本站并非行程内的价格最低的站，则加油致刚好行使到下一个
		//比其价格低的站。
		//而非行驶到，自己行程范围内，价格最小的站。 
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
 
 
// //从pat编译器中获得的，以前的答案；


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
//	int i=0;                       //第零个加油站。
//	int nextsta=-1;
//	while(i<n)
//	{
//		nextsta=-1;               
//		netank=(sta[i].dis-maxdis)/davg;
//		if(retank>=netank)      //判断能不能行驶到该目的加油站。如果能的话。
//		{
//			retank=retank-netank;        //行使到该加油站。
//			maxdis=sta[i].dis;
//			for(int j=i+1;j<n&&sta[j].dis<=maxdis+maxrange;j++)   //在它行程范围内，找下一个比它油价低的加油站序号。
//			{
//				if(sta[j].price<=sta[i].price)
//				{
//					nextsta=j;
//					break;
//				}
//			}
//			if(nextsta==-1)//行程范围内，没有比它价更低的加油站，所以看能否到达目的地，不能到达的话就加满，其次，计算行程内。
//			{
//				if(d<=maxdis+maxrange)  //如果目的地在此站的行程包含内，则加到刚刚可以行使到目的地即可
//				{
//					netank=(d-maxdis)/davg;
//					mincost+=(netank-retank)*sta[i].price;
//					i=n;
//				}
//				else     //目的站不在行程范围内。则挑能到达的加油站中，价格最低的加油站作为下一站。    
//				{
//					int minprice=INF;   //初始化为一个无限大的值。
//					for(int j=i+1;j<n&&sta[j].dis<=maxdis+maxrange;j++)
//					{
//						if(sta[j].price<minprice)
//						{
//							minprice=sta[j].price;
//							nextsta=j;
//						}
//					}
//					if(minprice==INF)  //说明行程范围内没有加油站。说明到不了目的地了
//					{
//						mincost+=(c-retank)*sta[i].price;   //加满，行驶到最远。
//						maxdis+=c*davg;
//						flag=false;
//						i=n;
//					}
//					else  //行程范围内有加油站  ,加满油，行使到这个站。
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
//				if(netank>retank)                                    //**********开始忘了这步。如果剩余的油比需要的油多的话，就不加油了。
//				{
//					mincost+=(netank-retank)*sta[i].price;           // 计算要加多少油
//					retank=netank;   //更新油箱
//				}
//				i=nextsta;         //更新下一个要去的加油站
//			}
//		}
//		else                    //表示行使不到下一个加油站。则提前结束。
//		{
//			maxdis+=retank*davg;
//			i=n;
//			flag=false; //表示行驶不到
//			break;
//		}
//	}
//	if(flag==true)
//		printf("%.2f\n",mincost);
//	else
//		printf("The maximum travel distance = %.2f",maxdis);
//	return 0;
//}
  

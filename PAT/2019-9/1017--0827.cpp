//14:00-14:49 ��23�֡���2�ִ𰸴��� 
//�����֣�ģ���Ŷӵ��¼�����������һ�����ڣ�����һ���˿͡����ķ�ʽ
//���ǰ���ʱ��ķ�ʽ��Ȼ��Ա������˵�ʱ�䡣 
//��Ȼǰ���ǰ���Ӧ�����ݶ�������ˡ� 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005;
const int maxk = 105;
struct cus{
	int arrTime;
	int proTime;
}tempCus;
vector<cus>v;
bool cmp(cus a,cus b){
	return a.arrTime<b.arrTime;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int winTime[maxk];
	int st = 8*3600;
	fill(winTime,winTime+maxk,st);
	int hh,mm,ss,pt;
	int count = n;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&pt);
		if(pt>60){
			pt = 60;
		}
		int at = hh*3600+mm*60+ss;
		int end = 17*3600;
		if(at>end)
			continue;
		tempCus.arrTime = at;
		tempCus.proTime = pt*60;
		v.push_back(tempCus);
	}
	sort(v.begin(),v.begin()+v.size(),cmp);
	int total = 0;
	for(int i=0;i<v.size();i++){
		int earlyWT = 24*3600;
		int earlyW = 0; 
		//��һ������ʱ������Ĵ��ڣ�ȥ������������û��� ʵ���Ǵ��ں��˵�
		//�ĶԽӡ� 
		for(int j=0;j<k;j++){
			if(winTime[j]<earlyWT){
				earlyWT = winTime[j];
				earlyW = j;
			}
		}
		if(earlyWT<v[i].arrTime){
			//���õ� 
			winTime[earlyW] = v[i].arrTime+v[i].proTime;
		}else{
			total += earlyWT - v[i].arrTime;
			winTime[earlyW] +=v[i].proTime;
		}
	}
	double ave = total/(60*v.size()*1.0);
	printf("%.1f",ave);
	return 0;	
} 

////��ǰ����
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int maxn = 10005;
//const int maxk = 105;
//struct customer{
//	int atime;
//	int ptime;
//	int wtime;
//}c[maxn];
//bool cmp(customer a,customer b)
//{
//	return a.atime<b.atime;
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int temph,tempm,temps,tempp;
//	int tempt=0;
//	int num=0;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d:%d:%d %d",&temph,&tempm,&temps,&tempp);
//		if(tempp>60)
//		{
//			tempp=60;
//		}
//		tempt=temph*3600+tempm*60+temps;
//		if(tempt>17*3600)
//			continue;
//		c[num].atime = tempt;
//		//��ʼ���Ǹ�tempp��60���½������ 
//		c[num].ptime = tempp*60;
//		num++;
//	}
//	sort(c,c+num,cmp);
//	int begint[maxk];
//	for(int i=0;i<k;i++)
//	{
//		begint[i]=8*3600;
//	}
//	int sumwait=0;
//	int count=0;
//	while(count<num)
//	{
//		if(c[count].atime<begint[0])
//		{
//			//c[count].atime=max(c[count].atime,8*3600);
//			sumwait+=begint[0]-c[count].atime;
//			
//			begint[0]+=c[count].ptime;
//			//printf("%d**\n",begint[0]);
//			count++;
//		}
//		else
//		{
//			begint[0]=c[count].atime+c[count].ptime;
//			//printf("%d\n",begint[0]);
//			count++;
//		}
//		sort(begint,begint+k);
//	 } 
//	 //printf("%d\n",sumwait);
//	 double avewt = (sumwait*1.0)/(1.0*num*60);
//	 printf("%.1f",avewt);
//	 return 0;	
// }
//  

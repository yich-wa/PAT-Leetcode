//20:03
//——22:38  25分。
//注意把时间转化为秒处理，都要转化，包括处理时间，开始没有转化。
//每次处理一个人，然后挑出最早可以开始工作的柜台，以及处于队首的人。
 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10005;
const int maxk = 105;
struct customer{
	int atime;
	int ptime;
	int wtime;
}c[maxn];
bool cmp(customer a,customer b)
{
	return a.atime<b.atime;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int temph,tempm,temps,tempp;
	int tempt=0;
	int num=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d",&temph,&tempm,&temps,&tempp);
		if(tempp>60)
		{
			tempp=60;
		}
		tempt=temph*3600+tempm*60+temps;
		if(tempt>17*3600)
			continue;
		c[num].atime = tempt;
		//开始忘记给tempp乘60导致结果出错。 
		c[num].ptime = tempp*60;
		num++;
	}
	sort(c,c+num,cmp);
	int begint[maxk];
	for(int i=0;i<k;i++)
	{
		begint[i]=8*3600;
	}
	int sumwait=0;
	int count=0;
	while(count<num)
	{
		if(c[count].atime<begint[0])
		{
			//c[count].atime=max(c[count].atime,8*3600);
			sumwait+=begint[0]-c[count].atime;
			
			begint[0]+=c[count].ptime;
			//printf("%d**\n",begint[0]);
			count++;
		}
		else
		{
			begint[0]=c[count].atime+c[count].ptime;
			//printf("%d\n",begint[0]);
			count++;
		}
		sort(begint,begint+k);
	 } 
	 //printf("%d\n",sumwait);
	 double avewt = (sumwait*1.0)/(1.0*num*60);
	 printf("%.1f",avewt);
	 return 0;	
 } 

//知识手册91页。没必要每次都去判断是不是闰年。只需要在
//年份改变时，去判断是否是闰年。 
//复杂判断条件下，尽量用"括号",区分清楚判断条件。 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
	int count =0;
	int time1,time2,day1,day2,mon1,mon2,year1,year2;
	scanf("%d%d",&time1,&time2);
	if(time1>time2)
		swap(time1,time2);
	day1 =time1%100;
	day2 =time2%100;
	time1 =time1/100;
	time2 = time2/100;
	mon1 =time1%100;
	mon2 =time2%100;
	year1 = time1/100;
	year2 =time2/100;
	int tag;
	if((year1%4==0&&year1/100!=0)||(year1%400==0))
		tag =1;
	else tag=0;
	while(year1<year2||mon1<mon2||day1<day2)
	{
		count++;
		day1++;
		if(day1>month[mon1][tag])
		{
			mon1++;
			day1 =1;
			if(mon1==13)
			{
				year1++;
				mon1=1;
				if(year1%4==0&&year1/100!=0||year1%400==0)
					tag =1;
				else 
					tag =0;
			}
		}	
	}
	printf("%d\n",count);
	return 0;
 } 

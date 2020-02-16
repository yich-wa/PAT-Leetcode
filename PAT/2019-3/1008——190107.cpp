//问题想多想少的张力都要有。 
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int totaltime=0;
	int now_floor =0;
	for(int i=0;i<n;i++)
	{
		int aim_floor;
		scanf("%d",&aim_floor);
		if(aim_floor>now_floor)
		{
			totaltime+=(aim_floor-now_floor)*6;
		}
		else
		{
			totaltime+=(now_floor-aim_floor)*4;
		}
		//一开始我想多了想到，同一层，连续请求
		//还有就是开始第一层就开始请求。 
//		if(now_floor!=aim_floor||i==0)
//		{
		totaltime+=5;
		now_floor=aim_floor;
//		}	
	}
	printf("%d\n",totaltime);
	return 0;
 } 

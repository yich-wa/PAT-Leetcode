//����������ٵ�������Ҫ�С� 
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
		//һ��ʼ��������뵽��ͬһ�㣬��������
		//���о��ǿ�ʼ��һ��Ϳ�ʼ���� 
//		if(now_floor!=aim_floor||i==0)
//		{
		totaltime+=5;
		now_floor=aim_floor;
//		}	
	}
	printf("%d\n",totaltime);
	return 0;
 } 

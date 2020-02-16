//这是一道普通模拟的题。 
#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	int N[105];
	scanf("%d",&n);
	int sum = 0;
	int firFloor = 0;
	int tempFloor;
	for(int i=0;i<n;i++){
		scanf("%d",&tempFloor);
		if(tempFloor>firFloor){
			sum+= (tempFloor-firFloor)*6+5;	
		}else{
			sum+=(firFloor-tempFloor)*4+5;
		}
		firFloor = tempFloor;
	}
	printf("%d",sum);
	return 0;	
}

////以前做的：
// #include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int totaltime=0;
//	int now_floor =0;
//	for(int i=0;i<n;i++)
//	{
//		int aim_floor;
//		scanf("%d",&aim_floor);
//		if(aim_floor>now_floor)
//		{
//			totaltime+=(aim_floor-now_floor)*6;
//		}
//		else
//		{
//			totaltime+=(now_floor-aim_floor)*4;
//		}
//		//if(now_floor!=aim_floor||i==0)
//		//{
//			totaltime+=5;
//			now_floor=aim_floor;
//		//}	
//	}
//	printf("%d\n",totaltime);
//	return 0;
// } 

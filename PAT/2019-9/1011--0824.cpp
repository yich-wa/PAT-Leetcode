//注意单个字符的初始化，靠的是单引号； char result[3]={'W','T','L'};

#include<stdio.h>
#include<string.h>
int main(){
	double temp;
	double sum = 1.0;
	char result[3]={'W','T','L'};
	for(int i=0;i<3;i++){
		double max = 0;
		int id;
		for(int j=0;j<3;j++){
			scanf("%lf",&temp);
			if(temp>max){
				max = temp;
				id = j;
			} 
		}
		printf("%c ",result[id]);
		sum = sum*max;
	}
	sum = (sum*0.65 -1)*2;
	printf("%.2f",sum);
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	char ch[3]={'W','T','L'};
//	double odd[3];
//	int maxindex[3];
//	double maxodd[3];
//	double sum =1;
//	for(int i=0;i<3;i++)
//	{
//		double tempodd=0;
//		for(int j=0;j<3;j++)
//		{
//			scanf("%lf",&odd[j]);
//			if(odd[j]>tempodd)
//			{
//				tempodd=odd[j];
//				maxindex[i] =j;
//			}
//		}
//		sum=sum*tempodd;
//	}
//	sum =(sum*0.65-1)*2;
//	printf("%c %c %c %.2f\n",ch[maxindex[0]],ch[maxindex[1]],ch[maxindex[2]],sum);
//	return 0;
// } 

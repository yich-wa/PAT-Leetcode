// 13:59--14:20 得16分。 最后4分答案错误 
//最后4分答案错误，居然是因为，后面的false写错了。
//其中一个false写的拼错了。。 
#include<stdio.h>
typedef long long LL;
int main(){
	LL A ,B,C;
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		printf("Case #%d: ",i);
		LL result = A+B;
		if(A>0&&B>0&&result<0){
			printf("true\n");
		}else if(A<0&&B<0&&result>=0){
			printf("false\n");
		}else if(result>C){
			printf("true\n");
		}else{
			printf("false\n");
		}
	}
	return 0;
}

////以前写的
//#include<stdio.h>
//const int maxn =12;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	long long a,b,c;
//	long long res;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%lld%lld%lld",&a,&b,&c);
//		res = a+b;
//		printf("Case #%d: ",i+1);
//		if((a>0)&&(b>0)&&(res<0))
//			printf("true\n");
//		else if((a<0)&&(b<0)&&(res>=0))//***这个是有等于号的 
//			printf("false\n");
//		else if(res>c)
//			printf("true\n");
//		else
//			printf("false\n");	
//	}
//	return 0; 
//} 

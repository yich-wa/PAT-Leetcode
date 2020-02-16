//写了素数打表的方法，但是又没有在主方法中去调用，真是傻。 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
bool notPrime[maxn]; 
//素数打表 ,这块不太熟 
void primeTable(){
	fill(notPrime,notPrime+maxn,false);
	notPrime[0]=true;
	notPrime[1]=true;
	int s = (int)sqrt(1.0*maxn); 
	for(int i=2;i<=s;i++){
		if(notPrime[i]==false){
			for(int j=2*i;j<maxn;j=j+i)
				notPrime[j]=true;
		}
		
	}
}
//计算值a，在数值r的情况下序列相反的数的值。
//判断是不是素数，看的是值的多少。 
int rNum(int a,int r){
	int result = 0;
	int k = 0;
	while(a>0){
		result = result*r+ a%r;
		a = a/r;
		k++;	
	}
	return result;
}
int main(){
	int n,radix;
	primeTable();
	scanf("%d",&n);
	while(n>0){
		scanf("%d",&radix);
		if(notPrime[n]==true){
			printf("No\n");
		}else{
			int rn = rNum(n,radix);
			if(notPrime[rn]==true){
				printf("No\n");
				
			}else{
				printf("Yes\n");
			}
		}
		scanf("%d",&n);
	}
	return 0;
}


////以前写的
//#include<stdio.h>
// #include<math.h>
// const int maxn =400010;
// bool isprime(int a)
// {
//   if(a==1)
//	 	return false;
// 	int temp =(int)sqrt(1.0*a);
// 	for(int i=2;i<=temp;i++)
// 	{
// 		if(a%i==0)
// 		return false;
//	 }
//	 return true;
// }
// int r_val(int n,int d)   
// {
// 	int r[maxn];
// 	int count =0;
// 	while(n>0)
// 	{
// 		r[count++]=n%d;
// 		n=n/d;
//	 }
// 	int sum = 0;
// 	count--;
// 	int num =0;
//	while(count>=0)
//	{
//		sum =sum+ r[count--]*pow(1.0*d,1.0*num);
//		n=n/10;
//		num++;
//	}
//	return sum;
// }
// int main()
// {
// 	int n, d;
// 	int num1,num2;
// 	scanf("%d",&n);
//	 while(n>0)
//	 {
//	 	scanf("%d",&d);
//	 	if(isprime(n)==false)
//	 	{
//	 		printf("No\n");
//		}
//		 else
//		 {
//		 	num2 = r_val(n,d);
//		 //	printf("%d\n",num2);
//		 	if(isprime(num2)==false)
//		 		printf("No\n");
//		 	else
//		 		printf("Yes\n");		
//		 }
//		scanf("%d",&n);	
//	  } 
//	  return 0;
//  } 

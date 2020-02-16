//14:50——15:16 ，得18分。有 7分运行时错误。
//初试值是10位以内。最大经过100次相加。开会考虑用long long 去存储。
//估计仍旧需要大整数，进行处理。
//写出两个判断是不是回文序列和，进行翻转的函数是对的。 
//大整数的加法要熟悉。与此同时：reverse函数也要熟悉。 
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long LL;
const int maxn = 120;
bool isP(char str[]){
	bool flag = true;
	int len = strlen(str);
	for(int i=0;i<len/2;i++){
		if(str[i]!=str[len-1-i]){
			flag=false;
			break;
		}
	}
	return flag;
}
LL getR(LL a){
	char str[maxn];
	sprintf(str,"%lld",a);
	reverse(str,str+strlen(str));
	sscanf(str,"%lld",&a);
	return a;
}
int main(){
	char n[maxn],n1[maxn],n2[maxn];
	int k;
	int step=0;
	scanf("%s %d",n,&k);
	for(step=0;step<k;step++){
		if(isP(n)){
			break;
		}
		strcpy(n1,n);
		strcpy(n2,n); 
		int carry = 0;
		int len = strlen(n1);
		reverse(n2,n2+len);
		int num = 0;
		for(int i=len-1;i>=0;i--){
			int temp = (n1[i]-'0')+(n2[i]-'0')+carry;
			carry = temp/10;
			n[num++] = '0' + temp%10;
		}
		if(carry!=0)
			n[num++]='0'+carry;
		n[num]='\0';
		reverse(n,n+strlen(n));
	}
	printf("%s\n",n);
	printf("%d",step);
	return 0;
}

////以前写的：
//#include<stdio.h>
//#include<string.h>
//#include<algorithm> 
//using namespace std;
//const int maxn = 120;
//bool ispalind(char a[])
//{
//	int len = strlen(a);
//	for(int i=0;i<len/2;i++)
//	{
//		if(a[i]!=a[len-1-i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//void out(char a[])
//{
//	int len =strlen(a);
//	for(int i=len-1;i>=0;i--)
//	{
//		printf("%c",a[i]);
//	}
//	printf("\n");
//	return ;
// } 
//int main()
//{
//	char n[maxn];
//	char n2[maxn];
//	char n3[maxn];
//	int k;
//	int numk=0;
//	scanf("%s %d",n,&k);
//	if(ispalind(n)==true)
//	{
//		printf("%s\n",n);
//		printf("%d",numk);
//		return 0;
//	}
//	for(int i=1;i<=k;i++)
//	{
//		strcpy(n2,n);
//		int len = strlen(n2);
//		//下面是j<len/2；不能是j<=len/2
//		//否则，假如只有两位，(0,1)交换。(1,0)在交换，等于无效。
//		//临界条件要非常清晰。 
//		reverse(n2,n2+len); 
////		for(int j=0;j<len/2;j++)  //翻转 
////		{
////			swap(n2[j],n2[len-1-j]);
////		}
//		int carry =0;
//		int result;
//		int num3=0;
//		for(int j=0;j<len;j++)   //相加 
//		{
//			result = n[j]-'0'+n2[j]-'0'+carry;
//			carry = result/10;
//			result=result%10;
//			n[num3++]='0'+result;
//		}
//		if(carry!=0)
//		{
//			n[num3++]='0'+carry;
//		}
//		n[num3]='\0';
//		if(ispalind(n)==true)
//		{
//			printf("%s\n",n);
//			printf("%d",i);
//			return 0;
//		}
//	}
//	out(n);
//	printf("%d",k);
//	return 0;	
// } 

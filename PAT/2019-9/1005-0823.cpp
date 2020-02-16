//注意下面是i--;每回做完题之后要进行细致的总结。做一次题，就要提升一次
 
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 102;
int main(){
	char n[maxn];
	char tra[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};	
	scanf("%s",n);
	int sum = 0;
	for(int i=0;i<strlen(n);i++){
		sum += n[i]-'0'; 
	}
	vector<int>output;
	while(sum/10!=0){
		int temp = sum%10;
		sum=sum/10;
		output.push_back(temp);
	}
	output.push_back(sum);
	int len = output.size();
	for(int i=len-1;i>=0;i--){
		printf("%s",tra[output[i]]);
		if(i>0)
			printf(" ");
	}
	return 0;
}
//
////以前的别人的写法
//#include<stdio.h>
//#include<string.h>
//#include<vector>
//using namespace std;
//int main()
//{
//	char output[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//	char a[105];
//	scanf("%s",a);
//	vector<int>v; 
//	int len =strlen(a);
//	int sum =0;
//	for(int i=0;i<len;i++)
//	{
//		sum = sum+a[i]-'0';
//	}
//	if(sum==0)
//	{
//		printf("zero\n");
//	}
//	else
//	{
//		while(sum!=0)
//		{
//			v.push_back(sum%10);
//			sum =sum/10;
//		}
//		for(int i=v.size()-1;i>=0;i--)
//		{
//			printf("%s",output[v[i]]);
//			if(i>0)
//				printf(" ");
//			else
//				printf("\n");
//		}
//	}
//	return 0;	
// } 

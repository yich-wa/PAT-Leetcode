//22:09--
//本题是一道动态规划的题
//再次明确如何输入一行字符串 
//****
//为啥会程序一启动，就结束呢。
//经过最终对照试验。对"块"和"行"进行debug。发现问题出在对二维dp数组的
//定义上：int dp[maxn][maxn];具体为什么这么定义就不行。这么定义就
// 程序自动结束。为什么呢？ 
//最终发现，二维角标是maxn的数组，只能定义为全局变量。而不能放在主函数中去定义。 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string> 
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int main(){
//	printf("jflsdjfk");
	char str[maxn];
	cin.getline(str,maxn);
//	printf("%s",str);
//	scanf("%s",str);
//	string str;
//	getline(cin,str);
//	cout<<str<<endl;
	//经检测，以上代码没有问题。 
	int len = strlen(str); 
	
	int maxLen = 1;
//	memset(dp,0,sizeof(dp));
	fill(dp[0],dp[0]+maxn*maxn,0);
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if((i<len-1)&&(str[i]==str[i+1])){
			dp[i][i+1]=1;
			maxLen = 2;			
		}
	}
	for(int k=2;k<=len-1;k++){
		for(int i=0;i+k<len;i++){
			if(str[i]==str[i+k]&&dp[i+1][i+k-1]==1){
				dp[i][i+k]=1;
				maxLen = k+1;
			}
		}
	}
	printf("%d\n",maxLen);
	return 0;
}

//以前写的：
 
 

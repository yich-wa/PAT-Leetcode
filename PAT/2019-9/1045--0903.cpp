//10:48--
//******程序刚一启动，就自动结束。 
//实质是个*****最长不下降子序列问题******
//也就是说有自身的序列在的。
//dp[i][j]是在一个序列中。 而且，影响dp[i][j]结果的不仅是dp[i][j-1]
//而是：dp[i][i] 直到dp[i][j-1]。
//所以使用两层循环解决：i和j的定位问题。i小于j
//第三层循环，用dp[i][i]到dp[i][j-1]去更新。 
#include<stdio.h>
#include<map>
using namespace std;
const int maxn = 205;
const int maxl = 10005;
int dp[maxl][maxl];
int tail[maxl][maxl];
int main(){
	int n,m;
	int favO[maxn];
	bool isF[maxn]={false};
	int strO[maxl];
	map<int,int>order;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&favO[i]);
		isF[favO[i]]=true;
		order[favO[i]] = i;	
	}
	int tempL;
	int temp;
	int L = 0;
	scanf("%d",&tempL);
	for(int i=0;i<tempL;i++){
		scanf("%d",&temp);
		if(isF[temp]==true){
			strO[L++]=temp;	
		}
	}
	for(int i=0;i<L;i++){
		dp[i][i] = 1;
		tail[i][i] = strO[i];
	}
	for(int i=0;i<L;i++){
		for(int j=i+1;j<L;j++){
			///求d[i][j],要遍历dp[i][i+1]~dp[i][j-1];更新dp[i][j]
			for(int k=i+1;k<=j-1;k++){
				if(order[tail[i][k]]<=order[strO[j]]){
					if(dp[i][k]+1>dp[i][j]){
						dp[i][j] = dp[i][k]+1;
						tail[i][j] = strO[j];
					}else if(dp[i][k]+1==dp[i][j]){
						if(order[strO[j]]<order[tail[i][j]]){
							tail[i][j] = strO[j];
						}
					}
				}else{
					if(dp[i][k]>dp[i][j]){
						dp[i][j] = dp[i][k];
						tail[i][j] = tail[i][k];
					}
				}
			} 
		}
	}
	printf("%d",dp[0][L-1]);
	return 0;
} 

//题不难。第一遍写完，有三分超时
//看来得在一开始用动态规划的方法。记录dp[i][j]为从i到j的值的和
//动态规划属于把问题复杂化的一种方式

//简单方法：用dp[i]记录从头到i的所有值的和。求任意一段。用两个想减即可
//得到。 

#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int main(){
	int n;
	int d[maxn];
	int dp[maxn]; 
	int sum = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		sum += d[i];
		dp[i]=dp[i-1]+d[i];
	}
	int m;
	scanf("%d",&m);
//	printf("%d***\n",sum);
	int temp1,temp2;
	int tempSum;
	for(int i=0;i<m;i++){
		tempSum = 0;
		scanf("%d %d",&temp1,&temp2);
		if(temp1>temp2){
			swap(temp1,temp2);
		}
		tempSum = dp[temp2-1]-dp[temp1-1];
		if(sum-tempSum<tempSum){
			tempSum = sum-tempSum;
		}
		printf("%d\n",tempSum);
	}
	return 0;
} 

//以前做的
//#include<stdio.h>
//#include<algorithm> 
//#include<math.h> 
//using namespace std;
//const int maxn = 100005;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int dis[maxn]={0};
//	int dp[maxn]={0}; 
//	int sum =0;
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&dis[i]);
//		sum +=dis[i];
//		dp[i]=dp[i-1]+dis[i-1];
//	}
//	int m,u,v;
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&u,&v);
//		if(u>v)
//		swap(u,v);
//		int out;
//		int st =dp[v]-dp[u];
//		int nd = sum-st;
//		out = (st>nd)?nd:st;
//		printf("%d\n",out);
//	}
//	return 0;
//} 

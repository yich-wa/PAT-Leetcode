//16:23--
//这是一个动态规划的问题。o1背包问题。 质量和体积是一个意义的。 
//采用深度优先，估计会有部分超时。 尽量剪枝操作吧。 
//5点前拿了 3分。 
//本题，略难，首先v[i]和w[i]是一个数组。其次，当dp[v]!=m时，无解。
//如何输出动态规划的路径选择。这个很重要的知识点。 
//开始倒着排序为什么呢？ 
#include<stdio.h>
#include<algorithm>
#include<vector> 
using namespace std;
const int maxn = 10005;
const int maxm = 110;
int val[maxn];
int dp[maxn];
bool isCh[maxn][maxm]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	vector<int>output;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	//从大到小排序 ，为什么要从大到小排序呢？ 
	sort(val,val+n,cmp);
//	放，或者不放； 
	for(int i=0;i<n;i++){
		//倒着枚举 
		for(int v=m;v>=val[i];v--){
			if(dp[v]<=dp[v-val[i]]+val[i]){
				dp[v]=dp[v-val[i]]+val[i];
				isCh[i][v]=1;
			}
				
		}
	}
	if(dp[m]!=m){
		printf("No Solution\n");
		return 0;
	} 
	int num =n-1;
	int v= m;
	//倒着枚举，输出动态规划的路径。 
	while(num>=0){
		if(isCh[num][v]==1){
			output.push_back(val[num]);
			v = v-val[num];
		}
		num--;
	}
	for(int i=0;i<output.size();i++){
		if(i!=0)
			printf(" ");
		printf("%d",output[i]);
	}
	return 0;
} 


////以前写的
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 10010;
//const int maxm =105;
//int main()
//{
//	int n,m;
//	int value[maxn];
//	int dp[maxm];
//	int choice[maxn][maxn]={0};
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&value[i]);
//	}
//	sort(value+1,value+n+1);
//	for(int i=0;i<=m;i++)
//		dp[i]=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int v = m;v>=value[i];v--)
//		{
//			if(dp[v]<=dp[v-value[i]]+value[i])
//			{
//				dp[v]=dp[v-value[i]]+value[i];
//				choice[i][v]=1;
//			}
//		}
//	}
//	if(dp[m]!=m)
//		printf("No Solution\n");
//	else
//	{
//		bool flag[maxn]={false};
//		int num=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(choice[i][m]==1)
//			{
//				flag[i]=true;
//				num++;
//			}
//		}
//		int count =0;
//		for(int i=0;i<=n;i++)
//		{
//			if(flag[i]==true)
//			{
//				printf("%d",value[i]);
//				if(count<num)
//				printf(" ");
//				else
//				{
//					printf("\n");
//					break;	
//				}
//				count++;	
//			}
//		}	
//	}
//	return 0; 
// }  

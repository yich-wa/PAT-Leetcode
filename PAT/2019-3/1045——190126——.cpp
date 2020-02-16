//15：15——
//2 2 1 5 5 6 3 1 1 5 6 
//16:03   得 24分，6分超时。 自己写的时候采用的是深度优先搜素算法
//并没有想出动态规划的做法。 

//用书中的动态规划方法做了调整得21分。1个答案错误，2个段错误。
//后知dp数组大小开小了。改完27分还有3分答案错误。
 
//当序列中只有一个有效颜色时，答案应该是1，你是0； 
//开始将这更新最长长度，放入内层for循环中，结果就是当num为1时，ans无法
//更新，导致本应是1的结果，为0
//而且原来那么写，非常低效。 
//

//动态规划，一定要注意：状态的设计、状态转移方程的设计、边界 
//这道题有多种思路：
//第一最长不下降子序列 ，最直观的的方法 
//第二 ，最长公共子序列
//第三，DFS这个拿不到全分。 

//最长公共子序列的写法。 
//这种写法，注意：两个序列的输入序号是从1开始的
// 但dp[i][j]是从0开始初始化的，保证dp[0][j-1]和dp[i-1][0] 有意义 

//但下面写法有6分,可能是因为内外层循环的顺序放反了。
//长的序列应该做第二维，应做内层for循环。短的序列应该做第一维，
//做外层for循环 
//利用程序的局部性原理
//改完后30分。。完美。。。哈 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn =202;
const int maxl = 10010;
bool isfav[maxn]={false};
int favorder[maxn];
int stripe[maxl];
int num =1;
int dp[maxl][maxl];//截止到i位置，最长不下降子序列的长度。
//dp[i][j]表明，A串到i位置，B串到j位置 

int main()
{
	int n,l,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&favorder[i]);
		isfav[favorder[i]]=true;
		dp[i][0]=0; 
	} 
	int tempc;
	scanf("%d",&l);
	for(int i=1;i<=l;i++)
	{
		scanf("%d",&tempc);
		if(isfav[tempc]==true)
		{
			dp[0][num]=0;
			stripe[num++]=tempc;
		}
	}
	dp[0][0]=0;
	num--;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=num;j++)
		{
			int tempmax = max(dp[i][j-1],dp[i-1][j]);
			if(stripe[j]==favorder[i])
			{
				dp[i][j]=tempmax+1;
			}
			else
			{
				dp[i][j]=tempmax;
			}
		}
	}
	printf("%d\n",dp[m][num]);
	return 0;
}

////最长不下降子序列。 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn =202;
//const int maxl = 10010;
//bool isfav[maxn]={false};
//int favorder[maxn];
//int favseq[maxn];
//int stripe[maxl];
//int num =0;
//int dp[maxl];//截止到i位置，最长不下降子序列的长度。 
//int main()
//{
//	int n,l,m;
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&favorder[i]);
//		isfav[favorder[i]]=true;
//		favseq[favorder[i]]=i;//数字越小，位置越靠前。 
//	}
//	int tempc;
//	scanf("%d",&l);
//	for(int i=0;i<l;i++)
//	{
//		scanf("%d",&tempc);
//		if(isfav[tempc]==true)
//		{
//			stripe[num++]=tempc;
//		}
//	}
//	fill(dp,dp+maxn,1);
//	int ans =0;
//	for(int i=0;i<num;i++)
//	{
//		for(int j=0;j<i;j++)
//		{
//			if(favseq[stripe[i]]>=favseq[stripe[j]]&&dp[i]<dp[j]+1)
//			{
//				dp[i]=dp[j]+1;	
//			}
//		}
//		//开始将这句放入内层for循环中，结果就是当num为1时，ans无法
//		//更新，导致本应是1的结果，为0
//		//而且原来那么写，非常低效。 
//		ans = max(ans,dp[i]); 
//	}
//	printf("%d\n",ans);
//	return 0;
//}


//DFS写法 
//#include<stdio.h>
//const int maxn =202;
//const int maxl = 10010;
//bool isfav[maxn]={false};
//int favorder[maxn];
//int favseq[maxn];
//int stripe[maxl];
//int preid=0;
//int tempnum=0;
//int num =0;
//int maxnum=-1;
//void DFS(int a,int tempnum,int preid)
//{
//	//printf("%d\n",a);
//	if(a==num)
//	{
//		if(tempnum>maxnum)
//			maxnum = tempnum;
//		return;
//	}
//	if(favseq[stripe[a]]==preid)
//	{
//		DFS(a+1,tempnum+1,preid);
//	}
//	else if(favseq[stripe[a]]>preid)
//	{
//		DFS(a+1,tempnum+1,favseq[stripe[a]]);//算入其中  
//		DFS(a+1,tempnum,preid);  //不算入其中。 
//	}
//	else
//	{
//		DFS(a+1,tempnum,preid);//跳过。 
//	}	
//}
//int main()
//{
//	int n,l,m;
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&favorder[i]);
//		isfav[favorder[i]]=true;
//		favseq[favorder[i]]=i;//数字越小，位置越靠前。 
//	}
//	favseq[0]=0;
//	int tempc;
//	scanf("%d",&l);
//	for(int i=0;i<l;i++)
//	{
//		scanf("%d",&tempc);
//		if(isfav[tempc]==true)
//		{
//			stripe[num++]=tempc;
//		}
//	}
//	//printf("%d\n",num);
//	
//	DFS(0,0,0);
//	printf("%d\n",maxnum);
//	return 0;
//}

////以前写法 
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn=10010;
//int fa[maxn];
//int given[maxn];
//int dp[maxn];
//int ad[maxn]={0};//记录given[maxn]中每个数字在fa[maxn]中的几号位，不存在的话，则为0；
//int n,m,l;
//int find(int ai,int i)
//{
//	int d=1;
//	if(i>1)
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(ad[given[j]]<=ad[ai]&&d<dp[j]+1)  //此处没有映射较为繁杂。需仔细理解****
//				d=dp[j]+1;
//		}
//	}
//	return d;
//}
//int main()
//{
//	scanf("%d",&n);
//	scanf("%d",&m);
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d",&fa[i]);
//		ad[fa[i]]=i;   //建立序列映射，******答案中的提示,再输入时就形成映射。
//	}
//	scanf("%d",&l);
//	int res=0;      //*****8****刚开始忘记初始化为0了，所以其初值为其地址值，非常非常大的一个值。
//	int num=1;
//	int g;
//	for(int i=1;i<=l;i++)
//	{
//		scanf("%d",&g);
//		if(ad[g]>0)  //要对ad[maxn]初始化为0及以下的值。这样才能过滤中喜欢的颜色。
//		 {
//			given[num]=g;
//			dp[num]=find(g,num);
//			res=max(res,dp[num]);
//			num++;
//		}
//	}
//	printf("%d\n",res);
//	return 0;
//}

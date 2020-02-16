//13:12
//13:38——21分 4分段错误。 

//采用了两种做法。 

//采用第三种做法；
// 参考网上思路：
// 对给出的骑行距离排序后，从大到小扫描一遍就是答案。
//求input[i]>maxE的maxE的最大值，详见代码中。
//写完25分。 

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn =100005; 
int main()
{
	int n;
	int ori;
	vector<int>input;
	scanf("%d",&n);
	//int minNum =0;
	int maxNum=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori);
		input.push_back(ori);
	}
	sort(input.begin(),input.end());
	int maxE=1;
	for(int i=n-1;i>=0;i--)
	{
		//maxE表示大于等于input[i]的有多少天数。
		//求的是满足。input[i]>maxE的maxE的最大值。 
		if(input[i]<=maxE)    
			break;
		maxE++;
	}
	printf("%d\n",maxE-1);
	return 0;
}

//第二种做法： 
///又采用先排序后判断的方法。得17分。 8分答案错误。
//用特殊数据 ：
// 6 
// 5 5 5 5 5 5 
//实验发现错误。
//该错误排查后得21分 第3测试点，这回是答案错误。还是缺 4分。
// 
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int maxn =100005; 
//int main()
//{
//	int n;
//	int ori;
//	vector<int>input;
//	scanf("%d",&n);
//	//int minNum =0;
//	int maxNum=-1;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&ori);
//		input.push_back(ori);
//	}
//	sort(input.begin(),input.end());
//	int maxE=1;
//	//特殊情况特殊处理。即全部一样。 
//	if(input[0]==input[n-1]) 
//	{
//		maxE=input[0]-1;
//		while(n<maxE)
//		{
//			maxE--;
//		}
//	 } 
//	else
//		for(int i=0;i<n;i++)
//		{
//			if(i<n-1&&input[i]<input[i+1])
//			{
//				int num = n-i-1;
//				if(num>=input[i])
//				{
//		//比如input[i]=10;后面有11个12。则maxE应该是11而不是10；
//					while(num>=input[i]&&input[i]<input[i+1])
//					{
//						input[i]++;
//					}
//					maxE=input[i]-1;
//				}	
//			} 
//		}
//	printf("%d\n",maxE);
//	return 0;
//} 
// 
// 21分做法 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn =100005; 
//int main()
//{
//	int n;
//	int ori[maxn];
//	int count[maxn]={0};
//	scanf("%d",&n);
//	//int minNum =0;
//	int maxNum=-1;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&ori[i]);
//		
//		if(ori[i]>maxNum)
//			maxNum = ori[i];
//	}
//	maxNum=max(maxNum,n);
//	int k=0;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=k;j<ori[i];j++)
//		{
//			count[j]++;
//			//第一遍没有加这个部分。加了可以剪枝，提高效率。 
//			if(j<=count[j]&&j>k)
//			{
//				k=j;
//			}
//		}	
//	}
//	
//	for(;k<=maxNum;k++)
//	{
//		if(k>count[k])
//			break;
//	}
//	printf("%d\n",k-1);
//	return 0;
// } 


// //以前写的那一版。 
// 
// #include<stdio.h>
// #include<algorithm>
// using namespace std;
// const int maxn =100010;
// bool cmp(int a,int b)
// {
// 	return a>b;
// }
// int main()
// {
// 	int n;
// 	scanf("%d",&n);
// 	int ride[maxn];
// 	int edd[maxn]={0};
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&ride[i]);
//// 		for(int j=0;j<ride[i];j++)
//// 			edd[j]++;
// 			
// 	}
//// 	for(int j=n;j>=0;j--)
//// 	{
//// 		if(edd[j]>=j)   //开始少了一个“>"少了能有8分。加上得21分。 
//// 		{
//// 		printf("%d\n",j);
//// 		break;
//// 		}
//// 	}
//// 	
// 	sort(ride,ride+n,cmp);
// 	for(int j =n;j>=0;j--)
// 	{
// 		int ans =0;
// 		for(int i=0;i<n;i++)
// 		{
// 			if(ride[i]>j)
// 			{ 
// 			ans++;
// 			}
//			else 
//			break;
//		}
//		if(ans>=j)
//		{
//			printf("%d\n",j);
//			break;
//		}
//	}
//	return 0;
//}

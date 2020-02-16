//18:18
//——18:48  截止，与答案基本一模一样，但不清楚根本无法输入。
 
#include<stdio.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1005;
int main()
{
//	char st[maxn]; 
//	gets(st);
//	int len = strlen(st);
	string st;
	getline(cin,st);
	int len =st.length();
	int dp[maxn][maxn];
	//dp[i][j]表示i到j子序列是不是回文，是为1，不是为0 
	
	for(int i=0;i<len;i++)
	{
		dp[i][i]=1;
	}
	int ans =1;
	for(int i=0;i<len-1;i++)
	{
		if(st[i]==st[i+1])
		{
			dp[i][i+1]=1;
			ans =2;
		}
	}
	for(int L =3;L<=len;L++)  //L表示子序列的长度 
	{
		bool flag=false; 
		for(int i=0;i<=len-L;i++)
		{
			int j=i+L-1;
			if(st[i]==st[j])
			{
				dp[i][j]=dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=0;
			}
			if(dp[i][j]==1)
				flag=true;
		}
		if(flag==true)
			ans = max(ans,L); 
	}
	printf("%d\n",ans);
	return 0;
}

//20:38

//21:08——21分  4分2个答案错误。 
//经过测试，当N为素数时。出错。 
//将大循环的条件，也套给小循环，结果对了。就是大循环的条件，
//一般都有套给小循环。 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
const int maxm = 10005;
const int maxn = 103;
int g[maxm][maxn]; 
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int N;
	vector<int>input;
	int temp;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&temp);
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),cmp);
	int n =(int)sqrt(1.0*N); 
	while(N%n!=0)
	{
		n--;
	}
	int m=N/n; 
	int left=0;
	int right=n-1;
	int up=0;
	int down = m-1;
	int nowr=0;
	int nowc=0; 
	int count =0;
	while(count<N)
	{
		while(count<N&&nowc<right)
		{
			g[nowr][nowc++]=input[count++];
		}
		up++;
		while(count<N&&nowr<down)
		{
			g[nowr++][nowc]=input[count++];
		}
		right--;
		while(count<N&&nowc>left)
		{
			g[nowr][nowc--]=input[count++];
		}
		down--;
		while(count<N&&nowr>up)
		{
			g[nowr--][nowc]=input[count++];
		}
		if(count<N) 
			g[nowr][nowc++]=input[count++];
		left++;	
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",g[i][j]);
			if(j<n-1)
			printf(" ");
		}
		printf("\n");
	}
	return 0;	
}
 

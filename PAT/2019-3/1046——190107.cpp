//pat1046 �ö�̬�滮˼��ȥʡʱ�䣬�������������ֶ���Դ��
//��̬�滮�ؼ��������ö�����ĺ��壬��࣬��������������� 
//����� 
#include<stdio.h>
#include<algorithm> 
#include<math.h> 
using namespace std;
const int maxn = 100005;
int main()
{
	int n;
	scanf("%d",&n);
	int dis[maxn]={0};
	int dp[maxn]={0}; 
	int sum =0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dis[i]);
		sum +=dis[i];
		dp[i]=dp[i-1]+dis[i-1];
	}
	int m,u,v;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		if(u>v)
		swap(u,v);
		int out;
		int st =dp[v]-dp[u];
		int nd = sum-st;
		out = (st>nd)?nd:st;
		printf("%d\n",out);
	}
	return 0;
}

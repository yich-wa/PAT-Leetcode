//�ⲻ�ѡ���һ��д�꣬�����ֳ�ʱ
//��������һ��ʼ�ö�̬�滮�ķ�������¼dp[i][j]Ϊ��i��j��ֵ�ĺ�
//��̬�滮���ڰ����⸴�ӻ���һ�ַ�ʽ

//�򵥷�������dp[i]��¼��ͷ��i������ֵ�ĺ͡�������һ�Ρ��������������
//�õ��� 

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

//��ǰ����
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

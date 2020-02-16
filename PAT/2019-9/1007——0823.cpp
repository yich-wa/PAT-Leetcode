//����һ����̬�滮�����⣬����dp[maxk]����
//dp[k]��ʾ��k��β��������������к��Ƕ��١�
//�ڼ�¼from[maxk]���飬�궨��ʼλ�á� 

#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxk = 10005;
int main(){
	int k;
	scanf("%d",&k);
	bool isM=true;
	int N[maxk];
	int dp[maxk];
	int from[maxk]={0};
	dp[0] = -1; 
	for(int i=1;i<=k;i++){
		scanf("%d",&N[i]);
		if(isM==true&&N[i]>=0){
			isM = false;	
		}
		if(N[i]+dp[i-1]>N[i]){
			dp[i] = dp[i-1]+N[i];
			from[i] = from[i-1];
		}else{
			dp[i] = N[i];
			from[i] = i;
		}
	}
	if(isM==true){
		printf("0 %d %d",N[1],N[k]);
		return 0;
	}
	int maxSum = dp[1];
	int start =1;
	int last = 1;
	for(int i=2;i<=k;i++){
		if(dp[i]>maxSum){
			maxSum = dp[i];
			start = from[i];
			last = i;
		}
	}
	printf("%d %d %d",maxSum,N[start],N[last]);
	return 0;
}

////��ǰ��д��
//#include<stdio.h>
//const int maxn = 10010;
//int main()
//{
//	int k;
//	int seq[maxn];
//	int sum[maxn]={0};
//	int start[maxn];
//	int dp[maxn]; 
//	scanf("%d",&k);
//	bool flag =false;
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d",&seq[i]);
//		//��sum����ȥȷ���������е��������ȷ�ķ�ʽ������
//		//��ʹjȷ����i������С�ķ�ʽ�� 
//		if(i>0&&sum[i-1]>0)
//		{
//			sum[i]=sum[i-1]+seq[i];
//			start[i]=start[i-1];
//		}
//		else
//		{
//			start[i]=i;
//			sum[i]=seq[i];	
//		}
//		if(flag==false&&seq[i]>=0)
//			flag =true;
//	}
//	if(flag==false)
//	{
//		printf("0 %d %d\n",seq[0],seq[k-1]);
//		return 0;
//	}
//	int maxdp = sum[0];
//	int index = 0;
//	for(int i=1;i<k;i++)
//	{
//		if(sum[i]>maxdp)
//		{
//			maxdp=sum[i];
//			index=i;
//		}		
//	}
//	printf("%d %d %d\n",maxdp,seq[start[index]],seq[index]);
//	return 0;
//}




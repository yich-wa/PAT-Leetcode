//16:23--
//����һ����̬�滮�����⡣o1�������⡣ �����������һ������ġ� 
//����������ȣ����ƻ��в��ֳ�ʱ�� ������֦�����ɡ� 
//5��ǰ���� 3�֡� 
//���⣬���ѣ�����v[i]��w[i]��һ�����顣��Σ���dp[v]!=mʱ���޽⡣
//��������̬�滮��·��ѡ���������Ҫ��֪ʶ�㡣 
//��ʼ��������Ϊʲô�أ� 
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
	//�Ӵ�С���� ��ΪʲôҪ�Ӵ�С�����أ� 
	sort(val,val+n,cmp);
//	�ţ����߲��ţ� 
	for(int i=0;i<n;i++){
		//����ö�� 
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
	//����ö�٣������̬�滮��·���� 
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


////��ǰд��
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

//08:30
//****
//Ϊɶ�����һ�������ͽ����ء�

//���𰸣����֣����������еĺͣ�������Ҫ�ö�̬�滮��
//��¼sum[i]Ȼ����sum[j]-sum[i-1]ȥ��ʾ��i��j�ĺ͡� 
 
//������һ��ʼ������д�������⡣����ֱ�ӽ������÷�19�֡�6�����г�ʱ
 
#include<stdio.h>
#include<vector>
#include<algorithm> 
using namespace std;
const int maxn = 100005;
struct link{
	int left;
	int right;
}tempL;
vector<link>output;
bool cmp(link a,link b){
	return a.left<b.left;
}
int main(){
	int n,m;
	int dam[maxn];
	int sum[maxn]={0}; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&dam[i]);
		sum[i]=sum[i-1]+dam[i];
	}
	int value=1000000005;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int temp = sum[j]-sum[i-1];
			 if(temp>=m&&temp<=value){
		 		if(temp<value){
		 			value =temp;
		 			output.clear();
				 }
		 		tempL.left = i;
		 		tempL.right = j;
		 		output.push_back(tempL);
			 }
		}
	}
	sort(output.begin(),output.begin()+output.size(),cmp);
	for(int i=0;i<output.size();i++){
		printf("%d-%d\n",output[i].left,output[i].right);
	}
	return 0;
}


////��ǰд��
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 100010;
//int main()
//{
//	int n,m;
//	int d[maxn];
//	int dp[maxn]={0}; 
//	vector<int>vi,vj;
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&d[i]);
//		dp[i]=dp[i-1]+d[i];
//	}
//	int temp;
//	int mincost = maxn;
//	int i=1;int j=1;
//	while(i<=n&&j<=n)
//	{
//		temp =dp[j]-dp[i-1]-m;
//		//printf("%d %d %d\n",i,j,temp);
//		if(temp>=0)
//		{
//			if(temp>mincost)
//				i++;
//			else if(temp<mincost)
//			{
//				mincost =temp; 
//				vi.clear();
//				vj.clear();
//				vi.push_back(i);
//				vj.push_back(j);
//				if(temp==0)
//				{
//					i++;
//					j++;
//				}
//				else
//				{
//					i++;
//				}	
//			}
//			else 
//			{	
//				vi.push_back(i);
//				vj.push_back(j);
//				if(temp==0)
//				{
//					i++;
//					j++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//		}
//		else
//			j++;
//	}
//	int len =vi.size();
//	for(int i=0;i<len;i++)
//	{
//		printf("%d-%d\n",vi[i],vj[i]);
//	}
//	return 0;
//} 

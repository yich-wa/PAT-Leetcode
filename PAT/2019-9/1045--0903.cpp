//10:48--
//******�����һ���������Զ������� 
//ʵ���Ǹ�*****����½�����������******
//Ҳ����˵������������ڵġ�
//dp[i][j]����һ�������С� ���ң�Ӱ��dp[i][j]����Ĳ�����dp[i][j-1]
//���ǣ�dp[i][i] ֱ��dp[i][j-1]��
//����ʹ������ѭ�������i��j�Ķ�λ���⡣iС��j
//������ѭ������dp[i][i]��dp[i][j-1]ȥ���¡� 
#include<stdio.h>
#include<map>
using namespace std;
const int maxn = 205;
const int maxl = 10005;
int dp[maxl][maxl];
int tail[maxl][maxl];
int main(){
	int n,m;
	int favO[maxn];
	bool isF[maxn]={false};
	int strO[maxl];
	map<int,int>order;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&favO[i]);
		isF[favO[i]]=true;
		order[favO[i]] = i;	
	}
	int tempL;
	int temp;
	int L = 0;
	scanf("%d",&tempL);
	for(int i=0;i<tempL;i++){
		scanf("%d",&temp);
		if(isF[temp]==true){
			strO[L++]=temp;	
		}
	}
	for(int i=0;i<L;i++){
		dp[i][i] = 1;
		tail[i][i] = strO[i];
	}
	for(int i=0;i<L;i++){
		for(int j=i+1;j<L;j++){
			///��d[i][j],Ҫ����dp[i][i+1]~dp[i][j-1];����dp[i][j]
			for(int k=i+1;k<=j-1;k++){
				if(order[tail[i][k]]<=order[strO[j]]){
					if(dp[i][k]+1>dp[i][j]){
						dp[i][j] = dp[i][k]+1;
						tail[i][j] = strO[j];
					}else if(dp[i][k]+1==dp[i][j]){
						if(order[strO[j]]<order[tail[i][j]]){
							tail[i][j] = strO[j];
						}
					}
				}else{
					if(dp[i][k]>dp[i][j]){
						dp[i][j] = dp[i][k];
						tail[i][j] = tail[i][k];
					}
				}
			} 
		}
	}
	printf("%d",dp[0][L-1]);
	return 0;
} 

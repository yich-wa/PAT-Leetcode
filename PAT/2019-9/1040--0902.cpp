//22:09--
//������һ����̬�滮����
//�ٴ���ȷ�������һ���ַ��� 
//****
//Ϊɶ�����һ�������ͽ����ء�
//�������ն������顣��"��"��"��"����debug������������ڶԶ�άdp�����
//�����ϣ�int dp[maxn][maxn];����Ϊʲô��ô����Ͳ��С���ô�����
// �����Զ�������Ϊʲô�أ� 
//���շ��֣���ά�Ǳ���maxn�����飬ֻ�ܶ���Ϊȫ�ֱ����������ܷ�����������ȥ���塣 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string> 
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int main(){
//	printf("jflsdjfk");
	char str[maxn];
	cin.getline(str,maxn);
//	printf("%s",str);
//	scanf("%s",str);
//	string str;
//	getline(cin,str);
//	cout<<str<<endl;
	//����⣬���ϴ���û�����⡣ 
	int len = strlen(str); 
	
	int maxLen = 1;
//	memset(dp,0,sizeof(dp));
	fill(dp[0],dp[0]+maxn*maxn,0);
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if((i<len-1)&&(str[i]==str[i+1])){
			dp[i][i+1]=1;
			maxLen = 2;			
		}
	}
	for(int k=2;k<=len-1;k++){
		for(int i=0;i+k<len;i++){
			if(str[i]==str[i+k]&&dp[i+1][i+k-1]==1){
				dp[i][i+k]=1;
				maxLen = k+1;
			}
		}
	}
	printf("%d\n",maxLen);
	return 0;
}

//��ǰд�ģ�
 
 

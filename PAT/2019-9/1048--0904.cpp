//8:40--8:57 。思路建立好，本题比较简单。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n,m;
	int coin[maxn];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+n);
	int i=0;
	int j= n-1;
	bool flag= false;
	int v1,v2;
	while(i<j){
		if(coin[i]+coin[j]==m){
			v1 = coin[i];
			v2 = coin[j];
			flag = true;
			break;
		}else if(coin[i]+coin[j]<m){
			i++;
		}else{
			j--;
		}
	}
	if(flag==true){
		printf("%d %d\n",v1,v2);
	}else{
		printf("No Solution\n");
	}
	return 0;
} 


////以前写的
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 100010;
//int main()
//{
//	int n,m;
//	int coin[maxn];
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&coin[i]);
//	}
//	sort(coin,coin+n);
//	int left =0;
//	int right=n-1;
//	while(left<right&&coin[left]+coin[right]!=m)
//	{
//		if(coin[left]+coin[right]<m)
//			left++;
//		else if(coin[left]+coin[right]>m)
//			right--;
//	}
//	if(coin[left]+coin[right]==m&&left<right)
//		printf("%d %d\n",coin[left],coin[right]);
//	else
//		printf("No Solution\n");
//	return 0;
// } 

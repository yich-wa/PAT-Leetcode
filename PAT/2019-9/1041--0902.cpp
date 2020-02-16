//22:40--22:52
//对map的映射要非常熟悉。映射去，映射回来。 
#include<stdio.h>
#include<map>
using namespace std; 
const int maxn = 100005;
const int maxk = 10005;
int main(){
	int n;
	scanf("%d",&n);
	int temp;
	int num =0;
	map<int,int>mp;
	map<int,int>mp2;
	int K[maxk]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(mp.find(temp)==mp.end()){
			mp[temp]=num;
			mp2[num]=temp;
			num++;
		}
		int tempN = mp[temp];
		K[tempN]++;		
	}
	for(int i=0;i<num;i++){
		if(K[i]==1){
			printf("%d",mp2[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}

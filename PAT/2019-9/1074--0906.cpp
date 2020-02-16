//15:04-- 15:54 //犯了一些很愚蠢，很基础的错误。
//写的不够稳健。 
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 100005;
struct node{
	int add;
	int value;
	int next;
}N[maxn];
int main(){
	int firAdd,n,k;
	scanf("%d%d%d",&firAdd,&n,&k);
	int tempA;
	for(int i=0;i<n;i++){
		scanf("%d",&tempA);
		scanf("%d%d",&N[tempA].value,&N[tempA].next);
		N[tempA].add = tempA;
	}
	int p =firAdd;
	vector<node>v,output;
	while(p!=-1){
		v.push_back(N[p]);
		p = N[p].next;
	}
	int num = v.size();
	int st;
	stack<node>s;
	for(int i=0;i<num;){
		st = i;
		if(st+k-1<num){
			for(int j= st+k-1;j>=st;j--){
				output.push_back(v[j]);
				i++;
//				printf("  %05d %d %05d****\n",v[j].add,v[j].value,v[j].next);
			}
		}else{
			for(int j= st;j<num;j++){
				output.push_back(v[j]);
				i++;
//				printf("  %05d %d %05d****\n",v[j].add,v[j].value,v[j].next);
			}
		}
	}
	for(int i=0;i<num;i++){
		if(i!=0){
			printf("%05d\n",output[i].add);
		}
		printf("%05d %d ",output[i].add,output[i].value);
	}
	printf("-1\n");
	return 0;
} 

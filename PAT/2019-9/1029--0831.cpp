//21:21--22:31 得分13分。 
//--22:45
//最后借鉴书上思路，做完了
//从小比较，两两比较，有点像两个有序序列归一样。
//挑小的，逐渐压到向量里。压到一半时，那个数就是：中位数。 
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std; 
const int maxn = 200005;
int main(){
	int n1,n2;
	int s1[maxn];
	int s2[maxn];
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		scanf("%d",&s1[i]);
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		scanf("%d",&s2[i]);
	}
	int n3 = (n1+n2+1)/2;
	//先把下面两种特殊情况直接输出。 
//	printf("%d***\n",n3); 
	if(s1[n1-1]<s2[0]){
		if(n3<=n1){
			printf("%d",s1[n3-1]);
		}else{
			printf("%d",s2[n3-1-n1]);	
		}
		return 0;
	}
	if(s2[n2-1]<s1[0]){
		if(n3<=n2){
			printf("%d",s2[n3-1]);
		}else{
			printf("%d",s1[n3-1-n2]);
		}
		return 0;
	}
	int p1 = 0;
	int p2 = 0;
	int num =1;
	//n3,num都指的是第几个数，而p1,p2等是角标。 
	while(num<n3&&p1<n1&&p2<n2){
		if(s1[p1]<s2[p2]){
			p1++;
			num++;
		}else if(s1[p1]>s2[p2]){
			p2++;
			num++;
		}else{
			p1++;
			p2++;
			num+=2;
		}
	}
	if(num==n3){
		printf("%d",min(s1[p1],s2[p2]));
	}else if(num>n3){
		printf("%d",s1[p1-1]);
	}else if(num<n3&&p1==n1){
		while(num<n3&&p2<n2){
			num++;
			p2++;
		}
		printf("%d",s2[p2]);
	}else{
		while(num<n3&&p1<n1){
			num++;
			p1++;
		}
		printf("%d",s1[p1]);
	}
	return 0;
} 

////以前做的：
//#include<stdio.h>
//const int maxn =200005;
//const int inf = 0x7fffffff; 
//int seq[2][maxn];
//int main()
//{
//	
//	int n[2];
//	for(int i=0;i<2;i++)
//	{
//		scanf("%d",&n[i]);
//		for(int j=0;j<n[i];j++)
//			scanf("%d",&seq[i][j]);
//	}
//	seq[0][n[0]]=inf;
//	seq[1][n[1]]=inf;
//	int num0=0;
//	int num1 =0;
//	int num =0;
//	int mid = n[0]+n[1];
//	mid = (mid-1)/2; 
//	while(num!=mid)
//	{
//		if(seq[0][num0]<seq[1][num1])
//		{
//			num0++;
//		}
//		else
//		{
//			num1++;
//		}
//		num++;
//	}	
//	int temp ;
//	if(seq[0][num0]<seq[1][num1])
//		temp = seq[0][num0];
//	else
//		temp = seq[1][num1];
//	printf("%d\n",temp);
//	return 0;
//} 

#include<stdio.h>
#include<vector> 
using namespace std;
int main(){
	int m,n;
	scanf("%d",&m);
	double a[1002] = {0};
	int tempExp;
	double tempCoe;
	for(int i=0;i<m;i++){
		scanf("%d %lf",&tempExp,&tempCoe);
		a[tempExp] =tempCoe;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %lf",&tempExp,&tempCoe);
		a[tempExp]+=tempCoe; 
	}
	vector<int>vec;
	for(int i=1001;i>=0;i--){
		if(a[i]!=0){
			vec.push_back(i);
		}
	}
	printf("%d",vec.size());
	for(int i=0;i<vec.size();i++){
		printf(" %d %.1f",vec[i],a[vec[i]]);
	}
	return 0;
} 

////
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std; 
//const int maxn =1005;
//int main()
//{
//	int n,m;
//	float co1[maxn]={0};
//	bool flag[maxn]={false};
//	vector<int>output;
//	int exp;
//	float coe;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d %f",&exp,&coe);
//		//printf("&**\n"); 
//		co1[exp]=coe;
//		output.push_back(exp);
//		flag[exp]=true;	
//	}
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%f",&exp,&coe);
//		co1[exp]+=coe;
//		if(co1[exp]!=0&&flag[exp]==false)
//			output.push_back(exp);
//	}
//	sort(output.begin(),output.end());
//	int count =0;
//	for(int i=output.size()-1;i>=0;i--)
//	{
//		if(co1[output[i]]!=0)
//			count++;
//	}
//	printf("%d",count);
//	for(int i=output.size()-1;i>=0;i--)
//	{
//		if(co1[output[i]]!=0)
//		{
//			printf(" %d %.1f",output[i],co1[output[i]]); 
//		}
//	}
//	printf("\n");
//	return 0;	
// } 


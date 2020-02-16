//是多项式的乘法。第一个多项式存储系数和指数。第二个直接计算结果。 
// 结果存储的时候，可能同一指数，多个系数，那几个系数相加也有可能
// 等于0；
// 先寄存一遍，在向量中，然后用另一个向量去综合一下。
// 复习：向量的查找和插入，还有集合的方法。 

//首次15分，有2个段错误的点。 开始把maxn开到1005估计不够，
// 因为两个指数为1000的数相乘，指数相加，为2000+ 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int maxn = 2005;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int k1,k2;
	vector<int>ex1,ex2;
	vector<double>co1,co2;
	vector<int>ex_temp,ex_final;
	double sum[maxn];
	int tempEx,sumEx;
	double tempCo,sumCo; 
	scanf("%d",&k1);
	for(int i=0;i<k1;i++){
		scanf("%d %lf",&tempEx,&tempCo);
		ex1.push_back(tempEx);
		co1.push_back(tempCo); 
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++){
		scanf("%d %lf",&tempEx,&tempCo);
		for(int j=0;j<ex1.size();j++){
			sumCo = co1[j]*tempCo;
			sumEx = ex1[j] + tempEx;
			sum[sumEx] +=sumCo;
			ex_temp.push_back(sumEx);
		}
	}
	sort(ex_temp.begin(),ex_temp.begin()+ex_temp.size(),cmp);
	int last = -1;
	for(int i=0;i<ex_temp.size();i++){
		if(ex_temp[i]!=last){
			if(sum[ex_temp[i]]!=0){
				ex_final.push_back(ex_temp[i]);
			}
			last = ex_temp[i];
		}
	}
	printf("%d",ex_final.size());
	for(int i=0;i<ex_final.size();i++){
		printf(" %d %.1f",ex_final[i],sum[ex_final[i]]);
	} 
	return 0;	
} 


//// 以前写的
//#include<stdio.h>
//#include<math.h>
//#include<vector>
//#include<algorithm> 
//using namespace std;
////下面数值开错5分段错误 
//const int maxn = 2005;
//int main()
//{
//	int n1,n2;
//	vector<int>ex1,ex2;
//	vector<double>co1,co2;
//	scanf("%d",&n1);
//	int tempex;
//	double tempco;
//	for(int i=0;i<n1;i++)
//	{
//		scanf("%d%lf",&tempex,&tempco);
//		ex1.push_back(tempex);
//		co1.push_back(tempco);
//	}
//	scanf("%d",&n2);
//	for(int i=0;i<n2;i++)
//	{
//		scanf("%d%lf",&tempex,&tempco);
//		ex2.push_back(tempex);
//		co2.push_back(tempco);
//	}
//	vector<int>exout,exout2;
//	double co[maxn]={0};
//	bool flag[maxn]={false}; 
//	for(int i=0;i<ex1.size();i++)
//	{
//		for(int j=0;j<ex2.size();j++)
//		{
//			tempex = ex1[i]+ex2[j];
//			tempco = co1[i]*co2[j];
//			co[tempex]+=tempco;
//			exout.push_back(tempex);
//		}	
//	}
// 	for(int i=0;i<exout.size();i++)
// 	{
// 		tempex= exout[i];
// 		if(co[tempex]!=0&&flag[tempex]==false)
// 		{
// 			exout2.push_back(tempex);
// 			flag[tempex]=true;
//		 }
//	 }
//	 printf("%d",exout2.size());
//	 //发现自己忘记给系数排序了。 
//	 sort(exout2.begin(),exout2.end()); 
//	 for(int i=exout2.size()-1;i>=0;i--)
//	 {
//	 	printf(" %d %.1f",exout2[i],co[exout2[i]]);
//	 }
//	 return 0;
//}


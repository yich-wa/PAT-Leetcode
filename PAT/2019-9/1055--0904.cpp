//15:10--15:41 ，题不难，但是注意排序的cmp函数。 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
struct rich{
	char name[10];
	int age;
	int worth;
}temp;
vector<rich>v;
bool cmp(rich a,rich b){
	if(a.worth!=b.worth){
		return a.worth>b.worth;
	}else if(a.age!=b.age){
		return a.age<b.age;
	}else{
		return strcmp(a.name,b.name)<0; 
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d%d",temp.name,&temp.age,&temp.worth);
		v.push_back(temp);
	}
	sort(v.begin(),v.begin()+v.size(),cmp);
	int m,aMin,aMax;
	int len = v.size();
	for(int i=1;i<=k;i++){
		 scanf("%d%d%d",&m,&aMin,&aMax);
		 printf("Case #%d:\n",i);
		 int num =0;
		 int j =0;
		 while(num<m&&j<len){
		 	if(v[j].age>=aMin&&v[j].age<=aMax){
		 		printf("%s %d %d\n",v[j].name,v[j].age,v[j].worth);
		 		num++;
			 }
			 j++;
		 }
		 if(num==0){
		 	printf("None\n");
		 }	
	}
	return 0;
} 

//
////以前做的
//#include<stdio.h>
//#include<vector>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 100010;
//struct billion{
//	char name[10];
//	int age;
//	int worth;
//}temp;
//vector<billion>input;
//vector<billion>output;
//bool cmp1(billion a,billion b)
//{
//	if(a.worth!=b.worth)
//		return a.worth>b.worth;
//	else
//	{
//		if(a.age!=b.age)
//			return a.age<b.age;
//		else
//			return strcmp(a.name,b.name)<0;
//	}
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s %d%d",temp.name,&temp.age,&temp.worth);
//		input.push_back(temp);
//	 } 
//	sort(input.begin(),input.end(),cmp1);
//	int m,amin,amax;
//	for(int i=1;i<=k;i++)
//	{
//		scanf("%d%d%d",&m,&amin,&amax);
//		printf("Case #%d:\n",i);
//		int count=0;
//		for(int j=0;j<input.size();j++)
//		{
//			//开始是： (input[j].age>=amin&&input[j].age<=amax&&count<m)
//			//上面那样是有超时的。而下面这种判断方式，会省掉一些不必要的。
//			if(count>=m)
//				break; 
//			if(input[j].age>=amin&&input[j].age<=amax)
//			{
//			printf("%s %d %d\n",input[j].name,input[j].age,input[j].worth);
//			count++;
//			}	
//		}
//		if(count==0)
//			printf("None\n");	
//	 } 
//	return 0;
//} 

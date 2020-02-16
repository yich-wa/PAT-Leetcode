//15:44——
///第一遍写完。 
///写完最后，所有的名字，全部变成最后的一个名字字符串。
//用vector<char*>v 是有问题的。 如果同一个char temp[] 输入一次，压入
//向量数组一次。向量数组中所有的字符串，都是最后一次输入那个。 
//因为char 数组，记录的是，字符串的首地址。而地址本身是不变的。 

//改成string 后是21分 有5分运行超时。这就是为什么名字是三个大写字母加
//一个数字的原因吧。是让你映射的吧。  

////用vector<char*>v的错误写法。错误原因。见上。
//本题可以先用字符串数组。把名字存储起来。然后用角标去操作即可。
//最后用角标去找对应字符串。 有较为简单的方式，先用简单的方式。
// 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxk = 2505;
const int maxn = 40005;
char name[maxn][5]; 
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int c;
	int tempC;
	
	vector<int>course[maxk];
	for(int i=0;i<n;i++){
		char tempN[5];
		scanf("%s %d",name[i],&c);
		for(int j=0;j<c;j++){
			scanf("%d",&tempC);
			course[tempC].push_back(i);
		}
	} 
	for(int i=1;i<=k;i++){
		sort(course[i].begin(),course[i].begin()+course[i].size(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
} 





////string做法会超时4分钟。 
//#include<stdio.h>
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//const int maxn = 2505;
//bool cmp(string a,string b){
//	return a<b;
//}
//int main(){
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int c;
//	int tempC;
//	string tempN;
//	vector<string>course[maxn];
//	for(int i=0;i<n;i++){
//		cin>>tempN>>c;
//		for(int j=0;j<c;j++){
//			scanf("%d",&tempC);
//			course[tempC].push_back(tempN);
//		} 
//	} 
//
//	 
//	for(int i=1;i<=k;i++){
//		sort(course[i].begin(),course[i].begin()+course[i].size(),cmp);
//		printf("%d %d\n",i,course[i].size());
//		for(int j=0;j<course[i].size();j++){
//			cout<<course[i][j]<<endl;
//		}
//	}
//	return 0;
//}




////以前的写法
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//using namespace std;
//const int maxn = 2505;
//vector<string>course[maxn];
//bool cmp(string a, string b)
//{
//	return a<b;
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int c_num;
//	int c;
//	string tempname;
//	for(int i=0;i<n;i++)
//	{
//		cin>>tempname;
//		scanf("%d",&c_num);
//		for(int j=0;j<c_num;j++)
//		{
//			scanf("%d",&c);
//			course[c].push_back(tempname);
//		}
//	}
//	for(int i=1;i<=k;i++)
//	{
//		printf("%d %d\n",i,course[i].size());
//		sort(course[i].begin(),course[i].end(),cmp);
//		for(int j=0;j<course[i].size();j++)
//		{
//			printf("%s\n",course[i][j].c_str());
//		}
//	}
//	return 0;
//} 

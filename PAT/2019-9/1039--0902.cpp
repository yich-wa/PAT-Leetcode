//16：58--中间水了好久的手机
//太傻逼了。第一次，一个格式错误，一个超时。只拿了8分。 
//怀疑cin,cout，会超时。其次。用map，就必须用string
//然后就必须用cin,cout。可以换一种写法，将名字映射成 数字。
//比如采用10进制位数。 

//向量数组，角标开的过大。程序会直接终止。 

//改成普通映射之后。整体程序会自动终止，无法输入。发现是因为
//直接用映射之后的数字当做向量的角标的话，太大了。即向量角标开的太大了 
//改小可以运行，但是似乎不够。所以还是要将数字映射成较小的角标。 改成这样还是23分
// 最后两分段错误。 
//角标开成 const int maxn = 26*26*26*10+1;   拿到25分。 
//可以不用进一步映射： 
//如果你不知道const int maxn要定多少，可以定：const int maxn = 26*26*26*10+1; 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map> 
#include<string.h>
using namespace std;
const int maxn = 26*26*26*10+1;
int trans(char s[]){
	int len = strlen(s);
	int sum;
	if(len>=4){	
		sum = s[3]-'0';
		sum +=(s[2]-'A')*10;
		sum +=(s[1]-'A')*26*10;
		sum +=(s[0]-'A')*26*26*10;
	}
	return sum;
} 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int cIndex,sNum;
	map<int,int>mp;
	int num =0; 
	vector<int>v[maxn];
	char sName[5];
	for(int i=0;i<k;i++){
		scanf("%d%d",&cIndex,&sNum);
		for(int i=0;i<sNum;i++){
			scanf("%s",sName);
			int temp;
			int tempN = trans(sName);
			if(mp.find(tempN)==mp.end()){
				mp[tempN]=num++;
			}
			temp = mp[tempN];
			v[temp].push_back(cIndex);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",sName);
		int tempN = trans(sName);
		if(mp.find(tempN)==mp.end()){
			printf("%s 0\n",sName);
		}else{
			int temp = mp[tempN];
			printf("%s %d",sName,v[temp].size());
			sort(v[temp].begin(),v[temp].begin()+v[temp].size());
			for(int j=0;j<v[temp].size();j++){
				printf(" %d",v[temp][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

////cincout 8分写法
//其实该写法正常的分是23分。是怪你将最后的换行输出放错位置。应该放在else里面。
//而不是放在整体外面 
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//#include<string.h>
//#include<map>
//using namespace std;
//const int maxn = 200005;
//int trans(char s[]){
//	int sum;
//	sum = s[3]-'0';
//	sum +=(s[2]-'A')*10;
//	sum +=(s[1]-'A')*26*10;
//	sum +=(s[0]-'A')*26*26*10;
//	return sum;
//} 
//int main(){
//	int n,k;
//	cin>>n>>k;
//	printf("%d%d",&n,&k)
//	int cIndex,sNum;
//	int num =0;
//	map<string,int>mp;
//	vector<int>v[maxn];
//	string sName;
//	for(int i=0;i<k;i++){
//		cin>>cIndex>>sNum;
//		for(int i=0;i<sNum;i++){
//			cin>>sName;
//			if(mp.find(sName)==mp.end()){
//				mp[sName]=num++;
//			}
//			int temp = mp[sName];
//			v[temp].push_back(cIndex);
//		}
//	}
//	for(int i=0;i<n;i++){
//		cin>>sName;
//		if(mp.find(sName)==mp.end()){
//			cout<<sName<<" 0"<<endl;
//		}else{
//			int temp = mp[sName];
//			cout<<sName<<" "<<v[temp].size();
//			sort(v[temp].begin(),v[temp].begin()+v[temp].size());
//			for(int j=0;j<v[temp].size();j++){
//				cout<<" "<<v[temp][j];
//			}
//		cout<<endl;
//		}
//换行不能放在这个位置输出。 
//	}
//	return 0;
//} 

//
////以前写的
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//#include<map>
//using namespace std;
//const int maxn = 40002;
//int main()
//{
//	map<string ,int>mp; 
//	map<int,string>r_mp;
//	vector<int>student[maxn];	
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int index;
//	int num;
//	string tempname;
//	int s_id=0;
//	int id;
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d%d",&index,&num);
//		getchar();
//		for(int j=0;j<num;j++)
//		{
//			cin>>tempname;
//			if(mp.find(tempname)==mp.end())
//			{
//				mp[tempname]=s_id++;
//			}
//			id = mp[tempname];
//			student[id].push_back(index);
//		}
//	}
//	s_id =-1;
//	vector<int>output; 
//	for(int i=0;i<n;i++)
//	{
//		cin>>tempname;
//		cout<<tempname;
//		if(mp.find(tempname)==mp.end())
//		{
//			printf(" 0\n");
//		} 
//		else
//		{
//			id = mp[tempname];
//			printf(" %d",student[id].size());
//			sort(student[id].begin(),student[id].end());
//			for(int j=0;j<student[id].size();j++)
//			{
//				printf(" %d",student[id][j]);
//			}
//			printf("\n");	
//		}
//	}
//	return 0;
//} 

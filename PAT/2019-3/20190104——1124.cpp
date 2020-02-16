//PAT——1124题，首先题中尽管有单词不能准确翻译，结合“已知
//单词的意思”和题中所给数据，可以准确猜出题意。这道题一开始
//猜了一种符合数据，但不符合题意的意思。结果只拿了14分。
//“数据”+“题意”两者都要符合，否则你就要推到重来，埋葬你的
//一定是你浪费的时间。
//其次map映射要很熟悉，尤其是 首次映射。怎样判断以前是否有过
//映射。尽量利用map<string,int>映射。if(!map[str]) 可表是否已有映射数
 
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
const int maxm =1005;
map<string ,int>mp;
map<string,bool>mp2;
vector<int>V;
int main()
{
	int m,n,s;
	string str[maxm];
	int count =0;
	scanf("%d %d %d",&m,&n,&s);
	for(int i=1;i<=m;i++)
	{
		cin>>str[i];
		if(i==s)
		{
			if(!mp[str[i]])
			{
				V.push_back(i);
				mp[str[i]]=1;
				s=s+n;
				//printf("%d\n",s);
			}
			else
			{
				s++;
			}
		}	
	 } 
	for(int i=0;i<V.size();i++)
		cout<<str[V[i]]<<endl;
	if(V.size()==0)
	 	cout<<"Keep going..."<<endl;
	return 0;
}


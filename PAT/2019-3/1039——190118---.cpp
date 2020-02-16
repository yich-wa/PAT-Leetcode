//15:25——16:06 

//23分 ，2分的段错误。
//一直把maxn改成 50都还是2分的"段错误"
//书中答案说，使用map<string,int>最后一个测试点会超时。
//因此必须使用字符串的hash 法。将名字映射成数字。
//答案说是最后一组数据会超内存限度。

//书上答案是输入一个查询，就输出一个查询。
//暂时放弃那个段错误。访问内存超限 
 
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
const int maxn = 20000;
int main()
{
	map<string ,int>mp; 
	map<int,string>r_mp;
	vector<int>student[maxn];	
	int n,k;
	scanf("%d%d",&n,&k);
	int index;
	int num;
	string tempname;
	int s_id=0;
	int id;
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&index,&num);
		getchar();
		for(int j=0;j<num;j++)
		{
			cin>>tempname;
			if(mp.find(tempname)==mp.end())
			{
				mp[tempname]=s_id++;
			}
			id = mp[tempname];
			student[id].push_back(index);
		}
	}
	s_id =-1;
	vector<int>output; 
	for(int i=0;i<n;i++)
	{
		cin>>tempname;
		cout<<tempname;
		if(mp.find(tempname)==mp.end())
		{
			printf(" 0\n");
		} 
		else
		{
			id = mp[tempname];
			printf(" %d",student[id].size());
			sort(student[id].begin(),student[id].end());
			for(int j=0;j<student[id].size();j++)
			{
				printf(" %d",student[id][j]);
			}
			printf("\n");	
		}
	}
	return 0;
}
 
 //一次输入统一输出如下： 
  
// #include<stdio.h>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//#include<map>
//using namespace std;
//const int maxn = 20000;
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
//		if(mp.find(tempname)==mp.end())
//		{
//			mp[tempname]=s_id--;
//		} 
//		id = mp[tempname];
//		r_mp[id]=tempname;
//		output.push_back(id);
//	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<r_mp[output[i]];
//		id=output[i];
//		if(id>=0)
//		{	
//			printf(" %d",student[id].size());
//			sort(student[id].begin(),student[id].end());
//			for(int j=0;j<student[id].size();j++)
//			{
//				printf(" %d",student[id][j]);
//			}
//			printf("\n");	
//		}
//		else
//		{
//			printf(" 0\n");
//		}
//	}
//	return 0;
// } 

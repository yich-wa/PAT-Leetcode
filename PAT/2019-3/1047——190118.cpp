//20:00——20:35 
//20分，有5分运行超时。 
//然后将cout输出，改为用scanf,结合string.c_str();输出搞定。 

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int maxn = 2505;
vector<string>course[maxn];
bool cmp(string a, string b)
{
	return a<b;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int c_num;
	int c;
	string tempname;
	for(int i=0;i<n;i++)
	{
		cin>>tempname;
		scanf("%d",&c_num);
		for(int j=0;j<c_num;j++)
		{
			scanf("%d",&c);
			course[c].push_back(tempname);
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++)
		{
			printf("%s\n",course[i][j].c_str());
		}
	}
	return 0;
}
 

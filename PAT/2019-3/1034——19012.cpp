//21:34——
//22:17 25分 5分答案错误
// 
//做题思路是先找集合的爸爸，然后把该群体的人都放到该爸爸的队列里。
//然后在每个爸爸队列里，挑出通话时间最长的头。
//但你对群体的排序，应该在确定每个集合的头的之后。所以你有5分错误。
// 
//改完后是30分。 
#include<stdio.h> 
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<set> 
#include<map>
using namespace std;
const int maxn = 2002;//1000通电话，最多有2000个人。 
int father[maxn];
int head[maxn];
map<string,int>mp;
map<int,string>mp2; 

//并查集和路径压缩。 
int findfather(int a)
{
	int x= a;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[a]!=x)
	{
		int b =father[a];
		father[a]=x;
		a=b;
	}
	return x;
}

bool cmp(int a,int b)
{
	return mp2[head[a]]<mp2[head[b]];
}

int main()
{
	int n,k;
	string str1,str2;
	int len;
	int lenth[maxn]={0};
	int id=0;
	for(int i=0;i<maxn;i++)
	{
		father[i]=i;
	}
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		cin>>str1>>str2>>len;
		int id1,id2,fa1,fa2;
		if(mp.find(str1)==mp.end())
		{
			mp[str1]=id++;
		}
		id1= mp[str1];
		mp2[id1]=str1;
		lenth[id1]+=len;
		if(mp.find(str2)==mp.end())
		{
			mp[str2]=id++;
		}
		id2= mp[str2];
		mp2[id2]=str2;
		lenth[id2]+=len;
		fa1 = findfather(id1);
		fa2 = findfather(id2);
		if(fa1!=fa2)
		{
			father[fa1]=fa2;
		}
	}
	vector<int>ga;
	vector<int>member[maxn]; 
	bool flag[maxn]={false};
	int totallen[maxn]={0};
	for(int i=0;i<id;i++)
	{
		int temp = findfather(i);
		member[temp].push_back(i);
		totallen[temp]+=lenth[i];
		if(flag[temp]==false&&member[temp].size()>2&&totallen[temp]>k*2)
		{
			ga.push_back(temp);
			flag[temp]=true;
		}
	}
	for(int i=0;i<ga.size();i++)
	{
		int temp =ga[i];
		int maxgtime=-1;
		for(int j=0;j<member[temp].size();j++)
		{
			int tempid = member[temp][j];
			if(lenth[tempid]>maxgtime)
			{
				maxgtime=lenth[tempid];
				head[temp]=tempid;
			}
		}
	} 
	sort(ga.begin(),ga.end(),cmp);
	printf("%d\n",ga.size());
	for(int i=0;i<ga.size();i++)
	{
		int temp =ga[i];
		cout<<mp2[head[temp]]<<" "<<member[temp].size()<<endl;
	}
	return 0;
}

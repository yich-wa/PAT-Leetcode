//21:34����
//22:17 25�� 5�ִ𰸴���
// 
//����˼·�����Ҽ��ϵİְ֣�Ȼ��Ѹ�Ⱥ����˶��ŵ��ðְֵĶ����
//Ȼ����ÿ���ְֶ��������ͨ��ʱ�����ͷ��
//�����Ⱥ�������Ӧ����ȷ��ÿ�����ϵ�ͷ��֮����������5�ִ���
// 
//�������30�֡� 
#include<stdio.h> 
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<set> 
#include<map>
using namespace std;
const int maxn = 2002;//1000ͨ�绰�������2000���ˡ� 
int father[maxn];
int head[maxn];
map<string,int>mp;
map<int,string>mp2; 

//���鼯��·��ѹ���� 
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

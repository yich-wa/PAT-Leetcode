//15:25����16:06 

//23�� ��2�ֵĶδ���
//һֱ��maxn�ĳ� 50������2�ֵ�"�δ���"
//���д�˵��ʹ��map<string,int>���һ�����Ե�ᳬʱ��
//��˱���ʹ���ַ�����hash ����������ӳ������֡�
//��˵�����һ�����ݻᳬ�ڴ��޶ȡ�

//���ϴ�������һ����ѯ�������һ����ѯ��
//��ʱ�����Ǹ��δ��󡣷����ڴ泬�� 
 
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
 
 //һ������ͳһ������£� 
  
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

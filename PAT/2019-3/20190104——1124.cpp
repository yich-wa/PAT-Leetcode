//PAT����1124�⣬�������о����е��ʲ���׼ȷ���룬��ϡ���֪
//���ʵ���˼���������������ݣ�����׼ȷ�³����⡣�����һ��ʼ
//����һ�ַ������ݣ����������������˼�����ֻ����14�֡�
//�����ݡ�+�����⡱���߶�Ҫ���ϣ��������Ҫ�Ƶ��������������
//һ�������˷ѵ�ʱ�䡣
//���mapӳ��Ҫ����Ϥ�������� �״�ӳ�䡣�����ж���ǰ�Ƿ��й�
//ӳ�䡣��������map<string,int>ӳ�䡣if(!map[str]) �ɱ��Ƿ�����ӳ����
 
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


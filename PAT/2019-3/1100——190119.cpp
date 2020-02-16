//19:25——
//
//初次12分。 其余全答案错误。 
// 发现字符串旁边低级失误填了空格，改完16分。
// 

//想到自己13输出可能是错误的。直接是tam 而不是tam tret; 
//进而发现，像13,26,39这样的数，都多输出了个tret; 
//改完后为20分。。

//上面那个点，其实题中数据已经间接给出了提示。所以数据中也包含
//着题意。 
//——20：10 
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	map<int,string>mph1;
	string high[13]={" ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string low[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	map<int,string>mpl1;
	map<string,int>mph2 ;
	map<string,int>mpl2;
	for(int i=0;i<13;i++)
	{
		mph1[i]=high[i];
		mpl1[i]=low[i];
		mph2[high[i]]=i;
		mpl2[low[i]]=i;
	}
	int n;
	scanf("%d",&n);
	getchar();
	string str;
	string str1;
	int number;
	for(int i=0;i<n;i++)
	{
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9')
		{
			sscanf(str.c_str(),"%d",&number);
			if(number%13==0&&number!=0)
			{
				cout<<mph1[number/13]<<endl;
			}
			else if(number>12)
			{
				cout<<mph1[number/13]<<" "<<mpl1[number%13]<<endl; 
			}
			else
			{
				cout<<mpl1[number]<<endl;
			}
		}
		else
		{
			if(mpl2.find(str)!=mpl2.end())
			{
				cout<<mpl2[str]<<endl;
				continue;
			}
			else if(mph2.find(str)!=mph2.end())
			{
				number= mph2[str]*13;
				cout<<number<<endl;
			}
			else 
			{
				str1 = str.substr(0,3);
				str.erase(0,4);
				int out = mph2[str1]*13+mpl2[str];
				cout<<out<<endl;
			}	
		}
	}
	return 0;
 } 

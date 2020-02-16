//20:30——

//——20:59 string 中，单个字符由大写转化为小写，似乎有猫腻
//以及删除个别字符，似乎有问题。 
//无法替换， 无法删除 
//string中无法替换指定字符，更无法删除指定字符 
//提取单个单词string ，最好还是用复制出来解决。

//反思，答案的做法更重要体现在集中精力在有用的字符上。
//而无效字符。至于大小写的转换。 先借鉴答案的做法。大写+32
//成为小写。 

//下面做法为借鉴答案做法。发现原先写的一个低级错误
//字符写串了。 
//——21:39 
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool ischeck(char a)
{
	if(a>='0'&&a<='9')
		return true;
	if(a>='a'&&a<='z')
		return true;
	if(a>='A'&&a<='Z')
		return true;
	return false;
}
int main()
{
	string str;
	map<string,int>mp;
	getline(cin,str);
//	cout<<str<<endl;
	string maxstr;
	int maxnum = 0;
	for(int i=0;i<str.length();)
	{
		if(ischeck(str[i])==true)
		{
			string str2;
			while(ischeck(str[i])==true)
			{
				if(str[i]>='A'&&str[i]<='Z')
				{
					str[i]+=32;
				}
				str2=str2+str[i];
				i++; 
			}
			if(mp.find(str2)==mp.end())
			{
				mp[str2]=1;
			}
			else
			{
				mp[str2]++;
			}
			if(mp[str2]>maxnum)
			{
				maxnum = mp[str2];
				maxstr = str2;
			}	
		 } 
		 else
		 {
		 	i++;
		 }	
	}
	cout<<maxstr<<" "<<maxnum<<endl;
	return 0; 	
} 
 
 
 
// #include<stdio.h>
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main()
//{
//	string str;
//	map<string,int>mp;
//	getline(cin,str);
////	cout<<str<<endl;
//	for(int i=0;i<str.length();)
//	{
//		if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z')||(str[i]=' '))
//		{
//			i++;
//		}
//		else if(str[i]>='A'&&str[i]<='Z')
//		{
//			str[i]='a'+str[i]-'A';
//			i++;
//		}
//		else
//		{
//			str.erase(i,1);
//		}	
//	}
////	cout<<str<<endl;
//	string str2;
//	string maxstr;
//	int maxnum = 0;
//	int i=0;
//	while(str[i]==' ')
//		i++;
//	int first = i;
//	int last;
//	str=str+" ";  
//	//末尾加上空格，方便下面处理。	
////下面的处理方式，建立在单词与单词之间只要有一个空格的基础之上。   
//	for(;i<str.length();i++)   
//	{
//		if(str[i]==' ')
//		{
//			str2=str.substr(first,i-first);
//			first = i+1;
//			if(mp.find(str2)==mp.end())
//			{
//				mp[str2]=1;
//			}
//			else
//			{
//				mp[str2]++;
//			}
//			if(mp[str2]>maxnum)
//			{
//				maxnum = mp[str2];
//				maxstr = str;
//			}	
//		}
//	}
//	cout<<maxstr<<" "<<maxnum<<endl;
//	return 0; 	
// } 

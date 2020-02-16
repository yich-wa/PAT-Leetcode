//08:44--09:24 
//有2分答案错误。
//string的单个，可以拿来，当char使用
//忘记了如何将：string，全部转换成小写，或者大写。
// transform(str.begin(),str.end(),str.begin(),::toupper);
//  transform(str.begin(),str.end(),str.begin(),::tolower);
//经过构造特殊样例试验：发现：最后一个字符是有效字符的情况错误。 
//这种题稳稳的肯定是能做出来的。思路清晰，不要受其他干扰。 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<string>
using namespace std;
const int maxn = 1048600;
bool isCh(char a){
//	printf("%c***%c\n",a);
	if(a>='0'&&a<='9')
	{
		return true;
	}else if(a>='A'&&a<='Z'){
		return true;
	}else if(a>='a'&&a<='z'){
		return true;
	}
	return false;
}
string trans(string a){
	for(int i=0;i<a.length();i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]='a'+(a[i]-'A');
		}
	}
	return a;
}
int main(){
	string str;
	getline(cin,str);
	int len = str.length();
	int st,ed;
	string tempW;
	map<string,int>mp;
	string maxS;
	int maxN =0;
	for(int i=0;i<len;){
		while(isCh(str[i])==false&&i<len){
			i++;
		}
//		printf("%d***\n",i);
		if(i==len){
			break;
		}
		st = i;
		ed = st+1;
		while(isCh(str[ed])==true&&ed<len){
			ed++;
		}
//		printf("%d***%d\n",st,ed);
		if(ed>len)
			break;
		tempW = str.substr(st,ed-st);
//		cout<<tempW<<endl;
		tempW = trans(tempW);
		if(mp.find(tempW)==mp.end()){
			mp[tempW]=1;
		}else{
			mp[tempW]++;
		}
		//判断并，更新最大值。 
		if(mp[tempW]>maxN){
			maxS = tempW;
			maxN = mp[tempW];
		}else if(mp[tempW]==maxN&&tempW<maxS){
			maxS = tempW;
		}
		i = ed;
	}
	cout<<maxS<<" "<<maxN<<endl;
	return 0;
}

////以前写的
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//bool ischeck(char a)
//{
//	if(a>='0'&&a<='9')
//		return true;
//	if(a>='a'&&a<='z')
//		return true;
//	if(a>='A'&&a<='Z')
//		return true;
//	return false;
//}
//int main()
//{
//	string str;
//	map<string,int>mp;
//	getline(cin,str);
////	cout<<str<<endl;
//	string maxstr;
//	int maxnum = 0;
//	for(int i=0;i<str.length();)
//	{
//		if(ischeck(str[i])==true)
//		{
//			string str2;
//			while(ischeck(str[i])==true)
//			{
//				if(str[i]>='A'&&str[i]<='Z')
//				{
//					str[i]+=32;
//				}
//				str2=str2+str[i];
//				i++; 
//			}
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
//				maxstr = str2;
//			}	
//		 } 
//		 else
//		 {
//		 	i++;
//		 }	
//	}
//	cout<<maxstr<<" "<<maxnum<<endl;
//	return 0; 	
// } 

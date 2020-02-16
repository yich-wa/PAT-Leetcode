//关键在于比较两个不一样长的数字字符串的大小。本题的比较方法很值得借鉴
//第一遍写完28分。 
//string的函数方法要复习。尤其是擦除方法。string.erase(pos,len) 
//
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool cmp(string a,string b){
	string temp1 = a+b;
	string temp2 = b+a;
	return temp1<temp2;	
}

int main(){
	int n;
	cin>>n;
	string str;
	vector<string>v;
	for(int i=0;i<n;i++){
		cin>>str;
		v.push_back(str);
		
	}
	sort(v.begin(),v.begin()+v.size(),cmp);
	string output;
	for(int i=0;i<v.size();i++){
		output=output+v[i];
//		cout<<output<<"    8888"<<endl;
	}
	while(output[0]=='0'&&output.size()>1){
		output.erase(0,1);
	}
	cout<<output<<endl;
	return 0;
}


////以前写的：
// #include<stdio.h>
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<string.h>
//using namespace std;
//const int maxn = 10010;
//const int maxc = 80010;
//bool cmp(string a ,string b)
//{
//	string str1=a+b;
//	string str2=b+a;
//	return str1<str2;
//}
//int main()
//{
//	int n;
//	string str[maxn];
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		cin>>str[i];
//	}
//	sort(str,str+n,cmp);
//	string output =str[0];
//	for(int i=1;i<n;i++)
//	{
//		output=output+str[i];
//	}
//	char coutput[maxc];
//	strcpy(coutput,output.c_str());
//	int len = strlen(coutput);
//	int k =0;
//	while(k<len&&coutput[k]=='0')
//		k++;
//	if(k==len)
//	{
//		printf("0\n");
//	 } 
//	 else
//	 {
//	 	for(int i=k;i<len;i++)
//	 		printf("%c",coutput[i]);
//	 	printf("\n");
//	 }	
//}

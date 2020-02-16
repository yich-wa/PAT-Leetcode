//14:13---15:02   18分。2分答案错误。
//有特殊值没有照顾到 
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
const int maxn = 10005;
int main(){
	string str;
	cin>>str;
	if(str[0]=='-'){
		printf("-");
	}
	str.erase(0,1);
	//小数点后有多少位bLen 
	int bLen;
	int exLen;
	string exStr;
	string beStr;
	for(int i=0;i<str.length();i++){
		if(str[i]=='E'){
			bLen = i-2;
			exLen = str.length()-(i+1);
			exStr = str.substr(i+1,exLen);
			beStr = str.substr(0,i);
		}
	}
//	cout<<bLen<<"***"<<endl;
	int exN;
	sscanf(exStr.c_str(),"%d",&exN);
	if(exN==0){
		cout<<beStr<<endl;
	}else if(exN<0){
		exN = -exN;
		//擦掉小数点 
		beStr.erase(1,1);
		exN--;
		printf("0.");
		while(exN>0){
			printf("0");
			exN--;
		}
		cout<<beStr<<endl;
	}else{
		beStr.erase(1,1);
		int resN;
		if(bLen<=exN){
			cout<<beStr;
			resN = exN-bLen;
			
			while(resN>0){
				cout<<"0";
				resN--;
			}
		}else{
			beStr.insert(beStr.begin()+exN,'.');
			cout<<beStr;
		}
	}
	return 0;		
}


////以前做的
//#include<stdio.h>
//#include<string.h>
//const int maxn = 10005;
//int main()
//{
//	char input[maxn] ;
//	char exp[6];
//	scanf("%s",input);
//	if(input[0]=='-')
//		printf("-");
//	int lenth =strlen(input);
//	bool ispo ;
//	int i=1;
//	while(input[i]!='E')
//		i++;
//	i++;
//	if(input[i]=='+')
//		ispo = true; 
//	else
//		ispo = false;
//	int num =0;
//	for(int j =i+1;j<=lenth;j++)
//	{
//		exp[num++]=input[j];
//	}
//	int d_exp;
//	sscanf(exp,"%d",&d_exp);
//	i--;
//	if(d_exp==0)
//	{
//		for(int j=1;j<i;j++)
//		{
//			printf("%c",input[j]);
//		}		
//	}	
//	else if(ispo==false)
//	{
//		printf("0.");
//		while(d_exp>1)
//		{
//			printf("0");
//			d_exp--;
//		}	
//		for(int j=1;j<i;j++)
//		{
//			if(input[j]!='.')
//			printf("%c",input[j]);
//		}
//	}
//	else if(ispo==true)
//	{
//		int count =-1;
//		int j=1;
//		while(j<i&&count<d_exp) 
//		{
//			if(input[j]!='.')
//			{
//				printf("%c",input[j]);
//				count++;
//			}	
//			j++;
//		}
//		if(count==d_exp&&j<i)
//		{
//			printf(".");
//			while(j<i)
//			{
//				printf("%c",input[j++]);
//			}
//		}
//		while(count<d_exp)
//		{
//			printf("0");
//			count++;
//		}
//	}
//	return 0;	
// } 

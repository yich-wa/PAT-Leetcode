//17:44——
//——18:32   23分，2分答案错误 


//采用str[0]和str[1]这种统一写法是对的。
// 10的0次方到底要不要输出。 
//开始写的是，不用输出。改成输出10^0，结果依旧是2分答案错误。
//看书发现： 4 000.0 0.0000是会出错的。数字的输出真是千奇百怪。 
// 

//改完后是25分。 
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 205;
int main()
{
	int n;
	string str[2];
	cin>>n>>str[0]>>str[1];
	int ten[2] ={0};
	for(int i=0;i<2;i++)
	{
		//先将前导'0'全抹掉。
		while(str[i][0]=='0')    
			str[i].erase(0,1);
		if(str[i][0]=='.')
		{
			str[i].erase(0,1);
			while(str[i][0]=='0') 
			{
				ten[i]--;
				str[i].erase(0,1);
			}
			//代表小数点后全是0的特殊情况
			if(str[i].length()==0)    
				ten[i]=0;
		}
		else
		{
			for(int j=0;j<str[i].length();j++)
			{
				if(str[i][j]!='.')
					ten[i]++;
				else
				{
					str[i].erase(j,1);
					break;
				}
			}
		}
		while(str[i].length()<n)
		{
			str[i]=str[i]+"0";
		}
		str[i]=str[i].substr(0,n);
	} 
	if(str[0]==str[1]&&ten[0]==ten[1])
	{
		cout<<"YES 0."<<str[0]<<"*10^"<<ten[0]<<endl;
//		if(ten[0]!=0)
//		cout<<"*10^"<<ten[0]<<endl;
//		else
//		cout<<endl;
	}
	else
	{
		cout<<"NO ";
		cout<<"0."<<str[0]<<"*10^"<<ten[0];
		cout<<" 0."<<str[1]<<"*10^"<<ten[1];
//		if(ten[0]!=0)
//		{
//			cout<<"0."<<str[0]<<"*10^"<<ten[0];
//		}
//		else
//		{
//			cout<<"0."<<str[0];
//		}
//		if(ten[1]!=0)
//		{
//			cout<<" 0."<<str[1]<<"*10^"<<ten[1];
//		}
//		else
//		{
//			cout<<" 0."<<str[1];
//		}
	}
	return 0;
}

//17:44����
//����18:32   23�֣�2�ִ𰸴��� 


//����str[0]��str[1]����ͳһд���ǶԵġ�
// 10��0�η�����Ҫ��Ҫ����� 
//��ʼд���ǣ�����������ĳ����10^0�����������2�ִ𰸴���
//���鷢�֣� 4 000.0 0.0000�ǻ����ġ����ֵ��������ǧ��ٹ֡� 
// 

//�������25�֡� 
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
		//�Ƚ�ǰ��'0'ȫĨ����
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
			//����С�����ȫ��0���������
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

//20:30����

//����20:59 string �У������ַ��ɴ�дת��ΪСд���ƺ���è��
//�Լ�ɾ�������ַ����ƺ������⡣ 
//�޷��滻�� �޷�ɾ�� 
//string���޷��滻ָ���ַ������޷�ɾ��ָ���ַ� 
//��ȡ��������string ����û����ø��Ƴ��������

//��˼���𰸵���������Ҫ�����ڼ��о��������õ��ַ��ϡ�
//����Ч�ַ������ڴ�Сд��ת���� �Ƚ���𰸵���������д+32
//��ΪСд�� 

//��������Ϊ���������������ԭ��д��һ���ͼ�����
//�ַ�д���ˡ� 
//����21:39 
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
//	//ĩβ���Ͽո񣬷������洦��	
////����Ĵ���ʽ�������ڵ����뵥��֮��ֻҪ��һ���ո�Ļ���֮�ϡ�   
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

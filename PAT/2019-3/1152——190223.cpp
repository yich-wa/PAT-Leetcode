//08:47 ����09:05 18��  2�ִ𰸴��� 
//���ɣ�������һЩ�ڵ����� �� 0����1�����г���������
//�ж�һ�������Ƿ�����������һ���ǵý��俪�����
// i*i<=a ���ɡ� ��������ŵ�Ľⷨ���ԱȲ�û�з��ֲ�һ���ĵط���
//�������ò��������֡� 
//�������ϲ�𰸵õ����ͣ����ʱ��Ҫ���ǰ����ġ�����0023
//֪ʶ�㣺�������ɱ�λ����ǰ���㡣 printf("%.*d", K, temp);
//���еĹ��ߺ�ģ�������ǳ������Ļ������·����ߺܶࡣ
//��Ҫ������Ĺ��ߺ�֪ʶ��Ҫ�ǳ������������� 

//���죬�ж��Ƿ���������ϸ�ڡ��ж�string.substr(pos,len); �Լ�str.c_str()  ;
//sscanf,�Լ�sprintf 
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
bool isprime(int a)
{
	if(a==0||a==1)
		return false; 
	for(int i = 2;i*i<=a;i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}
int main()
{
	string ori;
	int L,K;
	cin>>L>>K>>ori;
	int temp;
	for(int i=0;i<=L-K;i++)
	{
		string str = ori.substr(i,K);
		//temp = stoi(t); //�ַ�����������ת���� 
		sscanf(str.c_str(),"%d",&temp);
		if(isprime(temp))
		{
			printf("%.*d", K, temp);
			return 0;	
		}
	}
	cout<<"404"<<endl;
	return 0;
}

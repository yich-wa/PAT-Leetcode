//08:47 ——09:05 18分  2分答案错误 
//怀疑，是有有一些节的数是 ： 0或者1被误判成了素数。
//判断一个数，是否是素数。不一定非得将其开方求出
// i*i<=a 即可。 经过看柳诺的解法，对比并没有发现不一样的地方。
//但就是拿不到那两分。 
//经过网上查答案得到解释：输出时，要输出前导零的。比如0023
//知识点：如何输出可变位数的前导零。 printf("%.*d", K, temp);
//所有的工具和模板如果你非常清晰的话，你的路会好走很多。
//重要额是你的工具和知识点要非常熟练，清晰。 

//考察，判断是否是素数的细节。判断string.substr(pos,len); 以及str.c_str()  ;
//sscanf,以及sprintf 
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
		//temp = stoi(t); //字符串向整数的转化。 
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

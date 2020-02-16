//16:14 
//这道题写了蛮长时间的。首先你不能用每个字母的编码长度去对比是否一样
//来判断是否合格。应该用总的长度一样去判断是否合理。 
//所以你应该通过求其中一个哈夫曼树，得到总的编码长度。
//理清哈夫曼的编码长度如何去求。 
//后面也因为 map使用不熟练出国小问题。。主要是：mp.find(str)==mp.end()
//表示从来没有出现过。

//整体的有两个判别标准，
//其一是：最终结果的总编码长度应该一致。
////要求你求出一个哈夫曼编码的长度，然后作比较。 
//其二是：一个不能是另一个的前缀。 
////第一遍将其前缀都进行标记。 

///在一个同学的编码中，将其前缀编码都用 map<string,int>mp 建立映射。
//表示这些前缀不能再用做编码。为防止不同同学的mp映射之间互相影响 
//将前缀都映射成，该同学编号。

//中间用了很多次printf 按阶段步骤debug
 

//拿到19分。 第1、2 、6测试点错误。 
 
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 150;
struct Item{
	string cha;
	int fre;
	int lenth;
}item[maxn];
bool cmp(int a,int b)
{
	return item[a].fre>item[b].fre;
}
int main()
{
	int n; 
	cin>>n;
	int pre[maxn];
	int Id[maxn];
	map<string,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>item[i].cha>>item[i].fre;
		//scanf("%c %d",&item[i].cha,&item[i].fre);
		Id[i]=i;
	}
	//printf("%d**\n",n);
	int num =n;
	int numId = n;
	while(num>1)
	{
		sort(Id,Id+num,cmp);
		int newfre = item[Id[num-1]].fre+item[Id[num-2]].fre;
		pre[Id[num-1]]=numId;
		pre[Id[num-2]]=numId;
		//printf("%d****%d___%d\n",Id[num-1],Id[num-2],numId);
		Id[num-2] = numId;
		item[numId].fre = newfre;
		num--;
		
		numId++;
			
	}
	pre[Id[0]]=-1;
	//	printf("%d**\n",Id[0]);
	int sumlen = 0;
	for(int i=0;i<n;i++)
	{
		int len =0;
		int tempId = i;
		//printf("%d**\n",tempId);
		while(pre[tempId]!=-1)
		{
			tempId = pre[tempId];
			len++;
		}
		item[i].lenth = len;
		sumlen+=item[i].fre*len;
	} 
	int m;
	cin>>m;
	string tempcha;
	string code[maxn];
	for(int i=0;i<m;i++)
	{
		bool flag = true;
		int tempsumlen=0;
		for(int j=0;j<n;j++)
		{
			cin>>tempcha>>code[j];
			if(flag==true)
			{
				if(tempcha==item[j].cha&&code[j].length()<=63)
				{
					int len = code[j].length();
					for(int k=1;k<len-1;k++)
					{
						string tempstr = code[j].substr(0,k);
						mp[tempstr]=i;	
					}
				}
				else
				{
					flag=false;
				}
			}
			tempsumlen +=item[j].fre*code[j].length();
		}
		//printf("%d**ccc%d\n",tempsumlen,sumlen);
		if(flag==true&&sumlen!=tempsumlen)
		{
			flag=false;
		}
		if(flag==true)
			for(int j=0;j<n;j++)
			{
				if(mp.find(code[j])!=mp.end()&&mp[code[j]]==i)
				{
					flag=false;
					break;
				}
			}
		if(flag==false)
			printf("No\n");
		else
			printf("Yes\n");	
	}	
	return 0;
}

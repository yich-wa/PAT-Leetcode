//08:16——08:55
//22分 ，3分答案错误。
//学习如何在string 中将所有字母都转化为小写字母。用transform模板。 
//怀疑是分数计算有问题，单个的分数取整数和加起来后在取整数是不一样的
// 
//改完后得25分。 
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct ins{
	string name;
	int rank;
	int number;
	double score;
}S[maxn];
bool cmp(ins a,ins b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else if(a.number!=b.number)
		return a.number<b.number;
	else
		return a.name<b.name;
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int num =0 ;
	string tempId;
	int tempScore;
	string school;
	map<string,int>nameToId;
	for(int i=0;i<n;i++)
	{
		cin>>tempId>>tempScore>>school;
		int len = school.length();
		for(int i=0;i<len;i++)
		{
			if(school[i]>='A'&&school[i]<='Z')
			{
				school[i]='a'+(school[i]-'A');
			}
		}
		//cout<<school<<endl;
		if(nameToId.find(school)==nameToId.end())
		{
			nameToId[school]=num;
			S[num].name = school;
			S[num].score =0;
			S[num].number = 0;
			num++;
		}
		int insId = nameToId[school];
		S[insId].number++;
		if(tempId[0]=='A')
			S[insId].score +=tempScore;
		else if(tempId[0]=='T')
			S[insId].score +=tempScore*1.5;
		else 
			S[insId].score +=tempScore*1.0/1.5;
	}
	for(int i=0;i<num;i++)
	{
		S[i].score = (int)S[i].score;
	}
	sort(S,S+num,cmp);
	int lastrank ;
	int lastScore = -1;
	printf("%d\n",num);
	for(int i=0;i<num;i++)
	{
		if(S[i].score==lastScore)
			S[i].rank =lastrank;
		else
		{
			S[i].rank = i+1;
			lastScore = S[i].score;
			lastrank = i+1;
		}		
		cout<<S[i].rank<<" "<<S[i].name<<" "<<S[i].score<<" "<<S[i].number<<endl;	
	}
	return 0;
}

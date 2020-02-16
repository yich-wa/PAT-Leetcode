//15:11 ——15:53 25分。。
//注意变输入边初始化，变输入，边剪枝。以及小数进位的三个函数
//ceil();floor();round(); 
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
const int maxn = 10010;
struct student{
	string nameId;
	int gp;
	int gm;
	int gf;
	int g;
	bool isqualified;
}stu[maxn];
map<string,int>nameToId;
bool cmp(int a,int b)
{
	if(stu[a].g!=stu[b].g)
		return stu[a].g>stu[b].g;
	else
		return stu[a].nameId<stu[b].nameId;
}
int main()
{
	int p,m,n;
	cin>>p>>m>>n;
	int num =0;
	string tempStr;
	int tempScore;
	for(int i=0;i<p;i++)
	{
		cin>>tempStr>>tempScore;
		stu[num].gp = tempScore;
		stu[num].nameId = tempStr;
		stu[num].gm = stu[num].gf = -1;
		nameToId[tempStr]=num++;	
	}
	for(int i=0;i<m;i++)
	{
		cin>>tempStr>>tempScore;
		if(nameToId.find(tempStr)!=nameToId.end())
		{
			int temp = nameToId[tempStr];
			stu[temp].gm = tempScore;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>tempStr>>tempScore;
		if(nameToId.find(tempStr)!=nameToId.end())
		{
			int temp = nameToId[tempStr];
			stu[temp].gf = tempScore;
		}
	}
	vector<int>output; 
	for(int i=0;i<num;i++)
	{
		stu[i].isqualified = true;
		if(stu[i].gp<200)
		{
			stu[i].isqualified = false;
			continue;
		}
		if(stu[i].gm>stu[i].gf)
		{
			stu[i].g = round(stu[i].gm*1.0*0.4+stu[i].gf*1.0*0.6);
		}
		else
			stu[i].g = stu[i].gf;
		if(stu[i].g<60)
		{
			stu[i].isqualified = false;	
			continue;
		}
		output.push_back(i);
			
	}
	sort(output.begin(),output.end(),cmp);
	int lenO = output.size();
	for(int i=0;i<lenO;i++)
	{
		int tempId = output[i];
		cout<<stu[tempId].nameId<<" "<<stu[tempId].gp<<" ";
		if(stu[tempId].gm==-1)
			cout<<"-1"<<" ";
		else
			cout<<stu[tempId].gm<<" ";
		cout<<stu[tempId].gf<<" "<<stu[tempId].g<<endl;
	}
	return 0;
}

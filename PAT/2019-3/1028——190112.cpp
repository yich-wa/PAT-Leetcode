#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 100010;
struct student{
	int id;
	char name[10];
	int grade;
}temp;
vector<student>v;
bool cmp1(student a ,student b)
{
	return a.id<b.id;
}
bool cmp2(student a,student b)
{
	if(strcmp(a.name,b.name)==0)
		return a.id<b.id;
	else 
		return strcmp(a.name,b.name)<0;
}
bool cmp3(student a ,student b)
{
	if(a.grade==b.grade)
		return a.id<b.id;
	else
		return a.grade<b.grade;
}
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)
	{
		scanf("%d %s %d",&temp.id,temp.name,&temp.grade);
		v.push_back(temp);
	}
	if(c==1)
	{
		sort(v.begin(),v.end(),cmp1);
	}
	else if(c==2)
	{
		sort(v.begin(),v.end(),cmp2);
	}
	else if(c==3)
	{
		sort(v.begin(),v.end(),cmp3);	
	}
	for(int i=0;i<v.size();i++)
	{
		printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
	}
	return 0;
 } 

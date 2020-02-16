#include<stdio.h>
#include<algorithm>
#include<vector> 
using namespace std;
struct student{
	char name[15];
	char id[15];
	int grade;
}temp;
vector<student>input;
bool cmp(student a,student b)
{
	return a.grade>b.grade;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d",temp.name,temp.id,&temp.grade);
		input.push_back(temp);
	 } 
	int grade1 ,grade2;
	scanf("%d %d",&grade1,&grade2);
	 sort(input.begin(),input.end(),cmp);
	 int num =0;
	 while(num<input.size()&&input[num].grade>grade2)
	 	num++;
	int count =0;
	 for(int i=num;i<input.size();i++)
	 {
	 	if(input[i].grade>=grade1)
	 	{
	 		printf("%s %s\n",input[i].name,input[i].id);
	 		count++;
		 }
	 }
	 if(count==0)
	 	printf("NONE\n");
	return 0;
}

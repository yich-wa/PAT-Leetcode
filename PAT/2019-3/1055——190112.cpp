//��һ�������4�ֳ�ʱ��
//ע���㷨�ĸ�Ч�ԡ����ͨ���������ٲ���Ҫ��
//�жϴӶ�����ʱ�䡣 
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct billion{
	char name[10];
	int age;
	int worth;
}temp;
vector<billion>input;
vector<billion>output;
bool cmp1(billion a,billion b)
{
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	else
	{
		if(a.age!=b.age)
			return a.age<b.age;
		else
			return strcmp(a.name,b.name)<0;
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d%d",temp.name,&temp.age,&temp.worth);
		input.push_back(temp);
	 } 
	sort(input.begin(),input.end(),cmp1);
	int m,amin,amax;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&m,&amin,&amax);
		printf("Case #%d:\n",i);
		int count=0;
		for(int j=0;j<input.size();j++)
		{
			//��ʼ�ǣ� (input[j].age>=amin&&input[j].age<=amax&&count<m)
			//�����������г�ʱ�ġ������������жϷ�ʽ����ʡ��һЩ����Ҫ�ġ�
			//�б�ʽ���Ⱥ�˳��Ҳ����Ҫ�ġ� 
			if(count>=m)
				break; 
			if(input[j].age>=amin&&input[j].age<=amax)
			{
			printf("%s %d %d\n",input[j].name,input[j].age,input[j].worth);
			count++;
			}	
		}
		if(count==0)
			printf("None\n");	
	 } 
	return 0;
}

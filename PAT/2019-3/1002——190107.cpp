//float 用 "%f"输入，double用"%lf"输入 。代价——半个小时 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std; 
const int maxn =1005;
int main()
{
	int n,m;
	float co1[maxn]={0};
	bool flag[maxn]={false};
	vector<int>output;
	int exp;
	float coe;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %f",&exp,&coe);
		//printf("&**\n"); 
		co1[exp]=coe;
		output.push_back(exp);
		flag[exp]=true;	
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%f",&exp,&coe);
		co1[exp]+=coe;
		if(co1[exp]!=0&&flag[exp]==false)
			output.push_back(exp);
	}
	sort(output.begin(),output.end());
	int count =0;
	for(int i=output.size()-1;i>=0;i--)
	{
		if(co1[output[i]]!=0)
			count++;
	}
	printf("%d",count);
	for(int i=output.size()-1;i>=0;i--)
	{
		if(co1[output[i]]!=0)
		{
			printf(" %d %.1f",output[i],co1[output[i]]); 
		}
	}
	printf("\n");
	return 0;	
 } 

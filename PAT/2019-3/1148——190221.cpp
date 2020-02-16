//08:51 ——09：13
//应该假设按照编号从小到大的顺序去假设狼人。然后看说谎情况是否符合
//如果符合直接输出。并结束程序。。因为要求输出的复合要求的最小序列。
//这道题最重要的反思部分是，思路，一开始要想好自己的思路。
//并检查一遍思路。思路不对的话，就容易钻牛角尖。那样死的很惨。
// 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 102;
bool iswolf[maxn]={false};
int n;
int state[maxn]; 
bool check()
{
	int norLiar =0;
	int wolfLiar=0;
	for(int i=1;i<=n;i++)
	{
		if(state[i]<0&&iswolf[abs(state[i])]==false)
		{
			if(iswolf[i]==true)
				wolfLiar++;
			else
				norLiar++;
		}
		else if(state[i]>0&&iswolf[state[i]]==true)
		{
			if(iswolf[i]==true)
				wolfLiar++;
			else
				norLiar++;
		}
	}
	if(norLiar==1&&wolfLiar==1)
		return true;
	else
		return false;	
}
int main()
{	
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&state[i]);
	}
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			flag=false;
			fill(iswolf,iswolf+maxn,false);
			iswolf[i]=iswolf[j]=true;
			flag = check();
			if(flag==true)
			{
				printf("%d %d\n",i,j);
				break; 
			}
		}
		if(flag==true)
			break;
	}
	if(flag==false)
		printf("No Solution\n");
	return 0;
}

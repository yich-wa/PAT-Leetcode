//10:44——10:59  
//20分
//要懂得用筛法去建立素数表。不知道bool数组可不可以初始化成true;
// fill(prime,prime+maxn ,false/true);
#include<stdio.h>
#include<math.h>
const int maxn =100010;
int main()
{
	int n;
	scanf("%d",&n);
	bool prime[maxn]={false};
	int count =0;
	for(int i =2;i<=n;i++)
	{
		if(prime[i]==false)
		{
			for(int j=2*i;j<=n;j=j+i)
			{
				prime[j]=true;
			}
		}
	}
	int last =2;
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==false)
		{
			if(i-last==2)
				count++;
			last =i;	
		}
	}
	printf("%d\n",count);
	return 0;
 } 

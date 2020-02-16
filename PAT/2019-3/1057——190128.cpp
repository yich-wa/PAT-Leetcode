//15:42
//没有采用分块思想的17分。 
//采用分块思想后得30分。。——16:14； 
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int maxn = 100010;
const int maxc = 335;
int hash[maxn]={0};
int block[maxc]={0};
void out(int len)
{
	int count =0;
	int k;
	for(k=0;k<maxc;k++)
	{
		count+=block[k];
		if(count>=len)
		{
			count-=block[k];
			break;
		}
	}
	for(int i=k*maxc;i<maxn;i++)
	{
		count+=hash[i]; 
		if(count>=len)
		{
			printf("%d\n",i);
			return ; 
		}	 
	}
}
int main()
{
	int n; 
	stack<int>s;
	int key;
	char strp[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",strp);
		//printf("**\n");
		if(strp[1]=='u')
		{
			scanf("%d",&key);
			s.push(key);
			hash[key]++;
			key=key/maxc;
			block[key]++;
		}
		else if(strp[1]=='o')
		{
			//printf("**\n");
			if(!s.empty())
			{
				key = s.top();
				s.pop();
				hash[key]--;
				printf("%d\n",key);
				key = key/maxc;
				block[key]--;
			}
			else
			{
				printf("Invalid\n");
			}
		}
		else if(strp[1]=='e')
		{
			if(!s.empty())
			{
				int len = s.size();
				if(len%2==0)
				{
					len = len/2;
				}	
				else
				{
					len=(len+1)/2;
				}
				out(len);
			}
			else
			{
				printf("Invalid\n");
			}	
		}
	}
	return 0;
}

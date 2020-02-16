//PAT  1042 重要的是暂存思想。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn =55;
int main()
{
	int k;
	scanf("%d",&k);
	int shuff[maxn];
	int temphash[maxn];
	int hashtable[maxn];
	for(int i=1;i<=54;i++)
	{
		hashtable[i]=temphash[i]=i;
		scanf("%d",&shuff[i]);
	}
	for(int j=0;j<k;j++)
	{
		for(int i=1;i<=54;i++)
		{
			hashtable[shuff[i]]=temphash[i];
		}
		for(int i=1;i<=54;i++)
		{
			temphash[i]=hashtable[i]; 
		} 	
	}
	char c[5]={'S','H','C','D','J'};
	for(int i=1;i<=54;i++)
	{
		int c_number = (hashtable[i]-1)/13; 
		int n_number = (hashtable[i]-1)%13+1;
		printf("%c%d",c[c_number],n_number); 
		if(i<54)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
 } 

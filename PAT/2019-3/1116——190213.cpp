//12:00——12:29
//忘记prime()素数打表初始化，故浪费10分钟左右。 
#include<stdio.h>
#include<math.h>
const int maxn = 10001;
int notprime[maxn]={false};
void prime()
{
	notprime[1]=true;
	int sq= sqrt(1.0*maxn);
	for(int i=2;i<=sq;i++)
	{
		if(notprime[i]==false)
		{
			for(int j=i*2;j<maxn;j+=i)
			{
				notprime[j]=true;
			}
		}
	}	
}
int main()
{
	int n;
	scanf("%d",&n);
	int rank[maxn]={0};
	int ischecked[maxn]={false};
	int tempid;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tempid);
		rank[tempid]=i;
	}
	int m;
	//开始忘记打表，导致浪费6分钟左右。 
	prime();
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&tempid);
		printf("%04d: ",tempid);
		if(rank[tempid]==0)
		{
			printf("Are you kidding?\n");
		}
		else if(ischecked[tempid]==true)
		{
			printf("Checked\n");
		}
		else
		{
			//printf("%d_***\n",rank[tempid]);
			if(rank[tempid]==1)
			printf("Mystery Award\n");
			else if(notprime[rank[tempid]]==false)
			printf("Minion\n");
			else
			printf("Chocolate\n");
			ischecked[tempid]=true;
		}
	}
	return 0;
}

//10:21
//——11:28 20分 5分答案错误。中间有人打断15分钟左右吧 
//最后找出来，是其中一个变量写错了，低级错误，详细见下面注解。
//——11:49

//设置中间位置，及左右标量是对的。 
 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 10010;
const int maxk = 12;
struct person{
	char name[9];
	int height;
}P[maxn];
bool cmp(person a,person b)
{
	if(a.height!=b.height)
		return a.height>b.height;
	else
		return strcmp(a.name,b.name)<0;
 } 
int main()
{
	int G[maxk][maxn];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",P[i].name,&P[i].height);
	}
	sort(P,P+n,cmp);
	int browser=0;
	int rowNum = n/k;
	int lastNum = n/k+n%k;
	int position = lastNum/2+1;
	int templeft = position-1;
	int tempright = position+1;
	int tempNum =0;
	bool leftflag=true;
	while(tempNum!=lastNum)
	{
		G[0][position]=tempNum;
		tempNum++;
		if(leftflag==true)
		{
			position =templeft;
			leftflag=false;
			templeft--;
		}
		else
		{
			position = tempright;
			leftflag=true;
			tempright++;
		}
	}
	position = k/2 + 1;
	templeft = position - 1;
	tempright = position + 1;
	int nowrow = 1;
	while(nowrow!=k)
	{
		//开始下面这个rowNum写成k了，导致错误。
		//通过输出debug找出来。 
		position = rowNum/2 + 1;
		templeft = position - 1;
		tempright = position + 1;
		leftflag=true;
		int tempRowNum = 0;
		while(tempRowNum!=rowNum)
		{
			G[nowrow][position]=tempNum;
			//printf("%d****%d***%d***\n",nowrow,position,tempNum); 
			tempNum++;
			tempRowNum++;
			if(leftflag==true)
			{
				position =templeft;
				//printf("%d——\n",templeft);
				leftflag=false;
				templeft--;
			}
			else
			{
				position = tempright;
				leftflag=true;
				tempright++;
			}
		}
		nowrow++;	
	}
	for(int i=1;i<=lastNum;i++)
	{
		int tempid= G[0][i];
		if(i<lastNum)
			printf("%s ",P[tempid].name);
		else
			printf("%s\n",P[tempid].name);
	}
	for(int i=1;i<k;i++)
	{
		for(int j=1;j<=rowNum;j++)
		{
			int tempid = G[i][j];
			if(j<rowNum)
			printf("%s ",P[tempid].name);
			else
			printf("%s\n",P[tempid].name);
		}
	}
	return 0;
} 


//注意sort函数的使用，第一参数，第二参数 为左闭右开。
//注意strcmp 的使用。 以及对string.h的四个函数的熟悉 
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 30004;
const int maxc =15;
struct Testee{
	char r[maxc];
	int score;
	int f_rank;
	int l_rank;
	int l_number;
}T[maxn];
bool cmp1(Testee a,Testee b)
{
	return a.score>b.score;
}
bool cmp(Testee a,Testee b){
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.r,b.r)<0;
}
int main()
{
	int n;int k;
	int num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int lastnum =num;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%s %d",T[num].r,&T[num].score);
			T[num].l_number =i; 
			num++;
		}
		sort(T+lastnum,T+num,cmp1);
		int lastrank=1;
		int lastscore =-1;
		int temprank =1;
		for(int i=lastnum;i<num;i++)
		{
			if(T[i].score==lastscore)
			{
				T[i].l_rank=lastrank;
			}
			else
			{
				T[i].l_rank=temprank;
				lastrank = temprank;
				lastscore =T[i].score; 
			}
			temprank++;
		}
	}
	sort(T,T+num,cmp);
	int lastrank=1;
	int lastscore =-1;
	printf("%d\n",num);
	for(int i=0;i<num;i++)
	{
		if(T[i].score==lastscore)
		{
			T[i].f_rank=lastrank;
		}
		else
		{
			T[i].f_rank=i+1;
			lastrank = i+1;
			lastscore =T[i].score; 
		}
		printf("%s %d %d %d\n",T[i].r,T[i].f_rank,T[i].l_number,T[i].l_rank);
	}
	return 0;
}


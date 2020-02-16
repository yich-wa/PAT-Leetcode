//常规题，注意对向量局部排序的表达方式。 
//sort(t.begin()+lastnum,t.begin()+num,cmp1);
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 100;
const int maxc =15;
struct testee{
	char id[maxc];
	int location;
	int score;
	int f_rank;
	int l_rank;
}temp;
vector<testee>t;
bool cmp1(testee a,testee b)
{
	return a.score>b.score;
}
bool cmp2(testee a,testee b)
{
	if(a.score==b.score)
		return strcmp(a.id,b.id)<0;
	else
		return a.score>b.score;
}
int main()
{
	int n,k;
	scanf("%d",&n);
	int lastnum =0;
	int num=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%s %d",temp.id,&temp.score);
			temp.location = i+1;
			t.push_back(temp);
			num++;
		}	
		sort(t.begin()+lastnum,t.begin()+num,cmp1);
		int lastscore =-1;
		int lastrank ;
		int count =0;
		for(int j=lastnum;j<num;j++)
		{
			count++;
			if(t[j].score==lastscore)
			{
				t[j].l_rank = lastrank;
			}
			else
			{
				t[j].l_rank =count;
				lastscore=t[j].score;
				lastrank = count;
			}
		}
		lastnum =num;    //开始这个居然忘记了。。 
	}
	sort(t.begin(),t.end(),cmp2);
	int lastscore =-1;
	int lastrank ;
	for(int j=0;j<t.size();j++)
	{
		if(t[j].score==lastscore)
		{
			t[j].f_rank = lastrank;
		}
		else
		{
			t[j].f_rank =j+1;
			lastscore=t[j].score;
			lastrank =j+1;
		}
	}
	printf("%d\n",t.size());
	for(int i=0;i<t.size();i++)
	{
		printf("%s %d %d %d\n",t[i].id,t[i].f_rank,t[i].location,t[i].l_rank);
	}
	return 0;
}

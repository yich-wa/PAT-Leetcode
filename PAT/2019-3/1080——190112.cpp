//一遍过，搞清楚相同排名的情况，那是最基本的套路。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 40005;
const int maxm = 105;
struct apply{
	int id;
	int ge;
	int gi;
	int final;
	int choice[6];
	int rank;
}student[maxn];
vector<apply>input;
vector<int>school[maxm];
bool cmp(apply a ,apply b)
{
	if(a.final!=b.final)
		return a.final>b.final;
	else 
		return a.ge>b.ge;
}
int main()
{
	int n,m,k;
	int quota[maxm];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	scanf("%d",&quota[i]);
	for(int i=0;i<n;i++)
	{
		student[i].id =i;
		scanf("%d%d",&student[i].ge,&student[i].gi);
		student[i].final = student[i].ge+student[i].gi;
		for(int j=0;j<k;j++)
		{
			scanf("%d",&student[i].choice[j]);
		}
	}
	sort(student,student+n,cmp);
	int lastfinal=-1;int lastrank = -1;
	int lastge =-1;
	int lastadmit=-1;
	int sc_lastrank[maxm];
	fill(sc_lastrank,sc_lastrank+maxm,-1);
	for(int i=0;i<n;i++)
	{
		if(student[i].final==lastfinal&&student[i].ge==lastge)
		{
			student[i].rank =lastrank;
		}
		else
		{
			lastrank = i;
			lastfinal =student[i].final;
			student[i].rank = i;
			lastge = student[i].ge;
		}
		for(int j=0;j<k;j++)
		{
			int s_num = student[i].choice[j];
			if(school[s_num].size()<quota[s_num])
			{
				school[s_num].push_back(student[i].id);
				sc_lastrank[s_num]=student[i].rank;
				break;			
			}			
			else if(student[i].rank==sc_lastrank[s_num])
			{
				school[s_num].push_back(student[i].id);
				break;
			}
		}	
	}
	for(int i=0;i<m;i++)
	{
		sort(school[i].begin(),school[i].end());
		for(int j=0;j<school[i].size();j++)
		{
			printf("%d",school[i][j]);
			if(j<school[i].size()-1)
				printf(" ");		
		 } 
		 printf("\n");
	}
	return 0;
 }

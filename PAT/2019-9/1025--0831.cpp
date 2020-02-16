//15:47——16:15 想的和写的思路都要十分健壮。对于写代码来说，构思思路时
//要健壮。写的时候，要稳当。兴奋起来是对的，有目标感是对的。但是瞎急是没用的。 
//先进行单个排名，在进行整体排名。节点的代码要活学活用。 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn =  105;
struct testee{
	char Id[15];
	int site;
	int score;
	int f_rank;
	int l_rank;
}tempT;
vector<testee>v[maxn],f;
bool cmp(testee a,testee b){
	return a.score>b.score;
}
bool cmp1(testee a ,testee b){
	if(a.score!=b.score){
		return a.score>b.score;
	}else{
		return strcmp(a.Id,b.Id)<0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int m;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%s %d",tempT.Id,&tempT.score);
			tempT.site = i;
			v[i].push_back(tempT);
		}
		sort(v[i].begin(),v[i].begin()+v[i].size(),cmp);
		int last = 1;
		int lastScore = -1;
		for(int j=0;j<v[i].size();j++){
			if(v[i][j].score == lastScore){
				v[i][j].l_rank = last;
			}else{
				v[i][j].l_rank = j+1;
				last = j+1;
				lastScore= v[i][j].score;
			}
			f.push_back(v[i][j]);
		}
	}
	sort(f.begin(),f.begin()+f.size(),cmp1);
	int f_last = 1;
	int f_lastScore = -1;
	for(int i=0;i<f.size();i++){
		if(f[i].score==f_lastScore){
			f[i].f_rank = f_last;
		}else{
			f[i].f_rank = i+1;
			f_last = i+1;
			f_lastScore = f[i].score;
		}
	} 
	printf("%d\n",f.size());
	for(int i=0;i<f.size();i++){
		printf("%s %d %d %d\n",f[i].Id,f[i].f_rank,f[i].site,f[i].l_rank);
	}
	return 0;
}

////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//using namespace std;
//const int maxn = 100;
//const int maxc =15;
//struct testee{
//	char id[maxc];
//	int location;
//	int score;
//	int f_rank;
//	int l_rank;
//}temp;
//vector<testee>t;
//bool cmp1(testee a,testee b)
//{
//	return a.score>b.score;
//}
//bool cmp2(testee a,testee b)
//{
//	if(a.score==b.score)
//		return strcmp(a.id,b.id)<0;
//	else
//		return a.score>b.score;
//}
//int main()
//{
//	int n,k;
//	scanf("%d",&n);
//	int lastnum =0;
//	int num=0;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&k);
//		for(int j=0;j<k;j++)
//		{
//			scanf("%s %d",temp.id,&temp.score);
//			temp.location = i+1;
//			t.push_back(temp);
//			num++;
//		}	
//		sort(t.begin()+lastnum,t.begin()+num,cmp1);
//		int lastscore =-1;
//		int lastrank ;
//		int count =0;
//		for(int j=lastnum;j<num;j++)
//		{
//			count++;
//			if(t[j].score==lastscore)
//			{
//				t[j].l_rank = lastrank;
//			}
//			else
//			{
//				t[j].l_rank =count;
//				lastscore=t[j].score;
//				lastrank = count;
//			}
//		}
//		lastnum =num;    //开始这个居然忘记了。。 
//	}
//	sort(t.begin(),t.end(),cmp2);
//	int lastscore =-1;
//	int lastrank ;
//	for(int j=0;j<t.size();j++)
//	{
//		if(t[j].score==lastscore)
//		{
//			t[j].f_rank = lastrank;
//		}
//		else
//		{
//			t[j].f_rank =j+1;
//			lastscore=t[j].score;
//			lastrank =j+1;
//		}
//	}
//	printf("%d\n",t.size());
//	for(int i=0;i<t.size();i++)
//	{
//		printf("%s %d %d %d\n",t[i].id,t[i].f_rank,t[i].location,t[i].l_rank);
//	}
//	return 0;
//} 

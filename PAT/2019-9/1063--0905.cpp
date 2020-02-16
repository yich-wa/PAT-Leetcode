//08:48--09：06
//注意如何输出"%" 用两个"%" 
#include<stdio.h>
#include<set>
using namespace std;
const int maxn = 52;
set<int>s[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;
		int temp;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&temp);
			s[i].insert(temp);
		}
	}
	int q;
	scanf("%d",&q);
	int Nc,Nt;
	int s1,s2;
	for(int i=0;i<q;i++){
		scanf("%d%d",&s1,&s2);
		set<int>ts;
		for(set<int>::iterator it =s[s1].begin();it!=s[s1].end();it++){
			ts.insert(*it);
		}
		for(set<int>::iterator it =s[s2].begin();it!=s[s2].end();it++){
			ts.insert(*it);
		}
		Nt = ts.size();
		Nc = s[s1].size()+s[s2].size()-Nt;
		double result = (Nc*100*1.0)/(Nt*1.0);
		printf("%.1f%%\n",result);
		ts.clear();
	}
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<set>
//using namespace std;
//const int maxn =  55;
//int main()
//{
//	int n;
//	set<int>s[maxn];
//	set<int>total;
//	scanf("%d",&n);
//	int m,index;
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&m);
//		for(int j=0;j<m;j++)
//		{
//			scanf("%d",&index);
//			s[i].insert(index);
//		}
//	}
//	int k;
//	scanf("%d",&k);
//	int fir,sec;
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d %d",&fir,&sec);
//		set<int>::iterator it = s[fir].begin();
//		set<int>::iterator it2 = s[sec].begin();
//		int shared = 0;
//		for(;it!=s[fir].end()&&it2!=s[sec].end();)
//		{
//			//注意星号*是在前面。。 
//			if(*it==*it2)
//			{
//				shared++;
//				it++;
//				it2++;
//			}
//			else if(*it>*it2)
//			{
//				it2++;
//			}
//			else if(*it<*it2)
//			{
//				it++;
//			}
//		 } 
//		int t = s[fir].size()+s[sec].size()-shared;
//		double output = (shared*100.0)/(t*1.0);
//		printf("%.1f%%\n",output);
//		total.clear();
//	}
//	return 0;
//} 

//16:55——
//——17:29 21分  有4分运行超时。
//开始采用的是，将两个被查询的集合合并到一个集合中
//方法写起来简单但是运行效率低，估计是超时的根源。
//total.insert(s[fir].begin(),s[fir].end());
//total.insert(s[sec].begin(),s[sec].end()); 

//改为同时遍历两个集合，找相同元素的个数。 
//set<int>::iterator it = st.begin();   *it 表示元素值。
//是iterator 

//注意利用set的自动去重加“排序“功能。 去找两个集合的共有元素个数
//一次遍历即可 

//——17:42  改完后为25分。 
 
#include<stdio.h>
#include<set>
using namespace std;
const int maxn =  55;
int main()
{
	int n;
	set<int>s[maxn];
	set<int>total;
	scanf("%d",&n);
	int m,index;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&index);
			s[i].insert(index);
		}
	}
	int k;
	scanf("%d",&k);
	int fir,sec;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&fir,&sec);
		set<int>::iterator it = s[fir].begin();
		set<int>::iterator it2 = s[sec].begin();
		int shared = 0;
		for(;it!=s[fir].end()&&it2!=s[sec].end();)
		{
			//注意星号*是在前面。。 
			if(*it==*it2)
			{
				shared++;
				it++;
				it2++;
			}
			else if(*it>*it2)
			{
				it2++;
			}
			else if(*it<*it2)
			{
				it++;
			}
		} 
		int t = s[fir].size()+s[sec].size()-shared;
		double output = (shared*100.0)/(t*1.0);
		printf("%.1f%%\n",output);
		total.clear();
	}
	return 0;
}

//20:52——
//——20:18  24分 有1分的段错误。 
//我比答案多用了个vector结果超内存了。。
//答案是直接用node[maxn]排序输出。node[maxn]排序
//难在如何初试化。 
//
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn =100005;
struct Node{
	int key;
	int add;
	int next;
}node[maxn];
bool cmp(int a,int b)
{
	if(node[a].key<node[b].key)
		return true;
	else
		return false;
}
int main()
{
	int n,fa;
	int tempadd; 
	scanf("%d%d",&n,&fa);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tempadd);
		scanf("%d%d",&node[tempadd].key,&node[tempadd].next);
		node[tempadd].add = tempadd;
	}
	int p =fa;
	vector<int>list; 
	while(p!=-1)   //从头结点遍历一遍，将在链表上的节点提取出来 
	{
		list.push_back(p);  //左边两句的顺序一开始写反了。 
		p = node[p].next;	
	}
	sort(list.begin(),list.end(),cmp);
	fa = list[0];
	printf("%d ",list.size());
	int i;
	for(i=0;i<list.size();i++)
	{
		printf("%05d\n",list[i]);
		printf("%05d %d ",list[i],node[list[i]].key);
	}
	printf("-1\n");
	return 0;	
 } 

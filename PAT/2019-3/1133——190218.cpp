//08:33———09：04  25分 
//排序题，利用多个向量先存起来，在组合。
//用最快的方式达到目的。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100005;
struct node{
	int address;
	int data;
	int next;
}Node[maxn];
int k;
//bool cmp(int a,int b)
//{
//	if(Node[a].data>=0&&Node[b].data<0)
//		return false;
//	else if(Node[a].data>k&&Node[b].data>=0&&Node[b].data<=k)
//		return false;
//	else 
//		return true;
//}
int main()
{
	int firAdd,n;
	scanf("%d%d%d",&firAdd,&n,&k);
	int tempAdd;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tempAdd);
		scanf("%d%d",&Node[tempAdd].data,&Node[tempAdd].next);
		Node[tempAdd].address = tempAdd;
	}
	int p = firAdd;
	vector<int>link,link1,link2;
	while(p!=-1)
	{
		if(Node[p].data<0)
			link.push_back(p);
		else if(Node[p].data<=k)
			link1.push_back(p);
		else 
			link2.push_back(p);
		p= Node[p].next;
	}
	int len1 =link1.size();
	for(int i=0;i<len1;i++) 
	{
		link.push_back(link1[i]);
	}
	int len2 = link2.size();
	for(int i=0;i<len2;i++)
	{
		link.push_back(link2[i]);
	}
	int len = link.size();
	printf("%05d %d",link[0],Node[link[0]].data);
	for(int i=1;i<len;i++)
	{
		printf(" %05d\n",link[i]);
		printf("%05d %d",link[i],Node[link[i]].data);
	}
	printf(" -1\n");
	return 0;
 } 

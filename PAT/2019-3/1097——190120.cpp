//21:28——
//——21:49
//25分。
// 自己写的这套输出模式还不错。链表问题是有套路的。 
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const int maxn = 100010;
const int maxv = 10010;
struct Node{
	int add;
	int key;
	int next;
}node[maxn];
int main()
{
	int fa,n;
	bool hash[maxv]={false};
	scanf("%d%d",&fa,&n);
	int tempadd; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tempadd);
		scanf("%d%d",&node[tempadd].key,&node[tempadd].next);
	} 
	int p =fa;
	vector<int>left;
	vector<int>remove;
	while(p!=-1)
	{
		int value = node[p].key;
		if(hash[abs(value)]==false)
		{
			left.push_back(p);
			hash[abs(value)]=true;
		}
		else
		{
			remove.push_back(p);
		}
		p=node[p].next;
	}
	if(left.size()>0)
	{
		printf("%05d %d ",left[0],node[left[0]].key);
		for(int i=1;i<left.size();i++)
		{
			printf("%05d\n",left[i]);
			printf("%05d %d ",left[i],node[left[i]].key);
		}
		printf("-1\n");
	}
	if(remove.size()>0)
	{
		printf("%05d %d ",remove[0],node[remove[0]].key);
		for(int i=1;i<remove.size();i++)
		{
			printf("%05d\n",remove[i]);
			printf("%05d %d ",remove[i],node[remove[i]].key);
		}
		printf("-1\n");
	}
	return 0;
}

//20:52����
//����20:18  24�� ��1�ֵĶδ��� 
//�ұȴ𰸶����˸�vector������ڴ��ˡ���
//����ֱ����node[maxn]���������node[maxn]����
//������γ��Ի��� 
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
	while(p!=-1)   //��ͷ������һ�飬���������ϵĽڵ���ȡ���� 
	{
		list.push_back(p);  //��������˳��һ��ʼд���ˡ� 
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

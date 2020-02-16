//19:39
//���� 
//20:30   30��

//������ע��㣺
//���԰���Ϊ��λ���ۼ���Ⱥ�����Կ��ԣ���һ�����õ��˼��ϵ�һ��������
//set<int>s;  ���� s.insert();����Ԫ��ֵ��*it�� *��ǰ�档
//�Ұְ���·��ѹ��Ҫ����Ϥ�� 
 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn =1005;
int father[maxn];
vector<int>hobby[maxn];
set<int>s;
int findfather(int a)
{
	int x =a;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[a]!=x)
	{
		int n = father[a];
		father[a]=x;
		a=n;
	}
	return x;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		father[i]=i;
	int k;
	int temphobby;	
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		int lastfather = father[i];
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temphobby);
			hobby[temphobby].push_back(i);
			s.insert(temphobby);
		}
	}
	for(set<int>::iterator it = s.begin();it!=s.end();it++)
	{
		//��ʼд��it*��ϸ�ڼ���Ҫ������ 
		int temp =*it;
		int last = hobby[temp][0];
		for(int i=1;i<hobby[temp].size();i++)
		{
			int fa= findfather(hobby[temp][i]);
			int fb = findfather(last);
			if(fa!=fb)
			{
				father[fa]=fb;
			}
			last = hobby[temp][i];
		}
	}
	int cluster[maxn]={0};
	int cnum=0;
	for(int i=1;i<=n;i++)
	{
		int temp = findfather(i);
		if(cluster[temp]==0)
		{
			cluster[temp]=1;
			cnum++;
		}
		else
			cluster[temp]++;
	}
	printf("%d\n",cnum);
	sort(cluster,cluster+maxn,cmp);
	for(int i=0;i<cnum;i++)
	{
		printf("%d",cluster[i]);
		if(i<cnum-1)
		printf(" ");
		else
		printf("\n");
	}
	return 0;	
}

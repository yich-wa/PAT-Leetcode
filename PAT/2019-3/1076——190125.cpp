//14��19
//�ڼ䷸��Щ�ͼ����󡣲�����printf�ҳ����ˡ�
//�����±����
//�ַ�������Ƕ��forѭ�����õ�ָ��һ���Ĵ���
//25�֣�����5�ִ𰸴��� 

//�������𰸣����ֿ������Լ�����������ضϹ����Ե�ʡ� 
//��ϸ�����ƺ��Ƕ���û����յ�Ե�ʣ���Ϊ������ǰbreak�ˡ� 
//һ�β�����һ�����У���Ҫ����һ������
//�����Ǵ�����;break;������� ����30�֡����� 
//����15��13 
#include<stdio.h> 
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1005; 
vector<int>follow[maxn];
int l;
int isvisit[maxn]={false};
int level[maxn];
int BFS(int r)
{
	queue<int>q;
	int sum =0;
	q.push(r);
	isvisit[r]=true;
	level[r]=0;
	while(!q.empty())
	{
		int temp =q.front();
		q.pop();
	//	printf("%d**\n",temp);
		int templevel= level[temp]+1;
		if(templevel>l)
			break;
		for(int i=0;i<follow[temp].size();i++)
		{
			int tempId= follow[temp][i];
			//printf("%d****\n",tempId);
			if(isvisit[tempId]==false)
			{
				sum++;
				isvisit[tempId]=true;
				level[tempId]=templevel;
				q.push(tempId);
			}
		}
		
	 } 
	return sum;
}
int main()
{
	int n;
	scanf("%d%d",&n,&l);
	//�ַ�������Ƕ��forѭ�����õ�ָ��һ���Ĵ��� 
	for(int i=1;i<=n;i++)
	{
		int m;
		int user;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&user);
			follow[user].push_back(i);
		}	
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int queryId;
		fill(isvisit,isvisit+maxn,false);
		scanf("%d",&queryId);
		isvisit[queryId]=true;
		int tempsum = BFS(queryId);
		printf("%d\n",tempsum);
	}
	return 0;
}

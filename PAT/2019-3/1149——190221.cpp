//09:16����09:43�㶨 25�֡�
//��һ��д����Щ���⣬ÿ����������Ͷ��������ƥ�䣬����Ӧ�����ڽӱ�
//ȥ�洢�� ����⣬Ӧ��������������˼·���������ݼ��ɣ��ͻᷢ��Ӧ��
//�����ڽӱ�ȥ��¼֮��Ĺ�ϵ�� 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
const int maxg = 100005;
bool isDanger[maxg]={false};
vector<int>partner[maxg];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		isDanger[u]=true;
		isDanger[v]=true;
		partner[u].push_back(v);
		partner[v].push_back(u);
	}
	int k,tempG;
	for(int i=0;i<m;i++)
	{
		bool flag=true;
		bool isforbid[maxg]={false};
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&tempG);
			if(isforbid[tempG]==false)
			{
				if(isDanger[tempG]==true)
				{
					//printf("%d&&&%d\n",tempG,partner[tempG]);
					int len = partner[tempG].size();
					for(int h=0;h<len;h++)
					{
						int temp = partner[tempG][h];
						isforbid[temp]=true;
					}
					
				}
			}
			else if(flag==true)
			{
				printf("No\n");
				flag=false;
			}
		}
		if(flag==true)
			printf("Yes\n");
	}
	return 0;
 } 

//pat1126 eulerian path  8:55——9:28
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
const int maxn = 505;
vector<int>V[maxn];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v ;
		scanf("%d %d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	bool isvisit[maxn]={false};
	queue<int>Q;
	int count =1; //表示一次BFS可以访问多少节点。 
	isvisit[1]=true;
	Q.push(1);
	while(!Q.empty())
	{
		int a =Q.front();
		Q.pop();
		for(int j=0;j<V[a].size();j++)
		{
			if(isvisit[V[a][j]]==false)
			{
				Q.push(V[a][j]);
				isvisit[V[a][j]]=true;
				count++;
			}	
		}
	}
	int oddcount=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d",V[i].size());
		if(V[i].size()%2==1)
		{
			oddcount++;
		}
		if(i<n)
			printf(" ");
		else
			printf("\n");
	}
	if(count==n)
	{
		if(oddcount==0)
			printf("Eulerian\n");
		else if(oddcount ==2)
			printf("Semi-Eulerian\n");
		else 
			printf("Non-Eulerian\n");
	}
	else 
		printf("Non-Eulerian\n");
	return 0;
 } 

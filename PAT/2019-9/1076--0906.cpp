//16:59--17:28
//拿到22分。8分答案错误。
//22分是因为用深度优先遍历了。
//应该用广度优先。。改成BFS后30分。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
bool isVis[maxn]; 
vector<int>v[maxn];
int sum =0;
int l;
void BFS(int s,int level){
	vector<int>q,tempQ;
	q.push_back(s);
	isVis[s]=true;
	for(int k=1;k<=level;k++){
		for(int i=0;i<q.size();i++){
			for(int j=0;j<v[q[i]].size();j++){
				int temp = v[q[i]][j];
				if(isVis[temp]==false){
					sum++;
					isVis[temp]=true;
					tempQ.push_back(temp);
				}
			}	
		}
		q = tempQ;
		tempQ.clear();
	}
}
int main(){
	int n;
	scanf("%d%d",&n,&l);
	int m,temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			v[temp].push_back(i);
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		sum =0;
		fill(isVis,isVis+maxn,false);
		scanf("%d",&temp);
		BFS(temp,l);
		printf("%d\n",sum);
	}
	return 0;
}

//
////以前写的
//#include<stdio.h> 
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//const int maxn = 1005; 
//vector<int>follow[maxn];
//int l;
//int isvisit[maxn]={false};
//int level[maxn];
//int BFS(int r)
//{
//	queue<int>q;
//	int sum =0;
//	q.push(r);
//	isvisit[r]=true;
//	level[r]=0;
//	while(!q.empty())
//	{
//		int temp =q.front();
//		q.pop();
//	//	printf("%d**\n",temp);
//		int templevel= level[temp]+1;
//		if(templevel>l)
//			break;
//		for(int i=0;i<follow[temp].size();i++)
//		{
//			int tempId= follow[temp][i];
//			//printf("%d****\n",tempId);
//			if(isvisit[tempId]==false)
//			{
//				sum++;
//				isvisit[tempId]=true;
//				level[tempId]=templevel;
//				q.push(tempId);
//			}
//		}
//		
//	 } 
//	return sum;
//}
//int main()
//{
//	int n;
//	scanf("%d%d",&n,&l);
//	//又犯了两个嵌套for循环中用的指针一样的错误。 
//	for(int i=1;i<=n;i++)
//	{
//		int m;
//		int user;
//		scanf("%d",&m);
//		for(int j=0;j<m;j++)
//		{
//			scanf("%d",&user);
//			follow[user].push_back(i);
//		}	
//	}
//	int k;
//	scanf("%d",&k);
//	for(int i=0;i<k;i++)
//	{
//		int queryId;
//		fill(isvisit,isvisit+maxn,false);
//		scanf("%d",&queryId);
//		isvisit[queryId]=true;
//		int tempsum = BFS(queryId);
//		printf("%d\n",tempsum);
//	}
//	return 0;
//} 

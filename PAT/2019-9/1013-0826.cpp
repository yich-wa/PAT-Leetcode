//这是一个数连通分量的题。看几次能够遍历完。
//由于题中说明，要尽量快。所以尽量用邻接矩阵存储。然后用
//广度优先的方式去遍历。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
bool isVis[maxn];
vector<int>v[maxn];
void BFS(int c){
	for(int i=0;i<v[c].size();i++){
		if(isVis[v[c][i]]==false){
			isVis[v[c][i]]=true;
			BFS(v[c][i]);
		}
	}
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int c1,c2;
	for(int i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		 v[c1].push_back(c2);
		 v[c2].push_back(c1);
	}
	int c;
	vector<int>output;
	for(int i=0;i<k;i++){
		fill(isVis,isVis+maxn,false);
		scanf("%d",&c);
		int cnt =-1;
		isVis[c]=true;
		for(int j=1;j<=n;j++){
			if(isVis[j]==false){
				BFS(j);
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
//
////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 1005;
//int g[maxn][maxn]={0}; 
//vector<int>adjust[maxn];
//int flag[maxn]={false};
//int n,m,k;
//void DFS(int a)
//{
//	flag[a]=true;
//	for(int i=0;i<adjust[a].size();i++)
//	{
//		int temp =adjust[a][i];
//		if(flag[temp]==false)
//			DFS(temp);
//	}
//	return ;
//}
//int main()
//{
//	
//	int c1,c2;
//	scanf("%d%d%d",&n,&m,&k);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&c1,&c2);
//		adjust[c1].push_back(c2);
//		adjust[c2].push_back(c1);
//	}
//	int dcity;
//	for(int i=0;i<k;i++)
//	{
//		fill(flag+1,flag+n+1,false);
//		int num=0;
//		scanf("%d",&dcity);
//		flag[dcity]=true;
//		for(int j=1;j<=n;j++)
//		{
//			if(flag[j]==false)
//			{
//				DFS(j);
//				num++;
//			}
//		}
//		printf("%d\n",num-1);	
//	}
//	return 0;	
//}
 
 
 

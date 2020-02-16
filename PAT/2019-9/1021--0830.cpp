// 邻接表去存储，即用向量去存储。
//  深度优先搜索，带上level参数。然后在用一个全局变量记录最大level
 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
const int maxn = 10005;
vector<int>adj[maxn];
bool isVis[maxn];
int tempDepth ;
void DFS(int s,int level){
	if(level>tempDepth){
		tempDepth = level;
	}
	for(int i=0;i<adj[s].size();i++){
		int temp = adj[s][i];
		if(isVis[temp]==false){
			isVis[temp]=true;
			DFS(temp,level+1);
		}
	}
}
int rootDepth(int s){
	tempDepth = 0;
	isVis[s] = true;
	DFS(s,1);
	return tempDepth;
}
int main(){
	int n;
	scanf("%d",&n);
	int ed1,ed2;
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&ed1,&ed2);
		adj[ed1].push_back(ed2);
		adj[ed2].push_back(ed1); 
	}
	fill(isVis,isVis+maxn,false);
	int num = 0;
	for(int i=1;i<=n;i++){
		if(isVis[i]==false){
			isVis[i]=true;
			DFS(i,1);
			num++;
		}
	}
	if(num>1){
		printf("Error: %d components",num);
		return 0;
	}
	int maxdepth =0;
	vector<int>output;
	for(int i=1;i<=n;i++){
		fill(isVis,isVis+maxn,false);
		int depth = rootDepth(i);
//		printf("%d***\n",depth);
		if(depth>maxdepth){
			maxdepth = depth;
			output.clear();
			output.push_back(i);
		}else if(depth==maxdepth){
			output.push_back(i);
		}
	}
	for(int i=0;i<output.size();i++){
		printf("%d\n",output[i]);
	}
	return 0;	
}

////以前写的
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int maxn = 10010;
//vector<int>g[maxn];
//bool flag[maxn]={false};
//int deepest[maxn]={0};
//void DFS(int a)
//{
//	flag[a]=true;
//	for(int i=0;i<g[a].size();i++)
//	{
//		int temp = g[a][i];
//		if(flag[temp]==false)
//		{
//			DFS(temp);
//		 } 
//	}
//}
//void Depth(int a,int level,int seq)
//{
//	if(level>deepest[seq])
//		deepest[seq]=level;
//	flag[a]=true;
//	for(int i=0;i<g[a].size();i++)
//	{
//		int temp =g[a][i];
//		if(flag[temp]==false)
//		{
//			Depth(temp,level+1,seq);
//		}
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int c1,c2;
//	for(int i=0;i<n-1;i++)
//	{
//		scanf("%d%d",&c1,&c2);
//		g[c1].push_back(c2);
//		g[c2].push_back(c1);
//	}
//	int num=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(flag[i]==false)
//		{
//			DFS(i);
//			num++;
//		}
//	}
//	if(num>1)
//	{
//		printf("Error: %d components\n",num);
//	}
//	else
//	{
//		int maxdepth=0;
//		vector<int>out;
//		for(int i=1;i<=n;i++)
//		{
//			fill(flag+1,flag+n+1,false);
//			Depth(i,1,i);
//			if(deepest[i]>maxdepth)
//			{
//				maxdepth=deepest[i];
//				out.clear();
//				out.push_back(i);
//			}
//			else if(deepest[i]==maxdepth)
//			{
//				out.push_back(i);
//			}
//		}
//		for(int i=0;i<out.size();i++)
//		{
//			printf("%d\n",out[i]);	
//		}
//	}
//	return 0;
//} 

//第一次有3分答案错误 
//深度优先，带上参数深度。输出每一层的叶子节点数，最后一层高一定有
//叶子节点。一个节点的情况需要特判 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 102;
int level[maxn];
int maxDepth =0;
vector<int>v[maxn];
void DFS(int root ,int depth){
	if(depth>maxDepth){
		maxDepth=depth;
	}
	for(int i=0;i<v[root].size();i++){
		int tempId = v[root][i];
		if(v[tempId].size()==0){
			level[depth]++;
		}else{
			DFS(tempId,depth+1);
		}
	}
}
int main(){
	int n,m;
	int faId,k,chId;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&faId,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&chId);
			v[faId].push_back(chId);
		}
	}
	//要对一个节点的情况进行特判  
	if(n>1){
	 	DFS(1,1);
		printf("0");
	}else{
		printf("1");
	}
	for(int i=1;i<=maxDepth;i++){
		printf(" %d",level[i]);
	}
	return 0;
} 

//// 以前写的
//#include<stdio.h>
//#include<vector>
//using namespace std;
//const int maxn = 110;
//vector<int>child[maxn]; 
//int nochild[maxn]={0};
//int maxlevel=-1;
//void DFS(int a,int level)
//{
//	if(child[a].size()==0)
//	{
//		nochild[level]++;
//		if(level>maxlevel)
//		{
//			maxlevel=level;
//		}
//	}
//	else
//	{
//		for(int i=0;i<child[a].size();i++)
//		DFS(child[a][i],level+1);
//	}
//}
//int main()
//{
//	int n,m;
//	scanf("%d",&n);
//	if(n==0)
//		return 0;
//	else
//	{
//		scanf("%d",&m);
//	}
//	int id ,k,tempid;
//	for(int i=0;i<m;i++) 
//	{
//		scanf("%d%d",&id,&k);
//		for(int j=0;j<k;j++)
//		{
//			scanf("%d",&tempid);
//			child[id].push_back(tempid);
//		}
//	}
//	DFS(1,0);
//	for(int i=0;i<=maxlevel;i++)
//	{
//		printf("%d",nochild[i]);
//		if(i<maxlevel)
//		printf(" ");
//		else
//		printf("\n");
//	 } 
//	 return 0;
//}

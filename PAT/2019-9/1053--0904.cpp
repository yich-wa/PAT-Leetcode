//14:01--14:36
//题不难，用深度优先。构造节点。认真仔细。 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 102;
struct node{
	vector<int>child;
	int weight;
}N[maxn]; 
int n,m,s;
bool cmp(int a,int b){
	return N[a].weight>N[b].weight;
}
vector<int>output;
void outputP(){
	for(int i=0;i<output.size();i++){
		if(i!=0)
			printf(" ");
		printf("%d",N[output[i]].weight);
	}
	printf("\n");
}
void DFS(int r,int total){
	if(N[r].child.size()==0){
		if(total==s){
			outputP();
		}else{
			return ;
		}
	}
	for(int i=0;i<N[r].child.size();i++){
		int tId= N[r].child[i];
		int tWe = N[tId].weight;
		output.push_back(tId);
		DFS(tId,total+tWe);
		output.pop_back();
	}
}
int main(){
	
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&N[i].weight);
	}
	int tempId ,tempK;
	int tempC;
	for(int i=0;i<m;i++){
		scanf("%d%d",&tempId,&tempK);
		for(int j=0;j<tempK;j++){
			scanf("%d",&tempC);
			N[tempId].child.push_back(tempC);
		}
		sort(N[tempId].child.begin(),N[tempId].child.begin()+N[tempId].child.size(),cmp);
	}
	output.push_back(0);
	DFS(0,N[0].weight);
	return 0;	
}


//
////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 105;
//vector<int>path;
//int n,m,s;
//int weight[maxn];
//vector<int>child[maxn];
//bool cmp(int a,int b)
//{
//	return weight[a]>weight[b];
//}
//void out(vector<int>a)
//{
//	int len =a.size();
//	for(int i=0;i<len;i++)
//	{
//		printf("%d",weight[a[i]]);
//		if(i<len-1)
//		printf(" ");
//		else
//		printf("\n");
//	}
//}
//void DFS(int a,int w)
//{
//	if(w>s)
//		return ;
//	if(child[a].size()==0)
//	{
//		if(w==s)
//		{
//			out(path);
//		}
//		return;
//	}
//	else
//	{
//		for(int i=0;i<child[a].size();i++)
//		{
//			int temp =child[a][i];
//			path.push_back(temp);
//			DFS(temp,w+weight[temp]);
//			path.pop_back();
//		}
//	}
//}
//int main()
//{	
//	scanf("%d%d%d",&n,&m,&s);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&weight[i]);
//	}
//	int tempid,k,tempchild;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&tempid,&k);
//		for(int j=0;j<k;j++)
//		{
//			scanf("%d",&tempchild);
//			child[tempid].push_back(tempchild);
//		}
//		sort(child[tempid].begin(),child[tempid].end(),cmp);
//	 } 
//	 path.push_back(0);
//	 DFS(0,weight[0]);
//	 return 0;
// }  

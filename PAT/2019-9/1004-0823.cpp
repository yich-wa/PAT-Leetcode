//��һ����3�ִ𰸴��� 
//������ȣ����ϲ�����ȡ����ÿһ���Ҷ�ӽڵ��������һ���һ����
//Ҷ�ӽڵ㡣һ���ڵ�������Ҫ���� 
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
	//Ҫ��һ���ڵ�������������  
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

//// ��ǰд��
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

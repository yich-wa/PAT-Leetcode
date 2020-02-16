//15:47--17:00
//本题其实不难，就是复杂，复杂问题就局部清晰解决。一步一步。 
//如存在向量的复制和清零。
//同分数的排名
//挑最大值，并记录序号等。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
struct pro{
	int id;
	int weight;
	int rank;
	int round;
}P[maxn];
bool cmp(pro a,pro b){
	return a.round>b.round;
}
bool cmp2(pro a,pro b){
	return a.id<b.id;
}
int main(){
	int np,ng;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&P[i].weight);
		P[i].id = i;
	}
	vector<int>order,tempO;
	for(int i=0;i<np;i++){
		int temp;
		scanf("%d",&temp);
		order.push_back(temp);
	} 
	int num =0;
	int rNum =1;
//	printf("%d**\n",order.size());
	while(order.size()>1){
		for(int i=0;i<order.size();){
			int len = order.size();
			int gLeft = i;
			int gRight =min(gLeft+ng-1,len-1);
//			printf("%d*4444*%d\n",gLeft,gRight);
			int maxWeight =-1;
			int gMax;
			for(int j=gLeft;j<=gRight;j++){
				int temp = order[j];
				if(P[temp].weight>maxWeight){
					maxWeight = P[temp].weight;
					gMax = temp;
				}
			}
			for(int j=gLeft;j<=gRight;j++){
				int temp = order[j];
				if(temp!=gMax){
					P[temp].round = rNum;
				}else{
					tempO.push_back(gMax);
				}
			}
			i= gRight+1;	
		}
		order.clear();
		order = tempO;
		tempO.clear();
		rNum++;
	}
	int temp = order[0];
	P[temp].round = rNum;
	sort(P,P+np,cmp);
	int tRound =-1;
	int tRank;
	for(int i=0;i<np;i++){
		if(P[i].round!=tRound){
			P[i].rank = i+1;
			tRound = P[i].round;
			tRank = i+1;
		}else{
			P[i].rank = tRank;
		}
	}
	sort(P,P+np,cmp2);
	for(int i=0;i<np;i++){
		if(i!=0)
			printf(" ");
		printf("%d",P[i].rank);
	}
	return 0;	
}


////以前写的 
//#include<stdio.h>
//#include<queue>
//#include<string.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 1005;
//const int maxq =12;
//struct mouse{
//	int level;
//	int id;
//	int rank;
//}M[maxn];
//bool cmp1(mouse a,mouse b)
//{
//	return a.level>b.level;
//}
//bool cmp2(mouse a,mouse b)
//{
//	return a.id<b.id;
//}
//int main()
//{
//	queue<int>playqueue[2];
//	int weight[maxn];
//	int rank[maxn]={0};
//	int np,ng;
//	scanf("%d%d",&np,&ng); 
//	for(int i=0;i<np;i++)
//	{
//		scanf("%d",&weight[i]);
//		M[i].id =i;
//		M[i].level =1;
//	}
//	int order;
//	int num =0;
//	int othernum=1;
//	for(int i=0;i<np;i++)
//	{
//		scanf("%d",&order);
//		playqueue[num].push(order);
//	}
//	int levelnum=2;
//	while(playqueue[num].size()>1)  //确定每只老鼠打怪到第几层。 
//	{	
//		//里面存在一个人一组的，轮空，直接晋升。 
//		while(playqueue[num].size()>=1)   
//		{
//			int maxweight=-1;
//			int maxid;
//			for(int i=0;i<ng&&(!playqueue[num].empty());i++)
//			{
//				int f = playqueue[num].front();
//				playqueue[num].pop();
//				if(weight[f]>maxweight)
//				{
//					maxweight = weight[f];
//					maxid =f;
//				}
//			}
//			playqueue[othernum].push(maxid);
//			M[maxid].level=levelnum;
//		}
//		swap(num,othernum);   //两个队列交替使用。 
//		levelnum++; 
//	}
//	sort(M,M+np,cmp1);
//	int lastrank;
//	int lastlevel=-1;
//	for(int i=0;i<np;i++)
//	{
//		if(M[i].level!=lastlevel)
//		{
//			lastlevel = M[i].level;
//			M[i].rank = i+1;
//			lastrank =i+1;
//		}
//		else
//		{
//			M[i].rank=lastrank;	
//		}	
//	}
//	sort(M,M+np,cmp2);
//	for(int i=0;i<np;i++)
//	{
//		printf("%d",M[i].rank);
//		if(i<np-1)
//		printf(" ");
//		else
//		printf("\n");
//	}
//	return 0;	
//} 


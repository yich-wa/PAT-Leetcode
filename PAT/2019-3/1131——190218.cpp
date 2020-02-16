//09:25——10:40 得 18分。
//有12分的答案错误。 
//经过排查发现深度优先遍历时，首个节点没有放入路径中。
//改完后22分。原先对的一个点变错了。  第1、3测试点错误。

//经过思考发现，我考虑的经过的换乘站的个数，即使初始站是
//换乘站，也被考虑在内。但应该考虑的是，换乘的次数。初始站
//不应该算在内？可是但也不影响？ 经过换乘车站，不一定换乘，
// 考虑了上面问题后得 25分，第3测试点是错的。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10001;
const int inf = 1000000000;
vector<int>staLine[maxn];
int isvisit[maxn]={false};
int start,dest;
vector<int>G[maxn];
vector<int>tempPath,bestPath;
int bestNum;
int bestTrans;
int findComLine(int a ,int b)
{
	int lena = staLine[a].size();
	int lenb = staLine[b].size(); 
	for(int i=0;i<lena;i++)
	{
		for(int j=0;j<lenb;j++)
		{
			if(staLine[a][i]==staLine[b][j])
				return staLine[a][i];
		}
	}
}
void DFS(int s,int staNum,int trans,int preLine)
{
	if(s==dest)
	{
		if(staNum<bestNum)
		{
			bestPath = tempPath;
			bestNum = staNum;
			bestTrans = trans;
		}
		else if(staNum==bestNum&&trans<bestTrans)
		{
			bestPath = tempPath;
			bestTrans = trans;
		}
		return ;
	}
	int len = G[s].size();
	for(int i=0;i<len;i++)
	{
		int tempSta = G[s][i];
		if(isvisit[tempSta]==false)
		{
			isvisit[tempSta]=true;
			tempPath.push_back(tempSta);
			int comLine = findComLine(s,tempSta);
			if(comLine != preLine)
				DFS(tempSta,staNum+1,trans+1,comLine);
			else
				DFS(tempSta,staNum+1,trans,preLine);
			tempPath.pop_back();
			isvisit[tempSta]=false;
		}
	}	
}
bool isBelong(int s ,int l)
{
	int len = staLine[s].size();
	for(int i=0;i<len;i++)
	{
		if(staLine[s][i]==l)
			return true;
	}
	return false;
}
void out()
{
	int len = bestPath.size();
	printf("%d\n",len-1);
	int preSta = start;
	int nextSta;
	int preLine =-1;
	for(int i=1;i<len;i++)
	{
		if(preLine==-1)
		{
			preLine = findComLine(preSta,bestPath[i]);
			nextSta = bestPath[i];
		}
		else
		{
			if(isBelong(bestPath[i],preLine))
			{		
				nextSta = bestPath[i];
			}
			else
			{
				printf("Take Line#%d from %04d to %04d.\n",preLine,preSta,nextSta);
				preSta = nextSta;
				preLine =  findComLine(preSta,bestPath[i]);
				nextSta = bestPath[i];
			}
		}
	}
	printf("Take Line#%d from %04d to %04d.\n",preLine,preSta,nextSta);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		int last =-1;
		int tempsta;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&tempsta);
			staLine[tempsta].push_back(i);
			if(last!=-1)
			{
				G[last].push_back(tempsta);
				G[tempsta].push_back(last);
			}
			last = tempsta;	
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&start,&dest);
		bestNum = inf;
		bestTrans = inf;
		tempPath.clear();
		bestPath.clear();
		//fill(d,d+maxn,inf);
		fill(isvisit,isvisit+maxn,false);
		tempPath.push_back(start); 
		isvisit[start]=true;
		DFS(start,1,0,-1);
		out();
	}
	return 0;
} 
 
////之前写的 也是22分，但是第3测试点错误，第5测试点超时。 
//
////// 
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int maxm=10010;
//const int INF=1000000000;
//int G[maxm][maxm]={0};
//struct Station
//{
//	vector<int>l;
//	vector<int>neigh;
//}sta[maxm];
//int n;
//int m;
//int number;
//int nowline=-1;
//int nextline;
//int transf=0;
//int mintransf=INF;
//int minsta=INF;
//vector<int>temp;
//vector<int>out;
//bool flag[maxm]={false};
//int findline(int a,int b)
//{
//	for(int i=0;i<sta[a].l.size();i++)
//		for(int j=0;j<sta[b].l.size();j++)
//			if(sta[a].l[i]==sta[b].l[j])
//				return sta[a].l[i];
//}
//void DFS(int s,int d)
//{
//	if(s==d)
//	{
//		if(number<minsta)
//		{
//			minsta=number;
//			out=temp;
//			mintransf=transf;
//		}
//		else if(number==minsta&&transf<mintransf)
//		{
//			out=temp;
//			mintransf=transf;
//		}
//		return ;
//	}
//	flag[s]=true;
//	for(int i=0;i<sta[s].neigh.size();i++)
//	{
//		if(flag[sta[s].neigh[i]]==false)
//		{
//			int nowline1=nowline;
//			int transf1=transf;
//			nextline=findline(s,sta[s].neigh[i]);
//			if(nowline!=nextline)
//			{
//				transf++;
//				nowline=nextline;
//			}
//			temp.push_back(sta[s].neigh[i]);
//			number++;
//			DFS(sta[s].neigh[i],d);     //*********深度优先遍历********
//			number--;
//			temp.pop_back();
//			nowline=nowline1;
//			transf=transf1;
//		}
//	}
//	flag[s]=false;
//}
//int main()
//{
//	int index;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&m);
//		int p=-1;
//		for(int j=0;j<m;j++)
//		{
//			scanf("%d",&index);
//			sta[index].l.push_back(i);
//			if(p==-1)
//			{
//				p=index;
//			}
//			else
//			{
//				G[p][index]=1;
//				G[index][p]=1;
//				sta[index].neigh.push_back(p);
//				sta[p].neigh.push_back(index);
//				p=index;
//			}
//		}
//	}
//	int k;
//	scanf("%d",&k);
//	int start,des;
//	for(int i=0;i<k;i++)
//	{
//		out.clear();                     //**********初始化
//	    number=0;
//		minsta=INF;
//		nowline=-1;
//		mintransf=INF;
//		transf=0;
//		scanf("%d %d",&start,&des);
//		temp.push_back(start);
//		DFS(start,des);
//		temp.pop_back();
//		printf("%d\n",minsta);
//		int nowlineout=findline(out[0],out[1]);
//		int Start=out[0];
//		int End;
//		for(int j=1;j<out.size();j++)
//		{
//			int nextlineout=findline(out[j-1],out[j]);
//			if(nextlineout!=nowlineout)
//			{
//				End=out[j-1];
//				printf("Take Line#%d from %04d to %04d.\n",nowlineout,Start,End);
//				nowlineout=nextlineout;
//				Start=out[j-1];
//			}
//			if(j==out.size()-1)
//			{
//				End=out[j];
//				printf("Take Line#%d from %04d to %04d.\n",nowlineout,Start,End);
//			}
//		}
//	}
//	return 0;
//}

//12:30——

//开始犯了好多低级错误。
 
//当最短距离相等时，取时间最短的路径。开始自己直接在dijstras算法中
//解决了这个问题。但是到最后才意识到，要记录所有的路径，到最后
//用DFS去遍历，去找时间最短。只有确定完所有路径，才能确定，哪个时间
//最短。 
//所以两种路径都需要记录，最短"前驱数组" ，两个都是"前驱数组”

//14:30提交后全是段错误。 检查一遍后没查出问题。 
//查了十多分钟还是没查出问题，最后将提交网页编译器改成C++(clang++)就可以过了
//得到23分。
// 还有7分答案错误。

//怀疑是起点终点重合  

 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 502;
const int inf = 1000000000;
int Dis[maxn][maxn]={0}; 
int Tim[maxn][maxn]={0};
int d[maxn];
int t[maxn];
int isvisit[maxn];
int n,m;
int sou,des;
vector<int>vecdis;
vector<int>tempdis;
vector<int>pred[maxn];
int mintime = inf;
void DFSlenth(int s,int costtime)
{
	if(pred[s].size()==0)
	{
		if(costtime<mintime)
		{
			mintime=costtime;
			vecdis= tempdis;
		}
		return;
	}
	for(int i=0;i<pred[s].size();i++)
	{
		int tempid = pred[s][i];
		tempdis.push_back(tempid);
		DFSlenth(tempid,costtime+Tim[tempid][s]);
		tempdis.pop_back();
	}
}
void dijstralenth(int r)
{
	fill(isvisit,isvisit+maxn,false);
	fill(d,d+maxn,inf);
	fill(t,t+maxn,inf);
	//printf("%d***2232323\n",d[des]);
	d[r]=0;
	t[r]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;
		int min =inf;
		for(int j=0;j<n;j++)
		{
			if(isvisit[j]==false&&d[j]<min)
			{
				min = d[j];
				u=j;
			}
		}
		if(u==-1)
		break;
		isvisit[u]=true;
		for(int v=0;v<n;v++)
		{
			//开始忘记加Dis[u][v]!=0;导致，错误浪费20分钟多
			if(isvisit[v]==false&&Dis[u][v]!=0)
			{
				if(d[u]+Dis[u][v]<d[v])
				{
					d[v]=d[u]+Dis[u][v];
					t[v]=t[u]+Tim[u][v];
					pred[v].clear();
					pred[v].push_back(u);
				}
				else if(d[u]+Dis[u][v]==d[v]&&t[v]<t[u]+Tim[u][v])
				{
					t[v]=t[u]+Tim[u][v];
					pred[v].push_back(u);
				}
			}
		}
	}	
}
vector<int>pret[maxn];
void dijstratime(int r)
{	
	fill(isvisit,isvisit+maxn,false);
	fill(t,t+maxn,inf);
	fill(d,t+maxn,inf);
	d[r]=0;
	t[r]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;
		int min =inf;
		for(int j=0;j<n;j++)
		{
			if(isvisit[j]==false&&t[j]<min)
			{
				min = t[j];
				u=j;
			}
		}
		if(u==-1)
		break;
		isvisit[u]=true;
		for(int v=0;v<n;v++)
		{
			if(isvisit[v]==false)
			{
				//开始忘记加Tim[u][v]!=0;导致，错误浪费20分钟多 
				if(t[u]+Tim[u][v]<t[v]&&Tim[u][v]!=0)
				{
					t[v]=t[u]+Tim[u][v];
					pret[v].clear();
					pret[v].push_back(u);
				}
				else if(t[u]+Tim[u][v]==t[v])
				{
					pret[v].push_back(u);
				}
			}
		}
	}
}
vector<int>vectim;
vector<int>temptim;
int mininsec = inf;
int totalinsec=0;
void DFStime(int s,int totalinsec)
{
	if(pret[s].size()==0)
	{
		if(totalinsec<mininsec)
		{
			mininsec = totalinsec;
			vectim = temptim;
		}
		return;
	}
	for(int i=0;i<pret[s].size();i++)
	{
		int tempsec = pret[s][i];
		temptim.push_back(tempsec);
		DFStime(tempsec,totalinsec+1);
		temptim.pop_back();
	}	
}
int main()
{
	scanf("%d %d",&n,&m);
	int v1,v2;
	int tag,lenth,time;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&v1,&v2,&tag,&lenth,&time);
		Dis[v1][v2]=lenth;
		Tim[v1][v2]=time;
		if(tag==0)
		{
			Tim[v2][v1]=time;
			Dis[v2][v1]=lenth;
		}	 
	}
	scanf("%d %d",&sou,&des);
	dijstralenth(sou);
	//printf("%d***\n",d[des]);
	//下面的深度优先，填的应该是终点，由终点回溯，开始填成起点了。
	tempdis.push_back(des); 
	DFSlenth(des,0);
	int totaldis = d[des];
	dijstratime(sou);
	temptim.push_back(des);
	DFStime(des,1);
	int totaltime = t[des];
	//printf(" %d——%d \n",vecdis.size(),vectim.size());
	if(vectim==vecdis)
	{
		printf("Distance = %d; Time = %d:",totaldis,totaltime);
		//开始下面的i--写成了i++; 
		if(vectim.size()==1)
		{
			printf(" %d\n");
			return 0;
		 } 
		for(int i=vectim.size()-1;i>=0;i--)
		{
			if(i>0)
			{
				printf(" %d ->",vectim[i]);
			}			
			else
			{
				printf(" %d\n",vectim[i]);
			}
		}
	}
	else
	{
		printf("Distance = %d:",totaldis);
		//开始下面的i--写成了i++; 
		for(int i=vecdis.size()-1;i>=0;i--)
		{
			if(i>0)
			{
				printf(" %d ->",vecdis[i]);
			}			
			else
			{
				printf(" %d\n",vecdis[i]);
			}
		}
		printf("Time = %d:",totaltime);
		//开始下面的i--写成了i++; 
		for(int i=vectim.size()-1;i>=0;i--)
		{
			if(i>0)
			{
				printf(" %d ->",vectim[i]);
			}			
			else
			{
				printf(" %d\n",vectim[i]);
			}
		}
	}
	return 0;
}


//网上答案版，可以全过。 
//
//#include <iostream>
//#include <vector>
//#include <climits>
// 
//#define MAX 510
// 
//using namespace std;
// 
//int n, k;
//struct Node {
//	int v;
//	int time;
//	int len;
//};
//vector <Node> m[MAX];
//int disLen[MAX];
//int preLen[MAX];
//int timeLen[MAX];
// 
//int interTime[MAX];
//int preTime[MAX];
//int timeTime[MAX];
// 
//bool isVis[MAX];
// 
//void InitLen() {//初始化参数
//	for (int i = 0; i < MAX; i++) {
//		disLen[i] = INT_MAX;
//		preLen[i] = i;
//		timeLen[i] = INT_MAX;
//		isVis[i] = false;
//	}
//}
// 
//void InitTime() {//初始化参数
//	for (int i = 0; i < MAX; i++) {
//		interTime[i] = INT_MAX;
//		preTime[i] = i;
//		timeTime[i] = INT_MAX;
//		isVis[i] = false;
//	}
//}
// 
//void DijstraLen(int st) {
// 
//	disLen[st] = 0;
//	timeLen[st] = 0;
// 
//	for (int i = 0; i < n; i++) {
//		int min = INT_MAX, u = -1;
//		for (int j = 0; j < n; j++) {
//			if (!isVis[j] && min > disLen[j]) {
//				min = disLen[j];
//				u = j;
//			}
//		}
// 
//		if (u == -1) break;
// 
//		isVis[u] = true;
// 
//		for (int j = 0; j < m[u].size(); j++) {
//			int v = m[u][j].v;
//			if (!isVis[v]) {
//				if (disLen[u] + m[u][j].len < disLen[v]) {
//					disLen[v] = disLen[u] + m[u][j].len;
//					timeLen[v] = timeLen[u] + m[u][j].time;
//					preLen[v] = u;
//				}
//				else if (disLen[u] + m[u][j].len == disLen[v] && timeLen[u] + m[u][j].time < timeLen[v]) {
//					preLen[v] = u;
//					timeLen[v] = timeLen[u] + m[u][j].time;
//				}
//			}
//		}
//	}
//}
// 
//void DijstraTime(int st) {
//	interTime[st] = 0;
//	timeTime[st] = 0;
// 
//	for (int i = 0; i < n; i++) {
//		int min = INT_MAX, u = -1;
//		for (int j = 0; j < n; j++) {
//			if (!isVis[j] && min > timeTime[j]) {
//				min = timeTime[j];
//				u = j;
//			}
//		}
// 
//		if (u == -1) break;
// 
//		isVis[u] = true;
// 
//		for (int j = 0; j < m[u].size(); j++) {
//			int v = m[u][j].v;
//			if (!isVis[v]) {
//				if (timeTime[v] > timeTime[u] + m[u][j].time) {
//					timeTime[v] = timeTime[u] + m[u][j].time;
//					interTime[v] = 1 + interTime[u];
//					preTime[v] = u;
//				}
//				else if (timeTime[v] == timeTime[u] + m[u][j].time && interTime[v] > 1 + interTime[u]) {
//					interTime[v] = 1 + interTime[u];
//					preTime[v] = u;
//				}
//			}
//		}
//	}
//}
// 
//int main() {
//	cin >> n >> k;
// 
//	int u, v, tag;
//	Node tempNode;
//	for (int i = 0; i < k; i++) {
//		cin >> u >> v >> tag >> tempNode.len >> tempNode.time;
//		tempNode.v = v;
//		m[u].push_back(tempNode);
//		if (tag != 1) {//双行道
//			tempNode.v = u;
//			m[v].push_back(tempNode);
//		}
//	}
// 
//	cin >> u >> v;
//	InitLen();
//	DijstraLen(u);
//	vector <int> ansLen;
//	int prel = v;
//	while (prel != u) {
//		ansLen.push_back(prel);
//		prel = preLen[prel];
//	}
// 
//	InitTime();
//	DijstraTime(u);
//	vector <int> ansTime;
//	int pret = v;
//	while (pret != u) {
//		ansTime.push_back(pret);
//		pret = preTime[pret];
//	}
//	
// 
//	if (ansTime != ansLen) {//线路不相同
//		cout << "Distance = " << disLen[v] << ": " << u;
//		for (int i = ansLen.size() - 1; i >= 0; i--) {
//			cout << " -> " << ansLen[i];
//		}
//		cout << endl;
//	}
//	else {//线路相同
//		cout << "Distance = " << disLen[v] << "; ";
//	}
// 
//	cout << "Time = " << timeTime[v] << ": " << u;
//	for (int i = ansTime.size() - 1; i >= 0; i--) {
//		cout << " -> " << ansTime[i];
//	}
//	cout << endl;
//	
// 
// 
//	return 0;
//}


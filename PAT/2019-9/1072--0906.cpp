//09:26--11:11
// 本题出的问题都非常傻比：
// 即使自己不断的输出printf debug还是有很多傻逼的错误
//  错误一：求单源最短路径的时候，里面两层，外面一层。循环的上限都
//	设置错误。应该是n+m，而你却设置成：n+h;外面一层是彻底设置成n
//	 这是不懂，迪杰特斯拉算法的核心的。 车站本身就是站点。 
//	错误二： 开始输入的时候，内外层循环的指针都是i..
//	错误三： 开始时输入G[st[0]][st[1]]时，放错位置了。
//	总之都是低级错误。
//	感觉自己并不是很专注。总是出低级错误。还一边想着手机。写题的时候
//就一心想着拿分就可以。不要想其它的。分心，就是负债行为。 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
const int maxn = 1020;
const int inf = 1000000000;
struct station{
	double minDis;
	double aveDis;
	int Id; 
}tempS;
int G[maxn][maxn];
int d[maxn];
bool isVis[maxn];
bool cmp(station a,station b){
	if(a.minDis!=b.minDis)
		return a.minDis>b.minDis;
	else if(a.aveDis!=b.aveDis){
		return a.aveDis<b.aveDis;
	}else
		return a.Id<b.Id;
}
int main(){
	int n,m,k,ds;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	char p[2][6],p2[6];
	int st[2];
	int tempDis;
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int j=0;j<k;j++){
		scanf("%s %s %d",p[0],p[1],&tempDis);
		for(int i=0;i<2;i++){
			if(p[i][0]=='G'){
				sscanf(p[i],"G%d",&st[i]);
				st[i]+=n;
			}else{
				sscanf(p[i],"%d",&st[i]);
			}
		}	
		G[st[0]][st[1]]=tempDis;
		G[st[1]][st[0]]=tempDis;
//		printf("%d------%d----%d---%d\n",st[0],st[1],G[st[0]][st[1]],G[st[0]][st[1]]);	
	} 
//	printf("%d**G[5][7]*\n",G[5][7]);
	vector<station>output;
	for(int h=1;h<=m;h++){
		fill(d,d+maxn,inf);
		fill(isVis,isVis+maxn,false);
		d[n+h]=0;
		for(int i=0;i<n+m;i++){
			int min = inf;
			int u = -1;
			for(int j=1;j<=n+m;j++){
				if(isVis[j]==false&&d[j]<min){
					min = d[j];
					u =j;
				}
			}
//			printf("u:%d---du-%d--\n",u,d[u]);
			if(u==-1)
				break;
			isVis[u]=true;
			for(int v=1;v<=n+m;v++){
//				printf("u:%d******v:%d\n",u,v);
				if(isVis[v]==false&&G[u][v]!=inf){
					if(d[u]+G[u][v]<d[v]){
						d[v]=d[u]+G[u][v];
//						printf("h:%d  u:%d  v:%d G[u][v]:%d---dv:%d\n",h,u,v,G[u][v],d[v]);
					}
				}
			}
		}
		bool flag=true;
		int minD = inf;
		int sum = 0;
		for(int i=1;i<=n;i++){
			if(d[i]>ds){
				flag = false;
				break;
			}
//			printf("h:%d***%d***%d**\n",h,d[i],i);
			if(d[i]<minD){
				minD= d[i];
			}
			sum+=d[i];
		} 
		if(flag==true){
//			printf("sum:%d-----n:%d\n",sum,n);
			double ave = sum*1.0/(n*1.0);
			tempS.Id = h;
			tempS.minDis = minD;
			tempS.aveDis = ave;
//			printf("%d--%d--%d--\n",ave,h,minD);
			output.push_back(tempS);
		}
	}
	if(output.size()==0){
		printf("No Solution\n");
	}else{
		sort(output.begin(),output.begin()+output.size(),cmp);
		printf("G%d\n",output[0].Id);
		printf("%.1f %.1f\n",output[0].minDis,output[0].aveDis);
	}
	return 0;	
}

////以前写的
//#include<stdio.h>
//#include<iostream>
//#include<string.h>
//#include<string>
//#include<algorithm>
//using namespace std;
//const int inf = 1000000000;
//const int maxn = 1012;
//const int maxm = 12;
//int g[maxn][maxn];
//bool isvisit[maxn];
//int d[maxn];
//bool ischeck[maxm];
//double gasmindis[maxm];
//double gasavedis[maxm];
//int n,m,k,ds;
//void Dijstra(int s)
//{
//	fill(isvisit,isvisit+maxn,false);
//	fill(d,d+maxn,inf);
//	//printf("%d  %d\n",d[1],d[2]);
//	d[s]=0;
//	for(int i=1;i<=n+m;i++)
//	{
//		int mind = inf;
//		int u=-1;
//		for(int j=1;j<=n+m;j++)
//		{
//			if(isvisit[j]==false&&d[j]<mind)
//			{
//				mind= d[j];
//				u = j;
//			}
//		}
//		if(u==-1)
//			break;
//		isvisit[u]=true;
//		for(int v=1;v<=n+m;v++)
//		{
//			if(isvisit[v]==false&&g[u][v]!=inf&&d[u]+g[u][v]<d[v])
//				d[v]=d[u]+g[u][v];
//		}
//	}
//}
//int main()
//{	
//	scanf("%d%d%d%d",&n,&m,&k,&ds);
//	string p1,p2,tempp;
//	int d1,d2;
//	int tempdis;
//	fill(g[0],g[0]+maxn*maxn,inf);
//	for(int i=0;i<k;i++)
//	{
//		cin>>p1>>p2>>tempdis;
//		if(p1[0]=='G')
//		{
//			int len =p1.length(); 
//			tempp=p1.substr(1,len);
//			sscanf(tempp.c_str(),"%d",&d1);
//			d1+=n;
//		}
//		else
//			sscanf(p1.c_str(),"%d",&d1);
//		if(p2[0]=='G')
//		{
//			int len =p2.length(); 
//			tempp=p2.substr(1,len);
//			sscanf(tempp.c_str(),"%d",&d2);
//			d2+=n;
//		}
//		else
//			sscanf(p2.c_str(),"%d",&d2);
//		g[d1][d2]=tempdis;
//		g[d2][d1]=tempdis;
//		//printf("%d %d\n",d1,d2);
//	}
//	fill(ischeck,ischeck+maxm,true);
//	for(int i=n+1;i<=n+m;i++)
//	{
//		Dijstra(i);
//		double sum =0;
//		double min =inf;
//		for(int j=1;j<=n;j++)
//		{
//			//printf("%d ",d[j]);
//			sum+=d[j];
//			if(d[j]<min)
//				min=d[j];	
//			if(d[j]>ds)
//			{
//				ischeck[i-n]=false;
//				break;
//			}
//		}
//		//printf("\n");
//		if(ischeck[i-n]==true)
//		{
//			//printf("%.2f %.2f\n",sum,min);
//			gasmindis[i-n]=min;
//			gasavedis[i-n]=sum/(1.0*n);
//		}
//	}
//	int mindis =-1;
//	int minsta=-1; 
//	int minave;
//	for(int i=1;i<=m;i++)
//	{
//		if(ischeck[i]==true)
//		{
//			if(gasmindis[i]>mindis)
//			{
//				mindis=gasmindis[i];
//				minsta=i;
//				minave=gasavedis[i];
//			}
//			else if(gasmindis[i]==mindis&&gasavedis[i]<minave)
//			{
//				minsta=i;
//				minave=gasavedis[i];
//			}	
//		}
//	}
//	if(minsta!=-1)
//	{
//		printf("G%d\n",minsta);
//		printf("%.1f %.1f\n",gasmindis[minsta],gasavedis[minsta]);
//	}
//	else
//		printf("No Solution\n");
//	return 0;	
// } 

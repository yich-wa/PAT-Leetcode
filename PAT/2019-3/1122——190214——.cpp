//16:52——17:17 22分3分段错误
//这是无向图。感觉用的空间有点多，是不是超内存了。 
//经检查，开始fill函数没有加载“algorithm"头文件。 不过还不是这个
//问题。

// 发现问题： 
//好奇怪：为什么把G[maxn][maxn]定义到主函数外面就会段错误。
//改到主函数里面就过了。
//还是采用和以前的答案对照，试出来的。所以为什么呢？ 
//

//定义在主函数内用的是栈空间申请内存。 
//而栈空间是在进程创建时初始化的，大小由系统固定的。
//所以定义占用较大内存的变量（如大数组）时，
//编译可以通过但是运行不了。
//不是声明在栈内存中，而空间分配是在堆内存中吗？那是java的 
//函数内定义的在栈内存部分。//动态分配增加的在堆内存。 

//而当我们把变量的定义放在函数体以外时，
//所申请的内存来自于数据段，内存大小按需分配，
//可以自由增长，所以可以特别大。
//全局变量处在静态存储区。 
#include<stdio.h>
#include<algorithm> 
using namespace std;
const int maxn = 202;
int main()
{
	int G[maxn][maxn]={0};
	int n,m;
	scanf("%d%d",&n,&m);
	int edge1,edge2;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&edge1,&edge2);
		G[edge1][edge2]=1;
		G[edge2][edge1]=1;
	}
	int k;
	scanf("%d",&k);
	int nv;
	int path[maxn];
	bool ischeck[maxn]={false};
	for(int i=0;i<k;i++)
	{
		scanf("%d",&nv);
		fill(ischeck,ischeck+maxn,false);
		bool isout=false; 
		for(int j=0;j<nv;j++)
		{
			scanf("%d",&path[j]);
			ischeck[path[j]]=true;
		}
		for(int j=1;j<=n;j++)
		{
			if(ischeck[j]==false)
			{
				isout=true;
				break;
			}
		}
		if(isout==true)
			printf("NO\n");
		else if(nv!=n+1)  //点数对了。 
			printf("NO\n");
		else if(path[0]!=path[nv-1]) //首尾点相同。 
			printf("NO\n");
		else
		{
			for(int j=0;j<n;j++)
			{
				if(G[path[j]][path[j+1]]==0)
				{
					printf("NO\n");
					isout=true;
					break;
				}
			}
			if(isout==false)
				printf("YES\n");
		}
	 } 
	 return 0;
}

//25分做法：

//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 205;
//int main()
//{
//	int G[maxn][maxn]={0};
//	int n,m;
//	bool present[maxn]={false};
//	scanf("%d%d",&n,&m);
//	int u,v;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&u,&v);
//		G[u][v]=1;
//		G[v][u]=1;
//	}
//	int k;
//	int query[maxn];
//	scanf("%d",&k);
//	int num;
//	for(int i=0;i<k;i++)
//	{
//		bool isham =true;
//		fill(present,present+maxn,false);
//		scanf("%d",&num);
//		for(int j=0;j<num;j++)
//		{
//			scanf("%d",&query[j]);
//			present[query[j]]=true;
//		}
//		for(int j=1;j<=n;j++)
//		{
//			if(present[j]==false)
//			isham =false;
//		}
//		if(isham==false)
//		printf("NO\n");	
//		else if(num!=n+1)
//		printf("NO\n");
//		else if(query[0]!=query[n])
//		printf("NO\n");
//		else
//		{
//			bool flag =true;
//			for(int j=0;j<num-1;j++)
//			{
//				if(G[query[j]][query[j+1]]==0)
//				{
//					printf("NO\n");
//					flag=false;
//					break;
//				}
//			}
//			if(flag==true)
//			{
//				printf("YES\n");
//			}
//		}
//	}
//	return 0;
//}

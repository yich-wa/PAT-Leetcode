//15；07——
//——15:33  25分有5分段错误。
//将3维数组的3维最大值改成，准确允许最大值后，那5分变成运行超时
// //进行一定程度的优化处理，变成一个运行超时，一个段错误。

//看书中答案，说3维数组不能设置为bool型否则后面两组会超时。
//那改成int型，用0/1来代替。 还是25分，5分超时。
//各种优化完后依旧是5分超时。 

//是不是因为采用了递归而没有采用层序遍历加queue的结合。 
//按照答案的方法用重写了一遍层序遍历。将BFS的返回值改成int后
///才30分。

//反思，最好还是写出最高效整洁的代码。 
//减少判断次数。减少递归。递归感觉比较费时间 

//——16:27

#include<stdio.h>
#include<queue>
using namespace std;
const int maxm = 1286;
const int maxn = 128;
const int maxl = 60;
int g[maxl][maxm][maxn];
int isvisit[maxl][maxm][maxn] ={0};
int m,n,l,t;
//void BFS(int a,int b,int c)
//{
//	if(a<0||a>=l)
//		return ; 
//	if(b<0||b>=m)
//		return ;
//	if(c<0||c>=n)
//		return;
//	if(isvisit[a][b][c]==1)
//		return;
//	isvisit[a][b][c]=1;
//	if(g[a][b][c]==1)
//	{
//		tempcount++;
//		BFS(a-1,b,c);
//		BFS(a+1,b,c);
//		BFS(a,b+1,c);
//		BFS(a,b-1,c);
//		BFS(a,b,c+1);
//		BFS(a,b,c-1);
//	}
//}
struct node{
	int x;
	int y;
	int z;
}temp;
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int BFS(int a,int b,int c)
{
	int tempcount =0;
	queue<node>q;
	temp.x = a;
	temp.y = b;
	temp.z = c;
	isvisit[a][b][c]=1;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		tempcount++;
		node temp2;
		for(int i=0;i<6;i++)
		{
			 temp2.x = temp.x+X[i];
			 temp2.y = temp.y+Y[i];
			 temp2.z = temp.z+Z[i];	
			if(temp2.x<0||temp2.x>=l)
			 	continue;
			if(temp2.y<0||temp2.y>=m)
				continue;
			if(temp2.z<0||temp2.z>=n)
				continue;
			if(isvisit[temp2.x][temp2.y][temp2.z]==0&&g[temp2.x][temp2.y][temp2.z]==1)
			{
				isvisit[temp2.x][temp2.y][temp2.z]=1;//开始这个等号写成了"==" 
				q.push(temp2);	
			}		
		}	
	}
	if(tempcount>=t)
		return tempcount;
	else
		return 0;
}
int main()
{	
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<n;k++)
	scanf("%d",&g[i][j][k]);
	int sum =0;
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<n;k++)
	{
		//开始没有这个if判断，必然会导致多余的判断。
		//开始if中的判断语句只有一半，后来又填了另一半。 
		if(isvisit[i][j][k]==0&&g[i][j][k]==1)   
			sum+=BFS(i,j,k);
	}
	printf("%d\n",sum); 
	return 0; 
}

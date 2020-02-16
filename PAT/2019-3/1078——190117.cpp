// 17:26 —— 

//细节问题 
//——17:54 8分 
//经检查是由于传递参数 为i导致的 。函数送入参数设为i.的话，
//里面如果在设i。则会导致混乱。。本题即是。
//所以切记，以后不要用i做函数的传入定义参数。
//改完后依旧为 8分。但是确实是一个大错误。 
//——18:11  8分 

//审题问题 
//最后有看一遍最前面的介绍，发现是平方探测法的，一半
//只需要用正向增加部分。 (with positive increments only) 
//读题不细。没有真正读懂题中含义。 
//分数到20分。 

//知识点模糊问题——两点； 
//一： 
//看了书上答案知道，平方探测法，改变完变量后，要模一下msize;
//即 temp = (p+i*i)%msize;   i的范围是：[1,msize]; 

//二； 
//还有i的增量范围是msize
//不是msize的开方。 
//——18:19 改完25分。 

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 10779;
int pos[maxn];
int hash[maxn]={0};
int msize;
int qm;//平方探测的范围 
bool isprime(int a)
{
	if(a==1)
		return false;
	int temp = (int)sqrt(1.0*a);
	for(int i=2;i<=temp;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
void insert(int a,int id)
{
	int p =a%msize;
	if(hash[p]==0)
	{
		hash[p]=1;
		pos[id]=p;
		//printf("%d\n",p); 
		return ;
	}
	int temp;
	for(int i=1;i<=msize;i++)
	{
		temp = (p+i*i)%msize;
		if(temp>=0&&temp<msize&&hash[temp]==0)
		{ 
			hash[temp]=1;
			pos[id]=temp;
			//printf("%d\n",temp);
			return;
		}	
	}
}
int main()
{	
	int n;
	fill(pos,pos+maxn,-1);
	scanf("%d%d",&msize,&n);
	while(isprime(msize)==false)
	{
		msize++;
	}
	qm =(int)sqrt(1.0*msize);
	int input[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
		insert(input[i],i);
	}
	for(int i=0;i<n;i++)
	{
		if(pos[i]==-1)
			printf("-");
		else
			printf("%d",pos[i]); 
		if(i<n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
 } 

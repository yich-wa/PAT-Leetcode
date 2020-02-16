//09：00——09:17

//12分。用了极其简单的方式。但是答案应该是意思我用三次翻转。
//用了，还是12分。 

//一开始没有注意到n,m之间的大小比较， 谁告诉你m一定就小于n
//不要随便自己相当然默认
//改过后多了3分。 

//reverse 函数中不要想当然默认left<right 
//改完后多5分。 
 
#include<stdio.h>
#include<math.h>
#include<algorithm> 
using namespace std;
const int maxn=105;
int a[maxn];
void reverse(int left,int right)
{
	if(left>=right)   //开始缺这行代码 
	return ; 
	int mid = (left+right)/2;
	while(left<=mid)
	{
		swap(a[left],a[right]);
		left++;
		right--;
	 }  
	 return ;
 } 
int main()
{
	int n,m;
	
	scanf("%d%d",&n,&m);
	if(m>n)    //开始缺这行代码 
		m=m%n; 
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int count =0;
	reverse(0,n-1);
	reverse(0,m-1);
	reverse(m,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i<n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
 } 
 
// #include<stdio.h>
//#include<math.h>
//const int maxn=105;
//int main()
//{
//	int n,m;
//	int a[maxn];
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	scanf("%d",&a[i]);
//	int count =0;
//	int num = n-m;
//	for(int i=0;i<n;i++)
//	{
//		printf("%d",a[num]);
//		if(i<n-1)
//			printf(" ");
//		else
//			print
//			f("\n");
//		num++;
//		num = num%n;
//	}
//	return 0;
// } 

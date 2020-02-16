//11:27——11:50
//开始想着还要用分块思想，怕超时，但最后发现这种思想行不通。
//因为你就算挑出中位数。如果中位数的数字是重复的。你就没办法将其
//归到较小部分。还是较大 部分。

//最后觉得还是采用sort方法。居然没有超时，简直了。 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100005;
//const int sq = 335;
//int block [sq]={0};
//int table[maxn]={0};
int data[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
//		table[data[i]]++;
//		block[data[i]/sq]++;
	}
	int mid = n/2;
	sort(data,data+n);
	int num =0;
	int s1=0;
	int s2=0;
	while(num<mid)
	{
		s1+=data[num++];
	 }
	while(num<n)
	{
		s2+=data[num++];
	 } 
	printf("%d %d\n",n%2,s2-s1);
	return 0;
 } 
 
//	int num =0;
//	int b_id= 0;
//	while(num+block[b_id]<mid)
//	{
//		num=num+block[b_id];
//		b_id++;
//	}
//	int numid = b_id*sq;
//	while(num+table[numid]<mid)
//	{
//		num+=table[numid];
//		numid++;
//	}

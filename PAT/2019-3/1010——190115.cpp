//15:51——16:20 答完得9分，其余超时偏多。故采用二分法锁定
//用二分法找最后的进制。

//有一种低级错误叫做事与愿违的低级错误。就是你想的是a但写的是
//b一定要避免那种低级错误。这大题就差出一个
//这个一般认真理一遍题意就可以发现。
//改完那个低级错误后得15分。大多数错误是答案错误—— 16:49 

//你忽略了未知数的最小进制minradix，都大于已知数know的大小
//即minradix>know 的情况 ，添上到19分。

//看了答案发现：
//每个数的值，当进制极大时。可能超过int的表示范围。 所以两个数
//的值都需要用long long 表示 ,而且要判断溢出与否。 
//已知的那个数 默认不会超过long long(书上说的，题中并没有说） 

// 以及遍历进制会超时，所以还是要用二分法；进制下界易确认
//上界不易确认。上届为已知数和下界的较大值+"1".(答案说法)
//但是个人认为并不用+'1'

//不加1，不用二分法，则为23分，1分错误，一分超时 。 
///加上为22分。 为3分错误 

//此题最高做到23分。 不用过多纠结了。效率为王。这道题 能用3个多小时。
//细节有点多。 

 


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long LL;
//LL inf =(1LL << 63)-1;
int map[260]; //建立字母和数字之间的映射。
long long d_value(char str[],int r)
{
	int len = strlen(str);
	long long sum =0;
	for(int i=0;i<len;i++)
	{	
		sum = sum*r+map[str[i]];
		if(sum<0)
	 		return -1;
	 } 
	 return sum; 
 } 
int main()
{
	char N1[11],N2[11]; 
	//对map进行初始化 
	for(char i='0';i<='9';i++)
		map[i]=i-'0';
	for(char i='a';i<='z';i++)
		map[i]=i-'a'+10;
	int tag,radix;
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	char N[11];
	long long know;
	if(tag==1)
	{
		know = d_value(N1,radix);
		strcpy(N,N2);
	}
	else
	{
		know = d_value(N2,radix);
		strcpy(N,N1);
	}
	int minradix=0;
	int len = strlen(N);
	int temp;
	for(int i=0;i<len;i++)
	{
		temp=map[N[i]];
		if(temp>minradix)
			minradix = temp;
	}
	minradix++;
	long long u_know;
	int maxradix =max(know,(LL)minradix);
	int midradix;
//	while(minradix<=maxradix)
//	{
//		midradix = (minradix+maxradix)/2;
//		u_know = d_value(N,midradix);
//		if(u_know<0||u_know>know)
//		{
//			maxradix = midradix-1;
//		}
//		else if(u_know<know)
//		{
//			minradix = midradix+1;
//		}
//		else
//			break;
//	}
//	if(minradix>maxradix)
//		printf("Impossible\n");
//	else
//	{
//		//若多个进制都符合， 
//		///只发生在N只有一位数时。且这些进制相连。 
//		while(u_know==know&&midradix>=minradix)
//		{
//			midradix--;
//			u_know = d_value(N,midradix);	
//		}
//		printf("%d",midradix+1);	
//	}
	while(minradix<=maxradix)
	{
		u_know = d_value(N,minradix);///小于0表示溢出了。 
		if(u_know==know)
		{
			printf("%d\n",minradix);
			return 0;
		}
		if(u_know<0||u_know>know)
		{
			printf("Impossible\n");
			return 0;
		}
		minradix++; 
	}
	//你忽略了未知数的最小进制minradix，都大于已知数know的大小
	//即minradix>know 的情况 ，所以要补上下句。 
	//	printf("Impossible\n");
	return 0;
 } 

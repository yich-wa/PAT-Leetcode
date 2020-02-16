//13:50——14:22  运行超时还差3分。 

//经看答案只，找seq[j]>=temp的第一个数时，超时，应该使用
//二分法，或者是lower_bound(first ,last ,val); 
//注意 lower/upper_bound的使用方法； 其返回的为一个指针。 
// int j=lower_bound(seq,seq+i+1,temp)-seq;

//这是一个很重要的思想。 
//先用 M/p取上整数也是简化的思路，这样避免了使用long long 


#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 100010;
int main()
{
	int n;
	double p;
	int seq[maxn];
	scanf("%d %lf",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+n);
	int max_num=-1;
	int m,M;
	int temp;
	for(int i=n-1;i>=0;i--)
	{
		temp =ceil((double)seq[i]/p);
		//内在是使用二分法查找的
		int j=lower_bound(seq,seq+i+1,temp)-seq; 
//		for( j=0;j<n;j++)
//			if(seq[j]>=temp)
//				break; 
		int tempnum = i-j+1;
		if(tempnum>max_num)
			max_num=tempnum;
		if(j==0)
			break;			
	}
	printf("%d\n",max_num);
	return 0;	
}

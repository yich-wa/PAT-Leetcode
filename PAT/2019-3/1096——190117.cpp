//20:50——
//——21:24  18分 
//一分错误，一分超时。
// 
//原来是特判没有提前结束，最终通过测试素数数据发现错误。
//整体思路是从头遍历，假设第一个因子，然后看可以连续多少个
//不断更新最大个数。根据已知缩短要判断的范围。 
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
bool isprime(int a)
{
	if(a==1)
	return false;
	int temp= (int)sqrt(1.0*a);
	for(int i=2;i<=temp;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	//这就是本题的特殊情况，注意点。 
	if(isprime(n)==true) 
	{
		printf("1\n");
		printf("%d",n);
		return 0; 
	}
	int up =n;
	int down =2; 
	int max_num=0;
	int min_seq_f;
	while(down<=up)
	{
		//printf("%d\n",down);
		int temp =n;
		int td = down;
		int count=0;
		while(temp%td==0)
		{
			//printf("%d  ",td);
			//开始下面两个式子顺序写反了。。 
			temp = temp/td;
			td++;
			//printf(" *%d* ",temp);
			count++;
		}
		//printf("\n");
		if(count>max_num)
		{
			max_num=count;
			min_seq_f = down;
			//下面这句很关键。 
			up=(int)pow(1.0*n,1.0/(count*1.0));
		}
		down++;
	}
	printf("%d\n",max_num);
	printf("%d",min_seq_f);
	min_seq_f++; 
	for(int i=1;i<max_num;i++)
	{
		printf("*%d",min_seq_f);
		min_seq_f++;
	}
	return 0;
}

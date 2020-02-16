//20:52——
// 21:36 23分答案错误。
//直接从半中间去堆排序是最方便的。减少无用功。解决问题，提高效率。
//书中答案给的数据测试是错误的。上机手册334页
//在判断是否是插入排序时，你是从后往前比，先找与原序列不同的节点，
//然后判断该节点及之前是否已经有序 
//但初始和部分序列都是 3 4 2 1 就有问题了。找不到不同的节点。
//对那种特殊情况进行处理之后25分。
//当两个序列相同时，如果前面有大于2位的有序，则形成插入排序。
//因为是只排了一部分。所以必定有大于2位的有序， 

//判断插入排序可以从后向前比，遍历前面有序的部分。对于后面无序的
//部分，使之与原序列相比较，相同则是，插入。这样比较统一一些。

//堆排序的知识点要很清晰。不要给自己埋地雷。
//删除是删堆顶，向下调整  ;插入是先插在最后，然后向上调整。 
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 102;
int now[maxn];
void downadjust(int a,int len)
{
	int i;
	while(2*a<=len)
	{
		i=2*a;
		if(2*a+1<=len&&now[2*a+1]>now[i])
			i=2*a+1;
		if(now[a]<now[i])
		{
			swap(now[a],now[i]);
			a=i;
		}
		else
			break;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int ori[maxn];
	int tempori[maxn];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ori[i]);
		tempori[i]=ori[i];
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&now[i]);
	int k;
	for(k=n;k>=1;k--)
	{
		if(now[k]!=ori[k])
		break;
	}
	if(k==0)
	{
		k=1;
		while(now[k]<now[k+1])
			k++;
	 } 
	int tempk= k;
	bool isinsert=true;
	if(k<2)   //插入排序的前两个一定是有序的。 
		isinsert=false;
	else	
		for(int i=2;i<=k;i++)
		{
			if(now[i]<now[i-1])
			{
				isinsert = false;
				break;
			}
		}
	if(isinsert==true)
	{
		printf("Insertion Sort\n");
		sort(now+1,now+k+2);
		for(int i=1;i<=n;i++)
		{
			printf("%d",now[i]);
			if(i<n)
			printf(" ");
			else
			printf("\n");
		}
		return 0;
	}
	printf("Heap Sort\n");
	//堆排序的存储是从1开始的。 
	sort(tempori+1,tempori+n+1);
	for(k=n;k>=1;k--)
	{
		if(tempori[k]!=now[k])
		{
			break;
		}
	}
	swap(now[1],now[k]);
	downadjust(1,k-1);
	for(int i=1;i<=n;i++)
	{
		printf("%d",now[i]);
		if(i<n)
		printf(" ");
	} 
	return 0;	
}

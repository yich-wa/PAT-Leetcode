//09:55——10:33得了样例都过了。但只得了2分。 暂时查不出思维错误。
 
//细节1； 
//看自己在编译器上的答案 ，发现思路大致一致。
///犯了以前同样犯的错误。当0在0位时。确定要交换的元素位置k后。
//先改变hash，在交换。注意对位一致。改完后17分。8分3个点超时
//对位一定要一致，题颇为绕，所以要对位时要一致。 
 
///细节2： 
// 对比以前的答案发现：自己每次去找第一个不在其位的数时，都是
//从头去找因此可能超时吧。 应从上次的位置去找。改完还差2分。
//尽量保证算法的高效性。 

//细节3； 
//个人觉得是0一开始如果在其位的话。不在其位的个数not_pos，就与要恢复的
//个数一致了。所以整体循环的判别将是：not_pos>0而不是not_pos>1;
//但若0一开始不在其位的话，最后是not_pos>1；
//为统一起见：将not_pos规定为除0位之外，其他位上数不对的个数。
//改完后为满分。

//上面为三个细节错误点；发现问题——快速更正。
//整体用哈希法，表示每个数的位置。这样比较快。
///本题为变异的排序算法。
//哨兵思想 
 

#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
	int n;
	scanf("%d",&n);
	int orig[maxn];
	int hash[maxn];
	int not_pos =0;//有多少个不在其位的数。 
	bool flag[maxn]={false};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&orig[i]);
		hash[orig[i]]=i;
		if(orig[i]!=i&&i!=0)
			not_pos++;
		else 
			flag[i]=true;		
	}
	int count =0;//交换次数 
	 //不在其位的数不可能只有一个。必定成双出来 
	 //若只not_pos>0则，即使完全复位，也知识not_pos=1;
	 //该退出时却画蛇添足。 
	 int k=1;
	 //每次找不在其位的数的位置，应从上次的开始。因此
	 //将k=1放到循环外侧。k是顺序遍历。这次找时，上次的k
	 //位的数，已经归位 。故应放到外侧。 
	while(not_pos>0) 
	{
		if(hash[0]!=0)
		{
			int pos1=hash[0];
			int pos2 = hash[pos1];
			swap(orig[pos1],orig[pos2]);
			hash[0]=pos2;
			hash[pos1]=pos1;
			flag[pos1]=true; 
			count++; 
			not_pos--;	
		}
		else
		{ 
			while(flag[k])
				k++;
			//****下面两句的顺序不能反了。
			//若非要用先交换，后改变hash；
			//则用hash[orig[0]]=0;因为以前在k位置的数，交换后在0位置。 
			 hash[orig[k]]=0; 
			swap(orig[0],orig[k]);
			hash[0]=k;
			count++;
		}	
	}	
	printf("%d\n",count);
	return 0;
}


////编译器中上次答案。
// #include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn=100010;
//int a[maxn];
//int b[maxn];
//int pos[maxn];
//bool common[maxn]={false};
//int num=0;//总共需要交换的次数
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&a[i]);
//		pos[a[i]]=i;
//		b[i]=a[i];
//	}
//	sort(b,b+n);
//	bool flag=true;
//	int add0=0;  //表示0所在位置的角标i
//	int tru=0;
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]!=b[i])
//		{
//			flag=false;
//			common[i]=false;
//		}
//		else
//		{
//			common[i]=true;
//			if(i!=0)
//				tru++;
//		}
//		if(a[i]==0)
//		{
//			add0=i;
//		}
//	}
//	int k=1;   //后来debug时，参照答案，其实多次从头查找第一个本位上不是该数的数。添加K，省去很多功夫。
//	while(tru<n-1)  //tru表示除了0外，其余在本位的个数。
//	{
//		if(add0==0)   
//		{
//			for(int i=k;i<n;i++)
//			{
//				if(common[i]==false)   //找一个位置上不是正确数的位置。
//				{
//					pos[a[i]]=0;             //**********这句和下一句的顺序不能乱********刚开始写乱了。
//					swap(a[0],a[i]);
//					num++;
//					add0=i;
//					k=i;
//					break;
//				}
//			}
//		}
//		while(add0!=0)
//		{
//			swap(a[add0],a[pos[add0]]);
//			common[add0]=true;
//			num++;
//			tru++;
//			add0=pos[add0];
//			break;
//		}
//	}
//	printf("%d\n",num);
//	return 0;
//}

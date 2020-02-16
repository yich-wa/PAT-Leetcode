//15:36-- 16:23 得分19分。还有6分超时。估计是逻辑漏洞，死循环了。 
//通过看过去的写法，发现，每次找不在其位的位置时，都是从头开始找。
//这个是多余的动作。每次从上一次找到的位置开始找，这样省很多时间。。 
#include<stdio.h>
#include<algorithm>
using namespace std; 
const int maxn = 100005;
int val[maxn];
int pos[maxn];
int main(){
	int n;
	scanf("%d",&n);
	int recover = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
		//下面这个不包含零。 只统计需要归为多少个非零的数。
		//非零的归为，零自然也就归位了。 这个很关键。 
		if(val[i]!=i&&i!=0){
			recover++;
		}
		pos[val[i]]=i;
	}
	int sum = 0;
	int rNum =0;
	//记录不在其位的起始位置。 
	int stN=1; 
	while(rNum<recover){
		int tempP = pos[0];
		if(tempP!=0){
			int p = pos[tempP];
			swap(val[tempP],val[p]);
			pos[0] = p;
			//归为了一个地方 
			pos[tempP] = tempP;
			sum++;
			rNum++;
		}else{
			//0在0位上，不过还没有完全归序 
			int tempNum = stN;
			while(tempNum<n&&val[tempNum]==tempNum){
				tempNum++;
			}
			stN = tempNum+1;
			int temp = val[tempNum];
			swap(val[0],val[tempNum]);
			pos[temp] = 0;
			pos[0]=tempNum;
			sum++; 
		}
	}
	printf("%d",sum);
	return 0;
}


////以前写的
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 100010;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int orig[maxn];
//	int hash[maxn];
//	int not_pos =0;//有多少个不在其位的数。 
//	bool flag[maxn]={false};
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&orig[i]);
//		hash[orig[i]]=i;
//		if(orig[i]!=i&&i!=0)
//			not_pos++;
//		else 
//			flag[i]=true;		
//	}
//	int count =0;//交换次数 
//	 //不在其位的数不可能只有一个。必定成双出来 
//	 //若只not_pos>0则，即使完全复位，也知识not_pos=1;
//	 //该退出时却画蛇添足。 
//	 int k=1;
//	 //每次找不在其位的数的位置，应从上次的开始。因此
//	 //将k=1放到循环外侧。k是顺序遍历。这次找时，上次的k
//	 //位的数，已经归位 。故应放到外侧。 
//	while(not_pos>0) 
//	{
//		if(hash[0]!=0)
//		{
//			int pos1=hash[0];
//			int pos2 = hash[pos1];
//			swap(orig[pos1],orig[pos2]);
//			hash[0]=pos2;
//			hash[pos1]=pos1;
//			flag[pos1]=true; 
//			count++; 
//			not_pos--;	
//		}
//		else
//		{ 
//			while(flag[k])
//				k++;
//			//****下面两句的顺序不能反了。
//			//若非要用先交换，后改变hash；
//			//则用hash[orig[0]]=0;因为以前在k位置的数，交换后在0位置。 
//			 hash[orig[k]]=0; 
//			swap(orig[0],orig[k]);
//			hash[0]=k;
//			count++;
//		}	
//	}	
//	printf("%d\n",count);
//	return 0;
//} 

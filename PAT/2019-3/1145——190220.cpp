//09：12——09:54 
//hash 平方探测法。

//具体的步骤和知识点细节，要很清晰。
//开始将赋值 = 写成 判断 ==用printf检查出来。 
//平方探测法增量的范围是：j>=1&&j<=mSize 这一步很容易记不清 有等于
 
//newhk = hk+j*j;
//newhk = newhk%mSize; 这一步很容易忘记 
#include<stdio.h>
#include<math.h>
const int maxn = 100010;
bool notprime[maxn]={false};
void prime()
{
	notprime[1]=true;
	int sq = sqrt(1.0*100010);
	for(int i=2;i<=sq;i++)
	{
		if(notprime[i]==false)
		{
			for(int j=2*i;j<=maxn;j+=i)
			{
				notprime[j]=true;
			}
		}
	}
 } 
 int main()
 {
 	int mSize,n,m;
 	prime();
 	scanf("%d%d%d",&mSize,&n,&m);
 	while(notprime[mSize]==true)
 		mSize++;
 	int hash[maxn]={0};
 	int temp;
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&temp);
 		bool flag =false;
 		int hk = temp%mSize;
 		if(hash[hk]!=0)
 		{
 			for(int j=1;j<=mSize;j++)
 			{
 				int newhk = hk+j*j;
 				newhk=newhk%mSize;
 				if(hash[newhk]==0)
 				{
 					hash[newhk]=temp;
 					//printf("装入 %d  %d\n",newhk,temp);
 					flag=true;
 					break;
				 }
			 }
		 }
		 else
		 {
		 	hash[hk]=temp;
		 	//printf("装入 %d  %d\n",hk,temp);
		 	flag=true;
		 }
		 if(flag==false)
		 {
		 	printf("%d cannot be inserted.\n",temp);
		 }
	 }
	 int sumCount =0;
	 for(int i=0;i<m;i++)
	 {
	 	scanf("%d",&temp);
	 	int hk = temp%mSize;
	 	int count =0;
	 	if(hash[hk]==temp||hash[hk]==0)
	 		count++;
	 	else
	 	{
	 		count++;
	 		for(int j=1;j<=mSize;j++)
	 		{
	 			count++;
	 			int newhk = hk+j*j;
	 			newhk=newhk%mSize;
	 			if(hash[newhk]==temp||hash[newhk]==0)
	 			{
	 				break;
				}	
			}
		}
	//	printf("%d mSize  %d %d——%d\n",mSize,hk,temp,count);
	 	sumCount+=count;	
	 }
	printf("%.1f\n",(1.0*sumCount)/m);
	return 0;
 }

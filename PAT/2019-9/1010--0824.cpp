//进制转化的题，先算出已知进制的值value。当未知为一位时，直接特判。否则，算出未知进制数的进制最小值
//其进制最大的可能值则是value。然后从小到大，遍历，如遇相等，输出，并结束。 

//一分答案错误，一分超时。暂时就这样吧。。
//后来用折半只能拿到20分。与此同时，发现：已知进制的值，
// 用LL表示是够了。而未知那个数，用long long 可能还会
//越界，越界之后正值变成负值。所以：也可以判断出来。
//即通过越界来判断。 值过大正的也会变成负的 
//使用折半 之后，所有的int都改成longlong 之后，全对。 
#include<stdio.h>
#include<string.h>
typedef long long LL;
const int maxn = 12;
LL known(char a[],LL radix){
	LL sum = 0;
	LL level = 1;
	LL len = strlen(a);
	for(int i=len-1;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9'){
			sum+=(a[i]-'0')*level;
		}else{
			sum+=(a[i]-'a'+10)*level; 
		}
		level = level*radix;
	}
	return sum;
}
int main(){
	char n1[maxn];
	char n2[maxn],n[maxn];
	LL tag ,radix;
	scanf("%s %s %lld %lld",n1,n2,&tag,&radix);
	LL value = 0;
	if(tag==1){
		value = known(n1,radix);
		strcpy(n,n2);
	}else{
		value = known(n2,radix);
		strcpy(n,n1);
	}
	LL minR =1;
	LL tempValue;
	for(int i=0;i<strlen(n);i++){
		if(n[i]>='0'&&n[i]<='9'){
			tempValue= n[i]-'0';
		}else{
			tempValue = n[i]-'a'+10;
		}
		if(tempValue>minR){
			minR = tempValue;
		}
	}
	minR++;	
	if(strlen(n)==1){
		if(tempValue ==value){
			printf("%lld",minR);
		}else{
			printf("Impossible");
		}
		return 0;
	}
	LL maxR = value;
	LL finalR;
	bool isIm = false;
	LL mid;
	// 用下面的折半查找，会出现很多测试点答案错误。 
	while(minR<=maxR){
		mid = (minR+maxR)/2;
		tempValue = known(n,mid);
		if(tempValue==value){
			printf("%lld",mid);
			return 0;
		}
		else if(tempValue<0||tempValue>value){
			maxR = mid-1;
		}else{
			minR = mid+1;
		}
	} 
//	for(int i=minR;i<=maxR;i++){
//		tempValue = known(n,i);
//		if(tempValue>value){
//			break;
//		}
//		if(tempValue == value){
//			printf("%d",i);
//			return 0;	
//		} 
//	}
	printf("Impossible");
	return 0;	
}

////以前写的：
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//typedef long long LL;
////LL inf =(1LL << 63)-1;
//int map[260]; //建立字母和数字之间的映射。
//long long d_value(char str[],int r)
//{
//	int len = strlen(str);
//	long long sum =0;
//	for(int i=0;i<len;i++)
//	{	
//		sum = sum*r+map[str[i]];
//		if(sum<0)
//	 		return -1;
//	 } 
//	 return sum; 
// } 
//int main()
//{
//	char N1[11],N2[11]; 
//	//对map进行初始化 
//	for(char i='0';i<='9';i++)
//		map[i]=i-'0';
//	for(char i='a';i<='z';i++)
//		map[i]=i-'a'+10;
//	int tag,radix;
//	scanf("%s %s %d %d",N1,N2,&tag,&radix);
//	char N[11];
//	long long know;
//	if(tag==1)
//	{
//		know = d_value(N1,radix);
//		strcpy(N,N2);
//	}
//	else
//	{
//		know = d_value(N2,radix);
//		strcpy(N,N1);
//	}
//	int minradix=0;
//	int len = strlen(N);
//	int temp;
//	for(int i=0;i<len;i++)
//	{
//		temp=map[N[i]];
//		if(temp>minradix)
//			minradix = temp;
//	}
//	minradix++;
//	long long u_know;
//	int maxradix =max(know,(LL)minradix);
//	int midradix;
////	while(minradix<=maxradix)
////	{
////		midradix = (minradix+maxradix)/2;
////		u_know = d_value(N,midradix);
////		if(u_know<0||u_know>know)
////		{
////			maxradix = midradix-1;
////		}
////		else if(u_know<know)
////		{
////			minradix = midradix+1;
////		}
////		else
////			break;
////	}
////	if(minradix>maxradix)
////		printf("Impossible\n");
////	else
////	{
////		//若多个进制都符合， 
////		///只发生在N只有一位数时。且这些进制相连。 
////		while(u_know==know&&midradix>=minradix)
////		{
////			midradix--;
////			u_know = d_value(N,midradix);	
////		}
////		printf("%d",midradix+1);	
////	}
//	while(minradix<=maxradix)
//	{
//		u_know = d_value(N,minradix);///小于0表示溢出了。 
//		if(u_know==know)
//		{
//			printf("%d\n",minradix);
//			return 0;
//		}
//		if(u_know<0||u_know>know)
//		{
//			printf("Impossible\n");
//			return 0;
//		}
//		minradix++; 
//	}
//	//你忽略了未知数的最小进制minradix，都大于已知数know的大小
//	//即minradix>know 的情况 ，所以要补上下句。 
//	//	printf("Impossible\n");
//	return 0;
// } 

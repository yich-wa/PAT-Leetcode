//����ת�����⣬�������֪���Ƶ�ֵvalue����δ֪Ϊһλʱ��ֱ�����С��������δ֪�������Ľ�����Сֵ
//��������Ŀ���ֵ����value��Ȼ���С���󣬱�����������ȣ�������������� 

//һ�ִ𰸴���һ�ֳ�ʱ����ʱ�������ɡ���
//�������۰�ֻ���õ�20�֡����ͬʱ�����֣���֪���Ƶ�ֵ��
// ��LL��ʾ�ǹ��ˡ���δ֪�Ǹ�������long long ���ܻ���
//Խ�磬Խ��֮����ֵ��ɸ�ֵ�����ԣ�Ҳ�����жϳ�����
//��ͨ��Խ�����жϡ� ֵ��������Ҳ���ɸ��� 
//ʹ���۰� ֮�����е�int���ĳ�longlong ֮��ȫ�ԡ� 
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
	// ��������۰���ң�����ֺܶ���Ե�𰸴��� 
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

////��ǰд�ģ�
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//typedef long long LL;
////LL inf =(1LL << 63)-1;
//int map[260]; //������ĸ������֮���ӳ�䡣
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
//	//��map���г�ʼ�� 
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
////		//��������ƶ����ϣ� 
////		///ֻ������Nֻ��һλ��ʱ������Щ���������� 
////		while(u_know==know&&midradix>=minradix)
////		{
////			midradix--;
////			u_know = d_value(N,midradix);	
////		}
////		printf("%d",midradix+1);	
////	}
//	while(minradix<=maxradix)
//	{
//		u_know = d_value(N,minradix);///С��0��ʾ����ˡ� 
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
//	//�������δ֪������С����minradix����������֪��know�Ĵ�С
//	//��minradix>know ����� ������Ҫ�����¾䡣 
//	//	printf("Impossible\n");
//	return 0;
// } 

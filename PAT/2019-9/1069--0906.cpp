//7:35--08:00
//本题 特例有两种：一种2222这种。还有一种是：6174。特例就特殊输出和输入。 
//分类讨论，大化小。小的就很好解决了。拆题。 
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp1(char a,char b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	char str[5],str2[5];
	sprintf(str,"%04d",n);
	bool flag = true;
	for(int i=0;i<3;i++){
		if(str[i]!=str[i+1]){
			flag=false;
			break;
		}
	}
	if(flag==true){
		printf("%04d - %04d = 0000\n",n,n);
		return 0;
	}
	if(n==6174){
		printf("7641 - 1467 = 6174\n");
		return 0;
	}
	int result;
	int n1,n2;
	while(n!=6174){
		sprintf(str,"%04d",n);
		strcpy(str2,str);
		sort(str,str+4,cmp1);
		sort(str2,str2+4);
		sscanf(str,"%d",&n1);
		sscanf(str2,"%d",&n2);
		printf("%04d - %04d = %04d\n",n1,n2,n1-n2);
		n = n1-n2;
	}
	return 0;
}


////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//bool cmp( char a,char b)
//{
//	return a>b;
//}
//int main()
//{
//	char a1[6];
//	char a2[6];
//	int num1,num2,num;
//	scanf("%s",a1);
//	int len1 =strlen(a1);
//	if(len1==4)
//	{
//		bool flag=true;
//		for(int i=1;i<len1;i++)
//			if(a1[i]!=a1[i-1])
//			{
//				flag=false;
//				break;
//			}
//		if(flag==true)
//		{
//			printf("%s - %s = 0000\n",a1,a1);
//			return 0;
//		}		
//	}
//	num=0;
//	while(num!=6174)
//	{
//		int len1 =strlen(a1);
//		sort(a1,a1+len1);	
//		sscanf(a1,"%d",&num1); 
//		sort(a1,a1+len1,cmp);
//		sscanf(a1,"%d",&num2);
//		while(num2<1000)
//			num2=num2*10; 
//		num =num2-num1;
//		printf("%04d - %04d = %04d\n",num2,num1,num);
//		sprintf(a1,"%d",num);
//	}
//	//printf("7641 - 1467 = 6174\n");
//	return 0;
// }  

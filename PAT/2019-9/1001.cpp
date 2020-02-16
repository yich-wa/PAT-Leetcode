#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	c = a+b;
	// printf("%d\n",c);
	if(c<0){
		printf("-");
		c=-1*c;
	}
	char str[10];
	sprintf(str,"%d",c);
  	// printf("%s\n",str);
	int len = strlen(str);
	for(int i=0;i<len;i++){
		printf("%c",str[i]);
		int temp = len-1-i;
		if(temp!=0&&temp%3==0){
			printf(",");
		}
	}
	return 0;
} 

////之前的做法：
//#include<cstdio>   
//int main()
//{
//int a,b,c,j,i=0;
//int d[3];
//scanf("%d %d",&a,&b);
//c=a+b;
//if(c<0)
//{
//printf("-");
//c=-c;
//}
//do 
//{d[i++]=c%1000;
//c = c/1000;
//}while(c!=0);
//i--;
//printf("%d",d[i]);
//if(i!=0)
//	printf(",");
//for(j=i-1;j>=0;j--)
//{
//	printf("%03d",d[j]);
//	if(j!=0)
//	printf(",");
//}
//return 0;
//}	 


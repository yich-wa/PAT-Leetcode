//pat1001 这个题有几个注意点：如果你用字符串额处理方式
//要考虑到1,000,000这种。所以一开始你写了一个错误做法。后附
//以及负数的正确处理方式。
//将结果转化为字符串去输出是对的。尽量用sscanf 和sprintf 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main() {
 int a, b;
 cin >> a >> b;
 int c =a+b;
 if(c<0)
 {
 	printf("-");
 	c=-c;
	} 
	 string s = to_string(c);
	 int len = s.length();
	 for (int i = 0; i < len; i++) {
 	cout << s[i];
 	if (s[i] == '-') continue;
 	if ((i + 1) % 3 == len % 3 && i != len - 1) 
	 	cout << ",";
 	}
 return 0;
}

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
//		printf(",");
//}
//return 0;
//}
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//using namespace std;
//const int max = 5;
//int main()
//{
//	int a,b;
//	scanf("%d%d",&a,&b);
//	int c = a+b;
//	char  ch[5][6];
//	int count =0;
//	if(c ==0)
//		printf("%d\n",c);
//	else
//	while(c!=0)
//	{
//		int temp =c%1000;
//		c=c/1000;
//		if(c!=0)
//			sprintf(ch[count++],"%d",abs(temp));
//		else
//			sprintf(ch[count++],"%d",temp);
//		
//		}	
//	for(int i=count-1;i>=0;i--)
//	{
//		printf("%s",ch[i]);
//		if(i>0)
//		printf(",");
//	}
//	return 0;
// } 

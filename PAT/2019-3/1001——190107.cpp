//pat1001 ������м���ע��㣺��������ַ������ʽ
//Ҫ���ǵ�1,000,000���֡�����һ��ʼ��д��һ��������������
//�Լ���������ȷ����ʽ��
//�����ת��Ϊ�ַ���ȥ����ǶԵġ�������sscanf ��sprintf 
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

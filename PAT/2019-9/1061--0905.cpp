//07:54-08：27 
#include<stdio.h>
#include<string.h>
const int maxn = 65;
int main(){
	char str[4][maxn];
	int len[4];
	for(int i=0;i<4;i++){
		scanf("%s",str[i]);
		len[i] = strlen(str[i]);
	}
	bool isFir = false;
	int fir;
	int sec;
	int thi;
	for(int i=0;i<len[0]&&i<len[1];i++){
		if(str[0][i]==str[1][i]){
			//注意下面是到N; 
			if(str[0][i]>='A'&&str[0][i]<='N'){
				//下面是到'G' 
				if(isFir==false&&str[0][i]<='G'){
					fir = str[0][i]-'A';
					isFir = true;	
				}else if(isFir==true){
					sec = str[0][i]-'A'+10;
					break;
				}
			}else if(isFir==true&&str[0][i]>='0'&&str[0][i]<='9'){
				sec = str[0][i]-'0';
				break;
			}	
		}	
	}
	for(int i=0;i<len[2]&&i<len[3];i++){
		if(str[2][i]==str[3][i]){
			if(str[2][i]>='a'&&str[2][i]<='z'){
				thi = i;
				break;
			}else if(str[2][i]>'A'&&str[2][i]<='Z'){
				thi = i;
				break;
			}
			
		}
	}
	char week[7][10] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	printf("%s ",week[fir]);
	printf("%02d:%02d",sec,thi); 
	return 0;	
}
//
////以前写的
//#include <stdio.h>
//#include <iostream>
//#include <string.h>
//int main()
//{
//	char a[4][65];
//	char week[8][4]={" ","MON","TUE","WED","THU","FRI","SAT","SUN"};      //*********必须是4不能是3*****3会报错。
//	int day,hour,min;
//	for(int i=0;i<4;i++)
//	{
//		scanf("%s",a[i]);
//	}
//	int len0=strlen(a[0]);
//	int len1=strlen(a[1]);
//	bool flag=false;
//	for(int i=0;i<len0&&i<len1;i++)
//	{
//		if(flag==false&&a[0][i]==a[1][i]&&a[0][i]>='A'&&a[0][i]<='G')    ///*******不应该是<='Z',因为星期几，一共就7天所以应该是<='G'
//		{
//			day=a[0][i]-'A'+1;
//			flag=true;
//		}
//		else if(flag==true&&a[0][i]==a[1][i])                            //*******这个if语句和上条的if必须用else 连接，两个不能顺序串联执行，一次只能执行一个******
//		{
//			if(a[0][i]>='0'&&a[0][i]<='9')
//			{
//				hour=a[0][i]-'0';
//				break;
//			}
//			else if(a[0][i]>='A'&&a[0][i]<='N')
//			{
//				hour=a[0][i]-'A'+10;
//				break;
//			}
//		}
//	}
//	int len2=strlen(a[2]),len3=strlen(a[3]);
//	for(int i=0;i<len2&&i<len3;i++)               //****************这两个里面要加break，因为后续可能还有相同的字母。*********
//	{
//		if(a[2][i]==a[3][i])
//		{
//			if(a[2][i]>='A'&&a[2][i]<='Z')
//			{
//				min=i;
//				break;
//			}
//			else if(a[2][i]>='a'&&a[2][i]<='z')
//			{
//				min=i;
//				break;
//			}
//		}
//	}
//	printf("%s ",week[day]);
//	printf("%02d:%02d",hour,min);
//	return 0;
//}
 

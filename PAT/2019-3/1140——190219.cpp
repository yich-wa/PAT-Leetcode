//07:59 得 17分 ，3分运行时错误。 
//将maxn改大后，20分。 
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 100005; //在往小改就会有段错误。 
int main()
{
	char a[maxn],b[maxn];
	int n;
	scanf("%s %d",a,&n);
	for(int h =0;h<n-1;h++)
	{
		int len = strlen(a);
		int num =0;
		for(int i=0;i<len;)
		{
			int j =i+1; 
			int count =1;
			while(a[j]==a[j-1]) 
			{
				j++;
				count++; 
			} 
			b[num++]= a[i];
			b[num++]= '0'+ count;
			i=j;
		}
		b[num]='\0';
		strcpy(a,b);
		//printf("%s**\n",a);
	}
	printf("%s",a);
	return 0;	
}
//以前写的正确答案。
//
// #include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<string>
//using namespace std;
//const int maxc = 1000000;
//int main()
//{
//	int c,n;
//	scanf("%d%d",&c,&n);
//	char temp[maxc];
//	char temp2[maxc];
//	char last ='0'+(c-0);
//	temp[0]=last;
//	temp[1]='\0';
//	for(int i=1;i<n;i++)
//	{
//		last =temp[0];
//		int count =0;
//		int count2 =0;
//		int num=0;
//		while(temp[count]!='\0')
//		{
//			if(temp[count]==last)
//			{
//				num++;
//				count++;
//			}
//			else
//			{
//				temp2[count2++]=last;
//				temp2[count2++]='0'+(num-0);
//				last =temp[count];
//				num=0;
//			}
//		}
//		temp2[count2++]=last;
//		temp2[count2++]='0'+(num-0);
//		for(int i=0;i<count2;i++)
//		{
//			temp[i]=temp2[i];
//		}
//		temp[count2]='\0';	
//	}
//	printf("%s\n",temp); 
//	return 0;	
// } 

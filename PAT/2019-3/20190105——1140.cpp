// pat 1140  10:35����11:10 �õ�17�ֻ���3�֡��δ��� �� 
//���ս� maxc��ֵ��10000�ĳ�1000000�õ�20�֡� 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
using namespace std;
const int maxc = 1000000;
int main()
{
	int c,n;
	scanf("%d%d",&c,&n);
	char temp[maxc];
	char temp2[maxc];
	char last ='0'+(c-0);
	temp[0]=last;
	temp[1]='\0';
	for(int i=1;i<n;i++)
	{
		last =temp[0];
		int count =0;
		int count2 =0;
		int num=0;
		while(temp[count]!='\0')
		{
			if(temp[count]==last)
			{
				num++;
				count++;
			}
			else
			{
				temp2[count2++]=last;
				temp2[count2++]='0'+(num-0);
				last =temp[count];
				num=0;
			}
		}
		//�������µ��ǲ��ֺ���Ҫ 
		temp2[count2++]=last;
		temp2[count2++]='0'+(num-0);
		for(int i=0;i<count2;i++)
		{
			temp[i]=temp2[i];
		}
		temp[count2]='\0';	
	}
	printf("%s\n",temp); 
	return 0;	
 } 

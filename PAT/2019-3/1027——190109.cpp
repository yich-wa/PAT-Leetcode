#include<stdio.h>
int main()
{
	int input[3];
	for(int i=0;i<3;i++)
	{
		scanf("%d",&input[i]);
	}
	printf("#");
	for(int i=0;i<3;i++)
	{
		int a =input[i]/13;
		int b=input[i]%13;
		char out;
		if(a<10)
			printf("%d",a);
		else
		{
			out = 'A'+(a-10); 
			printf("%c",out);
		}
		if(b<10)
			printf("%d",b);
		else
		{
			out = 'A'+(b-10); 
			printf("%c",out);
		}	
	}
	printf("\n");
	return 0;
 } 

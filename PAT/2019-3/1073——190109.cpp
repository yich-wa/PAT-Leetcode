//读懂题意和细节，分为系数为正，为负，为0；分类讨论。 
#include<stdio.h>
#include<string.h>
const int maxn = 10005;
int main()
{
	char input[maxn] ;
	char exp[6];
	scanf("%s",input);
	if(input[0]=='-')
		printf("-");
	int lenth =strlen(input);
	bool ispo ;
	int i=1;
	while(input[i]!='E')
		i++;
	i++;
	if(input[i]=='+')
		ispo = true; 
	else
		ispo = false;
	int num =0;
	for(int j =i+1;j<=lenth;j++)
	{
		exp[num++]=input[j];
	}
	int d_exp;
	sscanf(exp,"%d",&d_exp);
	i--;
	if(d_exp==0)
	{
		for(int j=1;j<i;j++)
		{
			printf("%c",input[j]);
		}		
	}	
	else if(ispo==false)
	{
		printf("0.");
		while(d_exp>1)
		{
			printf("0");
			d_exp--;
		}	
		for(int j=1;j<i;j++)
		{
			if(input[j]!='.')
			printf("%c",input[j]);
		}
	}
	else if(ispo==true)
	{
		int count =-1;
		int j=1;
		while(j<i&&count<d_exp) 
		{
			if(input[j]!='.')
			{
				printf("%c",input[j]);
				count++;
			}	
			j++;
		}
		if(count==d_exp&&j<i)
		{
			printf(".");
			while(j<i)
			{
				printf("%c",input[j++]);
			}
		}
		while(count<d_exp)
		{
			printf("0");
			count++;
		}
	}
	return 0;	
 } 

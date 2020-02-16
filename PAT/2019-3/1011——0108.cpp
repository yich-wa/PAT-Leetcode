#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	char ch[3]={'W','T','L'};
	double odd[3];
	int maxindex[3];
	double maxodd[3];
	double sum =1;
	for(int i=0;i<3;i++)
	{
		double tempodd=0;
		for(int j=0;j<3;j++)
		{
			scanf("%lf",&odd[j]);
			if(odd[j]>tempodd)
			{
				tempodd=odd[j];
				maxindex[i] =j;
			}
		}
		sum=sum*tempodd;
	}
	sum =(sum*0.65-1)*2;
	printf("%c %c %c %.2f\n",ch[maxindex[0]],ch[maxindex[1]],ch[maxindex[2]],sum);
	return 0;
 } 

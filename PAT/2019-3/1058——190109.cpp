#include<stdio.h>
struct currency
{
	int galleon;
	int sickle;
	int knut;
}C[3];
int main()
{
	for(int i=0;i<2;i++)
	{
		scanf("%d.%d.%d",&C[i].galleon,&C[i].sickle,&C[i].knut);
	}
	int up;
	C[2].knut = (C[0].knut+C[1].knut)%29;
	up = (C[0].knut+C[1].knut)/29;
	C[2].sickle =(C[0].sickle+C[1].sickle+up)%17;
	up = (C[0].sickle+C[1].sickle+up)/17;
	C[2].galleon = C[0].galleon+C[1].galleon+up;
	printf("%d.%d.%d\n",C[2].galleon,C[2].sickle,C[2].knut);
	return 0;
}

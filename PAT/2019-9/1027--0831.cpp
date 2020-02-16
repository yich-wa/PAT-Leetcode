//20:51--21:02  尽量用for循环来，解决重复性代码。 
#include<stdio.h>
#include<string.h>
int main(){
	int c[3];
	int temp[2];
	for(int i=0;i<3;i++){
		scanf("%d",&c[i]);
	}
	printf("#");
	for(int i=0;i<3;i++){
		temp[0] = c[i]/13;
		temp[1] = c[i]%13;
		for(int j=0;j<2;j++){
			if(temp[j]<10)
				printf("%d",temp[j]);
			else{
				char a = 'A'+(temp[j]-10);
				printf("%c",a);
			}
		}
	}
	return 0; 
}

////以前做的
//#include<stdio.h>
//int main()
//{
//	int input[3];
//	for(int i=0;i<3;i++)
//	{
//		scanf("%d",&input[i]);
//	}
//	printf("#");
//	for(int i=0;i<3;i++)
//	{
//		int a =input[i]/13;
//		int b=input[i]%13;
//		char out;
//		if(a<10)
//			printf("%d",a);
//		else
//		{
//			out = 'A'+(a-10); 
//			printf("%c",out);
//		}
//		if(b<10)
//			printf("%d",b);
//		else
//		{
//			out = 'A'+(b-10); 
//			printf("%c",out);
//		}	
//	}
//	printf("\n");
//	return 0;
// }  

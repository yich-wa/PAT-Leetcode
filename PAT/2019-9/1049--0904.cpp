//数1的个数，分类讨论，注意边界条件。可以多用笔列列情况。
//分为左中右的数字。然后对中间的数字进行大于等于小于三种情况的
//讨论。 
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	int len =0;
	int tempN = n;
	while(tempN>0){
		len++;
		tempN = tempN/10;
	}
//	printf("%d***\n",len);
	int sum =0;
	int left;
	int right;
	int leftN,rightN;
	int mid; 
	for(int i=1;i<=len;i++){
		int level = (int)pow(10,i-1);
		int right = n%level;
		int temp = n/level;
		int mid = temp%10;
		int left = temp/10;
		if(mid>1){
			rightN = level;
			leftN = left+1;
			sum+=leftN*rightN;
		}else if(mid==1){
			//高位不变加上，低位剩余的。 
			sum+=right+1;
			leftN = left;
			rightN = level;
			sum+=leftN*rightN;
		}else{
			leftN = left;
			rightN = level;
			sum+=leftN*rightN;
		}
//		printf("%d-----%d\n",i,sum);
	}
	printf("%d",sum);
	return 0;
}

////以前的写法
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//int main()
//{
//	int n;
//	char a[15];
//	scanf("%s",a);
//	int len =strlen(a);
//	sscanf(a,"%d",&n);
//	int sum =0;
//	int left =0;
//	int right =0;
//	int pos;
//	int temp;
//	for(int i=0;i<len;i++)
//	{
//		temp = n;
//		right = temp%(int)(pow(10.0,i*1.0))+1;
//		temp = temp/pow(10.0,i);
//		pos = temp%10;
//		left = temp/10+1;
//		if(pos==0)
//		{
//			left=left-1;
//			right =(int)(pow(10.0,i*1.0)); 
//		}
//		else if(pos ==1)
//		{
//			sum+=right;
//			left=left-1;
//			right =(int)(pow(10.0,i*1.0));
//		}
//		else
//		{
//			right =(int)(pow(10.0,i*1.0));
//		} 
//		sum+=left*right;		
//	}
//	printf("%d\n",sum);
//	return 0;
} 

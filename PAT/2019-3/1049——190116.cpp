//09:51���� 
//����10:07��13�� 
//���������ĳһposλΪ1 �����ж��ٸ���
//����λΪ">1",��������������㡣����ܼ���left��pow(10,�ұ�λ��)
//����λΪ"=1" ,�� ����ܼ���(left-1)�� pow(10,�ұ�λ��)+ �ұ��ܼ���right
//����λΪ"=0" ,��  ����ܼ���(left-1)�� pow(10,�ұ�λ��)

//����10:40 
//��������ķ������ۣ���30�֡� 
//��������˼·Ҫ�ǳ������� 
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	char a[15];
	scanf("%s",a);
	int len =strlen(a);
	sscanf(a,"%d",&n);
	int sum =0;
	int left =0;
	int right =0;
	int pos;
	int temp;
	for(int i=0;i<len;i++)
	{
		temp = n;
		right = temp%(int)(pow(10.0,i*1.0))+1;
		temp = temp/pow(10.0,i);
		pos = temp%10;
		left = temp/10+1;
		if(pos==0)
		{
			left=left-1;
			right =(int)(pow(10.0,i*1.0)); 
		}
		else if(pos ==1)
		{
			sum+=right;
			left=left-1;
			right =(int)(pow(10.0,i*1.0));
		}
		else
		{
			right =(int)(pow(10.0,i*1.0));
		} 
		sum+=left*right;		
	}
	printf("%d\n",sum);
	return 0;
}
	
	


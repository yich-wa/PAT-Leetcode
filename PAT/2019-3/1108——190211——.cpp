//09:48����
//����10:20  18�֣�2�ֵ�����ʱ����
//��Ч���ص������������0����9��".","-" ������������
//"-"ֻ�ܳ�������λ��"."ֻ�ܳ���һ�Ρ� 

//�Ҳ�����ʱ���� ����Ϊ�����������ֵ��ַ���
//ͨ��sscanfת�������ʱ������ ���磺  90.
//����   -.90 

//���껹����2������ʱ���� 
//��ʱ�������ۺ�������󻯡� 

//�����ɲο���ŵ������������sscanf���ַ���ת��Ϊ���֣�Ȼ���ٽ�
//����ͨ��sprintfת��Ϊ�ַ������Ƚ�ǰ�������ַ����Ƿ���ȡ�
//���˼·�ǳ����
 
#include<stdio.h>
#include<math.h>
#include<string.h>
const int maxn = 102; 
bool isCheck(char a[])
{
	int len =strlen(a);
	bool existPoint=false;
	if((a[0]!='-')&&(a[0]<'0')&&(a[0]>'9'))
		return false;
//	int i=0;
//	if(a[i]=='-')
//		i++;
	for(int i=1;i<len;i++)
	{
		if(a[i]=='.')
		{
			if(i==1&&a[0]=='-')
				return false; 
			else if(existPoint==true)
			{
				return false;
			}
			else
			{
				//��ʼû�м�:"len-i>0"���֡� 
				if(len-i<=3&&len-i>0)
					existPoint=true;
				else
					return false;
			}	
		}
		else if((a[i]>'9')||(a[i]<'0'))
			return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	char temp[12];
	int checkNum = 0;
	double sum =0;
	double tempNum;
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		//printf("%s**\n",temp);
		if(isCheck(temp))
		{
			sscanf(temp,"%lf",&tempNum);
			if(tempNum<=1000&&tempNum>=-1000)
			{
				checkNum++;
				sum+=tempNum;
			}
			else
			{
				printf("ERROR: %s is not a legal number\n",temp);
			}
		}
		else
		{
			printf("ERROR: %s is not a legal number\n",temp);
		}
	}
	if(checkNum==0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(checkNum==1)
	{
		printf("The average of 1 number is %.2f\n",sum);
	}
	else
	{
		printf("The average of %d numbers is %.2f\n",checkNum,sum/(1.0*checkNum));
	}
	return 0;
}

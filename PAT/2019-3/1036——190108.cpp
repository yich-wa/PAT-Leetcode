//����Χ����������������в������á�ע��%c�ǿ���ʶ��ո�ͻ���
//������ģ���%s��ʶ���жϡ� ���ǿ�����һ��scanf���뿴���롣
//�ṹ��Ҳ����ֱ��"���"���¡� male = temp; female = temp;
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int maxc =15;
struct student{
	char name[15];
	char gender;
	char id[15];
	int score;
}male,female,temp;
int main()
{
	int n;
	int mlowest=101;
	int fhighest =-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//scanf("%s %c %s %d",temp.name ,&temp.gender,temp.id,&temp.score); 
		scanf("%s",temp.name);
		getchar();
		scanf("%c",&temp.gender);
		getchar();
		scanf("%s",temp.id);
		scanf("%d",&temp.score);
		if(temp.gender=='M'&&temp.score<mlowest)
		{
			mlowest = temp.score;
			strcpy(male.name,temp.name);
			strcpy(male.id ,temp.id);	
		}
		if(temp.gender=='F'&&temp.score>fhighest)
		{
			fhighest = temp.score;
			strcpy(female.name,temp.name);
			strcpy(female.id ,temp.id);
		}
	}
	if(fhighest<0)
		printf("Absent\n");
	else 
		printf("%s %s\n",female.name,female.id);
	if(mlowest>100)
		printf("Absent\n");
	else
		printf("%s %s\n",male.name,male.id);
	if(fhighest<0||mlowest>100)
		printf("NA\n");
	else
		printf("%d\n",fhighest-mlowest);
	return 0;	
 } 

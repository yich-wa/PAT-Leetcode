//�ٴ�����string.h  �е��ַ����飬��string�е��ַ���֮�������
//string.h������gets,puts �����е����������
//��stringֻ����cin,cout  ��
//C++��"��������string"���õ��ǣ�getline(cin,str); 
//���룺char str[100],�õ���cin.getline(str,100); 
//��ֵ������տ����ܳ������������ύȴ������� 
//�����������֣����ַ��������ټ��˸����з��� 
#include<stdio.h>
#include<string.h>
const int maxc = 260;
int main()
{
	int n;
	scanf("%d",&n);
	//����������û��з� 
	getchar();
	bool flag=true;
	char temp[maxc];
	char samepart[maxc];
	gets(samepart);
	int lens,lent;
	for(int k=1;k<n;k++)
	{
		gets(temp);
		if(flag==true)
		{
			lens =strlen(samepart);
			lent =strlen(temp);
			int i =lens-1;
			int j =lent-1;
			while(i>=0&&j>=0&&samepart[i]==temp[j])
			{
				i--;
				j--;
			}
			if(i==lens-1)
				flag=false;
			else
			{
				int count =0;
				for(int h=j+1;h<=lent;h++)
				{
					samepart[count++]=temp[h];
				}
				samepart[count]='\n'; 
			}
		 } 	
	}
	//�и����⹫��β׺���׸��ո�Ҫ����� 
	if(flag==false)
		printf("nai\n");
	else
	{
		lens =strlen(samepart);
		for(int i=0;i<lens;i++)
		{
			if(samepart[0]==' ')
				continue;
			printf("%c",samepart[i]);
		}
	}
	return 0;
 } 

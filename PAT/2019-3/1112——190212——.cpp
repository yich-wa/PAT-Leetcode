//10:41
//
//forѭ��������I++�ˣ��������ּ���һ��for�������滹����һ��i++
//�ͼ�����
//����11:16  �� 14�֡���6�ֵĴ𰸴��� 

//�������ݾ������Ǵ����
//�ɲο�set��ȥ�ع��ܡ� 

//����11:27���� 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
bool isStuck[256]={false};
bool isIn[256]={false};
char origin[maxn];
char after[maxn]; 
int k;
vector<char>st;
void check()
{
	int len =strlen(origin);
	int i=0;
	//���Ҳ�ǣ�Ҫô��forѭ������ı�i++��Ҫô������ı�i++�������������� 
	for(;i<len;)
	{
		int j= i;
		while(origin[j]==origin[i]&&j<len)
		{
			j++;
		}
		if((j-i)%k!=0)
		{
			//�߼����˵�С���⡣����Ӧ����true 
			isStuck[origin[i]]=true;  //������û�п�ס�� 
		}
		i=j;
	}
}
void change()
{
	int len = strlen(origin);
	int i=0;
	int num =0;
	//forѭ��������I++�ˣ��������ּ���һ��for�������滹����һ��i++
	//�ͼ����� 
	for(;i<len;)
	{
		after[num++]=origin[i];
		if(isStuck[origin[i]]==true)
		{
			i++;
		}
		else
		{
			//printf("%c**\n",origin[i]);
			if(isIn[origin[i]]==false)
			{
				st.push_back(origin[i]);
				isIn[origin[i]]=true;
			}
			i+=3;
		}
	}
	after[num]='\0';
}
int main()
{
	scanf("%d",&k);
	scanf("%s",origin);
	check();
	change();
	for(int i=0;i<st.size();i++)
	{
		printf("%c",st[i]);
	}
	printf("\n");
	printf("%s\n",after);
	return 0;	
}

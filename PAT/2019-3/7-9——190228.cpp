//16:14 
//�����д������ʱ��ġ������㲻����ÿ����ĸ�ı��볤��ȥ�Ա��Ƿ�һ��
//���ж��Ƿ�ϸ�Ӧ�����ܵĳ���һ��ȥ�ж��Ƿ���� 
//������Ӧ��ͨ��������һ�������������õ��ܵı��볤�ȡ�
//����������ı��볤�����ȥ�� 
//����Ҳ��Ϊ mapʹ�ò���������С���⡣����Ҫ�ǣ�mp.find(str)==mp.end()
//��ʾ����û�г��ֹ���

//������������б��׼��
//��һ�ǣ����ս�����ܱ��볤��Ӧ��һ�¡�
////Ҫ�������һ������������ĳ��ȣ�Ȼ�����Ƚϡ� 
//����ǣ�һ����������һ����ǰ׺�� 
////��һ�齫��ǰ׺�����б�ǡ� 

///��һ��ͬѧ�ı����У�����ǰ׺���붼�� map<string,int>mp ����ӳ�䡣
//��ʾ��Щǰ׺�������������롣Ϊ��ֹ��ͬͬѧ��mpӳ��֮�以��Ӱ�� 
//��ǰ׺��ӳ��ɣ���ͬѧ��š�

//�м����˺ܶ��printf ���׶β���debug
 

//�õ�19�֡� ��1��2 ��6���Ե���� 
 
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 150;
struct Item{
	string cha;
	int fre;
	int lenth;
}item[maxn];
bool cmp(int a,int b)
{
	return item[a].fre>item[b].fre;
}
int main()
{
	int n; 
	cin>>n;
	int pre[maxn];
	int Id[maxn];
	map<string,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>item[i].cha>>item[i].fre;
		//scanf("%c %d",&item[i].cha,&item[i].fre);
		Id[i]=i;
	}
	//printf("%d**\n",n);
	int num =n;
	int numId = n;
	while(num>1)
	{
		sort(Id,Id+num,cmp);
		int newfre = item[Id[num-1]].fre+item[Id[num-2]].fre;
		pre[Id[num-1]]=numId;
		pre[Id[num-2]]=numId;
		//printf("%d****%d___%d\n",Id[num-1],Id[num-2],numId);
		Id[num-2] = numId;
		item[numId].fre = newfre;
		num--;
		
		numId++;
			
	}
	pre[Id[0]]=-1;
	//	printf("%d**\n",Id[0]);
	int sumlen = 0;
	for(int i=0;i<n;i++)
	{
		int len =0;
		int tempId = i;
		//printf("%d**\n",tempId);
		while(pre[tempId]!=-1)
		{
			tempId = pre[tempId];
			len++;
		}
		item[i].lenth = len;
		sumlen+=item[i].fre*len;
	} 
	int m;
	cin>>m;
	string tempcha;
	string code[maxn];
	for(int i=0;i<m;i++)
	{
		bool flag = true;
		int tempsumlen=0;
		for(int j=0;j<n;j++)
		{
			cin>>tempcha>>code[j];
			if(flag==true)
			{
				if(tempcha==item[j].cha&&code[j].length()<=63)
				{
					int len = code[j].length();
					for(int k=1;k<len-1;k++)
					{
						string tempstr = code[j].substr(0,k);
						mp[tempstr]=i;	
					}
				}
				else
				{
					flag=false;
				}
			}
			tempsumlen +=item[j].fre*code[j].length();
		}
		//printf("%d**ccc%d\n",tempsumlen,sumlen);
		if(flag==true&&sumlen!=tempsumlen)
		{
			flag=false;
		}
		if(flag==true)
			for(int j=0;j<n;j++)
			{
				if(mp.find(code[j])!=mp.end()&&mp[code[j]]==i)
				{
					flag=false;
					break;
				}
			}
		if(flag==false)
			printf("No\n");
		else
			printf("Yes\n");	
	}	
	return 0;
}

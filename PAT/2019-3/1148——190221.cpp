//08:51 ����09��13
//Ӧ�ü��谴�ձ�Ŵ�С�����˳��ȥ�������ˡ�Ȼ��˵������Ƿ����
//�������ֱ����������������򡣡���ΪҪ������ĸ���Ҫ�����С���С�
//���������Ҫ�ķ�˼�����ǣ�˼·��һ��ʼҪ����Լ���˼·��
//�����һ��˼·��˼·���ԵĻ�����������ţ�Ǽ⡣�������ĺܲҡ�
// 
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 102;
bool iswolf[maxn]={false};
int n;
int state[maxn]; 
bool check()
{
	int norLiar =0;
	int wolfLiar=0;
	for(int i=1;i<=n;i++)
	{
		if(state[i]<0&&iswolf[abs(state[i])]==false)
		{
			if(iswolf[i]==true)
				wolfLiar++;
			else
				norLiar++;
		}
		else if(state[i]>0&&iswolf[state[i]]==true)
		{
			if(iswolf[i]==true)
				wolfLiar++;
			else
				norLiar++;
		}
	}
	if(norLiar==1&&wolfLiar==1)
		return true;
	else
		return false;	
}
int main()
{	
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&state[i]);
	}
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			flag=false;
			fill(iswolf,iswolf+maxn,false);
			iswolf[i]=iswolf[j]=true;
			flag = check();
			if(flag==true)
			{
				printf("%d %d\n",i,j);
				break; 
			}
		}
		if(flag==true)
			break;
	}
	if(flag==false)
		printf("No Solution\n");
	return 0;
}

//20:10����

//����20:21  18��  ��������Ϊ���ݶ�û�����꣬��͵ó������
//�ó����û���⣬���ǲ�Ӧ��return 0; 
//�޸������18�֣�2�ֵĴ𰸴���
//��mapȥ����int��int��ӳ��ǳ��ؼ����ǳ�ʡ�ռ䡣 

//����Լ������� ֻ��һ��Ԫ�ص���������ֳ��ִ���
//give thanks to god; 
//����20:31 ����� 20�֡�  
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int n,m;
	map<int,int>mp;
	scanf("%d%d",&n,&m);
	int mid = n*m/2;
	int color;
	int s_color=-1;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&color);
			if(s_color>=0)
				continue;
			if(mp.find(color)==mp.end())
			{
				mp[color]=1;
				if(mp[color]>mid)
				{
					s_color = color;
				}
			}
			else
			{
				mp[color]++;
				if(mp[color]>mid)
				{
					s_color = color;
				}
			}
		}
	printf("%d\n",s_color);
	return 0;		
 } 

//16:55����
//����17:29 21��  ��4�����г�ʱ��
//��ʼ���õ��ǣ�����������ѯ�ļ��Ϻϲ���һ��������
//����д�����򵥵�������Ч�ʵͣ������ǳ�ʱ�ĸ�Դ��
//total.insert(s[fir].begin(),s[fir].end());
//total.insert(s[sec].begin(),s[sec].end()); 

//��Ϊͬʱ�����������ϣ�����ͬԪ�صĸ����� 
//set<int>::iterator it = st.begin();   *it ��ʾԪ��ֵ��
//��iterator 

//ע������set���Զ�ȥ�ؼӡ����򡰹��ܡ� ȥ���������ϵĹ���Ԫ�ظ���
//һ�α������� 

//����17:42  �����Ϊ25�֡� 
 
#include<stdio.h>
#include<set>
using namespace std;
const int maxn =  55;
int main()
{
	int n;
	set<int>s[maxn];
	set<int>total;
	scanf("%d",&n);
	int m,index;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&index);
			s[i].insert(index);
		}
	}
	int k;
	scanf("%d",&k);
	int fir,sec;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&fir,&sec);
		set<int>::iterator it = s[fir].begin();
		set<int>::iterator it2 = s[sec].begin();
		int shared = 0;
		for(;it!=s[fir].end()&&it2!=s[sec].end();)
		{
			//ע���Ǻ�*����ǰ�档�� 
			if(*it==*it2)
			{
				shared++;
				it++;
				it2++;
			}
			else if(*it>*it2)
			{
				it2++;
			}
			else if(*it<*it2)
			{
				it++;
			}
		} 
		int t = s[fir].size()+s[sec].size()-shared;
		double output = (shared*100.0)/(t*1.0);
		printf("%.1f%%\n",output);
		total.clear();
	}
	return 0;
}

//19:50����

//����ϸ�����ࡣ
//ÿ�����д����꣬Ҫ���ջ�� 

//����20:46  25��
//�ܽ᣺
//ע��ջ�ľ���������̡�//ע���ж�������ϸ�ڣ�����Ҫ������
//ע���þ����ÿ������ȥ��ʵ���롣 
//stack��������ǰ���� ��Ϊ�� 
//debugʱ�����ʺϵ�λ��ȥ��������䡣 
//����ǰ�滹����һ�顣
 
#include<stdio.h>
#include<stack>  //stack��������ǰ���� ��Ϊ�� 
using namespace std;
const int maxn = 1010;
int main()
{
	int output[maxn];
	int n,m,k;
	stack<int>s;
	scanf("%d %d %d",&m,&n,&k);
	for(int i=0;i<k;i++)
	{ 
		for(int j=0;j<n;j++)
			scanf("%d",&output[j]);
		int j=0;
		int num =1;
		bool flag = false;
		s.push(num++);
		while(j<n)
		{
			//printf("%d\n",output[j]);
			while(s.size()<m&&s.top()!=output[j]&&num<=n)
			{
				s.push(num++);
			}
			if(s.size()<m&&s.top()!=output[j]&&num>n)
			{
				printf("NO\n");
				flag=true;
				break; 
			}
			else if(s.size()<=m&&s.top()==output[j])
			{
				//printf("%d\n",j);
				while(!s.empty()&&s.top()==output[j])
				{
					s.pop();
					j++;		
				}
				//���濪ʼд������˸�j<n�� 
				if(s.empty()&&j<n)
				{
					s.push(num++);
				}		
			}
			else if(s.size()==m&&s.top()!=output[j])
			{
				printf("NO\n");
				flag=true;
				break;
			}
		}
		if(flag==false)
			printf("YES\n");
		//��ʼ���Ǽ���������stack�Ĳ��������µ�4�����ݿ�ס 
		while(!s.empty())
		{
			s.pop();
		}			
	}
	return 0;
 } 

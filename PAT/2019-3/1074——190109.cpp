//�ⷨһ����ջ��"��ת"�ᳬʱ����5�ֳ�ʱ��
//������������������һ��  5�ֳ�ʱ����ˣ�����ȱ��һ�� 
// ��ʼ����i<nȥ����ѭ���Ľ�����������"��Ч���"����� 
// ����"p!=-1"���������
//ѡ�����ݽṹ��ѡ��ϸ�ڡ� 
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 100005;
struct node{
	int address;
	int data;
	int next;
}N[maxn],temp;
int main()
{
	int fadd;
	int n,k;
	scanf("%d%d%d",&fadd,&n,&k);
	int add;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&add);
		N[add].address = add;
		scanf("%d%d",&N[add].data,&N[add].next);
	}
	int p =fadd;  //�����ָ�� 
	int rp;//��תʱ��ָ�� 
	vector<int>v; 
	int newf=-1;
	int num =0;
	int last;
	int i=0; 
	// ��ʼ����i<nȥ����ѭ���Ľ�������������Ч���������
	// ����p!=-1��������� 
	while(p!=-1) 
	{
		while(i==0||(i%k!=0&&p!=-1))
		{
			v.push_back(p);
			p = N[p].next;
			i++;
		}
		if(i%k ==0)
		{
			for(int j=i-1;j>=i-k;j--)
			{
				if(newf==-1)
				{
					newf=v[j];
					rp=v[j];
				}
				else
				{
					N[rp].next = v[j];
					rp = v[j];	
				}
			}
			last =i;
			//printf("%d%d\n",last,i);  //debug�þ� 
			if(p==-1)
			{
				N[rp].next=-1;
				break;
			}
			//��ʼȱ����һ������������ѭ���� 
			v.push_back(p);  
			p = N[p].next;
			i++;	
		}
		else 
		{
			N[rp].next=v[last];
		}	
	}
	p=newf; 
	while(p!=-1)
	{
		if(N[p].next!=-1)
			printf("%05d %d %05d\n",N[p].address,N[p].data,N[p].next);
		else
			printf("%05d %d %d\n",N[p].address,N[p].data,N[p].next);
		p=N[p].next;
	}
	return 0;
} 

////�ⷨһ����ջ����ת�ᳬʱ���÷�20�� 
//#include<stdio.h>
//#include<vector>
//#include<stack>
//using namespace std;
//const int maxn = 100005;
//struct node{
//	int address;
//	int data;
//	int next;
//}N[maxn],temp;
//int main()
//{
//	int fadd;
//	int n,k;
//	scanf("%d%d%d",&fadd,&n,&k);
//	int add;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&add);
//		N[add].address = add;
//		scanf("%d%d",&N[add].data,&N[add].next);
//	}
//	int p =fadd;  //�����ָ�� 
//	int rp;//��תʱ��ָ�� 
//	stack<node>s;
//	int newf=-1;
//	while(p!=-1)
//	{
//		while(s.size()!=k&&p!=-1)
//		{
//			s.push(N[p]);
//			p = N[p].next;
//		}
//		if(s.size()==k)
//		{
//			if(newf==-1)
//			{
//				temp=s.top();
//				s.pop();
//				newf = temp.address;
//				rp=newf;	
//			}
//			while(!s.empty())
//			{
//				temp=s.top();
//				s.pop();
//				N[rp].next =temp.address;
//				rp=temp.address;
//			}
//		}
//		else if(s.size()>0)
//		{
//			while(s.size()>1)
//				s.pop();
//			temp = s.top();
//			s.pop();
//			N[rp].next=temp.address;
//		}
//		else 
//		{
//			N[rp].next =-1;
//		}	
//	}
//	p=newf; 
//	while(p!=-1)
//	{
//		if(N[p].next!=-1)
//			printf("%05d %d %05d\n",N[p].address,N[p].data,N[p].next);
//		else
//			printf("%05d %d %d\n",N[p].address,N[p].data,N[p].next);
//		p=N[p].next;
//	}
//	return 0;
//} 

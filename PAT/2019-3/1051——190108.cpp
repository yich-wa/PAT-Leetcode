//��ʼ��n,m���뷴�ˡ�������һ��ʼ˼·�����м����ġ�
//Aģ���ջ��ջ���м��Ҵ��� 
//B ���ǽ���ջ˳��ͽ�������ϵ 
//C ��������и���Ҫ��ĳ�ջ˳�������������Աȡ�
//���ʽ������5�ֳ�ʱ���𰸲���A˼·���������ж��Ƿ���ܡ� 
//����㣺��ʼ��n,m���뷴�ˡ�ͨ�������б���������������ִ��� 
//ĳЩ�ڵ������Ҫ�ģ����ǻ���Ҫѧ�ᵥ��debug 

//����Ϊ��˼·���� 
//ע��㣺��ջ�Ͷ��н��е���ʱ��Ҫ���жϲ�Ϊ�ա� 
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
const int maxn =1001;
vector<int>temp,output[maxn],outorder;
stack<int>s;
int n,m,k;
bool judge()
{
	int num =0;
	for(int i=1;i<=n;i++) //�Ե�����ջΪ��׼���ۿ��Ƿ���Գ�ջ 
	{
		if(s.size()<m)
		{
			if(outorder[num]==i)
			{
				num++;
				while(!s.empty()&&outorder[num]==s.top())
				{
					s.pop();
					num++;
				}
			}
			else
			{
				s.push(i);
			}
		}
		else
			break;
	}
	if(num==n)
		return true;
	else 
		return false;
}
int main()
{
	bool flag;
	scanf("%d%d%d",&m,&n,&k);
	int input;
	for(int i=0;i<k;i++)
	{
		flag=false;
		outorder.clear();
		while(!s.empty())
			s.pop();
		for(int j=0;j<n;j++)
		{
			scanf("%d",&input);
			outorder.push_back(input);
		}
		flag =judge();
		if(flag==false)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
 } 
 
 
// //����Ϊ���˼·д��  20�֡�5�ֶδ��� 
//#include<stdio.h>
//#include<vector>
//#include<stack>
//using namespace std;
//const int maxn =1001;
//vector<int>temp,output[maxn],outorder;
//stack<int>s;
//int n,m,k;
//int count;
//int now =1;
//void makeout()
//{
//	if(temp.size()==n)
//		output[count++]=temp;
//	else
//	{
//		if(!s.empty())  //��ջ�� 
//		{
//			temp.push_back(s.top());
//			s.pop();
//			makeout();
//			s.push(temp[temp.size()-1]);
//			temp.pop_back();
//		}
//		if(s.size()<m&&now<=n)  //��ջ 
//		{
//			s.push(now++);
//			makeout();
//			s.pop();
//			now--; 
//		}
//	}	
//}
//int main()
//{
//	bool flag;
//	scanf("%d%d%d",&m,&n,&k);
//	int input;
//	count =0;
//	makeout();
//	//�������ķ����� 
////	for(int j=0;j<count;j++)
////	{
////		for(int i=0;i<output[j].size();i++)
////		{
////			printf("%d ",output[j][i]);
////		}	
////		printf("\n");
////	}
//	for(int i=0;i<k;i++)
//	{
//		flag=false;
//		outorder.clear();
//		for(int j=0;j<n;j++)
//		{
//			scanf("%d",&input);
//			outorder.push_back(input);
//		}
//		for(int j=0;j<count;j++)
//		{
//			if(output[j]==outorder)
//			{
//				printf("YES\n");
//				flag=true;
//				break;
//			}	
//		}
//		if(flag==false)
//		printf("NO\n");
//	}
//	return 0;
// }

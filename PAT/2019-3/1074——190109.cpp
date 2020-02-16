//解法一：用栈来"翻转"会超时，有5分超时。
//改用线性向量数组试一下  5分超时解决了，但又缺了一分 
// 开始是用i<n去控制循环的结束，但存在"无效结点"的情况 
// 故用"p!=-1"符合情况。
//选好数据结构，选好细节。 
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
	int p =fadd;  //正序的指针 
	int rp;//翻转时的指针 
	vector<int>v; 
	int newf=-1;
	int num =0;
	int last;
	int i=0; 
	// 开始是用i<n去控制循环的结束，但存在无效结点的情况。
	// 故用p!=-1符合情况。 
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
			//printf("%d%d\n",last,i);  //debug用句 
			if(p==-1)
			{
				N[rp].next=-1;
				break;
			}
			//开始缺了这一步，导致无限循环。 
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

////解法一：用栈来翻转会超时。得分20分 
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
//	int p =fadd;  //正序的指针 
//	int rp;//翻转时的指针 
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

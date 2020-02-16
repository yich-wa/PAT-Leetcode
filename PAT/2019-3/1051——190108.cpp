//开始将n,m输入反了。这种题一开始思路还是有几个的。
//A模拟进栈出栈在中间找错误 
//B 考虑进出栈顺序和建树的联系 
//C 打表，将所有复合要求的出栈顺序打表出来，逐个对比。
//打表方式最终有5分超时。答案采用A思路，过程中判断是否可能。 
//错误点：开始将n,m输入反了。通过将所有表数据输出出来发现错误 
//某些节点输出是要的，可是还是要学会单步debug 

//以下为答案思路做法 
//注意点：对栈和队列进行弹出时，要先判断不为空。 
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
	for(int i=1;i<=n;i++) //以单个进栈为标准，观看是否可以出栈 
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
 
 
// //下面为打表思路写法  20分。5分段错误 
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
//		if(!s.empty())  //出栈； 
//		{
//			temp.push_back(s.top());
//			s.pop();
//			makeout();
//			s.push(temp[temp.size()-1]);
//			temp.pop_back();
//		}
//		if(s.size()<m&&now<=n)  //入栈 
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
//	//检验错误的方法。 
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

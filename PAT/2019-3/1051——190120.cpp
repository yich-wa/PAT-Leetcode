//19:50——

//此题细节蛮多。
//每个排列处理完，要清空栈， 

//——20:46  25分
//总结：
//注意栈的具体操作流程。//注意判断条件的细节，条理要清晰。
//注意用具体的每组数据去核实代码。 
//stack往出弹的前提是 不为空 
//debug时，在适合的位置去添加输出语句。 
//这题前面还做了一遍。
 
#include<stdio.h>
#include<stack>  //stack往出弹的前提是 不为空 
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
				//下面开始写完后少了个j<n； 
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
		//开始忘记加下面的清空stack的操作，导致第4组数据卡住 
		while(!s.empty())
		{
			s.pop();
		}			
	}
	return 0;
 } 

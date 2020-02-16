//11:03——
//考察栈。按照压入压出的过程来判断
//比较要压的值和序列的值相等、大于、小于。 
//栈的数量的上下限 。 
//思路出问题，要根据样例，及时调整思路。 
#include<stdio.h>
#include<stack> 
using namespace std;
const int maxn = 1005;
int main(){
	int m,n,k;
	int popS[maxn];
	scanf("%d%d%d",&m,&n,&k);
	stack<int>s;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&popS[j]); 
		}
		bool flag = true;
		int temp=1;
		int j =0;
		while(j<n){
			while(popS[j]>temp&&s.size()<m){
				s.push(temp);
				temp++;	
			}	
			if(popS[j]==temp){
				if(s.size()<m){
					j++;
					temp++;
				}else{
					flag = false;
					break;
				}
			}else{
				if(s.size()>0){
					int tempT = s.top();
					if(popS[j]==tempT){
						s.pop();
						j++;	
					}else{
						flag=false;
						break;
					}
				}
			}
		}
		if(flag==true)
			printf("YES\n");
		else
			printf("NO\n");	
		while(!s.empty()){
			s.pop();
		}	
	}
	return 0;	
}

////以前写的
//#include<stdio.h>
//#include<stack>  //stack往出弹的前提是 不为空 
//using namespace std;
//const int maxn = 1010;
//int main()
//{
//	int output[maxn];
//	int n,m,k;
//	stack<int>s;
//	scanf("%d %d %d",&m,&n,&k);
//	for(int i=0;i<k;i++)
//	{ 
//		for(int j=0;j<n;j++)
//			scanf("%d",&output[j]);
//		int j=0;
//		int num =1;
//		bool flag = false;
//		s.push(num++);
//		while(j<n)
//		{
//			//printf("%d\n",output[j]);
//			while(s.size()<m&&s.top()!=output[j]&&num<=n)
//			{
//				s.push(num++);
//			}
//			if(s.size()<m&&s.top()!=output[j]&&num>n)
//			{
//				printf("NO\n");
//				flag=true;
//				break; 
//			}
//			else if(s.size()<=m&&s.top()==output[j])
//			{
//				//printf("%d\n",j);
//				while(!s.empty()&&s.top()==output[j])
//				{
//					s.pop();
//					j++;
//						
//				}
//				//下面开始写完后少了个j<n； 
//				if(s.empty()&&j<n)
//				{
//					s.push(num++);
//				}		
//			}
//			else if(s.size()==m&&s.top()!=output[j])
//			{
//				printf("NO\n");
//				flag=true;
//				break;
//			}
//		}
//		if(flag==false)
//			printf("YES\n");
//		//开始忘记加下面的清空stack的操作，导致第4组数据卡住 
//		while(!s.empty())
//		{
//			s.pop();
//		}			
//	}
//	return 0;
// }  

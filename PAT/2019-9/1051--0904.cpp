//11:03����
//����ջ������ѹ��ѹ���Ĺ������ж�
//�Ƚ�Ҫѹ��ֵ�����е�ֵ��ȡ����ڡ�С�ڡ� 
//ջ�������������� �� 
//˼·�����⣬Ҫ������������ʱ����˼·�� 
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

////��ǰд��
//#include<stdio.h>
//#include<stack>  //stack��������ǰ���� ��Ϊ�� 
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
//				//���濪ʼд������˸�j<n�� 
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
//		//��ʼ���Ǽ���������stack�Ĳ��������µ�4�����ݿ�ס 
//		while(!s.empty())
//		{
//			s.pop();
//		}			
//	}
//	return 0;
// }  

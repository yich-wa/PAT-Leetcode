//第一遍写完，17分。其余13分均是运行超时。 开始求中间值用的是：vector 
//经过查书，得知，最后是要用分块的思想。用分块来找中间值。这样能省时间一点。
//这样添加和删除都比较简单。找中间值也能快一点。 
//  
#include<stdio.h>
#include<algorithm>
#include<stack>
#include<string.h>
#include<math.h> 
using namespace std;
const int maxn = 100005;
const int sqt = (int)sqrt(maxn*1.0);
int quantity[maxn];
int block[sqt];
int main(){
	int n;
	char str[15];
	scanf("%d",&n);
	stack<int>s;
	for(int i=0;i<n;i++){
		scanf("%s",str);
		if(str[1]=='u'){
			int temp;
			scanf("%d",&temp);
			s.push(temp);
			quantity[temp]++;
			block[temp/sqt]++;
		}else if(str[1]=='o'){
			if(!s.empty()){
				int temp = s.top();
				s.pop();
				quantity[temp]--;
				block[temp/sqt]--; 
				printf("%d\n",temp);
			}else{
				printf("Invalid\n");
			}
		}else{
			if(s.size()==0){
				printf("Invalid\n");
			}else{
				int len = s.size();
				int temp;
				if(len%2==0){
					temp = len/2;
				}else{
					temp = len/2+1;
				}
				int tNum = 0;
				int bNum = 0;
				while(tNum+block[bNum]<temp){
					tNum+=block[bNum];
					bNum++;
				}
				int stN = bNum*sqt;
				while(tNum<temp){
					tNum+=quantity[stN];
					stN++;
				}
//				sort(v.begin(),v.begin()+v.size());
				printf("%d\n",stN-1);
			}	
		}
	}
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<string.h>
//#include<stack>
//using namespace std;
//const int maxn = 100010;
//const int maxc = 335;
//int hash[maxn]={0};
//int block[maxc]={0};
//void out(int len)
//{
//	int count =0;
//	int k;
//	for(k=0;k<maxc;k++)
//	{
//		count+=block[k];
//		if(count>=len)
//		{
//			count-=block[k];
//			break;
//		}
//	}
//	for(int i=k*maxc;i<maxn;i++)
//	{
//		count+=hash[i]; 
//		if(count>=len)
//		{
//			printf("%d\n",i);
//			return ; 
//		}	 
//	}
//}
//int main()
//{
//	int n; 
//	stack<int>s;
//	int key;
//	char strp[10];
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s",strp);
//		//printf("**\n");
//		if(strp[1]=='u')
//		{
//			scanf("%d",&key);
//			s.push(key);
//			hash[key]++;
//			key=key/maxc;
//			block[key]++;
//		}
//		else if(strp[1]=='o')
//		{
//			//printf("**\n");
//			if(!s.empty())
//			{
//				key = s.top();
//				s.pop();
//				hash[key]--;
//				printf("%d\n",key);
//				key = key/maxc;
//				block[key]--;
//			}
//			else
//			{
//				printf("Invalid\n");
//			}
//		}
//		else if(strp[1]=='e')
//		{
//			if(!s.empty())
//			{
//				int len = s.size();
//				if(len%2==0)
//				{
//					len = len/2;
//				}	
//				else
//				{
//					len=(len+1)/2;
//				}
//				out(len);
//			}
//			else
//			{
//				printf("Invalid\n");
//			}	
//		}
//	}
//	return 0;
//}
 

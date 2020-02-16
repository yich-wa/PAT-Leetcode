#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	vector<int>v;
	while(n>0){
		v.push_back(n%b);
		n = n/b;
	}
	int len = v.size();
	bool flag = true;
	for(int i=0;i<len;i++){
		if(v[i]!=v[len-1-i]){
			flag = false;
			break;
		}
	}
	if(flag== true){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(int i=len-1;i>=0;i--){	
		if(i<len-1)
			printf(" ");
		printf("%d",v[i]);
	}
	return 0;
} 

////以前做的
//#include<stdio.h>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n,b;
//	vector<int>base_b;
//	scanf("%d%d",&n,&b);
//	while(n>0)
//	{
//		base_b.push_back(n%b);
//		n=n/b;
//	}
//	bool flag = true;
//	int lenth = base_b.size();
//	for(int i=0;i<lenth/2;i++)
//	{
//		if(base_b[i]!=base_b[lenth-i-1])
//		{
//			flag=false;
//			break;
//		}
//	}
//	if(flag==false)
//		printf("No\n");
//	else
//		printf("Yes\n");
//	for(int i=lenth-1;i>=0;i--)
//	{
//		printf("%d",base_b[i]);
//		if(i>0)
//			printf(" ");
//		else
//			printf("\n");
//	}
//	return 0;
// }  

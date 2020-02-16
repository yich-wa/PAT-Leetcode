//09:37--09:55 
#include<stdio.h>
#include<string.h>
const int maxn = 100005;
struct node{
	char data;
	int next;
}N[maxn];
int main(){
	int fir1, fir2,n;
	bool isVis[maxn]={false};
	scanf("%d%d%d",&fir1,&fir2,&n);
	int tempAdd,nextAdd;
	char d;
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&tempAdd,&d,&nextAdd);
		N[tempAdd].data = d;
		N[tempAdd].next = nextAdd;
	}
	int p = fir1;
	while(p!=-1){
		isVis[p]=true;
		p = N[p].next;
	}
	p = fir2;
	bool isCom = false;
	int com;
	while(p!=-1){
		if(isVis[p]==true){
			isCom = true;
			com = p;
			break;
		}
		p= N[p].next;
	}
	if(isCom == true){
		printf("%05d",com);
	}else{
		printf("-1");
	}
	return 0;
} 

////以前做的
//#include<stdio.h>
//#include<stack>
//using namespace std;
//const int maxn = 100005;
//struct node{
//	int address;
//	char data;
//	int next;
//	bool flag;
//}N[maxn]; 
//int main()
//{
//	stack<int>s1,s2;
//	int fadd1,fadd2,n;
//	scanf("%d%d%d",&fadd1,&fadd2,&n);
//	int tempadd,tempnext;
//	char tempdata;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d %c %d",&tempadd,&tempdata,&tempnext);
//		N[tempadd].data =tempdata;
//		N[tempadd].next =tempnext;
//		N[tempadd].flag =false;
//	}
//	if(fadd1==fadd2)
//	{
//		printf("%05d\n",fadd1);
//		return 0;
//	}
//	while(fadd1!=-1)
//	{
//		s1.push(fadd1);
//		
//		//开始下面的"="写成了"=="导致出错。。低级错误 
//		N[fadd1]. flag=true;   
//		fadd1 = N[fadd1].next;
//	}
//	int last=-1;
//	while(fadd2!=-1)
//	{
//		s2.push(fadd2);
//		if(N[fadd2].flag==true)
//		{
//			last =fadd2;
//			break;
//		}
//		fadd2 = N[fadd2].next;
//	}
//	if(last!=-1)
//		printf("%05d\n",last);
//	else
//		printf("-1\n");
//	return 0;
// }  

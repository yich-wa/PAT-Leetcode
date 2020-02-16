//注意对 "%d %c %d"的输入，由于%c可以识别空格，所以不能
//写成"%d%c%d" x写完后，有1分段错误。
//参考答案写法能简单些
///直接在第一个单词遍历时，为每个字母设置标签；
//打标签终究是hashtable的方法。 
//第二个单词遍历时，如果遇到有标签的字母，那说明为共同后缀的
//起始结点。 "
#include<stdio.h>
#include<stack>
using namespace std;
const int maxn = 100005;
struct node{
	int address;
	char data;
	int next;
	bool flag;
}N[maxn]; 
int main()
{
	stack<int>s1,s2;
	int fadd1,fadd2,n;
	scanf("%d%d%d",&fadd1,&fadd2,&n);
	int tempadd,tempnext;
	char tempdata;
	for(int i=0;i<n;i++)
	{
		scanf("%d %c %d",&tempadd,&tempdata,&tempnext);
		N[tempadd].data =tempdata;
		N[tempadd].next =tempnext;
		N[tempadd].flag =false;
	}
	if(fadd1==fadd2)
	{
		printf("%05d\n",fadd1);
		return 0;
	}
	while(fadd1!=-1)
	{
		s1.push(fadd1);
		
		//开始下面的"="写成了"=="导致出错。。低级错误 
		N[fadd1]. flag=true;   
		fadd1 = N[fadd1].next;
	}
	int last=-1;
	while(fadd2!=-1)
	{
		s2.push(fadd2);
		if(N[fadd2].flag==true)
		{
			last =fadd2;
			break;
		}
		fadd2 = N[fadd2].next;
	}
	if(last!=-1)
		printf("%05d\n",last);
	else
		printf("-1\n");
	return 0;
 } 

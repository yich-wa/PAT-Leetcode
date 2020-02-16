//10:05——
 
//——10:20  18分2分答案错误。 
//经数据测试，发现 如： 2 5 商0余2这样的数据出错。
// ——10:25  25分 
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int maxn = 1005;
int main()
{
	char a[maxn];
	int b;
	scanf("%s %d",a,&b);
	vector<int>q;
	int temp;
	int r=0;
	int len = strlen(a);
	for(int i=0;i<len;i++)
	{
		int now = a[i]-'0';
		now += r*10;
		temp = now/b;
		q.push_back(temp);
		r=now%b;
	}
	if(q.size()==1&&q[0]==0)   //商为0 需要特判。 
		printf("0");
	else
	for(int i=0;i<q.size();i++)
	{
		if(i==0&&q[i]==0)
			continue;
		else
		{
			printf("%d",q[i]);
		}
	}
	printf(" %d\n",r);
	return 0;
 } 

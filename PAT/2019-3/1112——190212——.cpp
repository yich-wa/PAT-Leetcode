//10:41
//
//for循环里面有I++了，你外面又加了一个for括号里面还用了一个i++
//低级错误。
//——11:16  得 14分。有6分的答案错误。 

//下面数据经试验是错误的
//可参考set的去重功能。 

//——11:27放弃 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
bool isStuck[256]={false};
bool isIn[256]={false};
char origin[maxn];
char after[maxn]; 
int k;
vector<char>st;
void check()
{
	int len =strlen(origin);
	int i=0;
	//这个也是，要么在for循环里面改变i++，要么在外面改变i++，别两个都做。 
	for(;i<len;)
	{
		int j= i;
		while(origin[j]==origin[i]&&j<len)
		{
			j++;
		}
		if((j-i)%k!=0)
		{
			//逻辑出了点小问题。下面应该是true 
			isStuck[origin[i]]=true;  //表明其没有卡住。 
		}
		i=j;
	}
}
void change()
{
	int len = strlen(origin);
	int i=0;
	int num =0;
	//for循环里面有I++了，你外面又加了一个for括号里面还用了一个i++
	//低级错误。 
	for(;i<len;)
	{
		after[num++]=origin[i];
		if(isStuck[origin[i]]==true)
		{
			i++;
		}
		else
		{
			//printf("%c**\n",origin[i]);
			if(isIn[origin[i]]==false)
			{
				st.push_back(origin[i]);
				isIn[origin[i]]=true;
			}
			i+=3;
		}
	}
	after[num]='\0';
}
int main()
{
	scanf("%d",&k);
	scanf("%s",origin);
	check();
	change();
	for(int i=0;i<st.size();i++)
	{
		printf("%c",st[i]);
	}
	printf("\n");
	printf("%s\n",after);
	return 0;	
}

//用结构体，vector简化输入输出 
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 1005;
struct account{
	char name[12];
	char pass[12];
}temp;
vector<account>input;
vector<account>output;
int main()
{
	int n;
	scanf("%d",&n);
	bool flag =false;
	for(int i=0;i<n;i++)
	{
		flag =false;
		scanf("%s %s",temp.name,temp.pass);
		int len =strlen(temp.pass);
		for(int j=0;j<len;j++)
		{
			if(temp.pass[j]=='1')
			{
				temp.pass[j]='@';
				flag=true;
			}
			else if(temp.pass[j]=='0')
			{
				temp.pass[j]='%';
				flag=true;
			}
			else if(temp.pass[j]=='l')
			{
				temp.pass[j]='L';
				flag=true;
			}
			else if(temp.pass[j]=='O')
			{
				temp.pass[j]='o';
				flag=true;
			}	 
		}
		if(flag==true)
			output.push_back(temp);
	}
	if(output.size()==0)
		if(n>1)
			printf("There are %d accounts and no account is modified\n",n);
		else
			printf("There is 1 account and no account is modified\n");
	else
	{
		printf("%d\n",output.size());
		for(int i=0;i<output.size();i++)
		{
			printf("%s %s\n",output[i].name,output[i].pass);
		}
	}
	return 0;
 } 

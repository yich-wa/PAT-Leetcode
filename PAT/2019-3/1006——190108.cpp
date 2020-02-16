//入门模拟， 开始strcpy(str1,str2);的使用给记错了 
#include<stdio.h>
#include<algorithm>
#include<string.h> 
using namespace std;
const int maxc = 18;
int main()
{
	int n;
	char lock[maxc];
	char unlock[maxc];
	char temp[maxc];
	scanf("%d",&n);
	int earliest = 150000;
	int lastest =-1;
	int temptime;
	int h,m,s;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d",temp,&h,&m,&s);
		temptime = h*3600+m*60+s;
		if(temptime<earliest)
		{
			earliest =temptime;
			strcpy(unlock,temp);
		}
		scanf("%d:%d:%d",&h,&m,&s);
		temptime = h*3600+m*60+s;
		if(temptime>lastest)
		{
			lastest = temptime;
			strcpy(lock,temp);
		}		
	}
	printf("%s %s\n",unlock,lock);
	return 0;
}

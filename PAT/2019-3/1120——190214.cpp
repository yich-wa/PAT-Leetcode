//12:51——13:04
//20分题不难。 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10001;
const int maxk = 50;
int findId(int a)
{
	int sum =0;
	while(a!=0)
	{
		sum+=a%10;
		a=a/10;
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	int ori[maxn];
	bool isId[maxk]={false};
	vector<int>outId;
	int numId = 0;
	int friendId;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori[i]);
		friendId=findId(ori[i]);
		if(isId[friendId]==false)
		{
			numId++;
			outId.push_back(friendId);
			isId[friendId]=true;	
		}
	}
	sort(outId.begin(),outId.end());
	int len = outId.size();
	printf("%d\n",len);
	for(int i=0;i<len;i++)
	{
		if(i<len-1)
		printf("%d ",outId[i]);
		else
		printf("%d\n",outId[i]);
	}
	return 0;
 } 

#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
	int n,m;
	int coin[maxn];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+n);
	int left =0;
	int right=n-1;
	while(left<right&&coin[left]+coin[right]!=m)
	{
		if(coin[left]+coin[right]<m)
			left++;
		else if(coin[left]+coin[right]>m)
			right--;
	}
	if(coin[left]+coin[right]==m&&left<right)
		printf("%d %d\n",coin[left],coin[right]);
	else
		printf("No Solution\n");
	return 0;
 } 

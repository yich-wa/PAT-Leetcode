//08:58 ——190220  20分。下面做法也有可取之处
//如果不想开数组，然后去用hash法标记存在否，可考虑map库。 
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std; 
const int maxn = 100010;
int main()
{
	int n;
	map<int,bool>mp;
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp>0)
			mp[temp]=true;	
	}
	int i= 1;
	while(mp[i]==true)
	{
		i++;
	}
	printf("%d\n",i);
	return 0;
}

//如果开数组 ,标记是否存在，组数组大小需开到int范围内。
//否则，就会段错误。否则。或者在标记时，判断下该数小于maxn。
//缺失最小整数必定小于maxn /
 
//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn = 100010;
//int a[maxn]={0};
//int main(){
//	int n;
//	int d;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&d);
//		if(d<maxn&&d>0&&a[d]==0)
//		{
//			a[d]=1;
//		}
//	}
//	int p=1;
//	while(a[p]==1)
//	{
//		p++;
//	}
//	printf("%d\n",p);
//	return 0;
//}

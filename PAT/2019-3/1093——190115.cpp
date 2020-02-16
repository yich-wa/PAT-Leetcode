//21:30——21:45
//拿到25分。首先用long long 是有先见之明
//也可以一边加一边取模。 
//其次用动态规划的思想尽可能的提高时间效率也是对的。 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
const long long maxr = 1000000007;
const int maxn = 100005;
typedef long long LL; 
int main()
{
	char str[maxn];
	scanf("%s",str);
	int len =strlen(str);
	int p_count[maxn];
	int t_count[maxn]; 
	vector<int>a_pos;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='P')
		{
			if(i>0)
			p_count[i]=p_count[i-1]+1;
			else
			p_count[i]=1;
		}
		else
		{
			if(i>0)
			p_count[i]=p_count[i-1];
			else
			p_count[i]=0;
		}
		if(str[i]=='A')
			a_pos.push_back(i);
	 } 
	 t_count[len]=0;
	 for(int i=len-1;i>=0;i--)
	 {
	 	if(str[i]=='T')
	 	{
	 		t_count[i]=t_count[i+1]+1;
		 }
		 else
		 {
		 	t_count[i]=t_count[i+1];
		 }
	 }
	 LL sum =0;
	 int alen = a_pos.size();
	 for(int i=0;i<alen;i++)
	 {
	 	int temp = a_pos[i];
	 	sum+=p_count[temp]*t_count[temp];
	 	sum = sum%maxr;
	 }
	 //sum = sum%maxr;
	 printf("%lld\n",sum);
	 return 0;	
 } 

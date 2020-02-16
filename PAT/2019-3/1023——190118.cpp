/// 10:26 ——10:51 20分
//重要的是 你要能熟悉和清楚乘法的细节。进位用carry表示
//细节考虑清楚。 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
const int maxn = 25;
int main()
{
	char a[maxn];
	scanf("%s",a);
	vector<int>ori;
	vector<int>dou;
	int len =strlen(a);
	int temp;
	for(int i=0;i<len;i++)
	{
		temp = a[i]-'0';
		ori.push_back(temp);
	} 
	int carry =0;
	int result;
	for(int i=len-1;i>=0;i--)
	{
		temp = a[i]-'0';
		result= temp*2+carry;
		carry = result/10;
		result = result%10;
		dou.push_back(result);
	}
	if(carry!=0)
		dou.push_back(carry);
	if(ori.size()!=dou.size())
	{
		printf("No\n");
	}
	else
	{
		vector<int>s_dou;
		s_dou= dou;
		sort(s_dou.begin(),s_dou.end());
		sort(ori.begin(),ori.end());
		if(ori==s_dou)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	for(int i=dou.size()-1;i>=0;i--)
		printf("%d",dou[i]);
	printf("\n");
	return 0;	
 } 

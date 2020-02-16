//10:50
//——11:00 得16分 有4分错误。 
//现将变量定义以及判断函数 ，放入主函数中 
//放入后还是有4分段错误。 

//发现自己将maxn定义错误。开始的量值定义错误。属于看错定义错。 
#include<stdio.h>
#include<math.h>
//using namespace std;
const int maxn = 1002;
int main()
{
	int n;
	int row[maxn];
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&row[i]); 
		}
		bool flag=true;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(row[i]==row[j]||abs(i-j)==abs(row[i]-row[j]))
				{
					flag= false;
					break;
				}
			}
			if(flag==false)
				break;
		}
		if(flag==true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//
//#include<stdio.h>
//#include<math.h>
//using namespace std;
//const int maxn = 202;
//int n;
//int row[maxn];
//bool check()
//{
//	for(int i=2;i<=n;i++)
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(row[i]==row[j])
//				return false;
//			else if(abs(i-j)==abs(row[i]-row[j]))
//				return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int k;
//	scanf("%d",&k);
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%d",&row[i]); 
//		}
//		bool flag= check();
//		if(flag==true)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}

 

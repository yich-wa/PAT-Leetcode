//08:58 ����190220  20�֡���������Ҳ�п�ȡ֮��
//������뿪���飬Ȼ��ȥ��hash����Ǵ��ڷ񣬿ɿ���map�⡣ 
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

//��������� ,����Ƿ���ڣ��������С�迪��int��Χ�ڡ�
//���򣬾ͻ�δ��󡣷��򡣻����ڱ��ʱ���ж��¸���С��maxn��
//ȱʧ��С�����ض�С��maxn /
 
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

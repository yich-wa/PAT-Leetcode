//��ʼ���˸�maxn���������顣��������n��scanf��Ȼ��4�ֶδ���
//��ʵֻ��Ҫһ��int�����þ��С� 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =10005; 
int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	int hashtable[maxn]={0};
	vector<int>appear;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		hashtable[temp]++;
		appear.push_back(temp);
	 } 
	for(int i=0;i<appear.size();i++)
	{
		if(hashtable[appear[i]]==1)
		{
			printf("%d\n",appear[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}

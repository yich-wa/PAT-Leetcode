//16:15����16:45  25�� 
//�ۻ��ϵ������������
//��һ�ǣ������ǵ���
//����ǣ��Լ��а��£����ǰ���û�����ۻ�
//һ��ʼ��û�ж������и����������ݡ�
//����Ҫ��ϸ 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100002;
int main()
{
	int n;
	bool iscouple[maxn]={false};
	int coupleId[maxn]={0};
	scanf("%d",&n);
	int c1,c2;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&c1,&c2);
		coupleId[c1]=c2;
		coupleId[c2]=c1;
		iscouple[c1]=true;
		iscouple[c2]=true;
	}
	int m,tempc;
	vector<int>single;
	vector<int>input; 
	bool isattend[maxn]={false};
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&tempc);
		isattend[tempc]=true;
		input.push_back(tempc);
	}
	for(int i=0;i<m;i++)
	{
		tempc = input[i];
		if(iscouple[tempc]==false)
		{
			single.push_back(tempc);
		}
		else
		{
			int tempcouple = coupleId[tempc];
			if(isattend[tempcouple]==false)
				single.push_back(tempc);
		}
	}
	sort(single.begin(),single.end());
	int len = single.size();
	printf("%d\n",len);
	for(int i=0;i<len;i++)
	{
		if(i<len-1)
		printf("%05d ",single[i]);
		else
		printf("%05d\n",single[i]);
	}
	return 0;
}

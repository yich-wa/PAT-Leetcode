//13:12
//13:38����21�� 4�ֶδ��� 

//���������������� 

//���õ�����������
// �ο�����˼·��
// �Ը��������о�������󣬴Ӵ�Сɨ��һ����Ǵ𰸡�
//��input[i]>maxE��maxE�����ֵ����������С�
//д��25�֡� 

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn =100005; 
int main()
{
	int n;
	int ori;
	vector<int>input;
	scanf("%d",&n);
	//int minNum =0;
	int maxNum=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ori);
		input.push_back(ori);
	}
	sort(input.begin(),input.end());
	int maxE=1;
	for(int i=n-1;i>=0;i--)
	{
		//maxE��ʾ���ڵ���input[i]���ж���������
		//��������㡣input[i]>maxE��maxE�����ֵ�� 
		if(input[i]<=maxE)    
			break;
		maxE++;
	}
	printf("%d\n",maxE-1);
	return 0;
}

//�ڶ��������� 
///�ֲ�����������жϵķ�������17�֡� 8�ִ𰸴���
//���������� ��
// 6 
// 5 5 5 5 5 5 
//ʵ�鷢�ִ���
//�ô����Ų���21�� ��3���Ե㣬����Ǵ𰸴��󡣻���ȱ 4�֡�
// 
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int maxn =100005; 
//int main()
//{
//	int n;
//	int ori;
//	vector<int>input;
//	scanf("%d",&n);
//	//int minNum =0;
//	int maxNum=-1;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&ori);
//		input.push_back(ori);
//	}
//	sort(input.begin(),input.end());
//	int maxE=1;
//	//����������⴦����ȫ��һ���� 
//	if(input[0]==input[n-1]) 
//	{
//		maxE=input[0]-1;
//		while(n<maxE)
//		{
//			maxE--;
//		}
//	 } 
//	else
//		for(int i=0;i<n;i++)
//		{
//			if(i<n-1&&input[i]<input[i+1])
//			{
//				int num = n-i-1;
//				if(num>=input[i])
//				{
//		//����input[i]=10;������11��12����maxEӦ����11������10��
//					while(num>=input[i]&&input[i]<input[i+1])
//					{
//						input[i]++;
//					}
//					maxE=input[i]-1;
//				}	
//			} 
//		}
//	printf("%d\n",maxE);
//	return 0;
//} 
// 
// 21������ 
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn =100005; 
//int main()
//{
//	int n;
//	int ori[maxn];
//	int count[maxn]={0};
//	scanf("%d",&n);
//	//int minNum =0;
//	int maxNum=-1;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&ori[i]);
//		
//		if(ori[i]>maxNum)
//			maxNum = ori[i];
//	}
//	maxNum=max(maxNum,n);
//	int k=0;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=k;j<ori[i];j++)
//		{
//			count[j]++;
//			//��һ��û�м�������֡����˿��Լ�֦�����Ч�ʡ� 
//			if(j<=count[j]&&j>k)
//			{
//				k=j;
//			}
//		}	
//	}
//	
//	for(;k<=maxNum;k++)
//	{
//		if(k>count[k])
//			break;
//	}
//	printf("%d\n",k-1);
//	return 0;
// } 


// //��ǰд����һ�档 
// 
// #include<stdio.h>
// #include<algorithm>
// using namespace std;
// const int maxn =100010;
// bool cmp(int a,int b)
// {
// 	return a>b;
// }
// int main()
// {
// 	int n;
// 	scanf("%d",&n);
// 	int ride[maxn];
// 	int edd[maxn]={0};
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&ride[i]);
//// 		for(int j=0;j<ride[i];j++)
//// 			edd[j]++;
// 			
// 	}
//// 	for(int j=n;j>=0;j--)
//// 	{
//// 		if(edd[j]>=j)   //��ʼ����һ����>"��������8�֡����ϵ�21�֡� 
//// 		{
//// 		printf("%d\n",j);
//// 		break;
//// 		}
//// 	}
//// 	
// 	sort(ride,ride+n,cmp);
// 	for(int j =n;j>=0;j--)
// 	{
// 		int ans =0;
// 		for(int i=0;i<n;i++)
// 		{
// 			if(ride[i]>j)
// 			{ 
// 			ans++;
// 			}
//			else 
//			break;
//		}
//		if(ans>=j)
//		{
//			printf("%d\n",j);
//			break;
//		}
//	}
//	return 0;
//}

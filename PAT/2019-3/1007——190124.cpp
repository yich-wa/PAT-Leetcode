//14��59����

///15:22   21�֣�4�ִ𰸴���
//�м��sum�����õķǳ��á�����˾����ú���ȵ����г�����ǰ���졣
//����ȫ������������Լ��뵽��д��ʱ����ֵͼ�ʧ���´���
//�Ĺ�����25�֡� 

//20190226�޸�
//�ö�̬�滮�ķ���
//��sum[i]��¼��seq[i]��β�ĵ�������������к͡�Ȼ��start[i]��¼
//�����е������š�
//���sum[i-1]<0�Ļ���sum[i]=seq[i]; �Լ�start[i]=i;
//����sum[i]=sum[i-1]+seq[i]; start[i]=start[i-1]; 
//������ 25�֡� 
 
#include<stdio.h>
const int maxn = 10010;
int main()
{
	int k;
	int seq[maxn];
	int sum[maxn]={0};
	int start[maxn];
	int dp[maxn]; 
	scanf("%d",&k);
	bool flag =false;
	for(int i=0;i<k;i++)
	{
		scanf("%d",&seq[i]);
		//��sum����ȥȷ���������е��������ȷ�ķ�ʽ������
		//��ʹjȷ����i������С�ķ�ʽ�� 
		if(i>0&&sum[i-1]>0)
		{
			sum[i]=sum[i-1]+seq[i];
			start[i]=start[i-1];
		}
		else
		{
			start[i]=i;
			sum[i]=seq[i];	
		}
		if(flag==false&&seq[i]>=0)
			flag =true;
	}
	if(flag==false)
	{
		printf("0 %d %d\n",seq[0],seq[k-1]);
		return 0;
	}
	int maxdp = sum[0];
	int index = 0;
	for(int i=1;i<k;i++)
	{
		if(sum[i]>maxdp)
		{
			maxdp=sum[i];
			index=i;
		}		
	}
	printf("%d %d %d\n",maxdp,seq[start[index]],seq[index]);
	return 0;
}

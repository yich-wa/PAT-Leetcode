//09:55����10:33�������������ˡ���ֻ����2�֡� ��ʱ�鲻��˼ά����
 
//ϸ��1�� 
//���Լ��ڱ������ϵĴ� ������˼·����һ�¡�
///������ǰͬ�����Ĵ��󡣵�0��0λʱ��ȷ��Ҫ������Ԫ��λ��k��
//�ȸı�hash���ڽ�����ע���λһ�¡������17�֡�8��3���㳬ʱ
//��λһ��Ҫһ�£�����Ϊ�ƣ�����Ҫ��λʱҪһ�¡� 
 
///ϸ��2�� 
// �Ա���ǰ�Ĵ𰸷��֣��Լ�ÿ��ȥ�ҵ�һ��������λ����ʱ������
//��ͷȥ����˿��ܳ�ʱ�ɡ� Ӧ���ϴε�λ��ȥ�ҡ����껹��2�֡�
//������֤�㷨�ĸ�Ч�ԡ� 

//ϸ��3�� 
//���˾�����0һ��ʼ�������λ�Ļ���������λ�ĸ���not_pos������Ҫ�ָ���
//����һ���ˡ���������ѭ�����б��ǣ�not_pos>0������not_pos>1;
//����0һ��ʼ������λ�Ļ��������not_pos>1��
//Ϊͳһ�������not_pos�涨Ϊ��0λ֮�⣬����λ�������Եĸ�����
//�����Ϊ���֡�

//����Ϊ����ϸ�ڴ���㣻�������⡪�����ٸ�����
//�����ù�ϣ������ʾÿ������λ�á������ȽϿ졣
///����Ϊ����������㷨��
//�ڱ�˼�� 
 

#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
	int n;
	scanf("%d",&n);
	int orig[maxn];
	int hash[maxn];
	int not_pos =0;//�ж��ٸ�������λ������ 
	bool flag[maxn]={false};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&orig[i]);
		hash[orig[i]]=i;
		if(orig[i]!=i&&i!=0)
			not_pos++;
		else 
			flag[i]=true;		
	}
	int count =0;//�������� 
	 //������λ����������ֻ��һ�����ض���˫���� 
	 //��ֻnot_pos>0�򣬼�ʹ��ȫ��λ��Ҳ֪ʶnot_pos=1;
	 //���˳�ʱȴ�������㡣 
	 int k=1;
	 //ÿ���Ҳ�����λ������λ�ã�Ӧ���ϴεĿ�ʼ�����
	 //��k=1�ŵ�ѭ����ࡣk��˳������������ʱ���ϴε�k
	 //λ�������Ѿ���λ ����Ӧ�ŵ���ࡣ 
	while(not_pos>0) 
	{
		if(hash[0]!=0)
		{
			int pos1=hash[0];
			int pos2 = hash[pos1];
			swap(orig[pos1],orig[pos2]);
			hash[0]=pos2;
			hash[pos1]=pos1;
			flag[pos1]=true; 
			count++; 
			not_pos--;	
		}
		else
		{ 
			while(flag[k])
				k++;
			//****���������˳���ܷ��ˡ�
			//����Ҫ���Ƚ�������ı�hash��
			//����hash[orig[0]]=0;��Ϊ��ǰ��kλ�õ�������������0λ�á� 
			 hash[orig[k]]=0; 
			swap(orig[0],orig[k]);
			hash[0]=k;
			count++;
		}	
	}	
	printf("%d\n",count);
	return 0;
}


////���������ϴδ𰸡�
// #include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int maxn=100010;
//int a[maxn];
//int b[maxn];
//int pos[maxn];
//bool common[maxn]={false};
//int num=0;//�ܹ���Ҫ�����Ĵ���
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&a[i]);
//		pos[a[i]]=i;
//		b[i]=a[i];
//	}
//	sort(b,b+n);
//	bool flag=true;
//	int add0=0;  //��ʾ0����λ�õĽǱ�i
//	int tru=0;
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]!=b[i])
//		{
//			flag=false;
//			common[i]=false;
//		}
//		else
//		{
//			common[i]=true;
//			if(i!=0)
//				tru++;
//		}
//		if(a[i]==0)
//		{
//			add0=i;
//		}
//	}
//	int k=1;   //����debugʱ�����մ𰸣���ʵ��δ�ͷ���ҵ�һ����λ�ϲ��Ǹ������������K��ʡȥ�ܶ๦��
//	while(tru<n-1)  //tru��ʾ����0�⣬�����ڱ�λ�ĸ�����
//	{
//		if(add0==0)   
//		{
//			for(int i=k;i<n;i++)
//			{
//				if(common[i]==false)   //��һ��λ���ϲ�����ȷ����λ�á�
//				{
//					pos[a[i]]=0;             //**********������һ���˳������********�տ�ʼд���ˡ�
//					swap(a[0],a[i]);
//					num++;
//					add0=i;
//					k=i;
//					break;
//				}
//			}
//		}
//		while(add0!=0)
//		{
//			swap(a[add0],a[pos[add0]]);
//			common[add0]=true;
//			num++;
//			tru++;
//			add0=pos[add0];
//			break;
//		}
//	}
//	printf("%d\n",num);
//	return 0;
//}

// 17:26 ���� 

//ϸ������ 
//����17:54 8�� 
//����������ڴ��ݲ��� Ϊi���µ� ���������������Ϊi.�Ļ���
//�����������i����ᵼ�»��ҡ������⼴�ǡ�
//�����мǣ��Ժ�Ҫ��i�������Ĵ��붨�������
//���������Ϊ 8�֡�����ȷʵ��һ������� 
//����18:11  8�� 

//�������� 
//����п�һ����ǰ��Ľ��ܣ�������ƽ��̽�ⷨ�ģ�һ��
//ֻ��Ҫ���������Ӳ��֡� (with positive increments only) 
//���ⲻϸ��û�������������к��塣 
//������20�֡� 

//֪ʶ��ģ�����⡪�����㣻 
//һ�� 
//�������ϴ�֪����ƽ��̽�ⷨ���ı��������Ҫģһ��msize;
//�� temp = (p+i*i)%msize;   i�ķ�Χ�ǣ�[1,msize]; 

//���� 
//����i��������Χ��msize
//����msize�Ŀ����� 
//����18:19 ����25�֡� 

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 10779;
int pos[maxn];
int hash[maxn]={0};
int msize;
int qm;//ƽ��̽��ķ�Χ 
bool isprime(int a)
{
	if(a==1)
		return false;
	int temp = (int)sqrt(1.0*a);
	for(int i=2;i<=temp;i++)
	{
		if(a%i==0)
		return false;
	}
	return true;
}
void insert(int a,int id)
{
	int p =a%msize;
	if(hash[p]==0)
	{
		hash[p]=1;
		pos[id]=p;
		//printf("%d\n",p); 
		return ;
	}
	int temp;
	for(int i=1;i<=msize;i++)
	{
		temp = (p+i*i)%msize;
		if(temp>=0&&temp<msize&&hash[temp]==0)
		{ 
			hash[temp]=1;
			pos[id]=temp;
			//printf("%d\n",temp);
			return;
		}	
	}
}
int main()
{	
	int n;
	fill(pos,pos+maxn,-1);
	scanf("%d%d",&msize,&n);
	while(isprime(msize)==false)
	{
		msize++;
	}
	qm =(int)sqrt(1.0*msize);
	int input[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
		insert(input[i],i);
	}
	for(int i=0;i<n;i++)
	{
		if(pos[i]==-1)
			printf("-");
		else
			printf("%d",pos[i]); 
		if(i<n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
 } 

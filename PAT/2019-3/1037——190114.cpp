//���ڸ�����ˡ���
//��ʼlong long ����һֱ��"%d" �� "%ld"���������û�뵽
//Ȼ����������0���бȽ�ʱ�����⡣��������whileѭ�������Խ�ȥ
// ����־�Ȼ��long long ����������õ��ǵ�"%lld",
//����ʱҪע�����и��ķ�Χ�����������԰�ʱҪ��long long�� ��
//ϸ��Ҫ����׼ȷ

 
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int nc,np;
	long long coup[maxn];
	long long value[maxn];
	scanf("%d",&nc);
	for(int i=0;i<nc;i++)
	{
		scanf("%lld",&coup[i]);
	}
	sort(coup,coup+nc,cmp); 
	scanf("%d",&np);
	for(int i=0;i<np;i++)
	{
		scanf("%lld",&value[i]);
	}
	sort(value,value+np,cmp);
	long long max_amount = 0;
	int c_left=0;
	int v_left=0;
	int c_right =nc-1;
	int v_right= np-1;
	long long ling =0;
	while(coup[c_left]>0&&value[v_left]>0)
	{
		max_amount+=coup[c_left]*value[v_left];
		//printf("%d %d\n",coup[c_left],value[v_left]);
		c_left++;
		v_left++;
	}
	//printf("%d\n",max_amount);
	while(coup[c_right]<0&&value[v_right]<0)
	{
		max_amount+=coup[c_right--]*value[v_right--];
	}
	printf("%d\n",max_amount);
	return 0;
}

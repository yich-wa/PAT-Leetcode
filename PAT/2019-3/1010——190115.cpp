//15:51����16:20 �����9�֣����೬ʱƫ�ࡣ�ʲ��ö��ַ�����
//�ö��ַ������Ľ��ơ�

//��һ�ֵͼ������������ԸΥ�ĵͼ����󡣾����������a��д����
//bһ��Ҫ�������ֵͼ����������Ͳ��һ��
//���һ��������һ������Ϳ��Է��֡�
//�����Ǹ��ͼ�������15�֡�����������Ǵ𰸴��󡪡� 16:49 

//�������δ֪������С����minradix����������֪��know�Ĵ�С
//��minradix>know ����� �����ϵ�19�֡�

//���˴𰸷��֣�
//ÿ������ֵ�������Ƽ���ʱ�����ܳ���int�ı�ʾ��Χ�� ����������
//��ֵ����Ҫ��long long ��ʾ ,����Ҫ�ж������� 
//��֪���Ǹ��� Ĭ�ϲ��ᳬ��long long(����˵�ģ����в�û��˵�� 

// �Լ��������ƻᳬʱ�����Ի���Ҫ�ö��ַ��������½���ȷ��
//�Ͻ粻��ȷ�ϡ��Ͻ�Ϊ��֪�����½�Ľϴ�ֵ+"1".(��˵��)
//���Ǹ�����Ϊ������+'1'

//����1�����ö��ַ�����Ϊ23�֣�1�ִ���һ�ֳ�ʱ �� 
///����Ϊ22�֡� Ϊ3�ִ��� 

//�����������23�֡� ���ù�������ˡ�Ч��Ϊ��������� ����3����Сʱ��
//ϸ���е�ࡣ 

 


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long LL;
//LL inf =(1LL << 63)-1;
int map[260]; //������ĸ������֮���ӳ�䡣
long long d_value(char str[],int r)
{
	int len = strlen(str);
	long long sum =0;
	for(int i=0;i<len;i++)
	{	
		sum = sum*r+map[str[i]];
		if(sum<0)
	 		return -1;
	 } 
	 return sum; 
 } 
int main()
{
	char N1[11],N2[11]; 
	//��map���г�ʼ�� 
	for(char i='0';i<='9';i++)
		map[i]=i-'0';
	for(char i='a';i<='z';i++)
		map[i]=i-'a'+10;
	int tag,radix;
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	char N[11];
	long long know;
	if(tag==1)
	{
		know = d_value(N1,radix);
		strcpy(N,N2);
	}
	else
	{
		know = d_value(N2,radix);
		strcpy(N,N1);
	}
	int minradix=0;
	int len = strlen(N);
	int temp;
	for(int i=0;i<len;i++)
	{
		temp=map[N[i]];
		if(temp>minradix)
			minradix = temp;
	}
	minradix++;
	long long u_know;
	int maxradix =max(know,(LL)minradix);
	int midradix;
//	while(minradix<=maxradix)
//	{
//		midradix = (minradix+maxradix)/2;
//		u_know = d_value(N,midradix);
//		if(u_know<0||u_know>know)
//		{
//			maxradix = midradix-1;
//		}
//		else if(u_know<know)
//		{
//			minradix = midradix+1;
//		}
//		else
//			break;
//	}
//	if(minradix>maxradix)
//		printf("Impossible\n");
//	else
//	{
//		//��������ƶ����ϣ� 
//		///ֻ������Nֻ��һλ��ʱ������Щ���������� 
//		while(u_know==know&&midradix>=minradix)
//		{
//			midradix--;
//			u_know = d_value(N,midradix);	
//		}
//		printf("%d",midradix+1);	
//	}
	while(minradix<=maxradix)
	{
		u_know = d_value(N,minradix);///С��0��ʾ����ˡ� 
		if(u_know==know)
		{
			printf("%d\n",minradix);
			return 0;
		}
		if(u_know<0||u_know>know)
		{
			printf("Impossible\n");
			return 0;
		}
		minradix++; 
	}
	//�������δ֪������С����minradix����������֪��know�Ĵ�С
	//��minradix>know ����� ������Ҫ�����¾䡣 
	//	printf("Impossible\n");
	return 0;
 } 

//14:50����15:16 ����18�֡��� 7������ʱ����
//����ֵ��10λ���ڡ���󾭹�100����ӡ����ῼ����long long ȥ�洢��
//�����Ծ���Ҫ�����������д���
//д�������ж��ǲ��ǻ������кͣ����з�ת�ĺ����ǶԵġ� 
//�������ļӷ�Ҫ��Ϥ�����ͬʱ��reverse����ҲҪ��Ϥ�� 
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long LL;
const int maxn = 120;
bool isP(char str[]){
	bool flag = true;
	int len = strlen(str);
	for(int i=0;i<len/2;i++){
		if(str[i]!=str[len-1-i]){
			flag=false;
			break;
		}
	}
	return flag;
}
LL getR(LL a){
	char str[maxn];
	sprintf(str,"%lld",a);
	reverse(str,str+strlen(str));
	sscanf(str,"%lld",&a);
	return a;
}
int main(){
	char n[maxn],n1[maxn],n2[maxn];
	int k;
	int step=0;
	scanf("%s %d",n,&k);
	for(step=0;step<k;step++){
		if(isP(n)){
			break;
		}
		strcpy(n1,n);
		strcpy(n2,n); 
		int carry = 0;
		int len = strlen(n1);
		reverse(n2,n2+len);
		int num = 0;
		for(int i=len-1;i>=0;i--){
			int temp = (n1[i]-'0')+(n2[i]-'0')+carry;
			carry = temp/10;
			n[num++] = '0' + temp%10;
		}
		if(carry!=0)
			n[num++]='0'+carry;
		n[num]='\0';
		reverse(n,n+strlen(n));
	}
	printf("%s\n",n);
	printf("%d",step);
	return 0;
}

////��ǰд�ģ�
//#include<stdio.h>
//#include<string.h>
//#include<algorithm> 
//using namespace std;
//const int maxn = 120;
//bool ispalind(char a[])
//{
//	int len = strlen(a);
//	for(int i=0;i<len/2;i++)
//	{
//		if(a[i]!=a[len-1-i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//void out(char a[])
//{
//	int len =strlen(a);
//	for(int i=len-1;i>=0;i--)
//	{
//		printf("%c",a[i]);
//	}
//	printf("\n");
//	return ;
// } 
//int main()
//{
//	char n[maxn];
//	char n2[maxn];
//	char n3[maxn];
//	int k;
//	int numk=0;
//	scanf("%s %d",n,&k);
//	if(ispalind(n)==true)
//	{
//		printf("%s\n",n);
//		printf("%d",numk);
//		return 0;
//	}
//	for(int i=1;i<=k;i++)
//	{
//		strcpy(n2,n);
//		int len = strlen(n2);
//		//������j<len/2��������j<=len/2
//		//���򣬼���ֻ����λ��(0,1)������(1,0)�ڽ�����������Ч��
//		//�ٽ�����Ҫ�ǳ������� 
//		reverse(n2,n2+len); 
////		for(int j=0;j<len/2;j++)  //��ת 
////		{
////			swap(n2[j],n2[len-1-j]);
////		}
//		int carry =0;
//		int result;
//		int num3=0;
//		for(int j=0;j<len;j++)   //��� 
//		{
//			result = n[j]-'0'+n2[j]-'0'+carry;
//			carry = result/10;
//			result=result%10;
//			n[num3++]='0'+result;
//		}
//		if(carry!=0)
//		{
//			n[num3++]='0'+carry;
//		}
//		n[num3]='\0';
//		if(ispalind(n)==true)
//		{
//			printf("%s\n",n);
//			printf("%d",i);
//			return 0;
//		}
//	}
//	out(n);
//	printf("%d",k);
//	return 0;	
// } 

//08:00--
//��һ��д��2�ִ𰸴��󡣻����ǽ������û���������롣
//���������Ȼ������round������ ���round֮�󡣻�����2�ִ��� 

//�鿴�𰸣������������ۼۿɶ�û��˵�ǣ�����Ŷ�����Զ��ø�������
//�����ʱ�򣬾�Ҫ��ȷ��ʲô���ı���ȥ�洢�� 
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = 1005;
struct cake{
	double amount;
	double totalP;
	double price;
}C[maxn];
bool cmp(cake a,cake b){
	return a.price>b.price;
}
int main(){
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&C[i].amount);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&C[i].totalP);
		C[i].price = C[i].totalP/(C[i].amount*1.0);
	}
	sort(C,C+n,cmp);
	double sumPro = 0;
	for(int i=0;i<n;i++){
		if(C[i].amount<d){
			sumPro += C[i].totalP;
			d = d-C[i].amount;
		}else{
			sumPro += C[i].price*d;
			break;
		}
	}
//	int sum = round(sumPro*100);
//	char str[maxn];
//	sprintf(str,"%d",sum);
//	int len = strlen(str);
//	for(int i=0;i<len;i++){
//		if(i==len-2)
//			printf(".");
//		printf("%c",str[i]);
//	} 
	printf("%.2f",sumPro);
	return 0;
}

////��ǰд��
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 1005;
//struct moon
//{
//	double ton;
//	double tprice;
//}M[maxn];
//bool cmp(moon a,moon b)
//{
//	double pricea =a.tprice/a.ton;
//	double priceb =b.tprice/b.ton;
//	return pricea>priceb;
//}
//int main()
//{
//	int n;
//	double m;
//	scanf("%d %lf",&n,&m);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%lf",&M[i].ton);
//	}
//	for(int i=0;i<n;i++)
//		scanf("%lf",&M[i].tprice);
//	sort(M,M+n,cmp);
//	double profit=0;
//	for(int i=0;i<n;i++)
//	{
//		if(M[i].ton<m)
//		{
//			profit+=M[i].tprice;
//			m = m-M[i].ton;	
//		}
//		else 
//		{
//			profit+=(double)m*(M[i].tprice/M[i].ton);
//			break;
//		}	
//	}
//	printf("%.2f\n",profit);
//	return 0;
//} 

//16:30����17:14  
//18�֡� 
 
//����17:16
//1 ����������һ��ʼû�ж�"1",�������С� 

//�����ܿ������⡣
//
 
// �������Ҳ���Ϊʲô��23 ��2�����£�����������������
//

//   ����������������,n�Ǹ�������ֵ��Ȼ�����ڸý����е�
//ֵ�ķ�ת��ֵ�ǲ��������� 
//�ж��ǲ�������������ֵ��

//���ж�n�ǲ���������Ȼ����d������ʽ��ʾ������Ȼ����ʽ��ת��
//Ȼ����d�����£��÷�ת����ֵ�����жϸ�ֵ�ǲ���������

/// 
//���ǲ����ģ���Ҫ ��ϸ������⣬�ҳ����ֶȺ��ϰ��㡣 
 #include<stdio.h>
 #include<math.h>
 const int maxn =400010;
 bool isprime(int a)
 {
 	if(a==1)
	 	return false; 
 	int temp =(int)sqrt(1.0*a);
 	for(int i=2;i<=temp;i++)
 	{
 		if(a%i==0)
 		return false;
	 }
	 return true;
 }
 int r_val(int n,int d)   
 {
 	int r[maxn];
 	int count =0;
 	while(n>0)
 	{
 		r[count++]=n%d;
 		n=n/d;
	 }
 	int sum = 0;
 	count--;
 	int num =0;
	while(count>=0)
	{
		sum =sum+ r[count--]*pow(1.0*d,1.0*num);
		n=n/10;
		num++;
	}
	return sum;
 }
 int main()
 {
 	int n, d;
 	int num1,num2;
 	scanf("%d",&n);
	 while(n>0)
	 {
	 	scanf("%d",&d);
	 	if(isprime(n)==false)
	 	{
	 		printf("No\n");
		}
		 else
		 {
		 	num2 = r_val(n,d);
		 //	printf("%d\n",num2);
		 	if(isprime(num2)==false)
		 		printf("No\n");
		 	else
		 		printf("Yes\n");		
		 }
		scanf("%d",&n);	
	  } 
	  return 0;
  } 

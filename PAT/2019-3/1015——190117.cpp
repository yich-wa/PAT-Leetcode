//16:30——17:14  
//18分。 
 
//——17:16
//1 不是素数，一开始没有对"1",进行特判。 

//这道题很考验审题。
//
 
// 看题意我不懂为什么，23 在2进制下，正反数都是素数？
//

//   你对题意理解有问题,n是给的数的值，然后看其在该进制中的
//值的翻转的值是不是素数？ 
//判断是不是素数看的是值。

//先判断n是不是素数，然后将其d进制形式表示出来，然后形式翻转；
//然后求d进制下，该翻转数的值。在判断该值是不是素数。

/// 
//题是不会错的，你要 仔细理解题意，找出区分度和障碍点。 
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

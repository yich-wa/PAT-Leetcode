//Ĭд��ϰ�� 
void gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
 } 
//�ض���a%b ,������С��b

//��������
int partition(int A[],int left,int right)
{
	int temp = A[left];
	while(left<right)
	{
		while(left<right&&A[right]>temp)right--;
		A[left]=A[right];
		while(left<right&&A[left]<=temp)left++;
		A[right]=A[left]; 
	}
	A[left]=temp;
	return left;
 } 
 
//
int* lowerpos = lower_bound(a,a+n,val);
int* upperpos = upper_bound(a,a+n,val);
printf("%d %d\n",lowerpos-a,upperpos-a); 

//�����
//�߽��������Լ�ѡ��ѡ���һ������ 
long long C(long long m,long long n)
{
	if(m==n||m==0)
		return 1;
	return C(m,n-1)+C(m-1,n-1);
}

//����n!���ж��ٸ������� p
int cal(int n,int p)
{
	int ans =0;
	while(n>0)
	{
		ans+=n/p;
		n/=p;
	}
	return ans;
} 

string ::npos;
if(str.find(str2)==string::npos) 
 
 
 

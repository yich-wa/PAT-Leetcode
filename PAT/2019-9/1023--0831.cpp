//11:01——11:15时，拿到11分。后面三个答案错误。 
//输入数字不超过20位，但是已经超出long long表示范围了，long long是18位。  这是一个大整数运算。
//--11:32这是一个大整数运算。记住要稳。还犯了。给字符串数组赋值，整数的错误。 
#include<stdio.h>
#include<string.h>
const int maxn = 25;
int main(){
	int per[10]={0};
	char str[maxn];
	int perd[10]={0};
	char strd[maxn];
	bool flag =true;
	scanf("%s",str);
	int carry = 0;
	int num = 0;
	for(int i=strlen(str)-1;i>=0;i--){
		int temp = (str[i]-'0')*2+carry;
		strd[num++] = '0'+temp%10;
		carry = temp/10;
	}
	if(carry!=0){
		strd[num++] = '0'+ carry;
		flag = false;
//		printf("iandjf\n");
	}
	strd[num]= '\0';
//	printf("%s****\n",strd);
	if(flag==true){
		for(int i=0;i<strlen(str);i++){
			per[str[i]-'0']++;
		}
		for(int i=0;i<strlen(strd);i++){
			perd[strd[i]-'0']++;
		}
		
		for(int i=0;i<=9;i++){
			if(per[i]!=perd[i]){
				flag=false;
				break;
			}
		}
	}
	if(flag==true)
		printf("Yes\n");
	else 
		printf("No\n");
	for(int i=strlen(strd)-1;i>=0;i--){
		printf("%c",strd[i]);
	}
	return 0;
} 

////以前写的
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//#include<string.h>
//using namespace std;
//const int maxn = 25;
//int main()
//{
//	char a[maxn];
//	scanf("%s",a);
//	vector<int>ori;
//	vector<int>dou;
//	int len =strlen(a);
//	int temp;
//	for(int i=0;i<len;i++)
//	{
//		temp = a[i]-'0';
//		ori.push_back(temp);
//	} 
//	int carry =0;
//	int result;
//	for(int i=len-1;i>=0;i--)
//	{
//		temp = a[i]-'0';
//		result= temp*2+carry;
//		carry = result/10;
//		result = result%10;
//		dou.push_back(result);
//	}
//	if(carry!=0)
//		dou.push_back(carry);
//	if(ori.size()!=dou.size())
//	{
//		printf("No\n");
//	}
//	else
//	{
//		vector<int>s_dou;
//		s_dou= dou;
//		sort(s_dou.begin(),s_dou.end());
//		sort(ori.begin(),ori.end());
//		if(ori==s_dou)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	for(int i=dou.size()-1;i>=0;i--)
//		printf("%d",dou[i]);
//	printf("\n");
//	return 0;	
// }  

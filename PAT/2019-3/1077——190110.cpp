//再次明晰string.h  中的字符数组，和string中的字符串之间的区别
//string.h可以用gets,puts 做整行的输入输出。
//而string只能用cin,cout  。
//C++的"整行输入string"，用的是：getline(cin,str); 
//输入：char str[100],用的是cin.getline(str,100); 
//奇怪的是最终可以跑出样例，但是提交却编译错误。 
//后来看，发现，给字符串后面少加了个换行符。 
#include<stdio.h>
#include<string.h>
const int maxc = 260;
int main()
{
	int n;
	scanf("%d",&n);
	//吸收整数后得换行符 
	getchar();
	bool flag=true;
	char temp[maxc];
	char samepart[maxc];
	gets(samepart);
	int lens,lent;
	for(int k=1;k<n;k++)
	{
		gets(temp);
		if(flag==true)
		{
			lens =strlen(samepart);
			lent =strlen(temp);
			int i =lens-1;
			int j =lent-1;
			while(i>=0&&j>=0&&samepart[i]==temp[j])
			{
				i--;
				j--;
			}
			if(i==lens-1)
				flag=false;
			else
			{
				int count =0;
				for(int h=j+1;h<=lent;h++)
				{
					samepart[count++]=temp[h];
				}
				samepart[count]='\n'; 
			}
		 } 	
	}
	//有个问题公共尾缀的首个空格要输出吗？ 
	if(flag==false)
		printf("nai\n");
	else
	{
		lens =strlen(samepart);
		for(int i=0;i<lens;i++)
		{
			if(samepart[0]==' ')
				continue;
			printf("%c",samepart[i]);
		}
	}
	return 0;
 } 

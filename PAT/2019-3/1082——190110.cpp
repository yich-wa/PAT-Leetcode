//vector中如果要以字符串为单位的话。则vector<char*>  或者vector<string> 
//重点是分节的思想，万、亿。一节一节输出。单独的零需要特判输出。 
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn =12;
int main()
{
	char input[maxn];
	scanf("%s",input);
	vector<char*>output;
	int len =strlen(input);
	char index[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
 	char section[2][6]={"Wan","Yi"};
 	char digit[3][6]={"Shi","Bai","Qian"};
	int nump=0;
	int templen=len;
	if(input[nump]=='0')
	{
		printf("ling\n");
		return 0;
	}	
	 if(input[nump]=='-')
	 {
	 	printf("Fu ");
	 	nump++;
	 	templen--;	
	 }	
	 int section_num=0;
	 while(templen>4)
	 {
	 	templen-=4;
	 	section_num++; //0表示个字节；1万，2亿； 
	 } 
	bool flag1 ;   //表示借个字节是否都为零 。 
	bool preflag;  //每个字节中的在遇到一个非零数前是否有数 
	while(section_num>=0)
	{
		flag1 =true;
		preflag=false;
		while(templen>0&&nump<len) 
		{
			int num = input[nump]-'0';
			if(num!=0)
			{
				if(preflag==true)
				{
					output.push_back(index[0]);
					preflag=false;
				}
				flag1=false;
				output.push_back(index[num]);
				if(templen>=2)
				output.push_back(digit[templen-2]);
			} 
			else
			{
				preflag=true;
			}
			nump++;
			templen--;	
		}
		if(section_num>0)
		{
			templen =4;
			if(flag1==false)
				output.push_back(section[section_num-1]);	
		}
		section_num--; 
	}
	for(int i=0;i<output.size();i++)
	{
		printf("%s",output[i]);
		if(i<output.size()-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
 } 

//vector�����Ҫ���ַ���Ϊ��λ�Ļ�����vector<char*>  ����vector<string> 
//�ص��Ƿֽڵ�˼�룬���ڡ�һ��һ�����������������Ҫ��������� 
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
	 	section_num++; //0��ʾ���ֽڣ�1��2�ڣ� 
	 } 
	bool flag1 ;   //��ʾ����ֽ��Ƿ�Ϊ�� �� 
	bool preflag;  //ÿ���ֽ��е�������һ��������ǰ�Ƿ����� 
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

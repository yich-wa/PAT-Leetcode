//ע��ÿ���ж����Ƿ��Ѿ������ʱ����ǰ��Сд��ĸ��ת��Ϊ��д �� 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h> 
#include<map>
using namespace std;
const int maxn = 90;
int main()
{
	char str1[maxn];
	char str2[maxn];
	map<char,int>mp;
	vector<char>output;
	scanf("%s %s",str1,str2);
	int len1 =strlen(str1);
	int len2 =strlen(str2); 
	int i,j;
	for(i=0,j=0;i<len1&&j<len2;)
	{
		if(str1[i]!=str2[j])
		{
			//�ȶ�ת��Ϊ��д������鿴�Ƿ���ӣ���ӡ� 
			if(str1[i]>='a'&&str1[i]<='z')    
			{
				str1[i]=str1[i]-'a'+'A';
			}
			if(mp.find(str1[i])==mp.end())
			{ 
				mp[str1[i]]=i;    
				output.push_back(str1[i]);
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	while(i<len1)
	{
		if(str1[i]>='a'&&str1[i]<='z')    
		{
			str1[i]=str1[i]-'a'+'A';
		}
		if(mp.find(str1[i])==mp.end())
		{
			mp[str1[i]]=i;
			if(str1[i]>='a'&&str1[i]<='z')
			{
				str1[i]=str1[i]-'a'+'A';
			}
			output.push_back(str1[i]);
		}
		i++;
	}
	for(i =0;i<output.size();i++)
	printf("%c",output[i]);
	printf("\n");
	return 0;
 } 

//这道题，题意其实有点绕，有点违常理，更需要你认真审题，翻译题意。 
//正确去划分等级是正确的做法。 
///第一遍做完，还是忘了一个题中的小细节。所以下次一定要题意和代码对应符合 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h> 
using namespace std;
const int maxn =100005;
struct people{
	char id[10];
	int virtue;
	int talent;
	int level;
	int total;
}temp;
bool cmp(people a,people b)
{
	if(a.level!=b.level)
		return  a.level<b.level;
	else
	{
		if(a.total!=b.total)
			return a.total>b.total;
		else if(a.virtue!=b.virtue)
			return a.virtue>b.virtue;
		else 
			return strcmp(a.id,b.id)<0;
	}
}
int main()
{
	vector<people>output;
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d%d",temp.id,&temp.virtue,&temp.talent);
		if(temp.virtue>=l&&temp.talent>=l) 
		{
			temp.total = temp.virtue+temp.talent;
			if(temp.virtue>=h&&temp.talent>=h)  //圣人 
				temp.level =0;
			else if(temp.virtue>=h&&temp.talent>=l)  //君子 
				temp.level =1;
			else if(temp.virtue<h&&temp.talent<h&&temp.virtue>=temp.talent)  //愚人 
				temp.level= 2;
			else 
				temp.level=3;
			output.push_back(temp);
		}
	 }
	 sort(output.begin(),output.end(),cmp); 
	 printf("%d\n",output.size());
	 for(int i=0;i<output.size();i++)
	 {
	 	printf("%s %d %d\n",output[i].id,output[i].virtue,output[i].talent);
	 }
	 return 0;
}

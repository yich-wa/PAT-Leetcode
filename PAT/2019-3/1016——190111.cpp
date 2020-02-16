//相邻的call的姓名的比较用的是strcmp(string.h)；不要再用直接相等。
//题如果很复杂的话，框架理清，与输出相对应，仔细思考错在哪个环节。 
//有一个新知识点：map中如果是字符串到int 的映射，只能用string,
//不能用char[]; 
//也不能用char* ，vector<char*>input 是对的 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<map>
using namespace std;
const int maxn = 1005;
int price[24];
struct call{
	char name[23];
	int month;
	int day;
	int hour;
	int min;
	bool in_out;
}temp;
struct bill{
	char name[23];
	int month;
	vector<int>intime;
	vector<int>outtime;
	vector<int>eachtime;
	vector<double>eachcost; 
	double cost;	 
}tempb;
vector<bill>output; 
vector<call>input;
map<char*,int>mp;   //mp中字符串到数字的映射该如何表示 
bool cmp1(call a,call b)
{
	if(strcmp(a.name,b.name)==0)
		if(a.month==b.month)
			if(a.day == b.day)
				if(a.hour == b.hour)
					return a.min<b.min;
				else
					return a.hour<b.hour;
			else
				return a.day<b.day;
		else
			return a.month<b.month;
	else
		return strcmp(a.name,b.name)<0;
 } 
int main()
{
	for(int i=0;i<24;i++)
	{
		scanf("%d",&price[i]);
	}
	int n;
	scanf("%d",&n);
	char tempin_out[10];
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d:%d %s",temp.name,&temp.month,&temp.day,&temp.hour,&temp.min,tempin_out); 
		if(tempin_out[1]=='n')
			temp.in_out = true;
		else
			temp.in_out = false;
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),cmp1);
//	for(int i=0;i<input.size() ;i++)
//	{
//		printf("%s %d:%d:%d:%d",input[i].name,input[i].month,input[i].day,input[i].hour,input[i].min);	
//		if(input[i].in_out==true)
//			printf("on\n");
//		else
//			printf("off\n");
//	}
	int count =0;
	char lastname[23]="bukeneng";
	for(int i=0;i<input.size();) 
	 //对i的改变要准确 ,分类 讨论，啥时对i进行何种改变。 
	{
		bool flag =true;
		if(i+1<input.size())
		{ 
		//相邻的call的姓名的比较用的是strcmp；
		if(strcmp(input[i].name,input[i+1].name)==0)
		if(input[i].month==input[i+1].month)
		if(input[i].in_out==true&&input[i+1].in_out==false)
		{
			tempb.intime.clear();
			tempb.outtime.clear();
			tempb.eachcost.clear();
			tempb.eachtime.clear();
			double e_c = 0;
			int e_t=0;
			int inday =input[i].day; 
			int inhour =input[i].hour;
			int inmin = input[i].min;
			while(inday<input[i+1].day||inhour<input[i+1].hour||inmin<input[i+1].min)
			{
				e_c+=price[inhour];
				inmin++;
				e_t++;
				if(inmin==60)
				{
					inhour++;
					inmin =0;
				}
				if(inhour==24)
				{
					inday++;
					inhour=0;
				}
			}
			e_c=e_c/100.0; 
			//printf("%.2f\n",e_c);
			if(strcmp(input[i].name,lastname)!=0)
			{
				strcpy(lastname,input[i].name);
				count++;
				tempb.month = input[i].month;
				strcpy(tempb.name,input[i].name);
				tempb.intime.push_back(i);
				tempb.outtime.push_back(i+1);
				tempb.eachcost.push_back(e_c);
				tempb.eachtime.push_back(e_t);
				tempb.cost=e_c;
				output.push_back(tempb);
			}
			else
			{
				int num =count-1;
				//printf("%d***\n",num);
				output[num].intime.push_back(i);
				output[num].outtime.push_back(i+1);
				output[num].eachcost.push_back(e_c);
				output[num].eachtime.push_back(e_t);
				output[num].cost+=e_c;	
			}
			i+=2;
			flag =false; 
		}
	}
	if(flag==true)
		i++;
	}
	for(int i=0;i<output.size();i++)
	{
		printf("%s %02d\n",output[i].name,output[i].month);
		for(int j=0;j<output[i].intime.size();j++)
		{
			int in= output[i].intime[j];		
			int out = output[i].outtime[j];	
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",input[in].day,input[in].hour,input[in].min,input[out].day,input[out].hour,input[out].min,output[i].eachtime[j],output[i].eachcost[j]);
		}
		printf("Total amount: $%.2f\n",output[i].cost);
	}
	return 0;	
}

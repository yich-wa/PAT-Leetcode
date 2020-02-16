//09:50_11:20;25�֡�ֱ�������û�����ݴ浽������ ��
//��ס������������������һ����˼��
//map<char*,int>mp; �����ַ�����������ӳ�䡣 
//���м�סif�����෴�Ĳ��֣�Ҫ�ܴ���һ�����壬��Ҫ���Ի�������һ���֡� 
#include<stdio.h>
#include<vector>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int price[24];
struct record{
	char name[22];
	int month;
	int day;
	int hour;
	int minute;
	int tag;
}R;
vector<record>list;
int len = 0;
bool cmp(record a,record b){
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else{
		if(a.day!=b.day)
			return a.day<b.day;
		else if(a.hour!=b.hour)
			return a.hour<b.hour;
		else 
			return a.minute<b.minute;
	}
}
int cal(record a,record b){
	int result = 0;
	int d1 = a.day;
	int d2 = b.day;
	int h1 = a.hour;
	int h2 = b.hour;
	int m1 = a.minute;
	int m2 = b.minute;
	while(d1!=d2||h1!=h2||m1!=m2){
		len++;
		m1++;
		result+=price[h1];
		if(m1==60){
			m1=0;
			h1++;
			if(h1==24){
				h1 = 0;
				d1++;
			}
		}		
	}
	return result;
}
int main(){
	for(int i=0;i<24;i++)
		scanf("%d",&price[i]);
	int n;
	scanf("%d",&n);
	char status[10];
	for(int i =0;i<n;i++){
		scanf("%s %d:%d:%d:%d %s",R.name,&R.month,&R.day,&R.hour,&R.minute,status);
		if(status[1]=='n'){
			R.tag = 0; 
		}else{
			R.tag = 1;
		}
		list.push_back(R); 	
	}
	sort(list.begin(),list.begin()+list.size(),cmp);
	double totalAmount =0;
	double singleAmount = 0;
	for(int i=0;i<list.size();i++){
		int j=i+1;
		if(j<list.size()&&strcmp(list[i].name,list[j].name)==0&&list[i].tag==0&&list[j].tag==1){
			if(totalAmount==0){
				printf("%s %02d\n",list[i].name,list[i].month);
			}
			for(int k=i;k<=i+1;k++)
				printf("%02d:%02d:%02d ",list[k].day,list[k].hour,list[k].minute);
			singleAmount = (cal(list[i],list[j])*1.0)/(100*1.0);
			totalAmount+=singleAmount; 
			printf("%d $%.2f\n",len,singleAmount);
			len = 0;	
		}else if(strcmp(list[i].name,list[j].name)!=0){
			if(totalAmount>0){
				printf("Total amount: $%.2f\n",totalAmount);
				totalAmount = 0;
			}
		}
	}
	return 0;
}
//
////��ǰ����
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//#include<string.h>
//#include<map>
//using namespace std;
//const int maxn = 1005;
//int price[24];
//struct call{
//	char name[23];
//	int month;
//	int day;
//	int hour;
//	int min;
//	bool in_out;
//}temp;
//struct bill{
//	char name[23];
//	int month;
//	vector<int>intime;
//	vector<int>outtime;
//	vector<int>eachtime;
//	vector<double>eachcost; 
//	double cost;	 
//}tempb;
//vector<bill>output; 
//vector<call>input;
//map<char*,int>mp;   //mp���ַ��������ֵ�ӳ�����α�ʾ 
//bool cmp1(call a,call b)
//{
//	if(strcmp(a.name,b.name)==0)
//		if(a.month==b.month)
//			if(a.day == b.day)
//				if(a.hour == b.hour)
//					return a.min<b.min;
//				else
//					return a.hour<b.hour;
//			else
//				return a.day<b.day;
//		else
//			return a.month<b.month;
//	else
//		return strcmp(a.name,b.name)<0;
// } 
//int main()
//{
//	for(int i=0;i<24;i++)
//	{
//		scanf("%d",&price[i]);
//	}
//	int n;
//	scanf("%d",&n);
//	char tempin_out[10];
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s %d:%d:%d:%d %s",temp.name,&temp.month,&temp.day,&temp.hour,&temp.min,tempin_out); 
//		if(tempin_out[1]=='n')
//			temp.in_out = true;
//		else
//			temp.in_out = false;
//		input.push_back(temp);
//	}
//	sort(input.begin(),input.end(),cmp1);
////	for(int i=0;i<input.size() ;i++)
////	{
////		printf("%s %d:%d:%d:%d",input[i].name,input[i].month,input[i].day,input[i].hour,input[i].min);	
////		if(input[i].in_out==true)
////			printf("on\n");
////		else
////			printf("off\n");
////	}
//	int count =0;
//	char lastname[23]="bukeneng";
//	for(int i=0;i<input.size();) 
//	 //��i�ĸı�Ҫ׼ȷ ,���� ���ۣ�ɶʱ��i���к��ָı䡣 
//	{
//		bool flag =true;
//		if(i+1<input.size())
//		{ 
//		//���ڵ�call�������ıȽ��õ���strcmp��
//		if(strcmp(input[i].name,input[i+1].name)==0)
//		if(input[i].month==input[i+1].month)
//		if(input[i].in_out==true&&input[i+1].in_out==false)
//		{
//			tempb.intime.clear();
//			tempb.outtime.clear();
//			tempb.eachcost.clear();
//			tempb.eachtime.clear();
//			double e_c = 0;
//			int e_t=0;
//			int inday =input[i].day; 
//			int inhour =input[i].hour;
//			int inmin = input[i].min;
//			while(inday<input[i+1].day||inhour<input[i+1].hour||inmin<input[i+1].min)
//			{
//				e_c+=price[inhour];
//				inmin++;
//				e_t++;
//				if(inmin==60)
//				{
//					inhour++;
//					inmin =0;
//				}
//				if(inhour==24)
//				{
//					inday++;
//					inhour=0;
//				}
//			}
//			e_c=e_c/100.0; 
//			//printf("%.2f\n",e_c);
//			if(strcmp(input[i].name,lastname)!=0)
//			{
//				strcpy(lastname,input[i].name);
//				count++;
//				tempb.month = input[i].month;
//				strcpy(tempb.name,input[i].name);
//				tempb.intime.push_back(i);
//				tempb.outtime.push_back(i+1);
//				tempb.eachcost.push_back(e_c);
//				tempb.eachtime.push_back(e_t);
//				tempb.cost=e_c;
//				output.push_back(tempb);
//			}
//			else
//			{
//				int num =count-1;
//				//printf("%d***\n",num);
//				output[num].intime.push_back(i);
//				output[num].outtime.push_back(i+1);
//				output[num].eachcost.push_back(e_c);
//				output[num].eachtime.push_back(e_t);
//				output[num].cost+=e_c;	
//			}
//			i+=2;
//			flag =false; 
//		}
//	}
//	if(flag==true)
//		i++;
//	}
//	for(int i=0;i<output.size();i++)
//	{
//		printf("%s %02d\n",output[i].name,output[i].month);
//		for(int j=0;j<output[i].intime.size();j++)
//		{
//			int in= output[i].intime[j];		
//			int out = output[i].outtime[j];	
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",input[in].day,input[in].hour,input[in].min,input[out].day,input[out].hour,input[out].min,output[i].eachtime[j],output[i].eachcost[j]);
//		}
//		printf("Total amount: $%.2f\n",output[i].cost);
//	}
//	return 0;	
//} 

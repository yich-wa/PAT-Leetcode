//第一遍写完后有两个错误，
//通过将各种排序的结果全部输出。查出问题所在 。
//对于需要多次排序的题，不要怕，稳住
//对于需要用到结构体嵌套的题时。更要稳住。 
//*****找匹配对出了问题，是按时间顺序，临近的in和out匹配，不是
//**不是相同的车牌的第一个 in和第一个out匹配。
//**如果先按时间顺序排列，相同车牌，第一个是in第二个还是in
//**则第一个in无效。
//*****其次，到底是一次停车时间的最长值，还是一个车辆今天总的
//**停车时间。 由于结果错误怀疑是后者 。。 经计算是后者，问的是总时间。
//上面两个问题处理后，样例看似可以过。但是提交全部是错的。 
//不确定是查询一次输出一个呢？还是所有查完，一次全部输出。 
//****奇怪，为什么，样例过了，但是一分都没有。 
///****？？？？为啥一分的都没有。。。。
//发现注意点、联系知识点、构造思路。 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
const int maxk = 80005;
const int maxtime = 24*3600;
struct car{
	int time;
	char plate[9];
	int tag ;
}record[maxn];
vector<car>check;
vector<char*>longest;
bool cmp(car a,car b)
{
	if(strcmp(a.plate,b.plate)!=0)
		return strcmp(a.plate,b.plate)<0;
	else
		return a.time<b.time;
}
bool cmp2(car a ,car b)
{
	return a.time<b.time;
}
bool cmp3(char a[],char b[])
{
	return strcmp(a,b)<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char temptag[5];
	int hour,min,second;
	for(int i=0;i<n;i++)
	{	
		scanf("%s %d:%d:%d %s",record[i].plate,&hour,&min,&second,temptag);
		record[i].time =hour*60*60+min*60+second;
		if(temptag[0]=='i')
			record[i].tag=0;
		else
			record[i].tag=1;
	 } 
	 sort(record,record+n,cmp);
	 int t_longest =-1;
	 int parktime=0;
	 char l_plate[10];  //查看相邻两次停车是否为一车。 
	 strcpy(l_plate,record[0].plate);
	 for(int i=0;i<n;i++)
	 {
	 	//直接锁定相邻，同车牌，一个in一个out。这是题目的本意。 
	 	if(i+1<n&&(record[i].tag==0)&&(record[i+1].tag==1)&&(strcmp(record[i].plate,record[i+1].plate)==0)) 
	 	{
	 		check.push_back(record[i]);
		 	check.push_back(record[i+1]);
		 	if(strcmp(record[i].plate,l_plate)!=0)
		 		parktime=0;
		 	parktime += record[i+1].time-record[i].time;
		 	if(parktime>t_longest)
		 	{
		 		t_longest = parktime;
		 		longest.clear();
		 		longest.push_back(record[i].plate);
			}
			 else if(parktime==t_longest)   
			 //同一辆车可能两次停车时间都是最长的 
			 //最后需要将longest中去重复。 
			 {
				longest.push_back(record[i].plate);
			 }
			 strcpy(l_plate,record[i].plate);	
		 } 
	 }
	 sort(check.begin(),check.end(),cmp2);
	 sort(longest.begin(),longest.end(),cmp3);
	 int num =0;
	 int count =0;
	 for(int i=0;i<k;i++)
	 {
	 	scanf("%d:%d:%d",&hour,&min,&second);
	 	int q_time = hour*3600+min*60+second;
	 	while(num<check.size()&&check[num].time<=q_time)
	 	{
	 		if(check[num++].tag==0)    //表示进入车库。 
	 			count ++;
	 		else
	 			count--;
		}
		printf("%d\n",count);	
	 }
	 printf("%s",longest[0]);
	 char lastplate[10];
	 strcpy(lastplate,longest[0]);
	 for(int i=1;i<longest.size();i++)
	 {
	 	if(strcmp(lastplate,longest[i])==0)
	 	 	continue;
	 	else
	 	{
	 		printf(" %s",longest[i]);
		 }	
	 } 
	 second =t_longest%60;
	 hour = t_longest/3600;
	 min = (t_longest/60)%60;
	 printf(" %02d%:%02d:%02d\n",hour,min,second);
	 return 0;
}


//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int maxn = 10005;
//const int maxk = 80005;
//const int maxtime = 24*3600;
//struct car{
//	int time;
//	char plate[9];
//	int tag ;
//}record[maxn];
//vector<car>check;
//vector<char*>longest;
//bool cmp(car a,car b)
//{
//	if(strcmp(a.plate,b.plate)!=0)
//		return strcmp(a.plate,b.plate)<0;
//	else
//		return a.time<b.time;
//}
//bool cmp2(car a ,car b)
//{
//	return a.time<b.time;
//}
//bool cmp3(char a[],char b[])
//{
//	return strcmp(a,b)<0;
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	char temptag[5];
//	int hour,min,second;
//	for(int i=0;i<n;i++)
//	{	
//		scanf("%s %d:%d:%d %s",record[i].plate,&hour,&min,&second,temptag);
//		record[i].time =hour*60*60+min*60+second;
//		if(temptag[0]=='i')
//			record[i].tag=0;
//		else
//			record[i].tag=1;
//	 } 
//	 sort(record,record+n,cmp);
//	 for(int i=0;i<n;i++)
//	 {
//	 	printf("%s %d %d\n",record[i].plate,record[i].time,record[i].tag);
//	 }
//	 printf("***\n");
//	 int t_longest =-1;
//	 for(int i=0;i<n;)
//	 {
//	 	while(i<n&&record[i].tag!=0) //找到进去的车 
//	 		i++;
//	 	if(i<n)
//	 	{
//	 		//printf("%d*****\n",i);
//	 		int j =i+1;
//	 		while(j<n&&(record[j].tag!=1||strcmp(record[i].plate,record[j].plate)!=0))
//	 			j++;
//	 		//printf("%d*****\n",j);
//	 		if(j<n)
//			{
//			 	check.push_back(record[i]);
//			 	check.push_back(record[j]);
//			 	int parktime = record[j].time-record[i].time;
//			 	if(parktime>t_longest)
//			 	{
//			 		t_longest = parktime;
//			 		longest.clear();
//			 		longest.push_back(record[i].plate);
//				}
//				 else if(parktime==t_longest)   
//				 //同一辆车可能两次停车时间都是最长的 
//				 //最后需要将longest中去重复。 
//				 {
//					longest.push_back(record[i].plate);
//				 }	
//			}	
//			i=j+1;
//		 } 
//	 }
//	 sort(check.begin(),check.end(),cmp);
//	 for(int i=0;i<check.size();i++)
//	 {
//	 	printf("%s %d %d\n",check[i].plate,check[i].time,check[i].tag);
//	 }
//	 sort(check.begin(),check.end(),cmp2);
//	 sort(longest.begin(),longest.end(),cmp3);
//	 int num =0;
//	 int count =0;
//	 for(int i=0;i<k;i++)
//	 {
//	 	scanf("%d:%d:%d",&hour,&min,&second);
//	 	int q_time = hour*3600+min*60+second;
//	 	//printf("%d\n",check.size());
//	 	while(num<check.size()&&check[num].time<=q_time)
//	 	{
//	 		if(check[num++].tag==0)
//	 			count ++;
//	 		else
//	 			count--;
//		}
//		printf("%d\n",count);	
//	 }
//	 printf("%s",longest[0]);
//	 char lastplate[10];
//	 strcpy(lastplate,longest[0]);
//	 for(int i=1;i<longest.size();i++)
//	 {
//	 	if(strcmp(lastplate,longest[i])==0)
//	 	 	continue;
//	 	else
//	 	{
//	 		printf(" %s",longest[i]);
//		 }	
//	 } 
//	 second =t_longest%60;
//	 hour = t_longest/3600;
//	 min = (t_longest/60)%60;
//	 printf(" %02d%:%02d:%02d\n",hour,min,second);
//	 return 0;
//}

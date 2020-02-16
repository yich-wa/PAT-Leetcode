//普通排序题，注意字符串的拷贝。复习那个知识点。这个排序只需要
//挑出最大值和最小值，因此没必要全部记录下来。只需在输入时，记录
//临时的最大值和最小值即可。 
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	int m;
	scanf("%d",&m);
	char inId[20];
	char outId[20];
	char tempId[20];
	int e_time = 24*3600;
	int l_time = 0;
	int h1,h2,m1,m2,s1,s2;
	int temp1,temp2;
	for(int i=0;i<m;i++){
		scanf("%s %d:%d:%d %d:%d:%d",tempId,&h1,&m1,&s1,&h2,&m2,&s2);
		temp1 = h1*3600+m1*60+s1;
		temp2 = h2*3600 +m2*60+s2;
		if(temp1<e_time){
			e_time = temp1;
			strcpy(inId,tempId);
		}
		if(temp2>l_time){
			l_time = temp2;
			strcpy(outId,tempId); 
		}
	}
	printf("%s %s",inId,outId);
	return 0;
}

//// 以前写的 
//#include<stdio.h>
//#include<algorithm>
//#include<string.h> 
//using namespace std;
//const int maxc = 18;
//int main()
//{
//	int n;
//	char lock[maxc];
//	char unlock[maxc];
//	char temp[maxc];
//	scanf("%d",&n);
//	int earliest = 150000;
//	int lastest =-1;
//	int temptime;
//	int h,m,s;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s %d:%d:%d",temp,&h,&m,&s);
//		temptime = h*3600+m*60+s;
//		if(temptime<earliest)
//		{
//			earliest =temptime;
//			strcpy(unlock,temp);
//		}
//		scanf("%d:%d:%d",&h,&m,&s);
//		temptime = h*3600+m*60+s;
//		if(temptime>lastest)
//		{
//			lastest = temptime;
//			strcpy(lock,temp);
//		}		
//	}
//	printf("%s %s\n",unlock,lock);
//	return 0;
//}











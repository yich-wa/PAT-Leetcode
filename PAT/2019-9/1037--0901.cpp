//20:15-- 20:36 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
bool cmp(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	return a<b;
}
int main(){
	int nc,np;
	vector<int>c1;
	vector<int>c2;
	vector<int>p1;
	vector<int>p2;
	scanf("%d",&nc);
	int temp;
	for(int i=0;i<nc;i++){
		scanf("%d",&temp);
		if(temp>0)
			c1.push_back(temp);
		else if(temp<0)
			c2.push_back(temp);
	} 
	sort(c1.begin(),c1.begin()+c1.size(),cmp);
	sort(c2.begin(),c2.begin()+c2.size(),cmp2);
	scanf("%d",&np);
	for(int i=0;i<np;i++){
		scanf("%d",&temp);
		if(temp>0)
			p1.push_back(temp);
		else if(temp<0)
			p2.push_back(temp);
	}
	sort(p1.begin(),p1.begin()+p1.size(),cmp);
	sort(p2.begin(),p2.begin()+p2.size(),cmp2);
	LL result = 0;
	for(int i=0;i<c1.size()&&i<p1.size();i++){
		result+=c1[i]*p1[i];
	}
	for(int i=0;i<c2.size()&&i<p2.size();i++){
		result+=c2[i]*p2[i];
	}
	printf("%lld",result);
	return 0;
} 


////ÒÔÇ°Ð´µÄ
//#include<stdio.h>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 100010;
//bool cmp(int a,int b)
//{
//	return a>b;
//}
//int main()
//{
//	int nc,np;
//	long long coup[maxn];
//	long long value[maxn];
//	scanf("%d",&nc);
//	for(int i=0;i<nc;i++)
//	{
//		scanf("%lld",&coup[i]);
//	}
//	sort(coup,coup+nc,cmp); 
//	scanf("%d",&np);
//	for(int i=0;i<np;i++)
//	{
//		scanf("%lld",&value[i]);
//	}
//	sort(value,value+np,cmp);
//	long long max_amount = 0;
//	int c_left=0;
//	int v_left=0;
//	int c_right =nc-1;
//	int v_right= np-1;
//	long long ling =0;
//	while(coup[c_left]>0&&value[v_left]>0)
//	{
//		max_amount+=coup[c_left]*value[v_left];
//		//printf("%d %d\n",coup[c_left],value[v_left]);
//		c_left++;
//		v_left++;
//	}
//	//printf("%d\n",max_amount);
//	while(coup[c_right]<0&&value[v_right]<0)
//	{
//		max_amount+=coup[c_right--]*value[v_right--];
//	}
//	printf("%d\n",max_amount);
//	return 0;
//} 

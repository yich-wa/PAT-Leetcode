//08:28--08:46
//题不难，一定要准确切割题意 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct person{
	int id;
	int vg;
	int tg;
	int total;
	int cat;
}tempP;
vector<person>v;
bool cmp(person a,person b){
	if(a.cat!=b.cat){
		return a.cat<b.cat;
	}else if(a.total!=b.total){
		return a.total>b.total;
	}else if(a.vg!=b.vg){
		return a.vg>b.vg;
	}else{
		return a.id<b.id;
	}
}
int main(){
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	int tempId,tempV,tempT;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&tempId,&tempV,&tempT);
		if(tempV>=l&&tempT>=l){
			tempP.vg = tempV;
			tempP.tg = tempT;
			tempP.id = tempId;
			tempP.total = tempV+tempT;
			if(tempV>=h&&tempT>=h){
				tempP.cat = 1;
			}else if(tempV>=h){
				tempP.cat = 2;
			}else if(tempV>=tempT){
				tempP.cat =3;
			}else{
				tempP.cat = 4;
			}
			v.push_back(tempP);
		}
	}
	sort(v.begin(),v.begin()+v.size(),cmp);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%08d %d %d\n",v[i].id,v[i].vg,v[i].tg);
	}
	return 0;
}


////以前写的
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//#include<string.h> 
//using namespace std;
//const int maxn =100005;
//struct people{
//	char id[10];
//	int virtue;
//	int talent;
//	int level;
//	int total;
//}temp;
//bool cmp(people a,people b)
//{
//	if(a.level!=b.level)
//		return  a.level<b.level;
//	else
//	{
//		if(a.total!=b.total)
//			return a.total>b.total;
//		else if(a.virtue!=b.virtue)
//			return a.virtue>b.virtue;
//		else 
//			return strcmp(a.id,b.id)<0;
//	}
//}
//int main()
//{
//	vector<people>output;
//	int n,l,h;
//	scanf("%d%d%d",&n,&l,&h);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s %d%d",temp.id,&temp.virtue,&temp.talent);
//		if(temp.virtue>=l&&temp.talent>=l) 
//		{
//			temp.total = temp.virtue+temp.talent;
//			if(temp.virtue>=h&&temp.talent>=h)  //圣人 
//				temp.level =0;
//			else if(temp.virtue>=h&&temp.talent>=l)  //君子 
//				temp.level =1;
//			else if(temp.virtue<h&&temp.talent<h&&temp.virtue>=temp.talent)  //愚人 
//				temp.level= 2;
//			else 
//				temp.level=3;
//			output.push_back(temp);
//		}
//	 }
//	 sort(output.begin(),output.end(),cmp); 
//	 printf("%d\n",output.size());
//	 for(int i=0;i<output.size();i++)
//	 {
//	 	printf("%s %d %d\n",output[i].id,output[i].virtue,output[i].talent);
//	 }
//	 return 0;
//} 

//16:40--19:28 中间吃饭约一个小时。 
//本题遗漏知识点：map映射，如果是字符串作为键值的话，必须是string。不能是：char*
//vector是可以用char*的。 
//根据father[i]是不是一样，不能判断是不是在一个集合里。应该用findFather(i)函数。
//因为中间可能还存在没有压缩的路径 
//样例过提交3分。
//原因是findFather函数没有写返回值。 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<string> 
#include<iostream>
using namespace std;
const int maxn = 2005;
struct member{
	string name;
	int pw;
}M[maxn];
struct gang{
	int sw;
	int number;
	vector<member>m;
}G[1005];
struct output{
	int head;
	int quantity;
}tempO;
int father[maxn];
int findFather(int a){
	int x= a;
	while(father[x]!=x){
		x=father[x];
	}
	//路径压缩
	while(father[a]!=x){
		int u =father[a];
		father[a] = x;
		a = u;
	} 
	return x; 
}
void join(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	father[faA]= faB;
}
bool cmp(gang a,gang b){
	if(a.number!=b.number)
		return a.number>b.number;
	else
		return a.sw>b.sw;
}
bool cmp2(output a,output b){
	return M[a.head].name<M[b.head].name;
}
int main(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
	int n,k;
	int num =0;
	map<string,int>mp;
	scanf("%d%d",&n,&k);
	string str1,str2;
	int tempW;
	int s1,s2;
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>tempW;
		if(mp.find(str1)!=mp.end()){
			s1 = mp[str1];
		}else{
			mp[str1]=num++;
			s1 = mp[str1];
		}
		M[s1].pw+=tempW;
		M[s1].name=str1;
		if(mp.find(str2)!=mp.end()){
			s2 = mp[str2];
		}else{
			mp[str2] = num++;
			s2 = mp[str2];
		}
		M[s2].pw+=tempW;
		M[s2].name=str2;
		join(s1,s2);
	}
	int gangNum = 0;
	map<int,int>ftg;
	vector<int>gangM[1005];;
	int gangSum[1005]={0};
	for(int i=0;i<num;i++){
		int tempFa = findFather(i);
		if(ftg.find(tempFa)==ftg.end()){
			ftg[tempFa]=gangNum++;
		}
		int gangId = ftg[tempFa];
		gangM[gangId].push_back(i);
		gangSum[gangId]+=M[i].pw;
	}
	vector<output>O;
	for(int i=0;i<gangNum;i++){
		if(gangM[i].size()>2&&gangSum[i]>2*k){
			tempO.quantity = gangM[i].size();
			int max = -1;
			int tempId;
			for(int j=0;j<gangM[i].size();j++){
				int temp = gangM[i][j];
				if(M[temp].pw>max){
					max = M[temp].pw;
					tempId = temp;
				}
			}
			tempO.head = tempId;
			O.push_back(tempO);
		}
	}
	sort(O.begin(),O.begin()+O.size(),cmp2);
	printf("%d\n",O.size());
	for(int i=0;i<O.size();i++){
		cout<<M[O[i].head].name<<" "<<O[i].quantity<<endl;
	}
	return 0;
}


////以下是以前写的
//#include<stdio.h> 
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<set> 
//#include<map>
//using namespace std;
//const int maxn = 2002;//1000通电话，最多有2000个人。 
//int father[maxn];
//int head[maxn];
//map<string,int>mp;
//map<int,string>mp2; 
//int findfather(int a)
//{
//	int x= a;
//	while(father[x]!=x)
//	{
//		x=father[x];
//	}
//	while(father[a]!=x)
//	{
//		int b =father[a];
//		father[a]=x;
//		a=b;
//	}
//	return x;
//}
//bool cmp(int a,int b)
//{
//	return mp2[head[a]]<mp2[head[b]];
//}
//int main()
//{
//	int n,k;
//	string str1,str2;
//	int len;
//	int lenth[maxn]={0};
//	int id=0;
//	for(int i=0;i<maxn;i++)
//	{
//		father[i]=i;
//	}
//	scanf("%d%d",&n,&k);
//	for(int i=0;i<n;i++)
//	{
//		cin>>str1>>str2>>len;
//		int id1,id2,fa1,fa2;
//		if(mp.find(str1)==mp.end())
//		{
//			mp[str1]=id++;
//		}
//		id1= mp[str1];
//		mp2[id1]=str1;
//		lenth[id1]+=len;
//		if(mp.find(str2)==mp.end())
//		{
//			mp[str2]=id++;
//		}
//		id2= mp[str2];
//		mp2[id2]=str2;
//		lenth[id2]+=len;
//		fa1 = findfather(id1);
//		fa2 = findfather(id2);
//		if(fa1!=fa2)
//		{
//			father[fa1]=fa2;
//		}
//	}
//	vector<int>ga;
//	vector<int>member[maxn]; 
//	bool flag[maxn]={false};
//	int totallen[maxn]={0};
//	for(int i=0;i<id;i++)
//	{
//		int temp = findfather(i);
//		member[temp].push_back(i);
//		totallen[temp]+=lenth[i];
//		if(flag[temp]==false&&member[temp].size()>2&&totallen[temp]>k*2)
//		{
//			ga.push_back(temp);
//			flag[temp]=true;
//		}
//	}
//	for(int i=0;i<ga.size();i++)
//	{
//		int temp =ga[i];
//		int maxgtime=-1;
//		for(int j=0;j<member[temp].size();j++)
//		{
//			int tempid = member[temp][j];
//			if(lenth[tempid]>maxgtime)
//			{
//				maxgtime=lenth[tempid];
//				head[temp]=tempid;
//			}
//		}
//	} 
//	sort(ga.begin(),ga.end(),cmp);
//	printf("%d\n",ga.size());
//	for(int i=0;i<ga.size();i++)
//	{
//		int temp =ga[i];
//		cout<<mp2[head[temp]]<<" "<<member[temp].size()<<endl;
//	}
//	return 0;
//} 

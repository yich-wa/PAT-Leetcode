//这道题不难，主要是麻烦。但是重复的动作蛮多的。多个分数，多个排名。
//注意最后平均分的优先级比较高。 
//可以在节点内设置得分数组，和排名数组。得到各科排名，
//在拿到每个学生的最佳排名和最佳科目。以及建立学号和数组编号的映射，便于查找 

#include<stdio.h>
#include<string.h> 
#include<algorithm>
#include<vector>
#include<map>
const int maxn = 2005;
using namespace std; 
struct student{
	int id;
	int score[4];
	int rank[6];
}tempS;
bool cmp0(student a,student b){
	return a.score[0]>b.score[0];
}
bool cmp1(student a,student b){
	return a.score[1]>b.score[1];
}
bool cmp2(student a,student b){
	return a.score[2]>b.score[2];
}
bool cmp3(student a,student b){
	return a.score[3]>b.score[3];
}
int main(){
	int n,m;
	vector<student>v;
	char course[4] = {'C','M','E','A'};
	map<int,int>mp;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&tempS.id,&tempS.score[0],&tempS.score[1],&tempS.score[2]);
		tempS.score[3] = (tempS.score[0]+tempS.score[1]+tempS.score[2])/3;
		v.push_back(tempS);
	}
	for(int i=0;i<4;i++){
		if(i==0){
			sort(v.begin(),v.begin()+v.size(),cmp0);
		}else if(i==1){
			sort(v.begin(),v.begin()+v.size(),cmp1);
		}else if(i==2){
			sort(v.begin(),v.begin()+v.size(),cmp2);
		}else{
			sort(v.begin(),v.begin()+v.size(),cmp3);
		}
		
		int lastRank = 0;
		int lastScore = -1;
		for(int j=0;j<v.size();j++){
			if(v[j].score[i]!=lastScore){
				lastScore = v[j].score[i];
				v[j].rank[i] = j+1;
				lastRank = j+1;
			}else{
				v[j].rank[i] = lastRank;
			}
		}
	}
	for(int i=0;i<v.size();i++){
		int bestRank = v[i].rank[3];
		int bestCourse = 3;
		for(int j=0;j<=2;j++){
			if(v[i].rank[j]<bestRank){
				bestRank = v[i].rank[j];
				bestCourse = j;
			}
		}
		v[i].rank[4] = bestRank;
		v[i].rank[5] = bestCourse;
		mp[v[i].id] = i;
	}
	int qId;
	for(int i=0;i<m;i++){
		scanf("%d",&qId);
		if(mp.find(qId)!=mp.end()){
			int tId = mp[qId];
			int cId = v[tId].rank[5];
			printf("%d %c\n",v[tId].rank[4],course[cId]);
		}else{
			printf("N/A\n");
		}
	}
	return 0;
} 


////以前写的。
// #include<stdio.h>
//#include<vector>
//#include<algorithm>
//#include<math.h>
//#include<map>
//using namespace std;
//const int maxn = 2005;
//struct student{
//	int id;
//	int cg;
//	int mg;
//	int eg;
//	int ag;
//	int arank;
//	int crank;
//	int mrank;
//	int erank;
//	int bestrank;
//	int bestid;
//}temp;
//vector<student>output;
//map<int,int>mp;
//bool cmp1(student a,student b)
//{
//	return a.ag>b.ag;
//}
//bool cmp2(student a,student b)
//{
//	return a.cg>b.cg;
//}
//bool cmp3(student a,student b)
//{
//	return a.mg>b.mg;
//}
//bool cmp4(student a,student b)
//{
//	return a.eg>b.eg;
//}
//int main()
//{
//	int n,m;
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d %d %d %d",&temp.id,&temp.cg,&temp.mg,&temp.eg);
//		temp.ag= (round)((double(temp.cg+temp.mg+temp.eg))/3);
//		//	printf("%d \n",temp.ag);
//		output.push_back(temp);
//	}
//	sort(output.begin(),output.end(),cmp1);
//	int lastscore =-1;int lastrank=1;
//	for(int i=0;i<output.size();i++)
//	{
//		if(output[i].ag==lastscore)
//		{
//			output[i].arank =lastrank;
//		}
//		else
//		{
//			lastscore = output[i].ag;
//			output[i].arank = i+1;
//			lastrank =i+1;
//		}
//	}
//	sort(output.begin(),output.end(),cmp2);
//	lastscore =-1;
//	lastrank=1;
//	for(int i=0;i<output.size();i++)
//	{
//		if(output[i].cg==lastscore)
//		{
//			output[i].crank =lastrank;
//		}
//		else
//		{
//			lastscore = output[i].cg;
//			output[i].crank = i+1;
//			lastrank =i+1;
//		}
//	}
//	sort(output.begin(),output.end(),cmp3);
//	lastscore =-1;lastrank=1;
//	for(int i=0;i<output.size();i++)
//	{
//		if(output[i].mg==lastscore)
//		{
//			output[i].mrank =lastrank;
//		}
//		else
//		{
//			lastscore = output[i].mg;
//			output[i].mrank = i+1;
//			lastrank =i+1;
//		}
//	}
//	sort(output.begin(),output.end(),cmp4);
//	lastscore =-1;lastrank=1;
//	for(int i=0;i<output.size();i++)
//	{
//		if(output[i].eg==lastscore)
//		{
//			output[i].erank =lastrank;
//		}
//		else
//		{
//			lastscore = output[i].eg;
//			output[i].erank = i+1;
//			lastrank =i+1;
//		}
//	}
//	for(int i=0;i<output.size();i++)
//	{
//		int b_rank =2006;
//		if(output[i].arank<b_rank)
//		{
//			b_rank =output[i].arank;
//			output[i].bestid = 0;
//		}
//		if(output[i].crank<b_rank)
//		{
//			b_rank =output[i].crank;
//			output[i].bestid = 1;
//		}
//		if(output[i].mrank<b_rank)
//		{
//			b_rank =output[i].mrank;
//			output[i].bestid = 2;
//		}
//		if(output[i].erank<b_rank)
//		{
//			b_rank =output[i].erank;
//			output[i].bestid = 3;
//		}
//		output[i].bestrank = b_rank;
//		mp[output[i].id]=i;  //表示id和编号之间的映射
//	}
//	int queryid;
//	char c[4]={'A','C','M','E'};
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",&queryid);
//		if(mp.find(queryid)==mp.end()) 
//			printf("N/A\n");
//		else
//		{
//			int num = mp[queryid];
//			printf("%d %c\n",output[num].bestrank,c[output[num].bestid]);
//		}
//	}
//	return 0;
//}

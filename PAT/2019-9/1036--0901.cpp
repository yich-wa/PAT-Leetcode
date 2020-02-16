//19:58--19:15 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
	char name[12];
	char Id[12];
	int grade;
}tempS;
bool cmp(student a, student b){
	return a.grade>b.grade;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<student>girl,boy;
	char gender[3];
	for(int i=0;i<n;i++){
		scanf("%s%s%s%d",tempS.name,gender,tempS.Id,&tempS.grade);
		if(gender[0]=='F'){
			girl.push_back(tempS);
		}else{
			boy.push_back(tempS);
		}
	}
	sort(girl.begin(),girl.begin()+girl.size(),cmp);
	sort(boy.begin(),boy.begin()+boy.size(),cmp);
	int hf =-1;
	int lm = -1;
	
	if(girl.size()!=0){
		printf("%s %s\n",girl[0].name,girl[0].Id);
		hf = girl[0].grade;
	}else{
		printf("Absent\n");
	}
	
	if(boy.size()!=0){
		int temp = boy.size()-1;
		printf("%s %s\n",boy[temp].name,boy[temp].Id);
		lm = boy[temp].grade;
	}else{
		printf("Absent\n"); 
	}
	
	if(hf==-1||lm==-1){
		printf("NA\n");
	}else{
		printf("%d",hf-lm);
	}
	return 0;
} 


//ÒÔÇ°Ð´µÄ
//#include<stdio.h>
//#include<algorithm>
//#include<iostream>
//#include<string.h>
//using namespace std;
//const int maxc =15;
//struct student{
//	char name[15];
//	char gender;
//	char id[15];
//	int score;
//}male,female,temp;
//int main()
//{
//	int n;
//	int mlowest=101;
//	int fhighest =-1;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%s",temp.name);
//		getchar();
//		scanf("%c",&temp.gender);
//		getchar();
//		scanf("%s",temp.id);
//		scanf("%d",&temp.score);
//		if(temp.gender=='M'&&temp.score<mlowest)
//		{
//			mlowest = temp.score;
//			strcpy(male.name,temp.name);
//			strcpy(male.id ,temp.id);	
//		}
//		if(temp.gender=='F'&&temp.score>fhighest)
//		{
//			fhighest = temp.score;
//			strcpy(female.name,temp.name);
//			strcpy(female.id ,temp.id);
//		}
//	}
//	if(fhighest<0)
//		printf("Absent\n");
//	else 
//		printf("%s %s\n",female.name,female.id);
//	if(mlowest>100)
//		printf("Absent\n");
//	else
//		printf("%s %s\n",male.name,male.id);
//	if(fhighest<0||mlowest>100)
//		printf("NA\n");
//	else
//		printf("%d\n",fhighest-mlowest);
//	return 0;	
// }  

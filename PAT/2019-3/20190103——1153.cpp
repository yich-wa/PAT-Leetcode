//PAT1153    初次做好多以前的细小知识点都忘记了。开始拿15分。
//最终找到两个错误点。**** 补到25分。 
//A  注意考虑问题要全面，一个是查询方式是对的，但是没有相应数据所以NA
//B 一个是同一类型的查询有多次，上一次查询完输出后，记得归零给下次同
//类查询做准备。 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10005;
const int maxm = 105;
const int maxs = 1001;
string card[maxn];
vector<int>L[4];  
//对第二种询问做出解答铺垫。 能在输入时就统计的查询，就是输入时搞定
//或者查询类型已知后，再遍历一遍，用vector去统计数据。 
struct testee{
	char level;
	string site;
	int sitenumber;
	string  date;
	string number;
	int score;
}T[maxn];

bool cmp1(int a,int b){
	if(T[a].score!=T[b].score)
		return T[a].score>T[b].score;
	else 
		return card[a]<card[b];  //string 是可以直接比较大小的。 
	}

struct testsite{
	int totalnumber ;
	int totalscore;	
}Testsite[maxs];
//将下列结构体初始化sitenum为0，siteid为角标序数。
bool  flag[maxs]={false};//表明是否初始化。 

struct datesite{ 
	int siteid;
	int sitenum;
}Datesite[maxs]; 
bool flag2[maxs]={false};  //表明是否初始化 

bool cmp2(datesite a,datesite b){
	if(a.sitenum!=b.sitenum)
		return a.sitenum>b.sitenum;
	else
		return a.siteid<b.siteid;	
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>> card[i]>>T[i].score;
		//scanf("%s",card[i]);  
		//string不能用scanf输入。 
		//scanf("%d",T[i].score);
		T[i].level = card[i][0];
		if(T[i].level=='T')
			L[0].push_back(i);
		else if(T[i].level=='A')
			L[1].push_back(i);
		else 
			L[2].push_back(i);
		T[i].site = card[i].substr(1,3);
		T[i].date = card[i].substr(4,6);
		T[i].number = card[i].substr(10,3);	
		sscanf(T[i].site.c_str(),"%d",&T[i].sitenumber); 
		//将字符串转化为数字。这个很常用 ，要熟练 
		//出现了C++的string到C的char数组的转换。 
		int sn = T[i].sitenumber;
		if(flag[sn]==false)
		{
			Testsite[sn].totalscore=Testsite[sn].totalnumber =0;
			flag[sn]=true;
		}
		Testsite[sn].totalscore+=T[i].score;
		Testsite[sn].totalnumber++;
	 } 
	 for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			char qlevel;
			getchar();
			scanf("%c",&qlevel);
			//单个'%c'是可以接收空格和换行的。所以要注意！！！ 
			printf("Case %d: 1 %c\n",i,qlevel);
			int q_id; 
			if(qlevel=='T')
			{
				q_id = 0;
			}
			else if(qlevel =='A')
			{
				q_id = 1;	
			}
			else if(qlevel =='B')
			{
				q_id = 2;
			}
			else 
			{
				printf("NA\n");
				continue;
			}
			sort(L[q_id].begin(),L[q_id].end(),cmp1);
			for(int j=0;j<L[q_id].size();j++)
			{
				int numid = L[q_id][j];
				cout<<card[numid]<<" "<<T[numid].score<<endl; 
			}	
			//经过对比网上答案知道还少下面这一步，这就是为什么只有15分的原因吧	
			//添上之后多了4分。 
			if(L[q_id].size()==0)
			printf("NA\n"); 
		}
		else if(k==2)
		{
			int tempsite;
			scanf("%d",&tempsite);
			printf("Case %d: 2 %d\n",i,tempsite);
			if(flag[tempsite]==false)  //若该地点没有发生过考试。 
			{
				printf("NA\n");
				continue;
			}
			printf("%d %d\n",Testsite[tempsite].totalnumber,Testsite[tempsite].totalscore);
		}
		else if(k==3)
		{
			string tempdate;
			cin>>tempdate;
			//要么建立结构体中再建结构体。
			//要么知道其要问什么之后，再通遍历一遍。这样子能更轻松些。 
			printf("Case %d: 3 ",i);
			cout<<tempdate<<endl; 
			//也可以将string 转化成C的字符数组，在用%s输出 
			memset(flag2,false,sizeof(flag2));
			bool isNA = false; 
			 //表明该日期内是否有测试者参加测试，若无，即为特殊情况，
			 //所以输出NA。 
			 //将结果都存入vector中，在排序，常用套路。
			 //****第三种情况，你同时进行两次第三次查询时，第二次显示的
			 //是第一次的结果。 所以是Datesite数组没有初始化。 
			for(int h = 0;h<n;h++)
			{
				if(T[h].date == tempdate)
				{	
					isNA = true;
					int tempsn = T[h].sitenumber;
					if(flag2[tempsn]==false)
					{
						Datesite[tempsn].sitenum=0;
						Datesite[tempsn].siteid=tempsn;
						flag2[tempsn]=true; 
					}
					Datesite[tempsn].sitenum++;
				 } 
			} 
			if(isNA==false)
			{
				printf("NA\n");
				continue;
			}
			sort(Datesite+100,Datesite+maxs,cmp2);
			for(int j=100;j<maxs;j++)
			{
				if(Datesite[j].sitenum>0)
				{ 
				printf("%d %d\n",Datesite[j].siteid,Datesite[j].sitenum);
				//输出之后，要对数据归零，方便下次查询。开始没有注意到这一点。 
				//这个改完之后又多了5分，两个测试点。 
				Datesite[j].siteid =0; 
				Datesite[j].sitenum =0; 
				} 
			}
		} 
	}
	return 0;		 	 
}

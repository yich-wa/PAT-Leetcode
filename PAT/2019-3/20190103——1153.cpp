//PAT1153    �������ö���ǰ��ϸС֪ʶ�㶼�����ˡ���ʼ��15�֡�
//�����ҵ���������㡣**** ����25�֡� 
//A  ע�⿼������Ҫȫ�棬һ���ǲ�ѯ��ʽ�ǶԵģ�����û����Ӧ��������NA
//B һ����ͬһ���͵Ĳ�ѯ�ж�Σ���һ�β�ѯ������󣬼ǵù�����´�ͬ
//���ѯ��׼���� 
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
//�Եڶ���ѯ����������̵档 ��������ʱ��ͳ�ƵĲ�ѯ����������ʱ�㶨
//���߲�ѯ������֪���ٱ���һ�飬��vectorȥͳ�����ݡ� 
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
		return card[a]<card[b];  //string �ǿ���ֱ�ӱȽϴ�С�ġ� 
	}

struct testsite{
	int totalnumber ;
	int totalscore;	
}Testsite[maxs];
//�����нṹ���ʼ��sitenumΪ0��siteidΪ�Ǳ�������
bool  flag[maxs]={false};//�����Ƿ��ʼ���� 

struct datesite{ 
	int siteid;
	int sitenum;
}Datesite[maxs]; 
bool flag2[maxs]={false};  //�����Ƿ��ʼ�� 

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
		//string������scanf���롣 
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
		//���ַ���ת��Ϊ���֡�����ܳ��� ��Ҫ���� 
		//������C++��string��C��char�����ת���� 
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
			//����'%c'�ǿ��Խ��տո�ͻ��еġ�����Ҫע�⣡���� 
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
			//�����Ա����ϴ�֪������������һ���������Ϊʲôֻ��15�ֵ�ԭ���	
			//����֮�����4�֡� 
			if(L[q_id].size()==0)
			printf("NA\n"); 
		}
		else if(k==2)
		{
			int tempsite;
			scanf("%d",&tempsite);
			printf("Case %d: 2 %d\n",i,tempsite);
			if(flag[tempsite]==false)  //���õص�û�з��������ԡ� 
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
			//Ҫô�����ṹ�����ٽ��ṹ�塣
			//Ҫô֪����Ҫ��ʲô֮����ͨ����һ�顣�������ܸ�����Щ�� 
			printf("Case %d: 3 ",i);
			cout<<tempdate<<endl; 
			//Ҳ���Խ�string ת����C���ַ����飬����%s��� 
			memset(flag2,false,sizeof(flag2));
			bool isNA = false; 
			 //�������������Ƿ��в����߲μӲ��ԣ����ޣ���Ϊ���������
			 //�������NA�� 
			 //�����������vector�У������򣬳�����·��
			 //****�������������ͬʱ�������ε����β�ѯʱ���ڶ�����ʾ��
			 //�ǵ�һ�εĽ���� ������Datesite����û�г�ʼ���� 
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
				//���֮��Ҫ�����ݹ��㣬�����´β�ѯ����ʼû��ע�⵽��һ�㡣 
				//�������֮���ֶ���5�֣��������Ե㡣 
				Datesite[j].siteid =0; 
				Datesite[j].sitenum =0; 
				} 
			}
		} 
	}
	return 0;		 	 
}

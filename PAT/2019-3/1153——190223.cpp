//09:50 ����
//������ѵĻ������������ĸо�ȥ��������һ���֣�������һ���֡�
//�����ǱȽϸ��ӵ������⡣ 
// ����11:28�� 22�֡��� ��4���Ե� ����ʱ����3�֡� 
//��������⣬Ҫ���������������
//��ȥ��Ϥ���ϵ����򡢱����������
//���򴫲Σ����������ô��Ρ��������졣                               
#include<stdio.h> 
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 10004;
const int maxs = 1001;
const int maxm = 105;
vector<int>input[3];
vector<int>s[maxs];
int s2[maxs]={0};
int sitescore[maxs]={0};
map<int,bool>exist;
map<string,int>dateId;
vector<int>dateset[maxm];
struct testee{
	string id;
	int score;
	int date;
	int site;	
}T[maxn];
bool cmp(int a,int b)
{
	if(T[a].score!=T[b].score)
		return T[a].score>T[b].score;
	else
	 	return T[a].id<T[b].id;
}
bool cmp2(int a,int b)
{
	if(s2[a]!=s2[b])
		return s2[a]>s2[b];
	else
		return a<b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	string str;
	string sitestr;
	string datestr;
	int tempsite,tempdate;
	int date_numId =0;
	for(int i=0;i<n;i++)
	{
		cin>>str>>T[i].score;
		T[i].id = str;
		if(str[0]=='T')
		{
			input[0].push_back(i);
		}
		else if(str[0]=='A')
		{
			input[1].push_back(i);
		}
		else
		{
			input[2].push_back(i);
		}
		sitestr = str.substr(1,3);
		sscanf(sitestr.c_str(),"%d",&tempsite);
		T[i].site = tempsite;
		s[tempsite].push_back(i);
		sitescore[tempsite]+=T[i].score;
		datestr = str.substr(4,6);
		int temp_date_Id;
		//���������Ա�š�
		if(dateId.find(datestr)!=dateId.end())  
		{
			temp_date_Id = dateId[datestr]; 
		}
		else
		{
			temp_date_Id = date_numId;
			dateId[datestr]=date_numId++; 
		}
		dateset[temp_date_Id].push_back(i);
	}
	int type;
	string tempstr;
	for(int i=1;i<=m;i++)
	{
		cin>>type>>tempstr;
		cout<<"Case "<<i<<":"<<" "<<type<<" "<<tempstr<<endl;
		if(type==1)
		{
			int term;
			if(tempstr[0]=='T')
				term = 0;
			else if(tempstr[0]=='A')
				term = 1;
			else
				term = 2;
			if(input[term].size()==0)
			{
				printf("NA\n");
				continue;
			}		
			sort(input[term].begin(),input[term].end(),cmp);
			int len = input[term].size();
			for(int j=0;j<len;j++)
			{
				cout<<T[input[term][j]].id<<" "<<T[input[term][j]].score<<endl; 
			}
		}
		else if(type ==2)
		{
			sscanf(tempstr.c_str(),"%d",&tempsite);
			int totalscore =0;
			int len = s[tempsite].size();
			if(len ==0)
			{
				printf("NA\n");
				continue;
			}
			else
				printf("%d %d\n",len,sitescore[tempsite]);
		}
		else 
		{
			if(dateId.find(tempstr)==dateId.end())
			{
				printf("NA\n");
				continue;
			}
			int temp_date_Id = dateId[tempstr];
			int len = dateset[temp_date_Id].size();
			fill(s2,s2+maxs,0);
			vector<int>output; 
			for(int j=0;j<len;j++)
			{
				int tempId = dateset[temp_date_Id][j];
				tempsite = T[tempId].site;
				s2[tempsite]++;
				output.push_back(tempsite);
			}
			sort(output.begin(),output.end(),cmp2);
			int lenO = output.size();
			int lastsite = -1;
			for(int j=0;j<lenO;j++)
			{
				if(output[j]!=lastsite)
				{
					printf("%d %d\n",output[j],s2[output[j]]);
					lastsite = 	output[j];
				}	
			}
		}
	}
	return 0;
}

//�����Ǿ䣬�ⲻ�ѣ��������ȣ��Ⱦ��ǿ졣���岽�衣
//ÿһ����д��������ν���Ⱦ��Ǵ�����д�����������ڵ�һ�����ͼ�����
//mapҲҪʹ��������//��ʼ�ĵͼ������������ʧ15�������ҡ� 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
const int maxn = 2005;
struct student{
	int id;
	int cg;
	int mg;
	int eg;
	int ag;
	int arank;
	int crank;
	int mrank;
	int erank;
	int bestrank;
	int bestid;
}temp;
vector<student>output;
map<int,int>mp;
bool cmp1(student a,student b)
{
	return a.ag>b.ag;
}
bool cmp2(student a,student b)
{
	return a.cg>b.cg;
}
bool cmp3(student a,student b)
{
	return a.mg>b.mg;
}
bool cmp4(student a,student b)
{
	return a.eg>b.eg;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&temp.id,&temp.cg,&temp.mg,&temp.eg);
		temp.ag= (round)((double(temp.cg+temp.mg+temp.eg))/3);
		//	printf("%d \n",temp.ag);
		output.push_back(temp);
	}
	sort(output.begin(),output.end(),cmp1);
	int lastscore =-1;int lastrank=1;
	for(int i=0;i<output.size();i++)
	{
		if(output[i].ag==lastscore)
		{
			output[i].arank =lastrank;
		}
		else
		{
			lastscore = output[i].ag;
			output[i].arank = i+1;
			lastrank =i+1;
		}
	}
	sort(output.begin(),output.end(),cmp2);
	lastscore =-1;
	lastrank=1;
	for(int i=0;i<output.size();i++)
	{
		if(output[i].cg==lastscore)
		{
			output[i].crank =lastrank;
		}
		else
		{
			lastscore = output[i].cg;
			output[i].crank = i+1;
			lastrank =i+1;
		}
	}
	sort(output.begin(),output.end(),cmp3);
	lastscore =-1;lastrank=1;
	for(int i=0;i<output.size();i++)
	{
		if(output[i].mg==lastscore)
		{
			output[i].mrank =lastrank;
		}
		else
		{
			lastscore = output[i].mg;
			output[i].mrank = i+1;
			lastrank =i+1;
		}
	}
	sort(output.begin(),output.end(),cmp4);
	lastscore =-1;lastrank=1;
	for(int i=0;i<output.size();i++)
	{
		if(output[i].eg==lastscore)
		{
			output[i].erank =lastrank;
		}
		else
		{
			lastscore = output[i].eg;
			output[i].erank = i+1;
			lastrank =i+1;
		}
	}
	for(int i=0;i<output.size();i++)
	{
		int b_rank =2006;
		if(output[i].arank<b_rank)
		{
			b_rank =output[i].arank;
			output[i].bestid = 0;
		}
		if(output[i].crank<b_rank)
		{
			b_rank =output[i].crank;
			output[i].bestid = 1;
		}
		if(output[i].mrank<b_rank)
		{
			b_rank =output[i].mrank;
			output[i].bestid = 2;
		}
		if(output[i].erank<b_rank)
		{
			b_rank =output[i].erank;
			output[i].bestid = 3;
		}
		output[i].bestrank = b_rank;
		mp[output[i].id]=i;  //��ʾid�ͱ��֮���ӳ��
	}
	int queryid;
	char c[4]={'A','C','M','E'};
	for(int i=0;i<m;i++)
	{
		scanf("%d",&queryid);
		if(mp.find(queryid)==mp.end()) 
			printf("N/A\n");
		else
		{
			int num = mp[queryid];
			printf("%d %c\n",output[num].bestrank,c[output[num].bestid]);
		}
	}
	return 0;
}

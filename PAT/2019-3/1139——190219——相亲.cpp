//09:17����10:45 22�֡���1���Ե㣬�𰸴���
//��5���Ե����г�ʱ�� 
// 
//��ʼ���м���ϸ�ڴ������Ĺ����ˡ����������ƵĴ��븴�ƣ�
//����Ҫ��ȫ����Ҫ����һ���֣� ���ͨ�����˺ܶ�printf������ˡ� 

//�ṹ���ʵ�������������ʵ������bridge a = new bridge;����
//���ԣ�ֱ�� bridge a;���ɡ� 

//����������ѯ����֪�����ܴ���0000��-0000 ����������Ǹ���
//���޷������Ĵ�С���жϣ�����С�ڻ��Ǵ����㡣�Ӹ�Ԥ�����ơ�
//�������1���Ե���ˡ�26�֡���һ���Ե�4�֡� 

// ������Ե㳬ʱ����Ӧ�ÿ����ǲ�������ʱ����������״̬��
//���ߣ������ʵ���֦�� 
//�𰸴����ã���A������C��B������D�оٳ������������ǲ�������
//�ǵĻ����ͷ���������С�
//���Լ��õ���������������ķ�����  
// �ж�CD�ǲ������ѵ�ʱ���ö�ά�����ܻᳬʱ�����Կ����ù�ϣ��
//����map<int,bool>mp ; map[C*10000+D]=true;�Լ�map[D*100000+C]=true
//����������ʽ�ӱ�ʾCD�����ѡ� 
//������һ�¡��о��ɻ��С� 25�ֵ�4��5���Ե����

// ����������Ҫ��������Ĵ��� 
//�ų� A==D||B==C ���30�֡� �м��ǻ�Ĺ�ϵ��ע���м��ǻ�Ĺ�ϵ�� 
//�����30�� 
//����������������鷳�ܶࡣ
//��ʵһ��ʼ���ڽӱ���¼����ʱ����ʱֻ��Ҫ��¼ͬ�����ѡ� 
//����˼·Ҳ����ӽ���Ŀԭ��Ľ���˼·�����׵����⡣ 
// 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<map> 
using namespace std;
const int maxn = 305;
const int maxk = 10001;
struct bridge{
	int fir;
	int sec;
}tempBridge;
vector<int>tempB;
vector<bridge>B;
vector<int>friShip[maxk];
map<int,bool>mp; 
int gender[maxk]={0};
bool isvisit[maxk]={false};
int target; 
bool cmp(bridge a,bridge b)
{
	if(a.fir!=b.fir)
		return a.fir<b.fir;
	else
		return a.sec<b.sec;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char str1[6];
	char str2[6]; 
	int temp1,temp2;
	for(int i=0;i<m;i++)
	{
		scanf("%s%s",str1,str2);
		sscanf(str1,"%d",&temp1);
		if(strlen(str1)==4)
			gender[temp1]=1;
		sscanf(str2,"%d",&temp2); 
		if(strlen(str2)==4)
			gender[temp2]=1;
		friShip[abs(temp1)].push_back(abs(temp2));
		friShip[abs(temp2)].push_back(abs(temp1));
		temp1=abs(temp1);
		temp2 = abs(temp2);
		mp[temp1*10000+temp2]=mp[temp2*10000+temp1]=true;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		B.clear(); 
		temp1 = abs(temp1);
		temp2 = abs(temp2);
		int len1 =friShip[temp1].size();
		int len2 =friShip[temp2].size();
		for(int j=0;j<len1;j++)
		{
			for(int h=0;h<len2;h++)
			{
				int C = friShip[temp1][j];
				int D = friShip[temp2][h];
				//A��C�Ա�һ����ͬ��B��D�Ա�һ����ͬ�� 
				if(gender[temp1]==gender[C]&&gender[temp2]==gender[D]) 
				{
					if(gender[temp1]==gender[temp2])//ͬ�� 
					{
						if(C==temp2||D==temp1)
							continue;
						else if(mp[C*10000+D]==true)
						{
							bridge a;
							a.fir =C;
							a.sec =D;
							B.push_back(a);
						}
					}
					else//���ԡ� 
					{
						if(mp[C*10000+D]==true)
						{
							bridge a;
							a.fir =C;
							a.sec =D;
							B.push_back(a);
						}
					}	
				}
			}
		}
		sort(B.begin(),B.end(),cmp);
		int len =B.size();
		printf("%d\n",len);
		for(int i=0;i<len;i++)
		{
			printf("%04d %04d\n",B[i].fir,B[i].sec);
		}
	}
	return 0;		
}

//������ǣ�������������棬��26�֣���4�ֳ�ʱ�� 
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//#include<math.h>
//using namespace std;
//const int maxn = 305;
//const int maxk = 10001;
//struct bridge{
//	int fir;
//	int sec;
//}tempBridge;
//vector<int>tempB;
//vector<bridge>B;
//vector<int>friShip[maxk]; 
//int gender[maxk]={0};
//bool isvisit[maxk]={false};
//int target;
//int fitNumber; 
//void oppoLoveDFS(int id,int depth)
//{
//	int len = friShip[id].size();
//	for(int i=0;i<len;i++)
//	{
//		int temp = friShip[id][i];
//		if(isvisit[temp]==false)
//		{
//			if((depth==3&&gender[id]==gender[temp])||(depth==2&&(gender[id]+gender[temp]==1)))
//			{
//				isvisit[temp]=true;
//				tempB.push_back(temp);
//				oppoLoveDFS(temp,depth-1);
//				tempB.pop_back();
//				isvisit[temp]=false;	
//			}
//			else if(depth==1&&gender[id]==gender[temp]&&temp==target)
//			{
//				bridge a;
//				a.fir = tempB[0];
//				a.sec = tempB[1];
//				B.push_back(a); 
////				tempBridge.fir = tempB[0];
////				tempBridge.sec = tempB[1];
////				B.push_back(tempBridge);
//				//return;
//			}	
//		}
//	}	
//}
//void sameLoveDFS(int id,int depth)
//{
//	int len = friShip[id].size();
//	for(int i=0;i<len;i++)
//	{
//		int temp = friShip[id][i];
//		//printf("%d****����**\n",temp);
//		if(isvisit[temp]==false&&(gender[id]==gender[temp]))
//		{
//			//printf("%d****����\n",temp);
//			if(depth==1&&temp==target)
//			{
//				//bridge a= new bridge;
//				tempBridge.fir = tempB[0];
//				tempBridge.sec = tempB[1];
//				B.push_back(tempBridge);
//				//return;
//			}
//			else if(depth==3||depth==2)
//			{
//				isvisit[temp]=true;
//				//printf("%d****%d\n",temp,depth);
//				tempB.push_back(temp);
//				//��������Ļ��õ��ǣ�oppoLoveDFS(); 
//				sameLoveDFS(temp,depth-1);
//				tempB.pop_back();
//				isvisit[temp]=false;	
//			}
//			//��ʼ��������ģ������ˡ���Ϊ��
//			//depth==1ʱ������һ������ͷ����ˡ�Ӧ��ȫ�������ꡣ 
////			else
////				return;		
//		}
//	}	
//}
//bool cmp(bridge a,bridge b)
//{
//	if(a.fir!=b.fir)
//		return a.fir<b.fir;
//	else
//		return a.sec<b.sec;
//}
//int main()
//{
//	int n,m;
//	scanf("%d%d",&n,&m);
//	char str1[6];
//	char str2[6]; 
//	int temp1,temp2;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%s%s",str1,str2);
//		sscanf(str1,"%d",&temp1);
//		if(strlen(str1)==4)
//			gender[temp1]=1;
//		sscanf(str2,"%d",&temp2); 
//		if(strlen(str2)==4)
//			gender[temp2]=1;
//		friShip[abs(temp1)].push_back(abs(temp2));
//		friShip[abs(temp2)].push_back(abs(temp1));
//	}
//	int k;
//	scanf("%d",&k);
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d%d",&temp1,&temp2);
//		fill(isvisit,isvisit+maxk,false);
//		B.clear();
//		fitNumber = 0;
//		target=abs(temp2);
//		isvisit[abs(temp1)]=true;
//		if(temp1*temp2<0)
//		{
//			oppoLoveDFS(abs(temp1),3);
//		}
//		else
//		{
//			sameLoveDFS(abs(temp1),3);
//		}
//		sort(B.begin(),B.end(),cmp);
//		int len =B.size();
//		printf("%d\n",len);
//		for(int i=0;i<len;i++)
//		{
//			printf("%04d %04d\n",B[i].fir,B[i].sec);
//		}
//	}
//	return 0;		
//}

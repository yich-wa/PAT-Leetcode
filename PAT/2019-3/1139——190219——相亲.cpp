//09:17——10:45 22分。第1测试点，答案错误
//第5测试点运行超时。 
// 
//开始是有几个细节错误。最后改过来了。尤其是类似的代码复制，
//更改要改全。不要改了一部分； 最后通过加了很多printf解出来了。 

//结构体的实例化，到底如何实例化。bridge a = new bridge;对吗？
//不对，直接 bridge a;即可。 

//经过上网查询，可知：可能存在0000和-0000 ，如果输入那个，
//你无法从数的大小上判断，其是小于还是大于零。加个预防机制。
//改正后第1测试点对了。26分。第一测试点4分。 

// 第五测试点超时，你应该看看是不是搜索时，进入无穷状态。
//或者，考虑适当剪枝。 
//答案大多采用，将A的朋友C和B的朋友D列举出来，看他们是不是朋友
//是的话，就放入输出队列。
//你自己用的是深度优先搜索的方法。  
// 判断CD是不是朋友的时候用二维数可能会超时，可以考虑用哈希法
//建立map<int,bool>mp ; map[C*10000+D]=true;以及map[D*100000+C]=true
//用以上两个式子表示CD是朋友。 
//改造了一下。感觉可还行。 25分第4、5测试点错误。

// 这种做法需要避免下面的错误。 
//排除 A==D||B==C 后得30分。 中间是或的关系。注意中间是或的关系。 
//改完后30分 
//这题用深度优先是麻烦很多。
//其实一开始用邻接表法记录朋友时，其时只需要记录同性朋友。 
//这种思路也是最接近题目原意的解题思路。相亲的例题。 
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
				//A和C性别一定相同。B和D性别一定相同。 
				if(gender[temp1]==gender[C]&&gender[temp2]==gender[D]) 
				{
					if(gender[temp1]==gender[temp2])//同性 
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
					else//异性。 
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

//下面的是：深度优先搜索版，得26分，有4分超时。 
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
//		//printf("%d****——**\n",temp);
//		if(isvisit[temp]==false&&(gender[id]==gender[temp]))
//		{
//			//printf("%d****——\n",temp);
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
//				//发现下面的还用的是：oppoLoveDFS(); 
//				sameLoveDFS(temp,depth-1);
//				tempB.pop_back();
//				isvisit[temp]=false;	
//			}
//			//开始加了下面的，出错了。因为在
//			//depth==1时，遇到一个错误就返回了。应该全部遍历完。 
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

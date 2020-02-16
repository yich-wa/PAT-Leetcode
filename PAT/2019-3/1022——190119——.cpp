//21:39——

//——22:43  样例过了。
// 纠正小细节后是 25分。还有5分运行时错误。 
//尽量将统一的操作用数组代替，即减少重复代码。
//找相似之处，尽量统一，简化。 

//书中答案很有学习的意义
//书中用的是set,set具有自动去重，排序功能。
//map<string,set<int> > string 到set的映射 set的遍历你也要清晰
//set<int>::iterator it = mp["mike"].begin();it!=mp["mike"].end();it++
//实际值是 "*it"  *在前面。 

//柳诺对关键字的切分值得学习
//输入一行内的关键字。 

//while(cin>>tkey)
//{
//	key[tkey].insert(id);
//	char c = getchar();
//	if(c=='\n')
//		break;
// } 

//其二：关键字如何读入。用cin读入。再去接收空格或者换行，换行挑出。
 
////但整体思路和答案一致，不清楚为什么，那5分运行时错误。 
//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<map>
//using namespace std;
//const int maxn =1005;
//void out(vector<int> &a)
//{
//	for(int i=0;i<a.size();i++)
//	{
//		printf("%07d\n",a[i]);
//	}
//	return ;
//}
//int main()
//{
//	vector<int>name[maxn];
//	vector<int>author[maxn];
//	vector<int>key[maxn];
//	vector<int>pub[maxn];
//	vector<int>year[maxn];
//	int st[6]={0};
//	map<string,int>mp[6]; 
//	int n;
//	scanf("%d",&n);
//	int id;
//	string str;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&id);
//		getchar();
//		for(int j=1;j<=5;j++)
//		{
//			getline(cin,str);
//			if(j==3)
//			{
//				str=str+" ";
//				for(int k =0;k<str.length();)
//				{
//					string word;
//					while(str[k]!=' ') 
//					{
//						word+=str[k]; 
//						k++;
//					}
//					k++;
//					if(mp[j].find(word)==mp[j].end())
//					{
//						mp[j][word]=st[j]++;	
//					}
//					int temp = mp[j][word];
//					key[temp].push_back(id);
//				}
//			}
//			else
//			{
//				if(mp[j].find(str)==mp[j].end())
//				{
//					mp[j][str]=st[j]++;	
//				}
//				int temp = mp[j][str];
//				if(j==1)
//				{
//					name[temp].push_back(id);
//				}
//				else if(j==2)
//				{
//					author[temp].push_back(id);
//				}
//				else if(j==4)
//				{
//					pub[temp].push_back(id);
//				 } 
//				else if(j==5)
//				{
//					year[temp].push_back(id);
//				}
//			}	
//		}
//	 }
//	 int m;
//	 scanf("%d",&m);
//	 getchar();
//	 for(int i=0;i<m;i++)
//	 {
//	 	getline(cin,str);
//	 	cout<<str<<endl; 
//	 	int temp = str[0]-'0';
//	 	str.erase(0,3);
//	 	if(mp[temp].find(str)==mp[temp].end())
//		 {
//		 	printf("Not Found\n");
//		}	 	
//		else
//		{
//			int tempid = mp[temp][str];
//			if(temp==1)
//			{
//				sort(name[tempid].begin(),name[tempid].end());
//				out(name[tempid]);
//			}
//			else if(temp ==2)
//			{
//				sort(author[tempid].begin(),author[tempid].end());
//				out(author[tempid]);
//			}
//			else if(temp==3)
//			{
//				sort(key[tempid].begin(),key[tempid].end());
//				out(key[tempid]);
//			}
//			else if(temp==4)
//			{
//				sort(pub[tempid].begin(),pub[tempid].end());
//				out(pub[tempid]);
//			}
//			else if(temp==5)
//			{
//				sort(year[tempid].begin(),year[tempid].end());
//				out(year[tempid]);
//			}
//		}
//	 }
//	 return 0;
// } 
 
 
//柳诺做法，更加简洁写。 
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
//带上 &这样会减少参数传递时间。 
//下面两个  > > 之间是有空格的。 
void query(map<string, set<int> > &m, string &str) {
  	if(m.find(str) != m.end()) {
 	for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
 		printf("%07d\n", *it);
 	} 
	else
 		cout << "Not Found\n";
}
int main() {
	 int n, m, id, num;
	 scanf("%d", &n);
	 string ttitle, tauthor, tkey, tpub, tyear;
	 for(int i = 0; i < n; i++) {
		 scanf("%d\n", &id);
		 getline(cin, ttitle);
		 title[ttitle].insert(id);
		 getline(cin, tauthor);
		 author[tauthor].insert(id);
		 //下面的代码非常经典。 
		 while(cin >> tkey) {
			 key[tkey].insert(id);
			 char c = getchar();
			 if(c == '\n') break;
		 }
		 
		 getline(cin, tpub);
		 pub[tpub].insert(id);
		 getline(cin, tyear);
		 year[tyear].insert(id);
	}
 	scanf("%d", &m);
 	for(int i = 0; i < m; i++) {
		 scanf("%d: ", &num);
		 string temp;
		 getline(cin, temp);
		 cout << num << ": " << temp << "\n";
		 if(num == 1) query(title, temp);
		 else if(num == 2) query(author, temp);
		 else if(num == 3) query(key, temp);
		 else if(num == 4) query(pub,temp);
		 else if(num ==5) query(year, temp);
 	}
 return 0;
}

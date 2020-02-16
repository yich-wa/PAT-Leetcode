//9:07 --10:40； 用map<string,vector<int> >mp。设置多个映射。
//如何输入一行字符，又通过空格进行拆分。然后放到子串中
//上面的命题请看下面以前的写法。里面拆分比较简洁。 
//子串是：substr(pos,len)后面是长度。不是截止位置。
//输入整数后，在输入一行。需要用getchar()吸收 换行符。即使整数是用cin输入的
//题目比较复杂，请认真写，认真debug。 
 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
const int maxn = 10005;
map<string,vector<int> >mpTitle,mpAuthor,mpKey,mpPublisher,mpYear;
int main(){
	int n,m;
	scanf("%d",&n);
	getchar();
	int id;
	string title,author,keyWords,publisher,pubYear;
	for(int i=0;i<n;i++){
		cin>>id;
		getchar();
		getline(cin,title);
		mpTitle[title].push_back(id);
		getline(cin,author);
		mpAuthor[author].push_back(id);
		getline(cin,keyWords);
		string sKey;
		int st = 0;
		for(int j=0;j<keyWords.size();){
			while(keyWords[j]!=' '&&j<keyWords.size()){
				j++;
			}
			if(j==keyWords.size()){
				//substr(pos,len); 
				sKey = keyWords.substr(st,j-st);
				mpKey[sKey].push_back(id);
				break;	
			}
			sKey = keyWords.substr(st,j-st);
			mpKey[sKey].push_back(id);
			st = j+1;
			j++;
			
		}	
		getline(cin,publisher);
		mpPublisher[publisher].push_back(id);
		getline(cin,pubYear);
		mpYear[pubYear].push_back(id);	
	}
	scanf("%d",&m);
	getchar();
	string query;
	string qStr;
	for(int i=0;i<m;i++){
		getline(cin,query);
		cout<<query<<endl;
		int len = query.size();
		qStr = query.substr(3,len);
		int qId = query[0] - '0';
		if(qId == 1){
			if(mpTitle.find(qStr)!=mpTitle.end()){
				sort(mpTitle[qStr].begin(),mpTitle[qStr].begin()+mpTitle[qStr].size());
				for(int j=0;j<mpTitle[qStr].size();j++){
					printf("%07d\n",mpTitle[qStr][j]);
				}
			}else{
				printf("Not Found\n");
			}	
		}else if(qId ==2){
			if(mpAuthor.find(qStr)!=mpAuthor.end()){
				sort(mpAuthor[qStr].begin(),mpAuthor[qStr].begin()+mpAuthor[qStr].size());
				for(int j=0;j<mpAuthor[qStr].size();j++){
					printf("%07d\n",mpAuthor[qStr][j]);
				}
			}else{
				printf("Not Found\n");
			}
		}else if(qId ==3){
			if(mpKey.find(qStr)!=mpKey.end()){
				sort(mpKey[qStr].begin(),mpKey[qStr].begin()+mpKey[qStr].size());
				for(int j=0;j<mpKey[qStr].size();j++){
					printf("%07d\n",mpKey[qStr][j]);
				}
			}else{
				printf("Not Found\n");
			}
		}else if(qId ==4){
			if(mpPublisher.find(qStr)!=mpPublisher.end()){
				sort(mpPublisher[qStr].begin(),mpPublisher[qStr].begin()+mpPublisher[qStr].size());
				for(int j=0;j<mpPublisher[qStr].size();j++){
					printf("%07d\n",mpPublisher[qStr][j]);
				}
			}else{
				printf("Not Found\n");
			}
		}
		else if(qId ==5){
			if(mpYear.find(qStr)!=mpYear.end()){
				sort(mpYear[qStr].begin(),mpYear[qStr].begin()+mpYear[qStr].size());
				for(int j=0;j<mpYear[qStr].size();j++){
					printf("%07d\n",mpYear[qStr][j]);
				}
			}else{
				printf("Not Found\n");
			}
		}
	}
	return 0;
} 

////以前做的
//#include <iostream>
//#include <map>
//#include <set>
//using namespace std;
//map<string, set<int> > title, author, key, pub, year;
//void query(map<string, set<int> > &m, string &str) {
//  	if(m.find(str) != m.end()) {
// 	for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
// 		printf("%07d\n", *it);
// 	} 
//	else
// 		cout << "Not Found\n";
//}
//int main() {
//	 int n, m, id, num;
//	 scanf("%d", &n);
//	 string ttitle, tauthor, tkey, tpub, tyear;
//	 for(int i = 0; i < n; i++) {
//		 scanf("%d\n", &id);
//		 getline(cin, ttitle);
//		 title[ttitle].insert(id);
//		 getline(cin, tauthor);
//		 author[tauthor].insert(id);
//		 while(cin >> tkey) {
//			 key[tkey].insert(id);
//			 char c = getchar();
//			 if(c == '\n') break;
//		 }
//		 getline(cin, tpub);
//		 pub[tpub].insert(id);
//		 getline(cin, tyear);
//		 year[tyear].insert(id);
//	 }
// 	scanf("%d", &m);
// 	for(int i = 0; i < m; i++) {
//		 scanf("%d: ", &num);
//		 string temp;
//		 getline(cin, temp);
//		 cout << num << ": " << temp << "\n";
//		 if(num == 1) query(title, temp);
//		 else if(num == 2) query(author, temp);
//		 else if(num == 3) query(key, temp);
//		 else if(num == 4) query(pub,temp);
//		 else if(num ==5) query(year, temp);
// 	}
// return 0;
//} 

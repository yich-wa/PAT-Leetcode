//15:44����
///��һ��д�ꡣ 
///д��������е����֣�ȫ���������һ�������ַ�����
//��vector<char*>v ��������ġ� ���ͬһ��char temp[] ����һ�Σ�ѹ��
//��������һ�Ρ��������������е��ַ������������һ�������Ǹ��� 
//��Ϊchar ���飬��¼���ǣ��ַ������׵�ַ������ַ�����ǲ���ġ� 

//�ĳ�string ����21�� ��5�����г�ʱ�������Ϊʲô������������д��ĸ��
//һ�����ֵ�ԭ��ɡ�������ӳ��İɡ�  

////��vector<char*>v�Ĵ���д��������ԭ�򡣼��ϡ�
//������������ַ������顣�����ִ洢������Ȼ���ýǱ�ȥ�������ɡ�
//����ýǱ�ȥ�Ҷ�Ӧ�ַ����� �н�Ϊ�򵥵ķ�ʽ�����ü򵥵ķ�ʽ��
// 
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxk = 2505;
const int maxn = 40005;
char name[maxn][5]; 
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int c;
	int tempC;
	
	vector<int>course[maxk];
	for(int i=0;i<n;i++){
		char tempN[5];
		scanf("%s %d",name[i],&c);
		for(int j=0;j<c;j++){
			scanf("%d",&tempC);
			course[tempC].push_back(i);
		}
	} 
	for(int i=1;i<=k;i++){
		sort(course[i].begin(),course[i].begin()+course[i].size(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
} 





////string�����ᳬʱ4���ӡ� 
//#include<stdio.h>
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//const int maxn = 2505;
//bool cmp(string a,string b){
//	return a<b;
//}
//int main(){
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int c;
//	int tempC;
//	string tempN;
//	vector<string>course[maxn];
//	for(int i=0;i<n;i++){
//		cin>>tempN>>c;
//		for(int j=0;j<c;j++){
//			scanf("%d",&tempC);
//			course[tempC].push_back(tempN);
//		} 
//	} 
//
//	 
//	for(int i=1;i<=k;i++){
//		sort(course[i].begin(),course[i].begin()+course[i].size(),cmp);
//		printf("%d %d\n",i,course[i].size());
//		for(int j=0;j<course[i].size();j++){
//			cout<<course[i][j]<<endl;
//		}
//	}
//	return 0;
//}




////��ǰ��д��
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//using namespace std;
//const int maxn = 2505;
//vector<string>course[maxn];
//bool cmp(string a, string b)
//{
//	return a<b;
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int c_num;
//	int c;
//	string tempname;
//	for(int i=0;i<n;i++)
//	{
//		cin>>tempname;
//		scanf("%d",&c_num);
//		for(int j=0;j<c_num;j++)
//		{
//			scanf("%d",&c);
//			course[c].push_back(tempname);
//		}
//	}
//	for(int i=1;i<=k;i++)
//	{
//		printf("%d %d\n",i,course[i].size());
//		sort(course[i].begin(),course[i].end(),cmp);
//		for(int j=0;j<course[i].size();j++)
//		{
//			printf("%s\n",course[i][j].c_str());
//		}
//	}
//	return 0;
//} 

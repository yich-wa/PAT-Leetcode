//16��58--�м�ˮ�˺þõ��ֻ�
//̫ɵ���ˡ���һ�Σ�һ����ʽ����һ����ʱ��ֻ����8�֡� 
//����cin,cout���ᳬʱ����Ρ���map���ͱ�����string
//Ȼ��ͱ�����cin,cout�����Ի�һ��д����������ӳ��� ���֡�
//�������10����λ���� 

//�������飬�Ǳ꿪�Ĺ��󡣳����ֱ����ֹ�� 

//�ĳ���ͨӳ��֮�����������Զ���ֹ���޷����롣��������Ϊ
//ֱ����ӳ��֮������ֵ��������ĽǱ�Ļ���̫���ˡ��������Ǳ꿪��̫���� 
//��С�������У������ƺ����������Ի���Ҫ������ӳ��ɽ�С�ĽǱꡣ �ĳ���������23��
// ������ֶδ��� 
//�Ǳ꿪�� const int maxn = 26*26*26*10+1;   �õ�25�֡� 
//���Բ��ý�һ��ӳ�䣺 
//����㲻֪��const int maxnҪ�����٣����Զ���const int maxn = 26*26*26*10+1; 
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map> 
#include<string.h>
using namespace std;
const int maxn = 26*26*26*10+1;
int trans(char s[]){
	int len = strlen(s);
	int sum;
	if(len>=4){	
		sum = s[3]-'0';
		sum +=(s[2]-'A')*10;
		sum +=(s[1]-'A')*26*10;
		sum +=(s[0]-'A')*26*26*10;
	}
	return sum;
} 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int cIndex,sNum;
	map<int,int>mp;
	int num =0; 
	vector<int>v[maxn];
	char sName[5];
	for(int i=0;i<k;i++){
		scanf("%d%d",&cIndex,&sNum);
		for(int i=0;i<sNum;i++){
			scanf("%s",sName);
			int temp;
			int tempN = trans(sName);
			if(mp.find(tempN)==mp.end()){
				mp[tempN]=num++;
			}
			temp = mp[tempN];
			v[temp].push_back(cIndex);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",sName);
		int tempN = trans(sName);
		if(mp.find(tempN)==mp.end()){
			printf("%s 0\n",sName);
		}else{
			int temp = mp[tempN];
			printf("%s %d",sName,v[temp].size());
			sort(v[temp].begin(),v[temp].begin()+v[temp].size());
			for(int j=0;j<v[temp].size();j++){
				printf(" %d",v[temp][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

////cincout 8��д��
//��ʵ��д�������ķ���23�֡��ǹ��㽫���Ļ�������Ŵ�λ�á�Ӧ�÷���else���档
//�����Ƿ����������� 
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//#include<string.h>
//#include<map>
//using namespace std;
//const int maxn = 200005;
//int trans(char s[]){
//	int sum;
//	sum = s[3]-'0';
//	sum +=(s[2]-'A')*10;
//	sum +=(s[1]-'A')*26*10;
//	sum +=(s[0]-'A')*26*26*10;
//	return sum;
//} 
//int main(){
//	int n,k;
//	cin>>n>>k;
//	printf("%d%d",&n,&k)
//	int cIndex,sNum;
//	int num =0;
//	map<string,int>mp;
//	vector<int>v[maxn];
//	string sName;
//	for(int i=0;i<k;i++){
//		cin>>cIndex>>sNum;
//		for(int i=0;i<sNum;i++){
//			cin>>sName;
//			if(mp.find(sName)==mp.end()){
//				mp[sName]=num++;
//			}
//			int temp = mp[sName];
//			v[temp].push_back(cIndex);
//		}
//	}
//	for(int i=0;i<n;i++){
//		cin>>sName;
//		if(mp.find(sName)==mp.end()){
//			cout<<sName<<" 0"<<endl;
//		}else{
//			int temp = mp[sName];
//			cout<<sName<<" "<<v[temp].size();
//			sort(v[temp].begin(),v[temp].begin()+v[temp].size());
//			for(int j=0;j<v[temp].size();j++){
//				cout<<" "<<v[temp][j];
//			}
//		cout<<endl;
//		}
//���в��ܷ������λ������� 
//	}
//	return 0;
//} 

//
////��ǰд��
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<string.h>
//#include<vector>
//#include<map>
//using namespace std;
//const int maxn = 40002;
//int main()
//{
//	map<string ,int>mp; 
//	map<int,string>r_mp;
//	vector<int>student[maxn];	
//	int n,k;
//	scanf("%d%d",&n,&k);
//	int index;
//	int num;
//	string tempname;
//	int s_id=0;
//	int id;
//	for(int i=0;i<k;i++)
//	{
//		scanf("%d%d",&index,&num);
//		getchar();
//		for(int j=0;j<num;j++)
//		{
//			cin>>tempname;
//			if(mp.find(tempname)==mp.end())
//			{
//				mp[tempname]=s_id++;
//			}
//			id = mp[tempname];
//			student[id].push_back(index);
//		}
//	}
//	s_id =-1;
//	vector<int>output; 
//	for(int i=0;i<n;i++)
//	{
//		cin>>tempname;
//		cout<<tempname;
//		if(mp.find(tempname)==mp.end())
//		{
//			printf(" 0\n");
//		} 
//		else
//		{
//			id = mp[tempname];
//			printf(" %d",student[id].size());
//			sort(student[id].begin(),student[id].end());
//			for(int j=0;j<student[id].size();j++)
//			{
//				printf(" %d",student[id][j]);
//			}
//			printf("\n");	
//		}
//	}
//	return 0;
//} 

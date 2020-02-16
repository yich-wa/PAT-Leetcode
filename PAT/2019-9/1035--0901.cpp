//19:40--19:57
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 1005;
struct account{
	char name[15];
	char password[15];
}tempA;
int main(){
	int n;
	scanf("%d",&n);
	vector<account>output;
	char strp[15];
	for(int i=0;i<n;i++){
		bool flag=true;
		scanf("%s %s",tempA.name,strp);
		int len = strlen(strp);
		for(int j=0;j<len;j++){
			if(strp[j]=='1'){
				strp[j]='@';
				flag=false;
			}else if(strp[j]=='0'){
				strp[j]='%';
				flag=false;
			}else if(strp[j]=='l'){
				strp[j]='L';
				flag=false;
			}else if(strp[j]=='O'){
				strp[j]='o';
				flag=false;
			}
		}
		if(flag==false){
			strcpy(tempA.password,strp);
			output.push_back(tempA);
		}	
	}
	if(output.size()>0){
		printf("%d\n",output.size());
		for(int i=0;i<output.size();i++){
			printf("%s %s\n",output[i].name,output[i].password);
		}
	}else if(n>1){
		printf("There are %d accounts and no account is modified",n);
	}else{
		printf("There is 1 account and no account is modified");
	}
	return 0;
}

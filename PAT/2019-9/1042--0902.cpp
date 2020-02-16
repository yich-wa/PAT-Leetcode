//22:52--23:13

//建构思路清晰。本题不难。 
#include<stdio.h>
int initial[55];
int result[55];
int order[55];
void shuffle(){
	for(int i=1;i<=54;i++){
		initial[i]=result[i];
	}
	for(int i=1;i<=54;i++){
		int temp = order[i];
		result[temp] = initial[i];
	}
}

int main(){
	int r;
	scanf("%d",&r);
	for(int i=1;i<=54;i++){
		scanf("%d",&order[i]);
	}
	for(int i=1;i<=54;i++){
		result[i]=i;
	}
	while(r>0){
		r--;
		shuffle();
	}
	for(int i=1;i<=54;i++){
		if(result[i]<=13){
			printf("S%d",result[i]);
		}else if(result[i]<=26){
			printf("H%d",result[i]-13);
		}else if(result[i]<=39){
			printf("C%d",result[i]-26);
		}else if(result[i]<=52){
			printf("D%d",result[i]-39);
		}else{
			printf("J%d",result[i]-52);
		}
		if(i<54)
			printf(" ");
	}
	return 0;
}

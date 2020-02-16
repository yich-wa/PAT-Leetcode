//��С�������Ƚڵ㣻
//�������Խڵ��������ͬ�ģ�
//�÷�23�֣���2���𰸴���һ���δ��� 
//��������һ�£�һ�����ݷ����д��󡣸Ĺ����� �ύ��
//29�֣�1�־��ȷ����ˡ����ؼ��ǣ���������ȣ������õ����Ƚڵ㡣
// ���ǽ����������������Ļ���֮�ϡ�����ǵ��������أ�
//��������Ⱦͻ��г�ʱ�ĸо��� 
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 10005;
int preOrder[maxn];
struct node{
	node* left;
	node* right;
	int value;
};
node* newnode(int k){
	node* r = new node;
	r->value = k;
	r->left = r->right = NULL;
	return r;
}
//�����Ĺ���Ҫ�еġ���Ҫ�¡� 
node* build(int left,int right){
	if(left>right)
		return NULL;
	node* r = newnode(preOrder[left]);
	int h = left;
	for(int k=left+1;k<=right;k++){
		if(preOrder[k]>=preOrder[left]){
			h=k;
			break;
		}
	}
	if(h==left){
		h = right+1;
	}
	r->left = build(left+1,h-1);
	r->right = build(h,right);
	return r;
}
int u,v;
bool isE[2] ={false};
bool isV = false;
vector<int>uA,vA,tempV;
void DFS(node* root,int k,int seq){
	if(root == NULL)
		return;
	if(root->value==k){
		isE[seq]=true;
		if(seq==0)
			uA = tempV;
		else
			vA = tempV;	
		return ;
	}
	tempV.push_back(root->value);
	if(k<root->value){
		DFS(root->left,k,seq);
	}else{
		DFS(root->right,k,seq);
	}
	return;	
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&preOrder[i]);
	}
	node* root = build(0,n-1);
	for(int i=0;i<m;i++){
		//ÿ�ֿ�ʼ ֮ǰҪ���г�ʼ���� 
		fill(isE,isE+2,false);
		uA.clear();
		vA.clear();
		tempV.clear();
		scanf("%d%d",&u,&v);
//		printf("%d****%d\n",u,v);
		DFS(root,u,0);
		tempV.clear();
		DFS(root,v,1);
		if(isE[0]==false&&isE[1]==true){
			printf("ERROR: %d is not found.\n",u);
		}else if(isE[0]==true&&isE[1]==false){
			printf("ERROR: %d is not found.\n",v);
		}else if(isE[0]==false&&isE[1]==false){
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else{
			//�������ҵ��ˡ�
			bool isOut =false;
			for(int j=0;j<uA.size();j++){
				if(uA[j]==v){
					isOut = true;
					printf("%d is an ancestor of %d.\n",v,u);
					break;
				}
			}
			if(isOut==true){
				continue;
			}
			for(int j=0;j<vA.size();j++){
				if(vA[j]==u){
					isOut = true;
					printf("%d is an ancestor of %d.\n",u,v);
					break;
				}
			}
			if(isOut==true){
				continue;
			}
			if(u==v){
				printf("LCA of %d and %d is %d.\n",u,v,uA[uA.size()-1]);
			}else{
				int j;
				for(j=0;j<uA.size()&&j<vA.size();j++){
					if(uA[j]!=vA[j]){
						isOut=true;
						printf("LCA of %d and %d is %d.\n",u,v,uA[j-1]);
						break;
					}
				}
				if(isOut==false){
					if(j==uA.size()){
						printf("LCA of %d and %d is %d.\n",u,v,uA[uA.size()-1]);
					}else{
						printf("LCA of %d and %d is %d.\n",u,v,vA[vA.size()-1]);
					}
				} 
				
			}	
		}		
	} 	
	return 0;
}

//Pat 1127 9:29——10:19 得16分。 
//   ——10.38 得30分。自己最后带入特殊数据试出错误。 
 #include<stdio.h>
 #include<algorithm>
 #include<queue>
 #include<vector>
 #include<stack>
 using namespace std;
 const int maxn = 32;
 int postorder[maxn];
 int inorder[maxn];
 struct Node{
 	int key;
 	int level;
 	Node* left;
 	Node* right;
 }; 
 Node* newnode( int k)
 {
 	Node* a = new Node();
 	a->key =k;
 	a->left = a->right = NULL;
 	return a;
 }
 Node* build(int inl,int inr ,int postl ,int postr,int lev)
 {
 	if(inl>inr)
 	return NULL;
 	Node* a =newnode(postorder[postr]);
 	a->level = lev;
 	int k;
 	for(int i=inl;i<=inr;i++)
	 	if(inorder[i]==postorder[postr])
	 	{
	 		k=i;
	 		break;
		 }
	int lengthleft = k-inl;
	a->left = build(inl ,k-1,postl,postl+lengthleft-1,lev+1);
	a->right= build(k+1, inr , postl+lengthleft,postr-1,lev+1);
	return a;	 
 }
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&inorder[i]);
	 }
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%d",&postorder[i]);
	 }
	 Node* root =build(0,n-1,0,n-1,1); 
	 vector<Node*>comlevel;
	 vector<int>ziglevel;
	 stack<int>S;
	 queue<Node*>Q;
	 Q.push(root);
	 while(!Q.empty())
	 {
	 	Node* a = Q.front();
	 	Q.pop();
	 	comlevel.push_back(a);
	 	if(a->left!=NULL)
	 	 	Q.push(a->left);
	 	if(a->right!=NULL)
	 	 	Q.push(a->right); 
	 }
	 int templevel =2;
	 bool flag =true;
	 ziglevel.push_back(comlevel[0]->key);
	 for(int i=1;i<comlevel.size();i++)
	 {
	 	if(comlevel[i]->level==templevel)
	 	{
	 		while(!S.empty())
	 		{
	 			int k = S.top();
	 			S.pop();
	 			ziglevel.push_back(k);
			 }
			 if(flag==false)
			 	flag=true;
	 		ziglevel.push_back(comlevel[i]->key);
		 }
		else
		{
			if(flag ==true)
			{
				templevel+=2;
				flag =false;
			}	
			S.push(comlevel[i]->key);	
		}	
	 }
	 //第一次少了这一行代码，最后自己做数据给试出来问题
	 //当最后一行是行数是奇数时，数据还存在栈中，没有压到输出向量中。 
	 while(!S.empty())
	{
		int k = S.top();
		S.pop();
		ziglevel.push_back(k);
	 }
	 
	 for(int i=0;i<ziglevel.size();i++)
	 {
	 	printf("%d",ziglevel[i]);
	 	if(i<ziglevel.size()-1)
	 		printf(" ");
	 	else
	 		printf("\n"); 	
	 }
	 return 0;	
 }

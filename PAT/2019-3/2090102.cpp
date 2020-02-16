Node* newnode(int value)
{
	Node* a = new Node;
	a->data = value;
	a->lchild = a->rchild = NULL;
	return a; 
}
#include<vector>
struct Node{
	int data;
	vector<int>child;
}node[maxn]; 

#include<queue>
#include<algorithm>
void layer(Node* r)
{
	queue<Node*>q;
	q.push(r);
	while(!q.empty()) 
	{
	Node* temp= q.front();
	q.pop();
	if(temp->lchild)q.push(temp->lchild);
	if(temp->rchild)q.push(temp->rchild);
	}
}

void L(Node* r)
{
	Node* temp = r->rchild;
	r->rchild = temp->lchild;
	temp->lchild = r;//理论上来说也是先更新下面的高度，在更新上面的高度。 
	updateheight(r);
	updateheight(temp)
	r= temp;
 } 
 
 priority_queue<int ,vector<int>,greater<int>>; 
 
 Node* newnode(int v)
 {
 	Node* node = new Node;
 	node->data = v;
 	node->height = 1;
 	node->lchild =node->rchild = NULL;
 	return node;
	 
  } 
  
  void heapsort(int n)
  {
  	creat();
  	for(int i=n;i>=1;i--)
  	{
	  swap(a[i],a[1]);
	  downadjust(1,i-1);
   } 
  
  
  //求哈夫曼带全最短路径之和。
  #include<queue>
  using namespace std;
  //越来越great的队列。 
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i=0;i<n;i++)
  {
  	scanf("%d",&a);
  	pq.push(a);
  }
  int ans =0;
  while(!pq.empty()){
  	int x = pq.front();pq.pop();
  	int y =pq.front();pq.pop();
  	pq.push(x+y);
  	ans +=x+y;
  }
  
  #include<algorithm>
  fill(G[0],G[0]+maxn*maxn,INF); 
  
  const int INF = (1<<30)-1;
  
   
  
  
  
  
  
  
  
  
  
   
  


//15��07����
//����15:33  25����5�ֶδ���
//��3ά�����3ά���ֵ�ĳɣ�׼ȷ�������ֵ����5�ֱ�����г�ʱ
// //����һ���̶ȵ��Ż��������һ�����г�ʱ��һ���δ���

//�����д𰸣�˵3ά���鲻������Ϊbool�ͷ����������ᳬʱ��
//�Ǹĳ�int�ͣ���0/1�����档 ����25�֣�5�ֳ�ʱ��
//�����Ż����������5�ֳ�ʱ�� 

//�ǲ�����Ϊ�����˵ݹ��û�в��ò��������queue�Ľ�ϡ� 
//���մ𰸵ķ�������д��һ������������BFS�ķ���ֵ�ĳ�int��
///��30�֡�

//��˼����û���д�����Ч����Ĵ��롣 
//�����жϴ��������ٵݹ顣�ݹ�о��ȽϷ�ʱ�� 

//����16:27

#include<stdio.h>
#include<queue>
using namespace std;
const int maxm = 1286;
const int maxn = 128;
const int maxl = 60;
int g[maxl][maxm][maxn];
int isvisit[maxl][maxm][maxn] ={0};
int m,n,l,t;
//void BFS(int a,int b,int c)
//{
//	if(a<0||a>=l)
//		return ; 
//	if(b<0||b>=m)
//		return ;
//	if(c<0||c>=n)
//		return;
//	if(isvisit[a][b][c]==1)
//		return;
//	isvisit[a][b][c]=1;
//	if(g[a][b][c]==1)
//	{
//		tempcount++;
//		BFS(a-1,b,c);
//		BFS(a+1,b,c);
//		BFS(a,b+1,c);
//		BFS(a,b-1,c);
//		BFS(a,b,c+1);
//		BFS(a,b,c-1);
//	}
//}
struct node{
	int x;
	int y;
	int z;
}temp;
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int BFS(int a,int b,int c)
{
	int tempcount =0;
	queue<node>q;
	temp.x = a;
	temp.y = b;
	temp.z = c;
	isvisit[a][b][c]=1;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		tempcount++;
		node temp2;
		for(int i=0;i<6;i++)
		{
			 temp2.x = temp.x+X[i];
			 temp2.y = temp.y+Y[i];
			 temp2.z = temp.z+Z[i];	
			if(temp2.x<0||temp2.x>=l)
			 	continue;
			if(temp2.y<0||temp2.y>=m)
				continue;
			if(temp2.z<0||temp2.z>=n)
				continue;
			if(isvisit[temp2.x][temp2.y][temp2.z]==0&&g[temp2.x][temp2.y][temp2.z]==1)
			{
				isvisit[temp2.x][temp2.y][temp2.z]=1;//��ʼ����Ⱥ�д����"==" 
				q.push(temp2);	
			}		
		}	
	}
	if(tempcount>=t)
		return tempcount;
	else
		return 0;
}
int main()
{	
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<n;k++)
	scanf("%d",&g[i][j][k]);
	int sum =0;
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<n;k++)
	{
		//��ʼû�����if�жϣ���Ȼ�ᵼ�¶�����жϡ�
		//��ʼif�е��ж����ֻ��һ�룬������������һ�롣 
		if(isvisit[i][j][k]==0&&g[i][j][k]==1)   
			sum+=BFS(i,j,k);
	}
	printf("%d\n",sum); 
	return 0; 
}

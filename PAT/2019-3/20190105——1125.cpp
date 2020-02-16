//pat  1125   8£º35¡ª¡ª8:55
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 10010;
int main()
{
	priority_queue<double,vector<double>,greater<double> >Q; 
	int n;
	scanf("%d",&n);
	double segment;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&segment);
		Q.push(segment);
	 } 
	 for(int i=1;i<n;i++)
	 {
	 	double segment1 = Q.top();
	 	Q.pop();
	 	double segment2 = Q.top();
	 	Q.pop();
		segment =(segment1+segment2)/2;
		Q.push(segment);
	 }
	 int output = floor(segment);
	 printf("%d\n",output);
	 return 0;
 } 
 

//14:36--
//��һƬ����ľ��Կ��Ƶ���ɫ�������໥�����Ĳ��ԡ�������ࡣ
//��������ۣ�˼·һ��Ҫ������ 
#include<stdio.h>
int main(){
	int m,n;
	int dc =-1;
	int num =0;
	int tempC;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&tempC);
			if(tempC==dc){
				num++;
			}else{
				if(num==0){
					dc = tempC;
					num =1;
				}else{
					num--;
				}
			}	
			
		}
	}
	printf("%d\n",dc);
	return 0;
} 

////��ǰд��
//#include<stdio.h>
//#include<vector>
//#include<map>
//using namespace std;
//int main()
//{
//	int n,m;
//	map<int,int>mp;
//	scanf("%d%d",&n,&m);
//	int mid = n*m/2;
//	int color;
//	int s_color=-1;
//	for(int i=0;i<m;i++)
//		for(int j=0;j<n;j++)
//		{
//			scanf("%d",&color);
//			if(s_color>=0)
//				continue;
//			if(mp.find(color)==mp.end())
//			{
//				mp[color]=1;
//				if(mp[color]>mid)
//				{
//					s_color = color;
//				}
//			}
//			else
//			{
//				mp[color]++;
//				if(mp[color]>mid)
//				{
//					s_color = color;
//				}
//			}
//		}
//	printf("%d\n",s_color);
//	return 0;		
// }  

//15:36-- 16:23 �÷�19�֡�����6�ֳ�ʱ���������߼�©������ѭ���ˡ� 
//ͨ������ȥ��д�������֣�ÿ���Ҳ�����λ��λ��ʱ�����Ǵ�ͷ��ʼ�ҡ�
//����Ƕ���Ķ�����ÿ�δ���һ���ҵ���λ�ÿ�ʼ�ң�����ʡ�ܶ�ʱ�䡣�� 
#include<stdio.h>
#include<algorithm>
using namespace std; 
const int maxn = 100005;
int val[maxn];
int pos[maxn];
int main(){
	int n;
	scanf("%d",&n);
	int recover = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
		//��������������㡣 ֻͳ����Ҫ��Ϊ���ٸ����������
		//����Ĺ�Ϊ������ȻҲ�͹�λ�ˡ� ����ܹؼ��� 
		if(val[i]!=i&&i!=0){
			recover++;
		}
		pos[val[i]]=i;
	}
	int sum = 0;
	int rNum =0;
	//��¼������λ����ʼλ�á� 
	int stN=1; 
	while(rNum<recover){
		int tempP = pos[0];
		if(tempP!=0){
			int p = pos[tempP];
			swap(val[tempP],val[p]);
			pos[0] = p;
			//��Ϊ��һ���ط� 
			pos[tempP] = tempP;
			sum++;
			rNum++;
		}else{
			//0��0λ�ϣ�������û����ȫ���� 
			int tempNum = stN;
			while(tempNum<n&&val[tempNum]==tempNum){
				tempNum++;
			}
			stN = tempNum+1;
			int temp = val[tempNum];
			swap(val[0],val[tempNum]);
			pos[temp] = 0;
			pos[0]=tempNum;
			sum++; 
		}
	}
	printf("%d",sum);
	return 0;
}


////��ǰд��
//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//const int maxn = 100010;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int orig[maxn];
//	int hash[maxn];
//	int not_pos =0;//�ж��ٸ�������λ������ 
//	bool flag[maxn]={false};
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&orig[i]);
//		hash[orig[i]]=i;
//		if(orig[i]!=i&&i!=0)
//			not_pos++;
//		else 
//			flag[i]=true;		
//	}
//	int count =0;//�������� 
//	 //������λ����������ֻ��һ�����ض���˫���� 
//	 //��ֻnot_pos>0�򣬼�ʹ��ȫ��λ��Ҳ֪ʶnot_pos=1;
//	 //���˳�ʱȴ�������㡣 
//	 int k=1;
//	 //ÿ���Ҳ�����λ������λ�ã�Ӧ���ϴεĿ�ʼ�����
//	 //��k=1�ŵ�ѭ����ࡣk��˳������������ʱ���ϴε�k
//	 //λ�������Ѿ���λ ����Ӧ�ŵ���ࡣ 
//	while(not_pos>0) 
//	{
//		if(hash[0]!=0)
//		{
//			int pos1=hash[0];
//			int pos2 = hash[pos1];
//			swap(orig[pos1],orig[pos2]);
//			hash[0]=pos2;
//			hash[pos1]=pos1;
//			flag[pos1]=true; 
//			count++; 
//			not_pos--;	
//		}
//		else
//		{ 
//			while(flag[k])
//				k++;
//			//****���������˳���ܷ��ˡ�
//			//����Ҫ���Ƚ�������ı�hash��
//			//����hash[orig[0]]=0;��Ϊ��ǰ��kλ�õ�������������0λ�á� 
//			 hash[orig[k]]=0; 
//			swap(orig[0],orig[k]);
//			hash[0]=k;
//			count++;
//		}	
//	}	
//	printf("%d\n",count);
//	return 0;
//} 

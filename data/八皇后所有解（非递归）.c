#include <stdio.h>

int Q[8];
int top=-1;
int cal[8]={0};
int left[15]={0};
int right[15]={0};
int cnt=0; 


void Print()
{
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++)
			if(Q[i]==j){
				printf("# ");
				top--;
			}
			else printf("* ");
		printf("\n");
	}
	top=8; 
}

void Queen()
{
	int i,j;
	j=0;
	for(i=0;i<8;){
		for(;j<8;j++)
			if(cal[j]==0&&left[i+j]==0&&right[i-j+7]==0)	break;
		if(i==0&&j==8)	break;//�ҵ����н� 
		if(j<8){
			//��
			top++;
			Q[top]=j;
			cal[j]=1;
			left[i+j]=1;
			right[i-j+7]=1;
			if(i<7){	//û����
				 i++;j=0;
			} 
			else{
				//������ 
				printf("��%d���Ϊ��\n",++cnt);
				Print();
				//Ĩ
				top--;
				cal[j]=0;
				left[i+j]=0;
				right[i-j+7]=0;
			 	j++;
			}
		}
		else{
			//����Ĩ���ʺ�
			i=top;j=Q[top];
			top--;
			cal[j]=0;
			left[i+j]=0;
			right[i-j+7]=0;
		 	j++;	 
		}
	}	
} 

 int main (void)
 {
 	Queen();
 	return 0;
 }

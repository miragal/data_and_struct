#include <stdio.h>
#include <stdlib.h>

void HeapSort(int *D,int n);

int main(void) 
{
	int *D,n,i;
	printf("���������ݸ�����");
	scanf("%d",&n);
	D=(int *)malloc(sizeof(int)*(n+1));
	printf("���������ݣ�");
	for(i=1;i<n+1;i++)
		scanf("%d",D+i);
	HeapSort(D,n);
	printf("���������ݣ�\n");
	for(i=1;i<n+1;i++)
		printf("%-5d",D[i]);
	
	return 0;
}

void HeapSort(int *D,int n)
{
	int p,end,tag,t,flag;
	end=n;
	while(end>1){
		//���������
		flag=1;
		while(flag){
			p=end/2; tag=0;
			//һ�ε��� 
			while(p){
				if(D[p]<D[2*p]){
					t=D[p];
					D[p]=D[2*p];
					D[2*p]=t;
					 tag=1;
				}
				if(2*p+1<=end&&D[p]<D[2*p+1]){
						t=D[p];
						D[p]=D[2*p+1];
						D[2*p+1]=t;
						 tag=1;
				}
				p--; 
			}	
			if(!tag)	flag=0; 
		}
		//�����������һ��Ҷ��
		t=D[1];
		D[1]=D[end];
		D[end]=t;
		//"���"β
		end--; 
	}
}

#include <stdio.h>
#include <stdlib.h>

void HeapSort(int *D,int n);

int main(void) 
{
	int *D,n,i;
	printf("请输入数据个数：");
	scanf("%d",&n);
	D=(int *)malloc(sizeof(int)*(n+1));
	printf("请输入数据：");
	for(i=1;i<n+1;i++)
		scanf("%d",D+i);
	HeapSort(D,n);
	printf("排序后的数据：\n");
	for(i=1;i<n+1;i++)
		printf("%-5d",D[i]);
	
	return 0;
}

void HeapSort(int *D,int n)
{
	int p,end,tag,t,flag;
	end=n;
	while(end>1){
		//调整大根堆
		flag=1;
		while(flag){
			p=end/2; tag=0;
			//一次调整 
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
		//交换根和最后一个叶子
		t=D[1];
		D[1]=D[end];
		D[end]=t;
		//"剁掉"尾
		end--; 
	}
}

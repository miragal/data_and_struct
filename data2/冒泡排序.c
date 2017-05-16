#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *a,int n);

int main (void)
{
	int *a,n,i;
	printf("请输入元素个数：");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入元素：");
	for(i=0;i<n;i++) 
		scanf("%d",a+i);
	BubbleSort(a,n);
	printf("排序后为：");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]);
	return 0;
}

void BubbleSort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}


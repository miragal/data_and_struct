#include <stdio.h>
#include <stdlib.h>

void QuickSort(int a[],int l,int h);

int main (void)
{
	int *a;
	int i,n;
	printf("请输入个数：");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：",n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	//快排
	QuickSort(a,0,n);
	printf("快排后的结果：\n"); 
	for(i=0;i<n;i++)
		printf("%d ",a[i]); 
} 


void QuickSort(int a[],int l,int h)
{
	int i,j,t;
	if(h-l>1){
		i=l+1;j=h-1;
		while(i<=j){
			for(;i<h&&a[i]<a[l];i++);
			for(;j>l&&a[j]>=a[l];j--);
			if(i<j){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		if(j>l){
			t=a[j];
			a[j]=a[l];
			a[l]=t;
		}
		if(j>l) 	QuickSort(a,l,j);
		if(j<h)		QuickSort(a,j+1,h);
	}
}

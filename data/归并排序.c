#include <stdio.h>
#include <stdlib.h>

void MergeSort(int a[],int l,int h);


int main (void)
{
	int *a;
	int i,n;
	printf("请输入数组长度:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	MergeSort(a,0,n);
	printf("合并排序后为：\n");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]);
	free(a);
	return 0;	
} 

void MergeSort(int a[],int l,int h)
{
	int m,i,j,k;
	int b[100];
	if(h-l>1){
		m=(l+h)/2;
		MergeSort(a,l,m);
		MergeSort(a,m,h);
		//合并
		i=l;j=m;k=l;
		while(i<m||j<h){
			if(i<m&&a[i]<a[j]||j==h)
				b[k++]=a[i++];
			else b[k++]=a[j++];
		} 
		for(i=l;i<h;i++)
			a[i]=b[i];
	}
}

#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a,int n); 

int main (void)
{
	int *a,n,i;
	printf("������Ԫ�ظ�����");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("������Ԫ�أ�");
	for(i=0;i<n;i++) 
		scanf("%d",a+i);
	InsertSort(a,n);
	printf("�����Ϊ��");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]);
	return 0;
}

void InsertSort(int *a,int n)
{
	int i,j,t;
	for(i=1;i<n;i++){
		t=a[i];
		for(j=i-1;j>-1&&a[j]>t;j--)
				a[j+1]=a[j];
		a[++j]=t;
	}
}

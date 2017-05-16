#include <stdio.h>
#include <stdlib.h>

void MergeSort(int a[],int l,int h);


int main (void)
{
	int *a;
	int i,n;
	printf("���������鳤��:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("������%d������",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	MergeSort(a,0,n);
	printf("�ϲ������Ϊ��\n");
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
		//�ϲ�
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

#include <stdio.h>
#include <stdlib.h>

int MaxSort(int a[],int low,int high);

int main(void)
{
	int *a;
	int i,n;
	printf("请输入数组长度:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	printf("最大字段和为：%d",MaxSort(a,0,n));
	free (a); 
	return 0;	
}

int MaxSort(int a[],int low,int high)
{
	int mid,i,ml,mr,m,s,maxl,maxr;
	if(high-low==1) 	return a[low];
	mid=(high+low)/2;
	ml=MaxSort(a,low,mid);
	mr=MaxSort(a,mid,high);
	if(ml<mr)	ml=mr;
	//由中间开始求最大字段和
	maxl=a[mid-1];
	s=0;
	for(i=mid-1;i>=low;i--){
		s+=a[i];
		if(maxl<s)
			maxl=s;
	} 
	maxr=a[mid];
	s=0;
	for(i=mid;i<high;i++){
		s+=a[i];
		if(maxr<s)
			maxr=s;
	}
	maxl+=maxr;
	if(ml<maxl)	ml=maxl;
	return ml;
}


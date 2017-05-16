#include <stdio.h>
#define M 100
void QuickSort(int a[],int left,int right);

int main(void)
{ 
	int a[M],i,n;
	printf("请输入个数："); 
	scanf("%d",&n);
	printf("请输入%d个数：\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	printf("原数组元素为："); 
	for(i=1;i<=n;i++)
		printf("%-5d",a[i]);
	QuickSort(a,1,n); 
	printf("\n排序后数组元素为："); 
	for(i=1;i<=n;i++)
		printf("%-5d",a[i]);
	return 0;
}

void QuickSort(int a[],int left,int right)
{
	int i,j,temp,t;
	//temp是基准数 
	if(left>right)	return;
	temp=a[left];	
	i=left;
	j=right;
	while(i!=j){
		//先从右开始比较找到第一个比基准值小的 
		while(a[j]>=temp&&i<j)	j--;
		//再从左开始比较找到第一个比基准值大的
		while(a[i]<=temp&&i<j)	i++;
		//当两个岗哨没有相遇时交换
		if(i<j){
			t=a[i];
		 	a[i]=a[j];
	 		a[j]=t;	
		}
	}
	//基准数归位
	a[left]=a[i];
	a[i]=temp; 
	QuickSort(a,left,i-1);
	QuickSort(a,i+1,right);	
}


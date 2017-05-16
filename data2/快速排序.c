#include <stdio.h>
#define M 100
void QuickSort(int a[],int left,int right);

int main(void)
{ 
	int a[M],i,n;
	printf("�����������"); 
	scanf("%d",&n);
	printf("������%d������\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	printf("ԭ����Ԫ��Ϊ��"); 
	for(i=1;i<=n;i++)
		printf("%-5d",a[i]);
	QuickSort(a,1,n); 
	printf("\n���������Ԫ��Ϊ��"); 
	for(i=1;i<=n;i++)
		printf("%-5d",a[i]);
	return 0;
}

void QuickSort(int a[],int left,int right)
{
	int i,j,temp,t;
	//temp�ǻ�׼�� 
	if(left>right)	return;
	temp=a[left];	
	i=left;
	j=right;
	while(i!=j){
		//�ȴ��ҿ�ʼ�Ƚ��ҵ���һ���Ȼ�׼ֵС�� 
		while(a[j]>=temp&&i<j)	j--;
		//�ٴ���ʼ�Ƚ��ҵ���һ���Ȼ�׼ֵ���
		while(a[i]<=temp&&i<j)	i++;
		//����������û������ʱ����
		if(i<j){
			t=a[i];
		 	a[i]=a[j];
	 		a[j]=t;	
		}
	}
	//��׼����λ
	a[left]=a[i];
	a[i]=temp; 
	QuickSort(a,left,i-1);
	QuickSort(a,i+1,right);	
}


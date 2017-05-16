#include <stdio.h>

#define Max 100

typedef int KeyType;
typedef char OtherType;

typedef struct
{	
	KeyType key;
	OtherType otherdaata;	 
}RecordType;

typedef struct
{
	RecordType r[Max+1];
	int length;	
}SeqRList;

int Search(SeqRList l,int key);

int main(void)
{
	SeqRList l;
	int i,n,key;
	printf("���������Ա�ĳ���(С��%d)��",Max);
	scanf("%d",&(l.length));
	printf("������Ԫ�أ�"); 
	for(i=1;i<=l.length;i++)
		scanf("%d",&(l.r[i].key));
	printf("���Ա�Ԫ��Ϊ��\n"); 
	for(i=1;i<=l.length;i++)
		printf("%-5d",l.r[i].key);
	printf("\n������Ҫ���ҵ�Ԫ��:");
	scanf("%d",&key);
	//i=Search(l,key);
	i=BinSearch(l,key);
	if(i)	printf("�ɹ��ҵ�%d!\n",l.r[i].key);
	else printf("δ�ҵ���\n");
	return 0;	
} 

/*
int Search(SeqRList l,int key)
{
	int i=l.length;
	l.r[0].key=key;
	while(l.r[i].key-key)	i--;
	return i;
}*/

int BinSearch(SeqRList l,int key)
{
	int mid,low,high;
	low=1;high=l.length;
	while(low<=high){
		mid=(low+high)/2;
		if(l.r[mid].key==key)
			return mid;
			else if(l.r[mid].key>key)	high=mid-1;
				else low=mid+1; 
	}
	return 0;
}

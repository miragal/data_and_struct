#include<stdio.h>
#include<stdlib.h>
#define N 7
typedef struct node
{
	int data;
	struct node *next;
}Elem;

Elem **CreatHashMap(int Data[],int n)
{
	Elem *t,*newp;
	int i,R;
	Elem **s;
	s=(Elem **)malloc(N*sizeof(Elem *));
	for(i=0;i<N;i++)
		s[i]=NULL;
	for(i=0;i<n;i++)
	{
		R=Data[i]%N;
		newp=(Elem *)malloc(sizeof(Elem));
		newp->data=Data[i];
		newp->next=NULL;
		for(t=s[R];t&&t->next;t=t->next);
		if(!t)
			s[R]=newp;
		else
			t->next=newp;
	}
	return s;
}

void PrintHash(Elem **s)
{
	int i;
	Elem *t;
	for(i=0;i<N;i++)
	{
		for(t=s[i];t;t=t->next)
			printf("%5d",t->data); 
	}
}

int FindKey(Elem **s,int key)
{
	Elem *t;
	int i,R;
	R=key%N;
	for(t=s[R];t&&t->data!=key;t=t->next);
	if(!t)
		return 1;
	else
		return 0;
}

int main(void)
{
	Elem **s;
	int key,k;
	int Data[8]={9,11,19,16,14,12,16,28};
	//´´½¨ 
	s=CreatHashMap(Data,8);
	//Êä³ö
	PrintHash(s);
	/*
	printf("please input:");
	scanf("%d",&key);
	k=FindKey(s,key);
	if(k)
		printf("Find!\n");
	else
		printf("Not Find!\n");
	*/
	return 0;
}

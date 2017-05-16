#include <stdio.h>
#include <stdlib.h>

#define S 7
typedef struct node
{
	int data;
	struct node *next;
}ElemSN;

ElemSN **CreateHashMap(int data[],int n);

void PrintHash(ElemSN **s);

ElemSN *FindKey(ElemSN **s,int key);

int main (void)
{
	ElemSN **s,*p;
	int data[8]={9,11,19,16,14,12,26,28},key;
	s=CreateHashMap(data,8);
	PrintHash(s);
	printf("请输入要查找的数：");
	scanf("%d",&key);
	p=FindKey(s,key);
	if(!p)	printf("Not Find!\n");
	else printf("Yes! %d\n",p->data);
	return 0;
}


ElemSN **CreateHashMap(int data[],int n)
{
	ElemSN **s,*t,*newp;
	int i,r;
	//创建指针数组 
	s=(ElemSN **)malloc(sizeof(ElemSN *)*S);
	for(i=0;i<S;i++)
		s[i]=NULL;
	 for(i=0;i<n;i++){
		//创建节点 
	 	r=data[i]%S;
	 	newp=(ElemSN *)malloc(sizeof(ElemSN));
	 	newp->data=data[i];
	 	newp->next=NULL;
	 	//挂链 
	 	for(t=s[r];t&&t->next;t=t->next);
	 	if(!t)	s[r]=newp;
	 	else t->next=newp;
	 }
	 return s;
}

void PrintHash(ElemSN **s)
{
	int i;
	ElemSN *p;
	for(i=0;i<S;i++){
		printf("散列位置%d:",i);
		for(p=s[i];p;p=p->next)
			printf("%-5d",p->data);
		printf("\n");
	}
}

ElemSN *FindKey(ElemSN **s,int key)
{
	ElemSN *p;
	int i,r;
	r=key%S;
	for(p=s[r];p&&p->data-key;p=p->next);
	return p;
}

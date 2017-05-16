#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

LinkNode *CreateLink(int n);

void PrintLink(LinkNode *h);

LinkNode *Reverse(LinkNode *h);


int main(void)
{
	int n;
	LinkNode *h,*hn;
	printf("������ڵ������");
	scanf("%d",&n);
	if(n>0){
		printf("���������ݣ�\n");
		h=CreateLink(n);
		printf("ԭ��������Ϊ��\n");
		PrintLink(h);
		hn=Reverse(h);
		printf("���ú���������Ϊ��\n");
		PrintLink(hn);
	} 
	else printf("����Ϊ�գ�\n");
	return 0;	
} 


LinkNode *CreateLink(int n)
{
	LinkNode *h,*t,*p;
	int i,x;
	h=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		t=(LinkNode *)malloc(sizeof(LinkNode));
		t->data=x;
		t->next=NULL;
		if(!h)	h=p=t;
		else p=p->next=t;
	}
	return h;
}

void PrintLink(LinkNode *h)
{
	LinkNode *p;
	for(p=h;p;p=p->next)
		printf("%-5d",p->data);
	printf("\n");
}

LinkNode *Reverse(LinkNode *h)
{
	LinkNode *hn=NULL,*t;
	t=h;
	while(h){
		h=h->next;
		t->next=hn;
		hn=t;
		t=h;
	}
	return hn;
}

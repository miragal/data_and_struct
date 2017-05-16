//循环链表实际上无头无尾 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkNode,*LinkList;


LinkList CreateLink(int n);
void PrintLink(LinkList h);
void JosOperate(LinkList h,int m);

int main (void)
{
	int n,m;
	LinkList h;
	printf("请输入人数和密码：");
	scanf("%d%d",&n,&m);
	h=CreateLink(n);
	if(h)
		JosOperate(h,m);
	else printf("链表为空！\n");
	return 0;
}

//没开辟一个节点都是完整的循环链表 
LinkList CreateLink(int n)
{
	int i;
	LinkList h,p,t;
	h=NULL;
	for(i=0;i<n;i++){
		p=(LinkList)malloc(sizeof(LinkNode));
		p->data=i+1;
		if(!h){
			p->next=p; //自链 
			h=t=p;
		} 
		else{
			p->next=h;
			t=t->next=p;
		}
	}
	return h;
}

void JosOperate(LinkList h,int m)
{
	LinkNode *p,*q,*t,*d;
	int cnt=1;
	p=h;
	while(p->next-p){
		cnt++;
		p=p->next;
		if(cnt==m-1){
			d=p->next;
			p->next=d->next;
			printf("%5d",d->data);
			free(d);
			cnt=0;
			p=p->next;
		}
	}
	//最后一个剩余的节点 
	printf("%5d",p->data);
	/* 
	p=h;q=p->next;
	while(p-q){
		cnt++;
		p=p->next;q=q->next;
		if(cnt==m-1){
			printf("%5d",q->data);
			p->next=q->next;
			free(q);
			cnt=0;
			q=p->next;
		}
	}
	//最后一个剩余的节点 
	printf("%5d",p->data);
	*/
}


void PrintLink(LinkList h)
{
	LinkList t;
	t=h;
	do{
		printf("%5d",t->data);
		t=t->next;
	}while(t-h);
	
}

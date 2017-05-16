#include <stdio.h>
#include <stdlib.h>
#define Max 100

typedef struct
{
	int front,rear;
	int data[Max];
}Queue;

void Print(int n);

void InitQueue(Queue *p);

int InQueue(Queue *p,int x);

int OutQueue(Queue *p,int *x);

int main (void)
{
	int n;
	printf("请输入行数：");
	scanf("%d",&n); 
	printf("杨辉三角：\n");
	Print(n);
	return 0;
}

void Print(int n)
{
	Queue *p;
	int i,x,e;
	p=(Queue *)malloc(sizeof(Queue));
	InitQueue(p);
	InQueue(p,0);
	InQueue(p,1);
	InQueue(p,0);
	for(i=1;i<n;i++){
		do{
				OutQueue(p,&x);
				if(x)	printf("%-5d",x);
				else printf("\n");
				e=p->data[p->front];
				InQueue(p,x+e); 
		}while(e);
		InQueue(p,0);
   }
   printf("\n");
	while(p->front-p->rear){
		OutQueue(p,&x);
		if(x)
		printf("%-5d",x);
	}
}


void InitQueue(Queue *p)
{
	p->front=p->rear=0;
}

//队尾入队 
int InQueue(Queue *p,int x)
{
	int s;
	if((p->rear+1)%Max==p->front)	s=0;
	else{
		p->data[p->rear]=x;
		p->rear=(p->rear+1)%Max;
		s=1;
	}
	return s;
}

//队头出队 
int OutQueue(Queue *p,int *x)
{
	int s;
	if(p->front==p->rear)	s=0;
	else{
		*x=p->data[p->front];
		p->front=(p->front+1)%Max;
		s=1;
	}
	return s;
}

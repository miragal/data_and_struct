#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100

typedef struct node
{
	char data;
	struct node *leftchild;
	struct node *rightchild;
}BiNode,*BiTree;

typedef struct 
{
	int top;
	BiTree data[Max];
}Stack; 

Stack *InitStack()
{
	Stack *p;
	p=(Stack *)malloc(sizeof(Stack));
	p->top=-1; 
}

int PushStack(Stack *p,BiTree x)
{
	if(p->top==Max-1)	return 0;
	p->data[++p->top]=x;
	return 1;
}

int PopStack(Stack *p,BiTree *x)
{
	if(p->top==-1) return 0;
	*x=p->data[p->top--];
	return 1;
}

int IsEmpty(Stack *p)
{
	if(p->top==-1)	return 1;
	else return 0;
}

BiTree CreateTree(char in[],char post[],int n);

void PreOrder(BiTree root);

int main (void)
{
	BiNode *root;
	char s1[Max],s2[Max];
	gets(s1);
	gets(s2); 
	root=CreateTree(s1,s2,strlen(s1));
	PreOrder(root);
	return 0;
}


BiTree CreateTree(char in[],char post[],int n)
{
	BiNode *s;
	int t;
	char *p;
	if(n<1)	s=NULL;
	else{
		s=(BiTree)malloc(sizeof(BiNode));
		s->data=*(post+n-1);
		for(p=in;(p<p+n)&&(*p-*(post+n-1));p++);
		t=p-in;
		s->leftchild=CreateTree(in,post,t);
		s->rightchild=CreateTree(p+1,post+t,n-t-1);
	}
	
	return s;
}
void PreOrder(BiTree root)
{
    Stack *s;
    BiTree p;
    s=InitStack();
    p=root;
    while(p||!IsEmpty(s)){
        while(p){
            printf("%c",p->data);
            PushStack(s,p);
            p=p->leftchild;
        }
        if(!IsEmpty(s)){
            PopStack(s,&p);
            p=p->rightchild;
        }   
    }
}  

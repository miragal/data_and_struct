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

BiTree CreateTree(char pre[],char in[],int n);

void PostOrder(BiTree root);

int main (void)
{
	BiNode *root;
	char s1[Max],s2[Max];
	gets(s1);
	gets(s2); 
	root=CreateTree(s1,s2,strlen(s1));
	PostOrder(root);
	return 0;
}


BiTree CreateTree(char pre[],char in[],int n)
{
	BiNode *s;
	int t;
	char *p;
	if(n<1)	s=NULL;
	else{
		s=(BiTree)malloc(sizeof(BiNode));
		s->data=*pre;
		for(p=in;(p<p+n)&&(*p-*pre);p++);
		t=p-in;
		s->leftchild=CreateTree(pre+1,in,t);
		s->rightchild=CreateTree(pre+t+1,p+1,n-t-1);
	}
	
	return s;
}
void PostOrder(BiTree root)
{
    BiTree p,q;
    Stack *s;
    s=InitStack();
    p=root;q=NULL;
    while(p||!IsEmpty(s)){
        if(p){
            PushStack(s,p);
            p=p->leftchild;
        }
        else{
            p=s->data[s->top];
            if(p->rightchild==NULL||p->rightchild==q){
                PopStack(s,&p);
                printf("%c",p->data);
                q=p;
                p=NULL;
            }
            else p=p->rightchild;
        }
    }
}

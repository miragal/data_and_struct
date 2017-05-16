#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "E:\xue\StackTree.h"

typedef struct queue
{
	int front,rear;
	BiTree data[Max];
}Queue;

void CreateTree(BiTree *root);

void PreOrder(BiTree root);

void InOrder(BiTree root);

void PostOrder(BiTree root);

void LevelOrder(BiTree root); 

int LeafCount(BiTree root);

int Depth(BiTree root);

void PrintTree(BiTree root,int h);

void PreTree(BiTree root,int h); 

void PathTree(BiTree root,char Path[],int len);

int main (void)
{
	BiNode *root;
	char Path[100];
	printf("请输入二叉树的节点：");
	CreateTree(&root);
	printf("\n先序遍历：");
	PreOrder(root); 
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n后序遍历：");
	PostOrder(root);
	printf("\n层次遍历：");
	LevelOrder(root);
	printf("\n叶子节点的个数：%d\n",LeafCount(root));
	printf("二叉树的高度：%d\n",Depth(root));
	printf("树状打印二叉树：\n");
	PrintTree(root,1);
	printf("输出节点及层次：\n");
	PreTree(root,0);
	printf("\n根到叶子节点的路径：\n");
	PathTree(root,Path,0);	
	return 0;
}

void CreateTree(BiTree *root)
{
	char ch;
	ch=getchar();
	if(ch=='#')	*root=NULL;
	else{
		*root=(BiTree)malloc(sizeof(BiNode));
		(*root)->data=ch;
		CreateTree(&((*root)->leftchild));
		CreateTree(&((*root)->rightchild));
	}
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

void InOrder(BiTree root)
{
	Stack *s;
	BiTree p;
	s=InitStack();
	p=root;
	while(p||!IsEmpty(s)){
		while(p){
			PushStack(s,p);
			p=p->leftchild;
		}
		if(!IsEmpty(s)){
			PopStack(s,&p);
			printf("%c",p->data);
			p=p->rightchild;
		}	
	}		
}	

//判断刚访问过的节点q是不是当前栈顶节点P的右孩子 
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

void LevelOrder(BiTree root)
{
	Queue *q;
	BiTree p;
	q=(Queue *)malloc(sizeof(Queue));
	q->front=q->rear=0;
	p=root;
	q->data[q->rear]=root;
	q->rear=(q->rear+1)%Max;
	while(q->front-q->rear){
		p=q->data[q->front];
		q->front=(q->front+1)%Max;
		printf("%c",p->data);
		if(p->leftchild){
			q->data[q->rear]=p->leftchild;
			q->rear=(q->rear+1)%Max;
		}
		if(p->rightchild){
			q->data[q->rear]=p->rightchild;
			q->rear=(q->rear+1)%Max;
		}
	}
}

int LeafCount(BiTree root)
{
	int rl,nl,n;
	if(!root)	return 0;
	if(root->leftchild==NULL&&root->rightchild==NULL)	return 1;
	nl=LeafCount(root->leftchild);
	rl=LeafCount(root->rightchild);
	return nl+rl;
}

int Depth(BiTree root)
{
	int h,hl,hr;
	if(!root)	return 0;
	hl=Depth(root->leftchild);
	hr=Depth(root->rightchild);
	h=hl>hr?hl:hr;
	return h+1;
}

void PrintTree(BiTree root,int h)
{
	int i; 
	if(root){
		PrintTree(root->rightchild,h+1);
		for(i=0;i<h;i++)
			printf(" ");
		printf("%c\n",root->data);
		PrintTree(root->leftchild,h+1);
	}
}


void PreTree(BiTree root,int h)
{
	if(root){
		printf("(%c,%d)",root->data,h+1);
		PreTree(root->leftchild,h+1);
		PreTree(root->rightchild,h+1);
	}
}

void PathTree(BiTree root,char Path[],int len)
{
	int i;
	if(root){
		if(root->leftchild==NULL&&root->rightchild==NULL){
			printf("%c:",root->data);
			for(i=0;i<len;i++)
				printf("%5c",Path[i]);
			printf("\n");
		}
		else{
			Path[len]=root->data;
			PathTree(root->leftchild,Path,len+1);
			PathTree(root->rightchild,Path,len+1);
		} 
	}
}

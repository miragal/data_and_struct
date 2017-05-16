/*根据先序和后序可以得出，先序的前面是所有祖先，后序的后面是所有祖先*/ 

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
    if(p->top==Max-1)    return 0;
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
    if(p->top==-1)   return 1;
    else return 0;
}

void CreateTree(BiTree *root);

int PreOrder(BiTree root,char a[]);

int PostOrder(BiTree root,char b[]);

int main(void)
{
	BiNode *root;
	char pre[Max],post[Max],a,b;
	int l1,l2,i,j,tag=1;
	printf("请输入节点域值：");
	CreateTree(&root);
	getchar();
	printf("请输入要查找祖先的两个节点："); 
	scanf("%c %c",&a,&b);
	l1=PreOrder(root,pre);	//先序遍历结果 
	l2=PostOrder(root,post);	//后序遍历结果 
	for(i=0;i<l1;i++)
		if(pre[i]==a||pre[i]==b)
			break; 
	for(j=l2-1;j>-1;j--)
		if(post[j]==a||post[j]==b)
			break;
	for(i--,j++;i>=0&&tag;i--)
		for(;j<l2&&tag;j++)
		if(pre[i]==post[j]){	
			printf("%c和%c最近的公共祖先为：%c",a,b,pre[i]);
			tag=0;
		}
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

int PreOrder(BiTree root,char a[])
{
	int i=0;
	Stack *s;
	BiTree p;
	s=InitStack();
	p=root;
	while(p||!IsEmpty(s)){
		while(p){
			a[i++]=p->data;
			PushStack(s,p);
			p=p->leftchild;
		}
		if(!IsEmpty(s)){
			PopStack(s,&p);
			p=p->rightchild;
		}	
	}
	return i;
}  

int PostOrder(BiTree root,char b[])
{
	int i=0;
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
				b[i++]=p->data;
				q=p;
				p=NULL;
			}
			else p=p->rightchild;
		}
	}
	return i;
}		 


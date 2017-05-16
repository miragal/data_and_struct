#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *firstchild;
	struct node *nextsibling;
}CSNode,*CSTree;

CSTree CreateTree();
void PreOrder(CSTree root);
int LeafCount(CSTree root);
int DepthTree(CSTree root);

int main (void)
{
	CSTree root;
	int n;
	printf("请输入树节点数据：\n");
	root=CreateTree();
	printf("先序遍历：");
	PreOrder(root);
	n=LeafCount(root);
	printf("\n叶子节点个数为：%d\n",n);
	printf("树的高度为：%d\n",DepthTree(root));
	return 0;
}

CSTree CreateTree()
{
	CSTree root;
	char ch;
	ch=getchar();
	if(ch=='#')	root=NULL;
	else{
		root=(CSTree)malloc(sizeof(CSNode)); 
		root->data=ch;
		root->firstchild=CreateTree();
		root->nextsibling=CreateTree();
	}
	return root;
}


void PreOrder(CSTree root)
{
	CSTree p;
	if(root){
		printf("%c",root->data);
		for(p=root->firstchild;p;p=p->nextsibling)
			PreOrder(p);
	}
}
/*
void PreOrder(CSTree root)
{
	if(root){
		printf("%c",root->data);
		PreOrder(root->firstchild);
		PreOrder(root->nextsibling);
	}
}*/

int LeafCount(CSTree root)
{	int nl,rl;
	if(!root)	return 0;
	if(root->firstchild==NULL)	return 1;
	nl=LeafCount(root->firstchild);
	rl=LeafCount(root->nextsibling);
	return nl+rl;
}

int DepthTree(CSTree root)
{
	int lh;
	if(!root)	return 0;
	lh=DepthTree(root->firstchild);
	return lh+1;
}

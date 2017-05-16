#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char data;
	struct node *leftchild;
	struct node *rightchild;
}BiNode,*BiTree;
void CreateTree(BiTree *root);

int CountLevelLeaf(BiTree root,int level);
int main(void)
{
	BiNode *root;
	int level; 
	printf("请输入节点值：");
	CreateTree(&root);
	printf("请输入层次：");
	scanf("%d",&level);
	printf("该层的叶子节点个数为：%d",CountLevelLeaf(root,level));
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

int CountLevelLeaf(BiTree root,int level)
{
	if(!root||level<1)	return 0;
	if(root&&level==1)	
		if(root->leftchild==NULL&&root->rightchild==NULL)	return 1;
			else return 0;
	return CountLevelLeaf(root->leftchild,level-1)+CountLevelLeaf(root->rightchild,level-1);
}

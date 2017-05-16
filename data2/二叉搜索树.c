#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left,*right;	
}BSTNode,*BSTree;

void CreateTree(BSTree *root);

BSTree SearchBST(BSTree root,int k);

void InsertBST(BSTree *root,int k);

BSTree DeleteBST(BSTree root,int k);

void PrintBST(BSTree root);

int main (void)
{
	BSTree root,s;
	int key;
	CreateTree(&root);
	PrintBST(root);
	printf("\n请输入要查找的数：");
	scanf("%d",&key);
	s=SearchBST(root,key);
	if(s)	printf("成功找到%d\n",s->key);
	else printf("未找到！\n");
	return 0;	
} 

//在一棵空树上不停的递归插入节点 
void CreateTree(BSTree *root)
{
	int key;
	*root=NULL;
	printf("请输入二叉搜索树的节点值（0结束）：\n");
	scanf("%d",&key);
	while(key){
		InsertBST(root,key);
		scanf("%d",&key);
	} 
}

BSTree SearchBST(BSTree root,int k)
{
	BSTree t;
	t=root;
	while(t){
		if(t->key==k)	return	t;
		else if(t->key<k)	t=t->right;
			else 	t=t->left; 
	}
	return NULL;
	/* 
	if(root){
		if(root->key==k)	return root;
		else if(root->key>k)	return SearchBST(root->left,k);
			else 	return SearchBST(root->right,k);
	}
	return NULL; 
	*/
}

void InsertBST(BSTree *root,int k)
{
		BSTree t;
		if(*root==NULL){
			t=(BSTree)malloc(sizeof(BSTNode));
			t->key=k;
			t->left=NULL;
			t->right=NULL;
			*root=t; 
		}
		else if(k<(*root)->key)	InsertBST(&((*root)->left),k);
			else InsertBST(&((*root)->right),k);
} 

BSTree DeleteBST(BSTree root,int k)
{
	BSTree t,s,p;
	int tag=1;
	t=root;p=NULL;
	//找到节点t及它的双亲p 
	while(t&&tag){
		if(t->key==k){
			tag=0;
			p=t;
		}
		else if(t->key<k) t=t->right;
			else t=t->left;
	}	
	if(!t)	return root;
	
}

void PrintBST(BSTree root)
{ 
	if(root){
		printf("%-5d",root->key);
		PrintBST(root->left);
		PrintBST(root->right);
	}
}

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	int data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode;

BTNode *CreateTree();

void PreTree(BTNode *root);

int LeafCount(BTNode *root); 

int main (void)
{
	BTNode *root;
	printf("请输入节点数据（0表示空）:\n");
	root=CreateTree();
	if(root){
		printf("先序:");
		PreTree(root);
		printf("\n叶子节点个数为：%d\n",LeafCount(root));
	}
	else printf("空！\n");
	return 0;
}


BTNode *CreateTree()
{
	BTNode *root=NULL;
	int data;
	scanf("%d",&data);
	if(data){
		root=(BTNode *)malloc(sizeof(BTNode));
		root->data=data;
		root->left=CreateTree();
		root->right=CreateTree();
	}
	return root;
}

void PreTree(BTNode *root)
{
	if(root){
		printf("%-5d",root->data);
		PreTree(root->left);
		PreTree(root->right);
	}
}

int LeafCount(BTNode *root)
{
	int r,l;
	if(root){
		if(root->left==NULL&&root->right==NULL)	return 1;
		r=LeafCount(root->left);
		l=LeafCount(root->right);
		return r+l;
	}
	return 0;
}


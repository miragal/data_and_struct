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
	printf("������ڵ����ݣ�0��ʾ�գ�:\n");
	root=CreateTree();
	if(root){
		printf("����:");
		PreTree(root);
		printf("\nҶ�ӽڵ����Ϊ��%d\n",LeafCount(root));
	}
	else printf("�գ�\n");
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


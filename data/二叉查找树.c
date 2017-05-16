#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}BTNode;

BTNode * CreateTree(int data[],int n);

void Forder(BTNode *root);

BTNode *FindMax(BTNode *root);

int main (void)
{
	BTNode *root,*max,*min;
	int data[8]={3,2,5,8,6,7,9,4};
	root=CreateTree(data,8);
	
		while(root)	root=root->right;
		printf("max=%d",root->data); 
	/*
	printf("先序遍历：");
	Forder(root);
	max=FindMax(root);
	printf("最大值为：",max->data);
	*/return 0; 
}


BTNode * CreateTree(int data[],int n)
{
	int i;
	BTNode *p,*q,*pa,*root=NULL;
	for(i=0;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=data[i];
		p->left=p->right=NULL;
		if(!root)	root=p;
		else{
			q=root;
			while(q){
				pa=q;
				if(q->data>p->data)
					q=q->left;
				else q=q->right;
			}
			if(pa->data>p->data)
				pa->left=p;
			else pa->right=p;
		}
	} 
	return root;
}


BTNode *FindMax(BTNode *root)
{
	if(root)
		while(root)	root=root->right;
		
	return root;
}

void Forder(BTNode *root)
{
	if(root){
		printf("%5d",root->data);
		Forder(root->left);
		Forder(root->right); 
	}
}

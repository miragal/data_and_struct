#include <stdio.h>
#include <stdlib.h>
#define V 10

//物品信息
typedef struct
{
	int gno;
	int gv;	
}Goods; 

//物品节点
typedef struct node
{
	int gno;
	struct node *link;	
}GNode;

//箱子节点
typedef struct box
{
	int restv;	//剩余容量
	GNode *hg;	//指向箱子链的头指针 
	struct box *next;	
}BNode; 

void SortD(Goods *g,int n);

BNode *PackingBox(Goods *g,int n);

void Print(BNode *hbox);

int main (void)
{
	int i,n;
	Goods *g;
	BNode *box;
	printf("请输入物品个数：");
	scanf("%d",&n);
	g=(Goods *)malloc(sizeof(Goods)*n);
	printf("请输入物品体积（物品从1开始按顺序编号）：\n");
	for(i=0;i<n;i++){
		g[i].gno=i+1;
		scanf("%d",&(g[i].gv));
	}
	SortD(g,n);
	box=PackingBox(g,n);
	printf("装箱结果为(箱子容量：%d)：\n",V); 
	Print(box);
	return 0;	
} 
//按照物品体积降序排序 
void SortD(Goods *g,int n)
{
	int i,j;
	Goods t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(g[i].gv<g[j].gv){
				t=g[i];
				g[i]=g[j];
				g[j]=t;
			}
}

BNode *PackingBox(Goods *g,int n)
{
	int i,j;
	BNode *hbox,*tbox,*p;
	GNode *t,*s;
	hbox=NULL;
	for(i=0;i<n;i++){
		//建物品链 
		s=(GNode *)malloc(sizeof(GNode));
		s->gno=g[i].gno;
		s->link=NULL;
		//跑箱子链，找到第一个能放下且剩余空间最小的  
		for(p=hbox;p&&p->restv<g[i].gv;p=p->next);
		//没找到开箱子 
		if(!p){
			p=(BNode *)malloc(sizeof(BNode));
			p->restv=V;
			p->next=NULL;
			p->hg=NULL;
			if(!hbox) 
			 	hbox=tbox=p; 
			else tbox=tbox->next=p;
		} 
		//统一放物品 
		for(t=p->hg;t&&t->link;t=t->link);
		if(!(t))	p->hg=s;
		else t->link=s;
		p->restv-=g[i].gv;
	} 
	return hbox;
}

void Print(BNode *hbox)
{
	BNode *t;
	GNode *p;
	int i;
	for(i=0,t=hbox;t;t=t->next){
		printf("第%d个箱子：",++i);
		for(p=t->hg;p;p=p->link)
			printf("%d ",p->gno);
		printf("\n");
	}
	printf("共打开%d个箱子。",i); 
}

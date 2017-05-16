#include <stdio.h>
#include <stdlib.h>
#define V 10

//��Ʒ��Ϣ
typedef struct
{
	int gno;
	int gv;	
}Goods; 

//��Ʒ�ڵ�
typedef struct node
{
	int gno;
	struct node *link;	
}GNode;

//���ӽڵ�
typedef struct box
{
	int restv;	//ʣ������
	GNode *hg;	//ָ����������ͷָ�� 
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
	printf("��������Ʒ������");
	scanf("%d",&n);
	g=(Goods *)malloc(sizeof(Goods)*n);
	printf("��������Ʒ�������Ʒ��1��ʼ��˳���ţ���\n");
	for(i=0;i<n;i++){
		g[i].gno=i+1;
		scanf("%d",&(g[i].gv));
	}
	SortD(g,n);
	box=PackingBox(g,n);
	printf("װ����Ϊ(����������%d)��\n",V); 
	Print(box);
	return 0;	
} 
//������Ʒ����������� 
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
		//����Ʒ�� 
		s=(GNode *)malloc(sizeof(GNode));
		s->gno=g[i].gno;
		s->link=NULL;
		//�����������ҵ���һ���ܷ�����ʣ��ռ���С��  
		for(p=hbox;p&&p->restv<g[i].gv;p=p->next);
		//û�ҵ������� 
		if(!p){
			p=(BNode *)malloc(sizeof(BNode));
			p->restv=V;
			p->next=NULL;
			p->hg=NULL;
			if(!hbox) 
			 	hbox=tbox=p; 
			else tbox=tbox->next=p;
		} 
		//ͳһ����Ʒ 
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
		printf("��%d�����ӣ�",++i);
		for(p=t->hg;p;p=p->link)
			printf("%d ",p->gno);
		printf("\n");
	}
	printf("����%d�����ӡ�",i); 
}

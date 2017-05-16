#include <stdio.h>
#include <stdlib.h>
#define Max 20
#include "E:\xue\Stack.h"
#include "E:\xue\Queue.h"

int visit[Max];
//边 
typedef struct ArcNode
{
	int adj;
	struct ArcNode *nextarc;
}ArcNode;

//顶点
typedef struct VertaxNode
{
	char data;
	struct ArcNode *firstarc;	
}VertaxNode;

//有向网
typedef struct 
{
	VertaxNode vertax[Max];		//顶点 
	int vernum;		//顶点数 
	int arcnum; 	//边数 
}ALGraph;
 
void CreateDG(ALGraph *g); 
 
int Locate(char c,ALGraph *g); 

void OutPutDG(ALGraph g);
 
void Degree(ALGraph g,int od[],int id[]); 

void TraverseDFS(ALGraph g);

void DFS(ALGraph g,int vi);

int TraverseBFS(ALGraph g,int n);

void BFS(ALGraph g,int vi);

int main (void)
{
 	ALGraph graph;
 	int od[Max],id[Max],i,n=0;
	CreateDG(&graph);
	printf("其邻接表为：\n");
	OutPutDG(graph);
	Degree(graph,od,id); 
	printf("顶点\t出度\t入度\n");
	for(i=1;i<=graph.vernum;i++)
		printf("%-8c%-8d%-8d\n",graph.vertax[i].data,od[i],id[i]);
	printf("深度优先遍历结果为（DFS)：\n");
	TraverseDFS(graph);
	printf("\n");
	printf("广度优先遍历结果为（BFS)：\n");
	n=TraverseBFS(graph,n);
	printf("\n强连通分量的个数为：%d\n",n);
	return 0;
}

void CreateDG(ALGraph *g)
{
	char v1,v2;
	int i,j,k,weight;
	ArcNode *p,*s;
	printf("请输入顶点个数和边的条数：\n");
	scanf("%d%d",&(g->vernum),&(g->arcnum)); 
	printf("输入顶点：\n");
	//初始化顶点 
	getchar();
	for(i=1;i<=g->vernum;i++){
		scanf("%c",&(g->vertax[i].data));
		g->vertax[i].firstarc=NULL;
	} 
	//创建边
	getchar();
	for(k=1;k<=g->arcnum;k++){
		printf("请输入第%d条边:",k);
		scanf("%c%c",&v1,&v2);
		getchar();	
		i=Locate(v1,g);
		j=Locate(v2,g);		
		
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adj=j;
		s->nextarc=NULL;
		//插入节点
		p=g->vertax[i].firstarc;
		if(!p)	g->vertax[i].firstarc=s;
			else if(p->adj>j){
				s->nextarc=p;
				g->vertax[i].firstarc=s;
			}
				else{
					while(p->nextarc&&p->nextarc->adj<j)
						p=p->nextarc;
					s->nextarc=p->nextarc;
					p->nextarc=s;	
				}
	} 
}


void OutPutDG(ALGraph g)
{
	int i;
	ArcNode *p;
	for(i=1;i<=g.vernum;i++){
		printf("%d,%-5c",i,g.vertax[i].data);
		p=g.vertax[i].firstarc;
		while(p){
			printf("%d",p->adj);
			p=p->nextarc;
		}
		printf("\n");
	}
}

int Locate(char c,ALGraph *g)
{
	int i;
	for(i=1;i<=g->vernum&&g->vertax[i].data-c;i++);
	return i;	
}


void Degree(ALGraph g,int od[],int id[])
{
	int j,i;
	ArcNode *p;
	for(j=1;j<=g.vernum;j++)
		od[j]=id[j]=0;
	for(j=1;j<=g.vernum;j++){
		p=g.vertax[j].firstarc;
		while(p){
			od[j]++;
			i=p->adj;
			id[i]++;
			p=p->nextarc;	
		}
	}
}


void TraverseDFS(ALGraph g)
{
	int j;
	for(j=1;j<=g.vernum;j++)
		visit[j]=0;
	for(j=1;j<=g.vernum;j++)
		if(!visit[j])
			DFS(g,j);
}
/*
//非递归 
void DFS(ALGraph g,int vi)
{
	Stack *s;
	ArcNode *p;
	int w; 
	s=InitStack();
	PushStack(s,vi);
	while(s->top!=-1){
		PopStack(s,&w);
		if(!visit[w])
			printf("%c",g.vertax[w].data);
		visit[w]=1;
		for(p=g.vertax[w].firstarc;p;p=p->nextarc)
			if(!visit[p->adj])
				PushStack(s,p->adj);	
	}
}
*/

//递归
void DFS(ALGraph g,int vi)
{
	ArcNode *p;
	printf("%c",g.vertax[vi].data);
	visit[vi]=1;
	p=g.vertax[vi].firstarc;
	while(p){
		if(!(visit[p->adj]))
			DFS(g,p->adj);
		p=p->nextarc;
	}
}



int TraverseBFS(ALGraph g,int n)
{
	int i;
	for(i=1;i<=g.vernum;i++)
		visit[i]=0;
	for(i=1;i<=g.vernum;i++)
		if(!visit[i]){
			n++;
			BFS(g,i);
		}
	return n;
}

//借助队列，先访问后入队 
void BFS(ALGraph g,int vi)
{
	Queue *s;
	ArcNode *p;
	int w;
	s=InitQueue();
	printf("%c",g.vertax[vi].data);
	visit[vi]=1;
	InQueue(s,vi);
	while(s->front-s->rear){
		OutQueue(s,&w);
		p=g.vertax[w].firstarc;
		while(p){
			if(!visit[p->adj]){
				printf("%c",g.vertax[p->adj].data);
				visit[p->adj]=1;
				InQueue(s,p->adj);
			}
			p=p->nextarc;
		}
	}
}


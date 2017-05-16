#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E:\xue\Queue.h"

#define Max 20	//��󶥵����
int visit[Max];
typedef char Vextype;
typedef struct
{
	int arcs[Max][Max];
	Vextype vex[Max];
	int vexnum;
	int arsnum;
}Graph;

void Create(Graph *g);

void OutPut(Graph *g);

void Degree(Graph *g,int od[],int id[]);

void TraverseDFS(Graph g);

void DFS(Graph g,int vi);

void TraverseBFS(Graph g);

void BFS(Graph g,int vi);

int main (void)
{
	Graph graph;
	int od[Max],id[Max],i; 
	Create(&graph);
	printf("��ͼ���ڽӾ���Ϊ��\n");
	OutPut(&graph);
	Degree(&graph,od,id);
	for(i=0;i<graph.vexnum;i++)
		printf("%c�ĳ���Ϊ:%d,���Ϊ:%d,��Ϊ:%d\n",graph.vex[i],od[i],id[i],od[i]+id[i]);
	printf("���������������(�ݹ�)���Ϊ��\n");
	TraverseDFS(graph);
	printf("\n������������������Ϊ��\n");
	TraverseBFS(graph);
	return 0;
}

void Create(Graph *g)
{
	int i,j,k,v1,v2;
	printf("�����붥�����ͱ�����");
	scanf("%d%d",&(g->vexnum),&(g->arsnum));
	printf("�����붥�㣺");
	getchar(); 
	for(i=0;i<g->vexnum;i++)
		scanf("%c",&(g->vex[i]));
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
		g->arcs[i][j]=0;
	for(k=0;k<g->arsnum;k++){
		printf("�������%d���ߵ�v1��v2:\n",k+1);
		scanf("%d%d",&v1,&v2);
		(g->arcs)[v1][v2]=1;
	}
	
}

void OutPut(Graph *g)
{
	int i,j;
	printf(" "); 
	for(i=0;i<g->vexnum;i++)
		printf("%5c",g->vex[i]);
	for(i=0;i<g->vexnum;i++){
		printf("\n%-5c",g->vex[i]);
		for(j=0;j<g->vexnum;j++)
			printf("%-5d",g->arcs[i][j]);
		printf("\n");
	}
}


void Degree(Graph *g,int od[],int id[])
{
	int i,j;
	for(i=0;i<g->vexnum;i++){
		od[i]=0;
		for(j=0;j<g->vexnum;j++)
			if(g->arcs[i][j])
				od[i]++;
	}
	for(i=0;i<g->vexnum;i++){
		id[i]=0;
		for(j=0;j<g->vexnum;j++)
			if(g->arcs[j][i])
				id[i]++;
	}
}

void TraverseDFS(Graph g)
{
	int v,count=0;
	for(v=0;v<g.vexnum;v++)
		visit[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visit[v]){
			DFS(g,v);
			count++;
		}
}

void DFS(Graph g,int vi)
{
	int vj;
	printf("%c",g.vex[vi]);
	visit[vi]=1;
	for(vj=0;vj<g.vexnum;vj++)
		if(visit[vj]==0&&g.arcs[vi][vj]==1)
			DFS(g,vj);
}

void TraverseBFS(Graph g)
{
	int v;
	for(v=0;v<g.vexnum;v++)
		visit[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visit[v])
			BFS(g,v);
}

//�������У��ȷ��ʺ���� 
void BFS(Graph g,int vi)
{
	Queue *p;
	int v,i;
	p=InitQueue(); 
	printf("%c",g.vex[i]);
	visit[vi]=1;
	InQueue(p,vi);
	while(p->front-p->rear){
		OutQueue(p,&v);
		for(i=0;i<g.vexnum;i++)
			if(!visit[i]&&g.arcs[v][i]==1){
				printf("%c",g.vex[i]);
				visit[i]=1;
				InQueue(p,i);
			}
	}
}

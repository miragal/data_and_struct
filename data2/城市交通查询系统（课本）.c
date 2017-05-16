#include <stdio.h>
#include <string.h>
#define Max 20
#define Infinity 32768

typedef struct
{
	int No;	//城市序号 
	char name[20];	//城市名 
}Vextype;	//顶点类型

typedef struct node
{
		int arcs[Max][Max];	//边集
		Vextype vex[Max];	//顶点集
		int vexnum;
		int arcnum; 
}AdjMatrix;	//邻接矩阵

//根据城市名确定城市编号
int Locate(AdjMatrix *g,char name[])
{
	int i;
	for(i=1;i<g->vexnum;i++)
		if(!strcmp(name,g->vex[i].name))
			return i;	
	return -1;
} 

//采用邻接矩阵创建无向图
int Create(AdjMatrix *g)
{
	int i,j,k,weight;
	char city[20];
	printf("请输入交通图中的城市数目和路线数目(citynum,cutnum)：\n");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	for(i=1;i<=g->vexnum;i++)
		for(j=1;j<=g->vexnum;j++)	
			g->arcs[i][j]=Infinity;
	printf("请输入交通图中的%d个城市和城市名：\n",g->vexnum);
	for(i=1;i<=g->vexnum;i++){
		printf("No.%d个城市：",i);
			g->vex[i].No=i;
		flushall();
		scanf("%s",g->vex[i].name);
	} 
	printf("请输入交通图中的%d条路线：\n",g->arcnum);
	for(k=0;k<g->arcnum;k++){
		printf("No.%d条路线：\n",k+1);
		printf("\n起点城市:");
		scanf("%s",city);
		i=Locate(g,city);
		printf("终点城市：");
		scanf("%s",city);
		j=Locate(g,city);
		printf("公里数：");
		scanf("%d",&weight);
		g->arcs[i][j]=weight;
		g->arcs[j][i]=weight;
	}
	return 1;
} 

//显示图信息
void Display(AdjMatrix *g)
{
	int i,j;
	printf("\n城市交通情况为：\n");
	for(i=1;i<=g->vexnum;i++){
		for(j=1;j<=i;j++){
			if(g->arcs[i][j]!=Infinity)
				printf("%s<--->%s:%6dkm\n",g->vex[i].name,g->arcs[i][j]);
		}
	}	
} 

void Serach(AdjMatrix *g)
{
	char city[20];
	int No,i,j;
	printf("请输入查询的城市：");
	scanf("%s",city);
	No=Locate(g,city);
	printf("该城市的交通情况为：\n");
	for(i=1;i<=g->vexnum;i++)
		if(i==No)
			for(j=1;j<=g->vexnum;j++)
				if(g->arcs[i][j]-Infinity)
					printf("%s---%s:%dkm\n",g->vex[No].name,g->vex[j].name,g->arcs[i][j]);	
}


void Add(AdjMatrix *g)
{
	char city[20];
	int start,end,weight;
	printf("请输入要添加的路线的起点城市：");
	scanf("%s",city);
	printf("终点城市：");
	scanf("%s",city);
	end=Locate(g,city);
	printf("距离：");
	g->arcs[start][end]=weight;
	g->arcs[end][start]=weight;	
}


void Del(AdjMatrix *g)
{
	char city[20];
	int start,end;
	printf("请输入撤销路线的起点城市: ");
	scanf("%s",city);
	printf("终点城市：");
	scanf("%s",city);
	end=Locate(g,city);
	g->arcs[start][end]=Infinity;
	g->arcs[end][start]=Infinity;
}


void Dijkstra(AdjMatrix *g,int start,int end,int dist[],int path[][Max])
{
	int mindist,i,j,k,t=1;
	//初始化
	for(i=1;i<=g->vexnum;i++){
		dist[i]=g->arcs[start][i];
		if(g->arcs[start][i]-Infinity)
			path[i][1]=start;
	} 
	path[start][0]=1;
	for(i=2;i<=g->vexnum;i++){
		mindist=Infinity;
		for(j=1;j<=g->vexnum;j++)
			if(!path[j][0]&&dist[j]<mindist){
				k=j;
				mindist=dist[j];
			}
		if(mindist==Infinity)	break;
		path[k][0]=1;
		for(j=1;j<=g->vexnum;j++){
			if(!path[j][0]&&g->arcs[k][j]<Infinity&&dist[k]+g->arcs[k][j]<dist[j]){
				dist[j]=dist[k]+g->arcs[k][j];
				t=1;
				while(path[k][t]){
					path[j][t]=path[k][t];
					t++;
				}
				path[j][t]=k;
				path[j][t+1]=0;
			}
		}
	}
	for(i=1;i<=g->vexnum;i++){
		if(i==end)	return;
		printf("%s--->%s的最短路线为：\n从%s",g->vex[start].name,g->vex[end].name,g->vex[start].name);
		for(j=2;path[i][j];j++)
			printf("->%s",g->vex[path[i][j]].name);
		printf("->%s,距离为%dkm\n",g->vex[end].name,dist[i]);
	}
}


void Sortcut(AdjMatrix *g)
{
	char city[20];
	int start,end;
	int dist[Max],path[Max][Max]={0};
	printf("请输入起点城市：");
	scanf("%s",city);
	start=Locate(g,city);
	printf("请输入终点城市：");
	scanf("%s",city);
	end=Locate(g,city);
	Dijikstra(g,start,end,dist,path);
}


void Prim(AdjMatrix *g,int start)
{
	struct{
		int adjvex;
		int lowcost;
	}closedge[Max];
	int i,e,k,m,min;
	closedge[start].lowcost=0;
	for(i=1;i<=g->vexnum;i++)
		if(i-start){
			closedge[i].adjvex=start;
			closedge[i].lowcost=g->arcs[start][i];
		}
	for(e=1;e<=g->vexnum;e++){
		min=Infinity;
		for(k=1;k<=g->vexnum;k++){
			if(closedge[k].lowcost&&closedge[k].lowcost<min){
				m=k;
				min=closedge[k].lowcost;
			}
		}
		printf("从%s---%s:%dkm\n",g->vex[closedge[m].adjvex].name,g->vex[m].name,closedge[m].lowcost);
		closedge[m].lowcost=0;
		for(i=1;i<=g->vexnum;i++)
			if(i-m&&g->arcs[m][i]<closedge[i].lowcost){
				closedge[i].lowcost=g->arcs[m][i];
				closedge[i].adjvex=m;
			}
	}
}

void MiniSpanTree(AdjMatrix *g)
{
	char city[20];
	int start;
	printf("请输入起点城市：");
	scanf("%s",city);
	start=Locate(g,city);
	Prim(g,start); 
}


int main(void)
{
	AdjMatrix g;
	int choice;
	Create(&g);
	do{
		printf("\n******城市交通情况查询系统*****\n");
		printf("\n1.显示基本信息;");
		printf("\n2.查询某个城市交通路线的基本情况;");
		printf("\n3.添加新路线;");
		printf("\n4.撤销旧路线;");
		printf("\n5.查询从某个城市出发到另外一个城市的最短路线;");
		printf("\n6.查询从某个城市出发的最短连通路线;");
		printf("\n0.退出;");
		printf("\n请选择：");
		scanf("%d",&choice);
		switch(choice){
			case 1: Display(&g); break;
			case 2: Serch(&g); break;
			case 3: Add(&g); break;
			case 4: Del(&g); break;
			case 5: Shortcut(&g); break;
			case 6: MiniSpanTree(&g); break;
			case 0: return; 
		} 
	}while(1);
}

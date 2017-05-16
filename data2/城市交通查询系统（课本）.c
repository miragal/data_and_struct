#include <stdio.h>
#include <string.h>
#define Max 20
#define Infinity 32768

typedef struct
{
	int No;	//������� 
	char name[20];	//������ 
}Vextype;	//��������

typedef struct node
{
		int arcs[Max][Max];	//�߼�
		Vextype vex[Max];	//���㼯
		int vexnum;
		int arcnum; 
}AdjMatrix;	//�ڽӾ���

//���ݳ�����ȷ�����б��
int Locate(AdjMatrix *g,char name[])
{
	int i;
	for(i=1;i<g->vexnum;i++)
		if(!strcmp(name,g->vex[i].name))
			return i;	
	return -1;
} 

//�����ڽӾ��󴴽�����ͼ
int Create(AdjMatrix *g)
{
	int i,j,k,weight;
	char city[20];
	printf("�����뽻ͨͼ�еĳ�����Ŀ��·����Ŀ(citynum,cutnum)��\n");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	for(i=1;i<=g->vexnum;i++)
		for(j=1;j<=g->vexnum;j++)	
			g->arcs[i][j]=Infinity;
	printf("�����뽻ͨͼ�е�%d�����кͳ�������\n",g->vexnum);
	for(i=1;i<=g->vexnum;i++){
		printf("No.%d�����У�",i);
			g->vex[i].No=i;
		flushall();
		scanf("%s",g->vex[i].name);
	} 
	printf("�����뽻ͨͼ�е�%d��·�ߣ�\n",g->arcnum);
	for(k=0;k<g->arcnum;k++){
		printf("No.%d��·�ߣ�\n",k+1);
		printf("\n������:");
		scanf("%s",city);
		i=Locate(g,city);
		printf("�յ���У�");
		scanf("%s",city);
		j=Locate(g,city);
		printf("��������");
		scanf("%d",&weight);
		g->arcs[i][j]=weight;
		g->arcs[j][i]=weight;
	}
	return 1;
} 

//��ʾͼ��Ϣ
void Display(AdjMatrix *g)
{
	int i,j;
	printf("\n���н�ͨ���Ϊ��\n");
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
	printf("�������ѯ�ĳ��У�");
	scanf("%s",city);
	No=Locate(g,city);
	printf("�ó��еĽ�ͨ���Ϊ��\n");
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
	printf("������Ҫ��ӵ�·�ߵ������У�");
	scanf("%s",city);
	printf("�յ���У�");
	scanf("%s",city);
	end=Locate(g,city);
	printf("���룺");
	g->arcs[start][end]=weight;
	g->arcs[end][start]=weight;	
}


void Del(AdjMatrix *g)
{
	char city[20];
	int start,end;
	printf("�����볷��·�ߵ�������: ");
	scanf("%s",city);
	printf("�յ���У�");
	scanf("%s",city);
	end=Locate(g,city);
	g->arcs[start][end]=Infinity;
	g->arcs[end][start]=Infinity;
}


void Dijkstra(AdjMatrix *g,int start,int end,int dist[],int path[][Max])
{
	int mindist,i,j,k,t=1;
	//��ʼ��
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
		printf("%s--->%s�����·��Ϊ��\n��%s",g->vex[start].name,g->vex[end].name,g->vex[start].name);
		for(j=2;path[i][j];j++)
			printf("->%s",g->vex[path[i][j]].name);
		printf("->%s,����Ϊ%dkm\n",g->vex[end].name,dist[i]);
	}
}


void Sortcut(AdjMatrix *g)
{
	char city[20];
	int start,end;
	int dist[Max],path[Max][Max]={0};
	printf("�����������У�");
	scanf("%s",city);
	start=Locate(g,city);
	printf("�������յ���У�");
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
		printf("��%s---%s:%dkm\n",g->vex[closedge[m].adjvex].name,g->vex[m].name,closedge[m].lowcost);
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
	printf("�����������У�");
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
		printf("\n******���н�ͨ�����ѯϵͳ*****\n");
		printf("\n1.��ʾ������Ϣ;");
		printf("\n2.��ѯĳ�����н�ͨ·�ߵĻ������;");
		printf("\n3.�����·��;");
		printf("\n4.������·��;");
		printf("\n5.��ѯ��ĳ�����г���������һ�����е����·��;");
		printf("\n6.��ѯ��ĳ�����г����������ͨ·��;");
		printf("\n0.�˳�;");
		printf("\n��ѡ��");
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

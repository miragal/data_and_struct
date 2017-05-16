#include<stdio.h>
#include<stdlib.h>


#define MAX 21
#define INFINTY 32768
typedef struct 
{
	int arcs[MAX][MAX];//边得信息 
	char vex[MAX];//顶点信息 
	int vexnum;//顶点个数 
	int arcnum;//边数 
	
 } AdjMatrix;
 typedef struct k
  {
  	int data[MAX];
  	int rear,front;
   }*SeQueue; 
   void init(SeQueue s)
   {
   		s->front=s->rear=-1;
   }
   int IsEmpty(SeQueue s)
   {
   	if(s->rear==s->front)
   		return 1;
   	return 0;
	} 	
	void push(SeQueue s,int k)
	{
		if(s->rear<=MAX)
		{
			s->rear++;
			
			s->data[s->rear]=k;
//			printf("ok\n"); 
		}
	}
	int  pop(SeQueue s)
	{

//		printf("POP:%d",s->data[s->front]);
		if(IsEmpty(s)!=1)
		{
				s->front++;
			return s->data[s->front];
		}
		else return 0;	
			 	
	}
	 
	int v[MAX]={0};
	int BFirst(AdjMatrix *G,char A,int k)
 {
 	int i,j;
 
 	for(i=k;i<=G->vexnum;i++)
 	{
 		for(j=1;j<=G->vexnum;j++)
 		{
 			if(G->arcs[i][j]==1&&v[j]==0)
 				return j;				
		 }
	 }	
	 return -1; 
 }
 
 void Create(AdjMatrix *G);
  void select(int *vex1,int *vex2,AdjMatrix *G,char c1,char c2);
  void BFS(AdjMatrix *G,char A,SeQueue s);
  void Num(AdjMatrix *G,int IN[],int OUT[]);
 int find(AdjMatrix *G,char A);
  int FNirst(AdjMatrix *G,char A,int k);
  void DFS(AdjMatrix *G,char A);
  int BFirst(AdjMatrix *G,char A,int k);
  int BFirst(AdjMatrix *G,char A,int k);
  void outNum(AdjMatrix *G,int IN[],int OUT[]) ;
  
 
 void Create(AdjMatrix *G)
 {
 
 	int i,j;
	int  vex1,vex2;
	char c1,c2;
// 	printf("请输入顶点数和边数：");
	 scanf("%d %d",&G->vexnum,&G->arcnum);
	 	
	 for(i=1;i<=G->vexnum;i++)
	 	for(j=1;j<=G->vexnum;j++)
	 		G->arcs[i][j]=2;//所有的顶点与顶点之间信息先存储最大值类似于表中的无穷（边或者弧的信息）		  
	//存储顶点的值 
	getchar(); 
	for(i=1;i<=G->vexnum;i++)
		scanf("%c",&G->vex[i]);
//	for(i=1;i<=G->vexnum;i++)
//			printf("l:%c ",G->vex[i]);
//			printf("\n");
	 for(j=1;j<=G->arcnum;j++)
	 {
	 	getchar(); 
	 	scanf("%c%c",&c1,&c2);
	 
//	 	scanf("%d",&weight);
		select(&vex1,&vex2,G,c1,c2);
	//	 printf(" :%d %d\n",vex1,vex2);
		//printf("      \n2. k:%d %d",vex1,vex2);
	 	G->arcs[vex1][vex2]=1;
	 }
 }
 
 void select(int *vex1,int *vex2,AdjMatrix *G,char c1,char c2)
 {
 	int i;
 	//printf("c1:%c  c2:%c",c1,c2);
 	for(i=1;i<=G->vexnum;i++)
 	{
 		if(c1==G->vex[i])
 			 *vex1=i;
 		if(c2==G->vex[i])
 			*vex2=i;		
	  } 
	 
 }
 void out(AdjMatrix *G)
 {
 	int i,j;
 	for(i=1;i<=G->vexnum;i++)
 	{
 		for(j=1;j<=G->vexnum;j++)
 			printf("%d\t",G->arcs[i][j]);
 		printf("\n");
	 }
 }
 
 //计算出度和入度
 void Num(AdjMatrix *G,int IN[],int OUT[])
 {
 	int i,j;
 	for(i=1;i<=G->vexnum;i++)
 		for(j=1;j<=G->vexnum;j++)
 			if(G->arcs[i][j]==1)
 				OUT[i]+=1;
 	for(i=1;i<=G->vexnum;i++)
 		for(j=1;j<=G->vexnum;j++)
 			if(G->arcs[j][i]==1)
 				IN[i]+=1;	
  } 
  //输出各个顶点的入度和出度
  void outNum(AdjMatrix *G,int IN[],int OUT[]) 
  {
  	int i;
  	for(i=1;i<=G->vexnum;i++)
  	{
  		printf("%c %d %d\n",G->vex[i],OUT[i],IN[i]);
	  }
  }
  
//  void init(int IN[],int OUT[],AdjMatrix *G)
//  {
//  	int j;
//  	for(j=1;j<=G->vexnum;j++)
//  	{
// 		IN[j]=0;
// 		OUT[j]=0;
//	  }
//  }
  //深度优先 
 int visted[MAX]={0};
 
 int find(AdjMatrix *G,char A)
 {
 	int i;
 	for(i=1;i<=G->vexnum;i++)
 	{
 		if(G->vex[i]==A)
 			return i;
 		
	 }
	 return -1;
 }
 int FNirst(AdjMatrix *G,char A,int k)
 {
 	int i,j;
 	for(i=1;i<=G->vexnum;i++)
 	{
	 	//	for(j=1;j<=G->vexnum;j++)
	//	{ 	
//				if(j==G->vexnum)	
//				printf("i:%d",i);	
	//				if(visted[j]==0&&G->arcs[i][j]==1)
	//				printf("\nj:%d %d i:%d\n",visted[j],G->arcs[1][j],j);
	 			if(G->arcs[k][i]==1&&visted[i]==0)
	 			
	 				return i;	
		//	 }
	 }
	return -1;
 }
 void DFS(AdjMatrix *G,char A)
 {
 	int w=-1,k;
 	 
 	printf("%c",A);
 	
 	k=find(G,A);
 
 	
 	visted[k]=1;
 	
 	w=FNirst(G,A,k);
 	
	printf(":%d",w);
 	if(w!=-1)
		DFS(G,G->vex[w]);
 }
  //广度优先
  
  
	void BFS(AdjMatrix *G,char A,SeQueue s)
	{
		int k,t,w=-1;
		printf("%c",A);
		k=find(G,A);
		v[k]=1;
		init(s);
		push(s,k);
		while(IsEmpty(s)!=1)
		{
			w=-1;
			t=pop(s);
			w=BFirst(G,A,t);
//			printf("%d,%c\n",w,G->vex[w]);
			while(w>1&&w<=G->vexnum)
			{
				printf("%c",G->vex[w]);
				push(s,w);
				v[w]=1;
				w=BFirst(G,G->vex[t],t);				
			}
			
		}
		
	}
	
	
 int main(void)
 {
 	AdjMatrix G;
 	Create(&G);
 	//out(&G);
 	int IN[MAX]={0},OUT[MAX]={0};	
 	Num(&G,IN,OUT);
 	outNum(&G,IN,OUT);
 	//out(&G);
 	DFS(&G,'A');
 	printf("\n");
 	SeQueue s;
 	//BFS(&G,'A',s);
 	return 0;
 }


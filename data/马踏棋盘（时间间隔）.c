#include <stdio.h>
#include <time.h> 

int chess[12][12]={
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
}; 
int Move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int cnt=0,t=0;
clock_t end,begin;


void Horse(int x,int y);

void Print();

int main (void)
{
	begin=clock();
	int x,y;
	printf("请输入起始位置：");
	scanf("%d%d",&x,&y);
	chess[x][y]=++cnt;
	Horse(x,y);
	return 0;
}

void Horse(int x,int y)
{
	int i,a,b;
	for(i=0;i<8;i++){
			a=x+Move[i][0];
			b=y+Move[i][1];
			if(chess[a][b]==0){
				chess[a][b]=++cnt; 
				if(cnt<64)	Horse(a,b);
				else{
 					end=clock();
					printf("第%d组解,耗时%.3f\n",++t,(end-begin)*1.0/CLK_TCK);
					Print();
				}
				//抹掉
				chess[a][b]=0;
				cnt--; 
			}
	}
}

void Print()
{
	int i,j;
	for(i=2;i<10;i++){
		for(j=2;j<10;j++)
			printf("%-3d",chess[i][j]);
		printf("\n");
	}
}



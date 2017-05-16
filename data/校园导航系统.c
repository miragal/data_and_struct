#include <stdio.h>
#include <stdlib.h>

#define M 65536



int main (void)
{
	int chioce;
	Graph g;
	Create(&g);
	do{
		printf("******************校园导航系统*******************\n");
		printf("1.显示所有景点信息\n")
		printf("2.显示某个景点交通路线基本信息\n");
		printf("3.添加新路径\n");
		printf("4.撤销旧路线\n");
		printf("5.查询从某个景点出发到另一个景点的最短路径\n"); 
		printf("6.查询从某个景点出发的最短连通路径\n");
		printf("0.退出");
		printf("请输入你的选择：");
		scanf("%d",&chioce);
		switch(chioce){
			case 1:Display(g);break; 
			case 2:DisplayAll(g);break;
			case 3:Add(&g);break;
			case 4:Delete(&g);break;
			case 5:ShortPath(&g);break;
			case 6:ShortAll(&g);break;
			default: return;
		}			
	}while(1);
	return 0;
} 

#include <stdio.h>
#include <stdlib.h>

#define M 65536



int main (void)
{
	int chioce;
	Graph g;
	Create(&g);
	do{
		printf("******************У԰����ϵͳ*******************\n");
		printf("1.��ʾ���о�����Ϣ\n")
		printf("2.��ʾĳ�����㽻ͨ·�߻�����Ϣ\n");
		printf("3.�����·��\n");
		printf("4.������·��\n");
		printf("5.��ѯ��ĳ�������������һ����������·��\n"); 
		printf("6.��ѯ��ĳ����������������ͨ·��\n");
		printf("0.�˳�");
		printf("���������ѡ��");
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

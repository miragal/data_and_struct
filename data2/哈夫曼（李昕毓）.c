#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#define maxsize 100   //哈夫曼编码的最大位数
#define N 256          //叶子结点个数
#define M 2*N-1
//#define LEN 100
#define maxval 10000
typedef struct
{
	char fu;
	int weight;
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];               /*0号单元不用*/
typedef char * HuffmanTreeCode[N+1];

int n=0;                                 //全局变量n

void select(HuffmanTree ht,int m,int *s1,int *s2)	
{
	int i,j;
	int x1=0,x2=0;
	int m1 = 1000;
	int m2 = 1000;
	for (j=1; j<=m;j++)
	        {
	            if (ht[j].weight < m1 && ht[j].parent==0)
	            {
	                m2=m1; 
	                x2=x1; 
	                m1=ht[j].weight;
	                x1=j;
	            }
	            else if (ht[j].weight < m2 && ht[j].parent==0)
	            {
	                m2=ht[j].weight;
	                x2=j;
	            }
	        } 
	*s1=x1;
	*s2=x2;
}

void Tongji(HuffmanTree ht,char  s[])
{
	int i,j;
	int a[256]={0};          //定义存储权值的数组
	j=1;
    for(i=0;s[i];i++)  //统计权值的大小
    a[s[i]]++;              
	for(i=0;i<=256;i++)
		if(a[i]>0)
		{
			n++;
			ht[j].fu=i;
		    ht[j++].weight=a[i];
		}
} 
void CrtHuffmanTree(HuffmanTree ht)
{

	int m,i,j,s1,s2,w;
    m=2*n-1;
	for(i=1;i<=n;i++)              /*初始化前n个元素成为根结点*/
	{
		ht[i].parent=0;
		ht[i].Lchild=0;
		ht[i].Rchild=0;
	}
	for(i=n+1;i<=m;i++)            /*初始化后n-1个空元素*/
	{             
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].Lchild=0;
		ht[i].Rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].Lchild=s1;
		ht[i].Rchild=s2;
		ht[s1].parent=i;
		ht[s2].parent=i;
	}
	printf("哈夫曼树:\n");
	for(i=1;i<=m;i++)
	{
		printf(" f:%7c      ",ht[i].fu);
		printf(" w:%7d      ",ht[i].weight);
		printf(" p:%7d      ",ht[i].parent);
		printf(" L:%7d      ",ht[i].Lchild);
		printf(" R:%7d      ",ht[i].Rchild);
		printf("\n");
	}
}




//哈夫曼编码
void CrtHuffmanCode1(HuffmanTree ht,HuffmanTreeCode hc)
/*从叶子到根，逆向求各叶子结点的编码*/
{
	char *cd;
	int start,i,c,p;
	cd=(char *)malloc(n*sizeof(char));         /*临时编码数组*/
	cd[n-1]='\0';                              /*从后向前逐位求编码，首先放编码结束符*/
	for(i=1;i<=n;i++)                          /*从每个叶子结点开始，求相应的哈夫曼编码*/
	{
		start=n-1;                             /*为当前结点，为其双亲*/
		c=i;
		p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].Lchild==c)                 /*左分支得0*/
				cd[start]='0';
			else
				cd[start]='1';                 /*右分支得1*/
		
			c=p;                               /*上溯一层*/
			p=ht[c].parent;
			
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));   /*动态申请编码串空间*/
		strcpy(hc[i],&cd[start]);                       /*复制编码*/
		printf("第%d个叶子结点%c的编码为:\n",i,ht[i].fu);
			printf("%d:%s\n",ht[i].weight,hc[i]);
	}
    free(cd);
}
/*
//哈夫曼译码
void CrtHuffmanCode2()
{


}
*/

int main()
{
	HuffmanTree ht;
	HuffmanTreeCode hc;
	char s[100];            //定义存储内容的数组
	//system("color 3");
    printf("请输入要编码的字符串:");
    gets(s);
	Tongji(ht,s);
	CrtHuffmanTree(ht); 
	CrtHuffmanCode1(ht,hc);				 							
    return 0;
}


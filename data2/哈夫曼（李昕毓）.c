#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#define maxsize 100   //��������������λ��
#define N 256          //Ҷ�ӽ�����
#define M 2*N-1
//#define LEN 100
#define maxval 10000
typedef struct
{
	char fu;
	int weight;
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];               /*0�ŵ�Ԫ����*/
typedef char * HuffmanTreeCode[N+1];

int n=0;                                 //ȫ�ֱ���n

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
	int a[256]={0};          //����洢Ȩֵ������
	j=1;
    for(i=0;s[i];i++)  //ͳ��Ȩֵ�Ĵ�С
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
	for(i=1;i<=n;i++)              /*��ʼ��ǰn��Ԫ�س�Ϊ�����*/
	{
		ht[i].parent=0;
		ht[i].Lchild=0;
		ht[i].Rchild=0;
	}
	for(i=n+1;i<=m;i++)            /*��ʼ����n-1����Ԫ��*/
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
	printf("��������:\n");
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




//����������
void CrtHuffmanCode1(HuffmanTree ht,HuffmanTreeCode hc)
/*��Ҷ�ӵ������������Ҷ�ӽ��ı���*/
{
	char *cd;
	int start,i,c,p;
	cd=(char *)malloc(n*sizeof(char));         /*��ʱ��������*/
	cd[n-1]='\0';                              /*�Ӻ���ǰ��λ����룬���ȷű��������*/
	for(i=1;i<=n;i++)                          /*��ÿ��Ҷ�ӽ�㿪ʼ������Ӧ�Ĺ���������*/
	{
		start=n-1;                             /*Ϊ��ǰ��㣬Ϊ��˫��*/
		c=i;
		p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].Lchild==c)                 /*���֧��0*/
				cd[start]='0';
			else
				cd[start]='1';                 /*�ҷ�֧��1*/
		
			c=p;                               /*����һ��*/
			p=ht[c].parent;
			
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));   /*��̬������봮�ռ�*/
		strcpy(hc[i],&cd[start]);                       /*���Ʊ���*/
		printf("��%d��Ҷ�ӽ��%c�ı���Ϊ:\n",i,ht[i].fu);
			printf("%d:%s\n",ht[i].weight,hc[i]);
	}
    free(cd);
}
/*
//����������
void CrtHuffmanCode2()
{


}
*/

int main()
{
	HuffmanTree ht;
	HuffmanTreeCode hc;
	char s[100];            //����洢���ݵ�����
	//system("color 3");
    printf("������Ҫ������ַ���:");
    gets(s);
	Tongji(ht,s);
	CrtHuffmanTree(ht); 
	CrtHuffmanCode1(ht,hc);				 							
    return 0;
}


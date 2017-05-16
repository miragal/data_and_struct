#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6	
#define M 2*N-1

typedef struct
{
	char c;
	int weight;
	int parent,lchild,rchild;
}HTNode,HuffmanTree[M];

typedef struct
{
	char ch;	//相应的字符 
	char b[N];	 //相应字符的编码 
	int start;	//每条编码的起始位置 
}Code;


void CtrHuffmanTree(HuffmanTree ht);

void Select(HuffmanTree ht,int n,int *s1,int *s2);

void CrtHuffmanCode(Code code[],HuffmanTree ht);

void Code1(Code code[]);
 	
void Code2(HuffmanTree ht);

int main (void)
{
	HuffmanTree ht;
	Code code[N];
	int i,j;
	CtrHuffmanTree(ht);
	CrtHuffmanCode(code,ht);
	printf("编码为：\n"); 
	for(i=0;i<N;i++){
 		 printf("%c:",code[i].ch);
  		for(j=code[i].start;j<N;j++)
   			printf("%c",code[i].b[j]);
  		printf("\n");
 	}
 	Code1(code);
 	printf("\n");
	Code2(ht);
	return 0;
}

void CtrHuffmanTree(HuffmanTree ht)
{
	int i,s1,s2,w[N];
	printf("请输入权值：\n");
	for(i=0;i<N;i++)
	scanf("%d",w+i);
	ht[0].c='A';	ht[1].c='B';
	ht[2].c='C';	ht[3].c='D';
	ht[4].c='E';	ht[5].c='F';
	for(i=0;i<N;i++){
		ht[i].weight=w[i];
		ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
	}
	for(i=N;i<M;i++)
	ht[i].weight=ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
	for(i=N;i<M;i++){
		Select(ht,i,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
		ht[s1].parent=ht[s2].parent=i;
	} 
}

void Select(HuffmanTree ht,int n,int *s1,int *s2)
{
	int i,a,b;
	a=b=2147483647;*s1=*s2=0;
	for(i=0;i<n;i++)
		if(a>ht[i].weight&&ht[i].parent==-1){
			a=ht[i].weight;
			*s1=i;		
		}
	for(i=0;i<n;i++)
		if(b>ht[i].weight&&(i-*s1)&&(ht[i].parent==-1)){
			b=ht[i].weight;
			*s2=i;	
		}
}

void CrtHuffmanCode(Code code[],HuffmanTree ht)
{
	int i,c,p; 
	Code cd;
	for(i=0;i<N;i++){
		cd.start=N;
		cd.ch=ht[i].c;
		c=i;
		p=ht[i].parent;
		while(p!=-1){
			--cd.start;
			if(ht[p].lchild==c)	cd.b[cd.start]='0';
			else cd.b[cd.start]='1';
			c=p;
			p=ht[p].parent;
		}
		code[i]=cd;
	}
}

void Code1(Code code[])
{
	int i,j,k;
	printf("请输入待编码的字符：");
	char s[N];
 	getchar();
	gets(s);
	printf("编码为：");
	for(i=0;i<strlen(s);i++){
		for(j=0;j<N;j++){
			if(s[i]==code[j].ch){
				k=j;
				for(j=code[j].start;j<N;j++)
					printf("%c",code[k].b[j]);
			}
		}
	}
}

void Code2(HuffmanTree ht)
{
	int i,j;
	char s[100];
	printf("请输入译码：");
	gets(s);
	i=2*N-2;j=0;
	printf("原码为：");
	while(s[j]){
		if(s[j]=='0')	i=ht[i].lchild;
		else i=ht[i].rchild;
		if(ht[i].lchild==-1){
			printf("%c",ht[i].c);
			i=M-1;
		}	
		j++;	
	}
}

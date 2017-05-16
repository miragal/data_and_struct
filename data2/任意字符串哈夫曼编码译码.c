#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
#define N 2*M+1 

typedef struct
{
	char c;
	int weight;
	int parent,lchild,rchild;
}HTNode,HuffmanTree[N];

typedef struct
{
	char ch;	//相应的字符 
	char b[M];	 //相应字符的编码 
	int start;	//每条编码的起始位置 
}Code;

int count=0;	//总节点个数 
void CtrHuffmanTree(HuffmanTree ht,char s[]);

void Select(HuffmanTree ht,int n,int *s1,int *s2);

void CrtHuffmanCode(Code code[],HuffmanTree ht);

void Code2(HuffmanTree ht);

int main (void) 
{
	HuffmanTree ht;
	Code code[M];
	char s[M];
	int i,j,l,ls=0;
	printf("请输入字符串：\n");	
	gets(s);
	l=strlen(s)-1;
	CtrHuffmanTree(ht,s);
	CrtHuffmanCode(code,ht);
	printf("编码为：");
	for(i=0;i<strlen(s);i++)
		for(j=0;j<count;j++)
			if(s[i]==code[j].ch){
				ls+=strlen(code[j].b+code[j].start);
				printf("%s",code[j].b+code[j].start);
			}
			 
	Code2(ht);
	printf("\n平均码长为：%.2f",(float)ls/l);
	return 0;
}

void CtrHuffmanTree(HuffmanTree ht,char s[])
{
	int i,s1,s2,a[256]={0},t;
	//初始化 
	for(i=0;i<N;i++){
		ht[i].weight=0;
		ht[i].c='#';
		ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
	}
	for(i=0;s[i]-'#';i++)
		a[s[i]]++;
	for(i=0;i<256;i++){
		if(a[i]>0){ 
			ht[count].c=i;
			ht[count++].weight=a[i];
		}
	}
	for(i=count;i<2*count-1;i++){
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
	for(i=0;i<count;i++){
		cd.start=count;
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

void Code2(HuffmanTree ht)
{
	int i,j;
	char s[1000];
	printf("\n请输入译码：");
	gets(s);
	i=2*count-2;j=0;
	printf("原码为：");
	while(s[j]){
		if(s[j]=='0')	i=ht[i].lchild;
		else i=ht[i].rchild;
		if(ht[i].lchild==-1&&ht[i].rchild==-1){
			printf("%c",ht[i].c);
			i=2*count-2;
		}	
		j++;	
	}
}

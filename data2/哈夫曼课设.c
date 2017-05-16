#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 1000
#define N 2*M+1 

typedef struct
{
	unsigned char c;			//字符 
	int weight;		//权值 
	int parent,lchild,rchild;	//双亲及左右孩子 
}HTNode,HuffmanTree[N];

typedef struct
{
	unsigned char ch;	//字符 
	char b[M];	 //相应字符的编码 
	int start;	//每个编码的起始位置 
}Code;

int count=0;	//总节点个数 

void Print()
{
	printf("*******************************************************************\n");
	printf("***********                                              **********\n");
	printf("***********          欢迎使用哈夫曼编/译码器             **********\n");
	printf("***********                                              **********\n");
	printf("*******************************************************************\n");
	printf("1.建立哈夫曼树     2.编码     3.压缩    4.解压     5.译码    0.退出\n"); 
	printf("请选择（0-5）\n");
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

//读取文件(file1)，建立哈夫曼树 
void CreateHuffman(HuffmanTree ht)
{
	FILE *f1;
	int i,s1,s2,a[256]={0},len;
	unsigned char c;
	if((f1=fopen("file1.txt","r"))==NULL){
		printf("file1文件打开失败！");
		return;
	}
	//初始化 
	for(i=0;i<N;i++){
		ht[i].weight=0;
		ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
	}
	//统计各个字符出现的频度，建立哈夫曼树
	while(!feof(f1)){
		c=fgetc(f1);
		a[c]++;
	} 
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
	fclose(f1); // 关闭文件
}

//编码并写入文件 (file2)
void CrtHuffmanCode(Code code[],HuffmanTree ht)
{
	FILE *f1,*f2;
	int i,j,c,p;
	f1=fopen("file2.txt","w"); //打开文件 
	Code cd;
	unsigned char ch;
	//从叶子到根依次进行编码 
	for(i=0;i<count;i++){
		cd.start=count;
		cd.b[cd.start]='\0'; 
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
	//存放对应字符的编码 
	f2=fopen("file1.txt","r");
	while(!feof(f2)){
		ch=fgetc(f2);
		for(i=0;i<count;i++)
			if(ch==code[i].ch)
				fprintf(f1,"%s",code[i].b+code[i].start);
	}
	fclose(f1); 
	fclose(f2);
}

//将file2压缩为file3 
void Compress()
{
	FILE *f1,*f2;
	char s[9];
	int i,j,a,len,l,t;	
	if((f1=fopen("file2.txt","r"))==NULL){
		printf("file1文件打开失败！");
		return;
	}
	fseek(f1, 0, SEEK_END);
    len=ftell(f1);
    l=len/8;
    fseek(f1,-len,2);
	f2=fopen("file3.txt","wb");
	i=0;
	while(!feof(f1)){
		fread(s,1,8,f1);
		t=0;
		for(j=0;j<8;j++){
				a=s[7-j]-'0';
				t+=pow(2,j)*a;
		}
		fprintf(f2,"%c",t);
		i++;
		if(i==l)	break;
	} 
	fread(s,1,len%8,f1);
	t=0;
	for(i=0,j=len%8;i<len%8;i++,j--){
				a=s[j-1]-'0';
				t+=pow(2,i)*a;
	}
	fprintf(f2,"%c",t);
	fclose(f1);
	fclose(f2);
}

//将file3解压缩为file4 
void UnCompress()
{
	FILE *f1,*f2,*f3;
	int i,l,len,j;
	char s[9];
	unsigned char n;
	if((f1=fopen("file2.txt","r"))==NULL){
		printf("file2文件打开失败！");
		return;
	}
	if((f2=fopen("file3.txt","rb"))==NULL){
		printf("file3文件打开失败！");
		return;
	}
	f3=fopen("file4.txt","w");
	fseek(f1,0,SEEK_END);
    len=ftell(f1);
    l=len/8;
    fseek(f1,-len,2);
	fclose(f1);
	i=0;
	while(!feof(f2))
	{ 
		fscanf(f2,"%c",&n);
		j=8;
		char s[9]={'0','0','0','0','0','0','0','0'};
		while(n){
			s[--j]=n%2+'0';
			n/=2;
		} 
		fprintf(f3,"%s",s);
		i++;
		if(i==l)	break;	 
	}
	fscanf(f2,"%c",&n);
	char ss[9]={'0','0','0','0','0','0','0','0'}; 
	j=8;
	while(n){
		ss[--j]=n%2+'0';
		n/=2;
	}
	fprintf(f3,"%s",ss+8-len%8);
	fclose(f2);
	fclose(f3);
}

//将file4译码并存放到file5中 
void DeCode(HuffmanTree ht)
{
	int i,len;
	char *s;
	unsigned char c; 
	FILE *f1,*f2;
	if((f1=fopen("file4.txt","r"))==NULL){
		printf("file4文件打开失败！");
		return;
	}
	i=2*count-2;
	f2=fopen("file5.txt","w"); 
	while(!feof(f1)){
		c=fgetc(f1);
		if(c=='0')	i=ht[i].lchild;
		else i=ht[i].rchild;
		if(ht[i].lchild==-1&&ht[i].rchild==-1){
			fprintf(f2,"%c",ht[i].c);
			i=2*count-2;
		}	
	}
	fclose(f1);
	fclose(f2);  
}
 
int main(void)
{
	HuffmanTree ht;
	int chioce;
	Code code[M];
	Print();
	while(1){
		scanf("%d",&chioce);
		switch(chioce){
			case 1:CreateHuffman(ht);
				   system("cls");
                   printf("已成功按照file1文件建立哈夫曼树！\n");
				   Print();
				   break;
			case 2:CrtHuffmanCode(code,ht);
				   system("cls"); 
				   printf("已成功将编码写入file2文件！\n");
				   Print();	
				   break;
			case 3:Compress();
				   system("cls");
				   printf("已成功将file2文件压缩到fil3文件！\n");
				   Print();
				   break; 
			case 4:UnCompress();
			 	   system("cls");
			       printf("已成功将file3解压缩为fil4！\n"); 
				   Print();
				   break;	   
			case 5:DeCode(ht);
				   system("cls");
				   printf("已成功译码并存入文件fil5！\n");
				   Print();
				   break;		   
			case 0:return 0;
			default:printf("输入有误,请重新输入："); 
		}
	} 
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 1000
#define N 2*M+1 

typedef struct
{
	unsigned char c;			//�ַ� 
	int weight;		//Ȩֵ 
	int parent,lchild,rchild;	//˫�׼����Һ��� 
}HTNode,HuffmanTree[N];

typedef struct
{
	unsigned char ch;	//�ַ� 
	char b[M];	 //��Ӧ�ַ��ı��� 
	int start;	//ÿ���������ʼλ�� 
}Code;

int count=0;	//�ܽڵ���� 

void Print()
{
	printf("*******************************************************************\n");
	printf("***********                                              **********\n");
	printf("***********          ��ӭʹ�ù�������/������             **********\n");
	printf("***********                                              **********\n");
	printf("*******************************************************************\n");
	printf("1.������������     2.����     3.ѹ��    4.��ѹ     5.����    0.�˳�\n"); 
	printf("��ѡ��0-5��\n");
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

//��ȡ�ļ�(file1)�������������� 
void CreateHuffman(HuffmanTree ht)
{
	FILE *f1;
	int i,s1,s2,a[256]={0},len;
	unsigned char c;
	if((f1=fopen("file1.txt","r"))==NULL){
		printf("file1�ļ���ʧ�ܣ�");
		return;
	}
	//��ʼ�� 
	for(i=0;i<N;i++){
		ht[i].weight=0;
		ht[i].lchild=ht[i].parent=ht[i].rchild=-1;
	}
	//ͳ�Ƹ����ַ����ֵ�Ƶ�ȣ�������������
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
	fclose(f1); // �ر��ļ�
}

//���벢д���ļ� (file2)
void CrtHuffmanCode(Code code[],HuffmanTree ht)
{
	FILE *f1,*f2;
	int i,j,c,p;
	f1=fopen("file2.txt","w"); //���ļ� 
	Code cd;
	unsigned char ch;
	//��Ҷ�ӵ������ν��б��� 
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
	//��Ŷ�Ӧ�ַ��ı��� 
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

//��file2ѹ��Ϊfile3 
void Compress()
{
	FILE *f1,*f2;
	char s[9];
	int i,j,a,len,l,t;	
	if((f1=fopen("file2.txt","r"))==NULL){
		printf("file1�ļ���ʧ�ܣ�");
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

//��file3��ѹ��Ϊfile4 
void UnCompress()
{
	FILE *f1,*f2,*f3;
	int i,l,len,j;
	char s[9];
	unsigned char n;
	if((f1=fopen("file2.txt","r"))==NULL){
		printf("file2�ļ���ʧ�ܣ�");
		return;
	}
	if((f2=fopen("file3.txt","rb"))==NULL){
		printf("file3�ļ���ʧ�ܣ�");
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

//��file4���벢��ŵ�file5�� 
void DeCode(HuffmanTree ht)
{
	int i,len;
	char *s;
	unsigned char c; 
	FILE *f1,*f2;
	if((f1=fopen("file4.txt","r"))==NULL){
		printf("file4�ļ���ʧ�ܣ�");
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
                   printf("�ѳɹ�����file1�ļ���������������\n");
				   Print();
				   break;
			case 2:CrtHuffmanCode(code,ht);
				   system("cls"); 
				   printf("�ѳɹ�������д��file2�ļ���\n");
				   Print();	
				   break;
			case 3:Compress();
				   system("cls");
				   printf("�ѳɹ���file2�ļ�ѹ����fil3�ļ���\n");
				   Print();
				   break; 
			case 4:UnCompress();
			 	   system("cls");
			       printf("�ѳɹ���file3��ѹ��Ϊfil4��\n"); 
				   Print();
				   break;	   
			case 5:DeCode(ht);
				   system("cls");
				   printf("�ѳɹ����벢�����ļ�fil5��\n");
				   Print();
				   break;		   
			case 0:return 0;
			default:printf("��������,���������룺"); 
		}
	} 
	return 0;
}

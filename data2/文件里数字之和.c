#include<stdio.h> 
#include<stdlib.h>
#include<io.h>
#include<string.h>

#include<io.h>

//long long fno,fsize;
long fno;
void fcountcode(char wenbenfile[]) {
FILE *fp;
//int flag=1; 
char ch;
//	char filename[LEN];
	
	printf("������Ҫ���ļ�������·�����ļ�����");
//	getchar() ;
	gets(wenbenfile) ;
	
	fp=fopen(wenbenfile,"r");
	if(fp==NULL){
		printf("\n���ļ�ʧ�ܣ�%s���ܲ�����\n",wenbenfile);
		exit(1);
		
	}
	fno=fileno(fp);
	//fsize=filelength(fno);/*ȡ���ļ���С����ByteΪ��λ*/
	//printf("\n%s�ļ��򿪳ɹ����ļ���С%d Bytes\n",wenbenfile,fsize) ;
	getchar();
//	while( (ch=fgetc(fp))!=EOF){
	while(!feof(fp)) {
	
//	while(flag){
//		fscanf(fp,"%c",&ch);
//				flag=0;
//				break;
		ch=fgetc(fp);
		printf("%c",ch);
//		if((int)ch>=0) {
//			w[ch]++;
//		}
//		else {
//			w[256+ch]++;
//		}
	    //printf("%c",ch)	;
		//w[(int)ch]++;
	}	
	fclose(fp);
	printf("\n");
	printf("**�����ļ�ͳ����ϣ�����"); 
//	getchar() ;
}
int main(){
	char wenbenfile[1000];
	fcountcode(wenbenfile);
}

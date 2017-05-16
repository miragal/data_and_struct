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
	
	printf("请输入要打开文件的完整路径及文件名：");
//	getchar() ;
	gets(wenbenfile) ;
	
	fp=fopen(wenbenfile,"r");
	if(fp==NULL){
		printf("\n打开文件失败，%s可能不存在\n",wenbenfile);
		exit(1);
		
	}
	fno=fileno(fp);
	//fsize=filelength(fno);/*取得文件大小，以Byte为单位*/
	//printf("\n%s文件打开成功，文件大小%d Bytes\n",wenbenfile,fsize) ;
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
	printf("**遍历文件统计完毕！！！"); 
//	getchar() ;
}
int main(){
	char wenbenfile[1000];
	fcountcode(wenbenfile);
}

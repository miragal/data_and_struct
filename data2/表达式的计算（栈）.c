#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100

typedef struct 
{
	int ptop;
	double data[Max];
}SeqStack;

typedef struct 
{
	int qtop;
	char s[Max];
}CharStack;

double Compute(char s[]);
int Level(char c);
double Cal(double x,double y,char c);

int main (void)
{
	char s[100];
	double t;
	printf("��������ʽ���磺10*(3/2+4*1-2)����");
	gets(s);
	t=Compute(s);
	printf("%s=%.2f",s,t);
	return 0;
}

double Compute(char s[])
{
	char c;
	int  i,m;
	double x,y;
	SeqStack *p;
	CharStack *q;
	p=(SeqStack *)malloc(sizeof(SeqStack));
	q=(CharStack *)malloc(sizeof(CharStack));
	p->ptop=-1;
	q->qtop=-1;
	q->s[++q->qtop]='#';
	i=0;
	while(s[i]){
		if(s[i]>='0'&&s[i]<='9'){	//�����ַ� 
			m=0;
			while(s[i]>='0'&&s[i]<='9'){
				m=m*10+s[i]-'0';
				i++;
			}
			p->data[++p->ptop]=m;
			i--;	//�˻ص������ַ�ĩβ
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){	//����� 
			while(Level(q->s[q->qtop])>=Level(s[i])){	//���ȼ��ߵľ���ջ���� 
				c=q->s[q->qtop--];
				y=p->data[p->ptop--];
				x=p->data[p->ptop--];
				p->data[++p->ptop]=Cal(x,y,c);	 //����������ջ 
			}
			q->s[++q->qtop]=s[i];	//�����ȼ��͵��������ջ 
		} 
		else if(s[i]=='(')	//������ֱ����ջ
			q->s[++q->qtop]='(';
		else if(s[i]==')'){	//�ȼ���
			while(q->s[q->qtop]!='('){
				c=q->s[q->qtop--];
				y=p->data[p->ptop--];
				x=p->data[p->ptop--];
				p->data[++p->ptop]=Cal(x,y,c);	
			}
			q->qtop--;	//�����ų�ջ 
		}	 
		i++;	//ͳһi++ 
	}
	while(q->qtop)	//�ַ��������ַ�ջ��û��
	{
		c=q->s[q->qtop--];
		y=p->data[p->ptop--];
		x=p->data[p->ptop--];
		p->data[++p->ptop]=Cal(x,y,c);			
	}
	return p->data[p->ptop];
}

int Level(char c)
{
	int i;
	if(c=='#')	i=-1;
		else if(c=='(')	i=0;
		else if(c=='+'||c=='-') i=1;
			else if(c=='*'||c=='/')	i=2;
	return i;
}

double Cal(double x,double y,char c)
{
	double t;
	if(c=='+')	t=x+y;
	else if(c=='-')	t=x-y;
	else if(c=='*')	t=x*y;
	else if(c=='/')	t=x/y;
	return t; 
}

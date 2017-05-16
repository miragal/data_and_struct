#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
typedef char Type;

typedef struct 
{
	int top;
	Type data[MAX];
}Stack; 

Stack *InitStack()
{
	Stack *p;
	p=(Stack *)malloc(sizeof(Stack));
	p->top=-1; 
	return p;
}

int PushStack(Stack *p,Type x)
{
	if(p->top==MAX-1)	return 0;
	p->data[++p->top]=x;
	return 1;
}

int IsEmpty(Stack *p)
{
	if(p->top==-1)	return 1;
	else return 0;
}


int Level(char a,char b)
{
	if(a=='('&&b==')'||a=='['&&b==']')
		return 1;
	else return 0;
}

int Match(char s[])
{
	int i,l=strlen(s),t,tag=1;
	Stack *p;
	char a;
	p=InitStack();
	for(i=0;i<l&&tag;i++){
		if(s[i]=='('||s[i]=='[')
			PushStack(p,s[i]);
			else{
				if(IsEmpty(p))	tag=0;
				else{
					a=p->data[p->top];
					t=Level(a,s[i]);
					if(t) p->top--;
					else tag=0;
				}
			}
	}
	if(!IsEmpty(p))	tag=0;
	return tag;
}


int main (void)
{
	int n,t;
	char s[MAX];
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(s);
		t=Match(s);
		if(t)	printf("Yes\n");
		else printf("No\n");
	}
	return 0; 
}


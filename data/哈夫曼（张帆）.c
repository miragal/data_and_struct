#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30
#define M 2*N-1
#define K 6
int n=K;
typedef struct 
{
	int weight;
	int parent,Lchild,Rchild;
}HfNode,hf[M+1];

void select(hf h,int n,int *temp1,int *temp2);
void judge(int n,hf h,int *min); 

void creathf(hf h,int n)
{
	int weight;
	int m=2*n-1;
	int i,temp;
	int s1,s2;
	for(i=1;i<=m;i++)
	{	
		if(i<=n)
		{
			scanf("%d",&weight);
			h[i].weight=weight;
		}
		else h[i].weight=0;
		h[i].parent=h[i].Lchild=h[i].Rchild=0;
	}
	
	for(i=n+1;i<=m;i++)
	{
		select(h,i-1,&s1,&s2);
		
		temp=h[s1].weight+h[s2].weight;
		
		h[i].weight=temp;
		
		h[i].Lchild=s1;
		h[i].Rchild=s2;
		h[s1].parent=h[s2].parent=i;
	
	}
}


void select(hf h,int n,int *s1,int *s2)	
{
	int i,j;
	int x1=0,x2=0;
	int m1 = 1000;
	int m2 = 1000;
	for (j=1; j<=n; j++)
	        {
	            if (h[j].weight < m1 && h[j].parent==0)
	            {
	                m2=m1; 
	                x2=x1; 
	                m1=h[j].weight;
	                x1=j;
	            }
	            else if (h[j].weight < m2 && h[j].parent==0)
	            {
	                m2=h[j].weight;
	                x2=j;
	            }
	        } 
	*s1=x1;
	*s2=x2;

}

void output(hf h,int n)
{
	int i=1;
	for(i=1;i<=2*n-1;i++)
	{	
		printf("%3d   p:%3d L£º%d R:%d\n",h[i].weight,h[i].parent,h[i].Lchild,h[i].Rchild);
	}


}	
typedef char* hfcode[6];	
void creathuffCode1(hf h,hfcode hc,int n)
{
	char *cd;
	int start,p,i,c;
	cd=(char *)malloc(sizeof(char)*n);
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		p=h[i].parent;
		while(p!=0)
		{
			--start;
			if(h[p].Lchild==c)
			cd[start]='0';
			else cd[start]='1';
			c=p;
			p=h[p].parent;
		}
			hc[i]=(char *)malloc(sizeof(char)*(n-start));
			strcpy(hc[i],&cd[start]);
	}
	free(cd);	
}	


void outcode(hfcode hc,hf h,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		switch(i)
		{
			case 1:printf("A:");break;
			case 2:printf("B:");break;
			case 3:printf("C:");break;
			case 4:printf("D:");break;
			case 5:printf("E:");break;
			case 6:printf("F:");break;
		}
		printf("%s\n",hc[i]);
	}
}

void printnum(hfcode hc,hf h,int n,char a[])
{
	int i,j;
	for(j=0;j<6;j++)
	{
		switch(a[j])
		{
			case 'A':printf("%s",hc[1]);break;
			case 'B':printf("%s",hc[2]);break;
			case 'C':printf("%s",hc[3]);break;
			case 'D':printf("%s",hc[4]);break;
			case 'E':printf("%s",hc[5]);break;
			case 'F':printf("%s",hc[6]);break;
			
		}	
	}
}


void translation(hf h,int n,char a[])
{
	int i,j,p,t;
	j=strlen(a);
	p=2*n-1;
	for(i=0;i<j;i++)
	{
		if(a[i]=='0')
			p=h[p].Lchild;
		else
			p=h[p].Rchild;
		if(h[p].Lchild==0&&h[p].Rchild==0)
		{
			t=p;
			switch(t)
			{
				case 1:printf("A");p=2*n-1;continue;
				case 2:printf("B");p=2*n-1;continue;
				case 3:printf("C");p=2*n-1;continue;
				case 4:printf("D");p=2*n-1;continue;
				case 5:printf("E");p=2*n-1;continue;
				case 6:printf("F");p=2*n-1;continue;
			}	
		}	
	}
}

int main(void)
{
	hf h;
	hfcode hc;
	creathf(h,n);
	creathuffCode1(h,hc, n);
	outcode(hc,h, n);
	int i=0;
	char a[6];
	scanf("%s",a);
	fflush(stdin);
	printnum(hc,h,n,a);
	printf("\n");
	char b[100];
	scanf("%s",b);
	translation(h,n,b);
	return 0;
}


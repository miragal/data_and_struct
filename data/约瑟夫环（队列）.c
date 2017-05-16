#include <stdio.h>
#include <stdlib.h>

void Josephus(int *q,int n,int s)
{
	int front,rear,i;
	int cnt=0;
	front=0;rear=n;
	while(front-rear){
		front=(front+1)%(n+1);
		cnt=(cnt+1)%s;
		if(cnt){
			rear=(rear+1)%(n+1);
			q[rear]=q[front];
		} 
		else	printf("%5d",q[front]);
	}
}

int main (void)
{
	int *q;
	int i,n,s;
	printf("请输入人数和密码：");
	scanf("%d%d",&n,&s);
	q=(int *)malloc(sizeof(int));
	for(i=1;i<=n;i++)
		q[i]=i;
	Josephus(q,n,s);
	return 0;
}

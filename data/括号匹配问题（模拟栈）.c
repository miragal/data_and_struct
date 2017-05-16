#include <stdio.h>
#include <string.h>

int IsMatch(char s[]);

int main (void)
{
	char s[100];
	int i;
	printf("«Î ‰»Î“ª–©¿®∫≈:");
	gets(s);
	i=IsMatch(s);
	if(i)	printf("∆•≈‰£°");
	else printf("≤ª∆•≈‰£°");
	return 0; 
}

int IsMatch(char s[])
{
	int i,top,tag;
	i=0;top=-1;tag=0;
	while(s[i]){
		if(s[i]=='(')	top++;
		else if(s[i]==')'){
			if(top==-1)	break;
			else top--;
		}	
		i++;
	}
	if(!s[i]&&top==-1)	tag=1;
	return tag;
}

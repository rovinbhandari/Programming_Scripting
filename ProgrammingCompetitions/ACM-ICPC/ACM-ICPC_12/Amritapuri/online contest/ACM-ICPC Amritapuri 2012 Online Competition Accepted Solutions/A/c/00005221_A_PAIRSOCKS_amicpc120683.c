#include<stdio.h>
int main()
{
char c[50],*p;
int r1,g1,b1,w1,n,i,S;
scanf("%d",&n);
while(n--)
{

scanf("%s",c);
p=&c;
r1=0;w1=0;g1=0;b1=0;
S=0;
	while(*p!='\0')
	{
		if(*p=='R')
		r1++;
		else if(*p=='W')
		w1++;
		else if(*p=='G')
		g1++;
		else if(*p=='B')
		b1++;
		else
		{ 
		printf("NO\n");
S=1;		
break;
		}
		
		p++;
	}
if(S==0)
{		
if((r1%2==0)&&(w1%2==0)&&(g1%2==0)&&(b1%2==0))
		printf("YES\n");
		else
		printf("NO\n");
}
}

return(0);
}

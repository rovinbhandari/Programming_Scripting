#include<stdio.h>

int main()
{
	int t;
	char c;
	int r,g,b,w;
	
scanf("%d\n",&t);
while(t--)
{
r=g=b=w=1;
while((c=getchar())!='\n')
{

if(c=='R')
r*=-1;
else if(c=='G')
g*=-1;
else if(c=='B')
b*=-1;
else if(c=='W')
w*=-1;
}
if((r+g+b+w)==4)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}

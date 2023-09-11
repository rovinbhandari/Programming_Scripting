#include<stdio.h>
#include<string.h>
int main()
{
char c[70];
int t,i=0,g=0,b=0,r=0,w=0,l[1005],q=0,j=0,v=0;
scanf("%d",&t);

q=t;
while(v<q)
{
scanf("%s",c);
if(strlen(c)%2!=0)
{
l[v]=1;
}
else
{	
	while(c[i]!='\0')
	{
		switch(c[i])
		{
		case 'R':
		r++;
		break;
		case 'B':
		b++;
		break;
		case 'G':
		g++;
		break;
		case 'W':
		w++;
		break;
		}i++;
	}

if(r%2==0 && w%2==0 && b%2==0 && g%2==0)
{
l[v]=2;
}
else
{
l[v]=1;
}}
v++;
i=0;
r=0;w=0;g=0;b=0;
}
for(j=0;j<q;j++)
{
if(l[j]==2)
{printf("YES\n");}
else
{printf("NO\n");}}

return 0;
}





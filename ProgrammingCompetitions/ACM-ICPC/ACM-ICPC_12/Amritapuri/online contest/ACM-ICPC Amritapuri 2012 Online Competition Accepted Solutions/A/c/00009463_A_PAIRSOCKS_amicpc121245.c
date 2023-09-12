#include<stdio.h>
#include<string.h>
int main()
{
int t,i,j,len,r=0,g=0,w=0,b=0;
char c[50];
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%s",c);
len=strlen(c);
r=0; b=0; g=0; w=0;
for(j=0;j<len;j++)
{
if(c[j]=='R')
{
    if(r==0)
    r++;
    else
    r=0;}
else if(c[j]=='G')
     {
    if(g==0)    g++;
    else    g=0;}
else if(c[j]=='B')
{
            if(b==0)
            b++;
            else
            b=0;
            }

            else if(c[j]=='W')
{
    if(w==0)
w++;
else
w=0;
}
}
if(r==0 && g==0 && w==0 && b==0)    printf("YES\n");
else    printf("NO\n");
}
return 0;
}

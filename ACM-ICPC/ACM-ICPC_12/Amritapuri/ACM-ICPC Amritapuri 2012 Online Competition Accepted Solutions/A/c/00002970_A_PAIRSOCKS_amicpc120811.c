#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,ans[1000],i,j,r,g,b,w;
char c[50];
scanf("%d",&t);
for(i=0;i<t;i++)
{
ans[i]=0;
scanf("%s",c);
for(r=g=b=w=j=0;c[j]!='\0';j++)
{
if(c[j]=='R')
r++;
else if(c[j]=='G')
g++;
else if(c[j]=='B')
b++;
else if(c[j]=='W')
w++;
}
if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
ans[i]=1;
}
for(j=0;j<i;j++)
{
if(ans[j]==1)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}



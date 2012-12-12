#include<stdio.h>
#include<string.h>
int main()
{

int num,r,g,b,w,i,j;
char st[50];
scanf("%d",&num);
for(i=0;i<num;i++)
{
scanf("%s",st);
r=g=b=w=0;
for(j=0;j<strlen(st);j++)
{
switch(st[j])
{
case 'R':
r++;
break;
case 'G':
g++;
break;
case 'B':
b++;
break;
case 'W':
w++;
break;
}
}
if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}

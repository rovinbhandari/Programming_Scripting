#include<stdio.h>
int main()
{
int t,r,g,b,w,i,j=0;
char a[50],*o[1005];
scanf("%d",&t);
while(t--)
{
r=g=b=w=0;
scanf("%s",a);
for(i=0;i<strlen(a);i++)
{
if(a[i]=='G')
g++;
else if(a[i]=='R')
r++;
else if(a[i]=='B')
b++;
else if(a[i]=='W')
w++;
}
if(g%2==0&&r%2==0&&w%2==0&&b%2==0)
o[j++]="YES";
else
o[j++]="NO";
}
for(i=0;i<j;i++)
printf("%s\n",o[i]);
return 0;
//getch();
}

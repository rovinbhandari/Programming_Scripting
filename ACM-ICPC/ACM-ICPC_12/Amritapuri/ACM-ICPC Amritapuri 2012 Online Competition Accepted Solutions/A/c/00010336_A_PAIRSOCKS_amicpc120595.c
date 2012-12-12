#include<stdio.h>
#include<string.h>
int main()
{int l;
int a,i,f=1,r=0,g=0,w=0,b1=0,j=0;
int ans[1005];
char b[100];
scanf("%d",&a);

while(f<=a)
{
r=0;g=0;w=0;b1=0;
scanf("%s",b);
l=strlen(b);
if(l%2!=0)
{
ans[j]=0;
j++;
}
else
{
for(i=0;b[i]!='\0';i++)
{

if(b[i]=='R')
{
r++;
}
else if(b[i]=='G')
{
g++;
}
else if(b[i]=='B')
{
b1++;
}
else 
{
w++;
}
}

if(r%2==0&&g%2==0&&w%2==0&&b1%2==0)
{
ans[j]=1;
j++;
}
else
{
ans[j]=0;
j++;
}
}
f++;
}
for(i=0;i<a;i++)
{
if(ans[i]==0)
{
printf("NO\n");
}
else
{
printf("YES\n");
}
}
return 0;
}

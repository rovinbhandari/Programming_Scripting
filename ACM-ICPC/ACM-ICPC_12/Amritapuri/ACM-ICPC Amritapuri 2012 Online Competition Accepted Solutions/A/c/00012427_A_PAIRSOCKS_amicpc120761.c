#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int r,g,b,w,i,j,k,T,m;

char *c;
char ch;
char *str[1001];
char temp[51];
scanf("%d",&T);
for(m=0;m<=T;m++)
{
gets(temp);
str[m]=(char*)malloc(strlen(temp));
strcpy(str[m],temp);
}

for(k=1;k<=T;k++)
{
c=str[k];
r=0;g=0;b=0;w=0;
for(i=0;i<strlen(c);i++)
{
ch=c[i];
if(ch=='R'&& r==0)
{
r++;
for(j=i+1;j<strlen(c);j++)
if(c[j]=='R')
r++;
}


if(ch=='G'&& g==0)
{
g++;
for(j=i+1;j<strlen(c);j++)
if(c[j]=='G')
g++;
}

if(ch=='B'&& b==0)
{
b++;
for(j=i+1;j<strlen(c);j++)
if(c[j]=='B')
b++;
}

if(ch=='W'&& w==0)
{
w++;
for(j=i+1;j<strlen(c);j++)
if(c[j]=='W')
w++;
}


}
if((r%2==0) && (g%2==0) && (b%2==0) && (w%2==0))
printf("%s","YES");
else
printf("%s","NO");

printf("%c",'\n');

}
return 0;
}

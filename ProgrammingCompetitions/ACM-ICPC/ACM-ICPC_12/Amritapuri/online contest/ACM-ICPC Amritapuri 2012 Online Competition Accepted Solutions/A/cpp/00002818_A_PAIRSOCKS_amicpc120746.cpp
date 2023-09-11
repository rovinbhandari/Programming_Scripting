#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
int t,i;
char a[51];
scanf("%d",&t);
while(t--)
{
int c[4]={0};
scanf("%s",&a);
i=0;
while(a[i]!='\0')
{
if(a[i]=='R')
++c[0];
else if(a[i]=='G')
++c[1];
else if(a[i]=='B')
++c[2];
else if(a[i]=='W')
++c[3];
++i;
}
for(i=0;i<4;++i)
{
if(c[i]%2!=0)
break;
}
if(i==4)
printf("YES\n");
else
printf("NO\n");
}
}

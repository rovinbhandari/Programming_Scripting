#include<stdio.h>
#include<string.h>
int main()
{
int N,i,p1,p2,p3,p4;
char str[250];
scanf("%d",&N);
while(N--)
{
p1=0;
p2=0;
p3=0;
p4=0;
scanf("%s",str);
for(i=0;str[i]!='\0';i++)
{
if(str[i]=='R')
p1++;
if(str[i]=='G')
p2++;
if(str[i]=='B')
p3++;
if(str[i]=='W')
p4++;
}
if(p1%2!=0 || p2%2!=0 || p3%2!=0 || p4%2!=0)
printf("NO\n");
else
printf("YES\n");
}
return 0;
}
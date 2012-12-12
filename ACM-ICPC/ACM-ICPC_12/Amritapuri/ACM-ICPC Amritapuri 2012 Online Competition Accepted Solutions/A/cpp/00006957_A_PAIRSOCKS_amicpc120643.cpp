#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
char a[51];
scanf("%s",a);int c1=0,c2=0,c3=0,c4=0;
for(int i=0;a[i]!='\0';i++)
{
switch(a[i])
{
case 'R':
c1++;
break;
case 'G':
c2++;
break;
case 'B':
c3++;
break;
case 'W':
c4++;
break;
}
}
if(c1%2==0&&c2%2==0&&c3%2==0&&c4%2==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}

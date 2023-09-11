#include<stdio.h>
#include<string.h>
int main()
{int t;
scanf("%d",&t);
while(t--)
{
char a[51];
scanf("\n");
gets(a);
int p=0,q=0,r=0,s=0,i;
for(i=0;i<strlen(a);i++)
{
if(a[i]=='R')
p++;
else if(a[i]=='G')
q++;
else if(a[i]=='B')
r++;
else
s++;
}
if(p%2==0&&q%2==0&&r%2==0&&s%2==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}

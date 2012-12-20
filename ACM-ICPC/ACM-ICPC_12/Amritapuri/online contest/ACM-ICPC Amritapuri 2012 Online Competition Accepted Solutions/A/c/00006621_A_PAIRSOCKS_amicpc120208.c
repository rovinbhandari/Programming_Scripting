#include<stdio.h>
#include<string.h>

int main()
{
int t,i=0;
char a[52];
int r=0,g=0,b=0,w=0,size=0;
scanf("%d",&t);
while(t--)
{
scanf("%s",a);
size=strlen(a);
r=0;b=0;g=0;w=0;
for(i=0;i<size;i++)
{

if(a[i]=='R')
r++;
else if(a[i]=='B')
b++;
else if(a[i]=='G')
g++;
else
w++;
}
if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
printf("YES\n");
else
printf("NO\n");

}





return 0;
}
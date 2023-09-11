#include<stdio.h>

int main()
{
int t,r=0,b=0,g=0,w=0,i,re[1000],j;
char c[50];

j=0;
scanf("%d",&t);

while(t--)
{
scanf("%s",c);
i=0;
while(c[i]!='\0')
{
 if(c[i]=='R')
   r++;
 else if(c[i]=='G')
   g++;
 else if(c[i]=='B')
  b++;
 else if(c[i]=='W')
  w++;
 else
 return 0;
i++;
}

if( r%2==0 && g%2==0 && b%2==0 && w%2==0)
re[j]=1;

else
 re[j]=0;
j++;

r=0;
g=0;
b=0;
w=0;
}

for(i=0;i<j;i++)
if(re[i]==1)
 printf("YES\n");
else
 printf("NO\n");  
return 0;

}


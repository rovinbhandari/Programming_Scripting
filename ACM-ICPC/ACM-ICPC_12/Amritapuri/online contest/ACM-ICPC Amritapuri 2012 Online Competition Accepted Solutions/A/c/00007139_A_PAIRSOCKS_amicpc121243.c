#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int i;
void main()
{
char s[51];
char m[1000][4];
int r,g,b,w,t,j;
scanf("%d",&t);
 i=0;
 if(t>1000)
 {
 printf("overflow");
 exit(0);
}
while(i<t)
{scanf("%s",s);j=0; 
 r=0;g=0;b=0;w=0;
while(s[j]!='\0')
{if(s[j]=='W')
w++;
else if(s[j]=='B')
b++;
else if(s[j]=='R')
r++;
else
g++;
j++;

}
if(((w%2)==0)&&((g%2)==0)&&((b%2)==0)&&((r%2)==0))
strcpy(m[i],"YES");
else
strcpy(m[i],"NO");i++;
}i=0;
for(i=0;i<t;i++)
printf("%s\n",m[i]);


}


#include <stdio.h>
#include<string.h>
int main()
{
  char c[51];
  int i,r=0,g=0,b=0,w=0;
  int t;
  scanf("%d",&t);
  while(t>0)
  {
r=0;g=0;b=0;w=0;
  scanf("%s",c);
  for(i=0;i<strlen(c);i++)
  {
  if(c[i]=='R')
  r++;
  if(c[i]=='G')
  g++;
  if(c[i]=='B')
  b++;
  if(c[i]=='W')
  w++;
  }
        
 if(((r%2)==0)&&((g%2)==0)&&((b%2)==0)&&((w%2)==0))
   printf("YES\n");
  else
  printf("NO\n");
t--;
}
}

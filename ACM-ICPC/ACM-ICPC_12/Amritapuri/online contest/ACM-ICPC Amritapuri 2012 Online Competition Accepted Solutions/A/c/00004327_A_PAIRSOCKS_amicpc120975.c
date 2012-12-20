#include<stdio.h>
int main()
{
   int i,t,r=0,g=0,b=0,w=0,j;
   char str[51];
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      scanf("%s",str);
      j=0;r=0;g=0;b=0;w=0;
      while(str[j]!='\0')
      {
          if(str[j]=='R')
          r++;
          else if(str[j]=='G')
          g++;
          else if(str[j]=='B')
          b++;
          else if(str[j]=='W')
          w++;
          j++;
      }
      if((r%2==0) && (g%2==0) && (b%2==0) && (w%2==0))
      printf("YES\n");
      else
      printf("NO\n");
   }
return 0;   
}

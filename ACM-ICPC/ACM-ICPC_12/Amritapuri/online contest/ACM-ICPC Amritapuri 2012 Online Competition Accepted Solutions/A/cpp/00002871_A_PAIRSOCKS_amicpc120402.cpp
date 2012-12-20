#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{
  long long i,j,k,m,n,t,p,c,red,blue,green,white,len;
  char s[100];

  scanf("%lld",&t);

  while(t--)
  {
    scanf("%s",s);
    len = strlen(s);
    red = 0;blue=0; green = 0; white = 0;

    for(i=0;i<len;i++)
    {
      if(s[i]=='R')
      red++;

       if(s[i]=='B')
       blue++;

       if(s[i]=='G')
        green++;

       if(s[i]=='W')
       white++;
    }

      if(red%2==0 && blue%2==0 && green%2==0 && white%2==0  )
      printf("YES\n");
      else
       printf("NO\n");


  }

  return 0;
}

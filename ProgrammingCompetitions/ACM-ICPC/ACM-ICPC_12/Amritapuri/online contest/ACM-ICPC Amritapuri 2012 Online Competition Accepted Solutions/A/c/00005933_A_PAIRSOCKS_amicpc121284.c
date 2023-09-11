#include<stdio.h>

#include<string.h>
int main()
{
      int i,j,t,m,w,p,q;
      char n[1000][50];
      scanf("%d",&t);
      
      for(i=0;i<t;i++)
      {
      scanf("%s",&n[i]);
		      m=0;
		      w=0;
		      p=0;
		      q=0;
      for(j=0;j<strlen(n[i]);j++)
      {
      if(n[i][j]=='R')
      m++;
      else if(n[i][j]=='G')
      w++;
      else if(n[i][j]=='B')
      p++;
      else if(n[i][j]=='W')
      q++;
      }
      if((m%2==0)&&(w%2==0)&&(p%2==0)&&(q%2==0))
      printf("YES\n");
      else
      printf("NO\n");
      }
    return 0;
}








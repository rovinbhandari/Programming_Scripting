#include <stdio.h>
#include<string.h>
int main()
{
int i;
 int T;

 char  string[50]; 
 int R,G,W,B;

 
 scanf("%d",&T);
	while(T--)
	{
	 R=G=B=W=0; 
	 scanf("%s",string);
	
	 i=0;
	 while(string[i]!='\0')
	 {
	 if(string[i]=='R')
	   R++;
	 else if(string[i]=='B')
	    B++;
          else if(string[i]=='G')
 	   G++;
          else if(string[i]=='W')
	   W++;
         i++;
         }
         if((R%2==0)&&(B%2==0)&&(W%2==0)&&(G%2==0))
          printf("YES\n");
         
         else 
          printf("NO\n");
         }
         return 0;
     }

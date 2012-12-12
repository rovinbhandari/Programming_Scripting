#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int i,t,w,r,g,b,k,j;
    char s[50];
    cin>>t;
   for(i=0;i<t;i++)
   {           cin>>s;
               r=0,w=0,g=0,b=0;
               if(strlen(s)%2==1)
                                  printf("NO\n");
               else
               {
               for(j=0;j<strlen(s);j++)
               {                  
                                  
                                 if (s[j]=='W')
                                    w++;
                                  else if (s[j]=='R')
                                    r++;
                                  else if (s[j]=='G')
                                    g++;
                                  else if (s[j]=='B')    
                                    b++;             
               }
               if(w%2==0 && r%2==0 && g%2==0 && b%2==0)
               printf("YES\n");
               else
               printf("NO\n");
               }

   }                      
}
                   

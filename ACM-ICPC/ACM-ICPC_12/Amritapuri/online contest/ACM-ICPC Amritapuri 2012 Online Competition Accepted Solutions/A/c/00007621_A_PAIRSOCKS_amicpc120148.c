#include<stdio.h>
int main()
{
    int t,a[4],i;
    char s[51];
    scanf("%d",&t);
    while(t--)
    {
     for(i=0;i<4;i++)
     {
       a[i]=0;              
     }
     scanf("%s",s);
     for(i=0;s[i]!='\0';i++)
     {
         if(s[i]=='R')
         {
           a[0]=(a[0]+1)%2;        
         }
         else if(s[i]=='G')
         {
           a[1]=(a[1]+1)%2;        
         }
         else if(s[i]=='B')
         {
           a[2]=(a[2]+1)%2;        
         }
         else if(s[i]=='W')
         {
           a[3]=(a[3]+1)%2;        
         }    
     }         
     for(i=0;i<4;i++)
     {
      if(a[i]!=0)
      {
       break;          
      }               
     }
     if(i==4)
     {
      printf("YES\n");       
     }
     else
     {
      printf("NO\n");   
     }
    }
 return 0;   
}

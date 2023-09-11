#include<stdio.h>
int main()
{ 
    
    int test_case,r,g,b,w,i;
    char in[50];
    scanf("%d",&test_case);
   while(test_case--)
   { 
    scanf("%s",&in);
    r=g=b=w=0;
     for(i=0;in[i]!='\0';i++)
     {    
      if(in[i]=='R')
      {
       ++r;
      }
      else if(in[i]=='G')
      {
       ++g;
      }
      else if(in[i]=='B')
      {
       ++b;
      }
      else if(in[i]=='W')
      {
       ++w;
      }
     }
     if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
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

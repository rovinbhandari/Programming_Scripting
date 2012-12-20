#include<iostream>
#include<stdio.h>
using namespace std;
int main()
  {
   	int t,i,rcount,gcount,bcount,wcount;
    char str[55];
    scanf("%d",&t);
    while(t!=0)
     {
      i=0;
      rcount=0;
      gcount=0;
      bcount=0;
      wcount=0;         
      scanf("%s",str);
      while(str[i]!='\0')
       {
         if(str[i]=='R')
           {
               rcount++;         
           } 
         if(str[i]=='G')
           {
               gcount++;         
           } 
         if(str[i]=='B')
           {
               bcount++;         
           } 
         if(str[i]=='W')
           {
               wcount++;         
           }            
          i++;                     
       }   
      if(rcount%2==0 && gcount%2==0 && bcount%2==0 && wcount%2==0)
        {
              printf("YES\n");                              
        }
      else
        {
              printf("NO\n");
        }   
      t--;
     }  	   		  
	return 0;
  }	   	  

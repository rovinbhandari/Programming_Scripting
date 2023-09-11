#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
  {
    long long int i,t,s,bx,st[50005],l,b,h,dim,sq,maxi,count;
    scanf("%lld",&t);
    while(t!=0)
     {      
      maxi=0;      
      count=0;
      scanf("%lld %lld",&s,&bx);
      for(i=0;i<s;i++)
          scanf("%lld",&st[i]); 
      for(i=0;i<bx;i++)
         {
          scanf("%lld",&l);
          scanf("%lld",&b);
          scanf("%lld",&h);
          sq=l*l+b*b+h*h;
          dim=sqrt(sq);
          if(dim>maxi)
             maxi=dim;          
         }
      for(i=0;i<s;i++)
          {
             if(st[i]<=maxi)
                count++;         
          }   
      printf("%lld\n",count);               
      t--;
     }  	  		  
	return 0;
  }	   	  

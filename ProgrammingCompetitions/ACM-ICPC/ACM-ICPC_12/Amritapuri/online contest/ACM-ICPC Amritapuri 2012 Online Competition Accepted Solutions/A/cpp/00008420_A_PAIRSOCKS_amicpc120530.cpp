//============================================================================
// Name        : pp1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
   int n,i,j;
   char c[100];
   int s[5];
   int flag;
   int b[1001];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
	   for(j=0;j<=4;j++)
	   {
		   s[j]=0;
	   }
      scanf("%s",c);
      flag=0;
      for(j=0;c[j]!=0;j++)
      {
    	  switch(c[j])
    	  {
    	  case 'R':s[1]++;
    	  break;
    	  case 'G':s[2]++;
    	  break;
    	  case 'B':s[3]++;
    	  break;
    	  case 'W':s[4]++;
    	  break;
    	  }
    	 }
        for(j=1;j<5;j++)
        {
        	if(s[j]%2==1)
        	{
        		b[i]=1;
        		flag=1;
        		break;
        	}
        }
        if(flag==0)
        {
        	b[i]=0;
        }
      }
    for(i=0;i<n;i++)
     {
    	 if(b[i]==0)
    	 {
    		 printf("YES\n");
    	 }
    	 else
    	 {
    		 printf("NO\n");
    	 }
     }

}


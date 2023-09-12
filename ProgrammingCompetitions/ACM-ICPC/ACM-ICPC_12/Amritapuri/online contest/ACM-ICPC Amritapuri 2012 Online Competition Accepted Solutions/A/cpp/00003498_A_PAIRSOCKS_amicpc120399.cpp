#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
   int t,r,g,b,w,i;
   char c[55];
   cin>>t;
   while(t--)
   {
      r=g=w=b=0;
      scanf("%s",c);
   for(i=0;c[i]!='\0';i++)
   {
      if(c[i]=='R')
      r++;
      else
      if(c[i]=='G')
      g++;
      else
      if(c[i]=='B')
      b++;
      else
      if(c[i]=='W')
      w++;
   }
   if((r%2==0)&&(b%2==0)&&(w%2==0)&&(g%2==0))
    cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;
   }
   return(0);
}              
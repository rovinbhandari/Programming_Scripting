#include<iostream>
#include<string.h>
using namespace std;
int main()
{
 int t=0;
 cin>>t;
 while(t--)
 {
   string c;
   int r=0,g=0,b=0,w=0;
   cin>>c;
   int n= c.size();
   if(n%2!=0)
   {cout<<"NO"<<endl;
   }
   else
   {
    for(int k=0;k<n;k++)
   {
     if(c[k]=='R')
     {
      r++;
     }
     else if(c[k]=='G')
     {
      g++;
     }
     else if(c[k]=='B')
     {
       b++;
     }
     else if(c[k]=='W')
     {
        w++;
     }
   }
   if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
 }
 }
 return 0;
}

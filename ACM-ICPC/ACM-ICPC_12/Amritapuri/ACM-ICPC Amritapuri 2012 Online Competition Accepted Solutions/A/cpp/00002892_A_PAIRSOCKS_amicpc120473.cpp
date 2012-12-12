#include<iostream>

using namespace std;
int main()
{  int t;
   cin>>t;
   while(t--)
   {  string c;
      cin>>c;
      int r,b,g,w,i;
      r=b=g=w=0;
      for(i=0;i<c.size();i++)
      {  if(c[i]=='R')
         r++;
         if(c[i]=='G')
         g++;
         if(c[i]=='B')
         b++;
         if(c[i]=='W')
         w++;
      }
      if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
      cout<<"YES"<<endl;
      else
      cout<<"NO"<<endl;
   }

   return 0;
}

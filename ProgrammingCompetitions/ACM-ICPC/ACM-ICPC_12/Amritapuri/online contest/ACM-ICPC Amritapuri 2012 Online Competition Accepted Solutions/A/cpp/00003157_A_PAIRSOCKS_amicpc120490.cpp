#include<iostream>
using namespace std;

int main()
{
    int t;
    string s;
    int i=0,r=0,g=0,b=0,w=0,l;
    
  cin>>t;
    
    while(t--)
    {
      r=0;g=0;b=0;w=0;
      
      cin>>s;
      
      l=s.length();
      
      for(i=0;i<l;i++)
      {
        if(s[i]=='R')
        r++;
        
        if(s[i]=='G')
        g++;
        
        if(s[i]=='B')
        b++;
        
        if(s[i]=='W')
        w++;
        
      }
      
      
      if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
     cout<<"YES\n";
      
      else
   cout<<"NO\n";
      
    } 
    return 0;
}

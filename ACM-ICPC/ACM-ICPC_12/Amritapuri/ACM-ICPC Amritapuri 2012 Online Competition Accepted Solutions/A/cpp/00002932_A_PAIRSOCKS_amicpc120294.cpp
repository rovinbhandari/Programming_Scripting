#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
 int r,g,b,w;
 r=g=b=w=0;
 string s;
 cin>>s;
 for(int i=0;i<s.length();i++)
         {
          if(s[i]=='R')
                       r++;                     
         else if(s[i]=='G')
                       g++;
         else if(s[i]=='B')
                       b++;
         else
                       w++;              
                       
         }
 if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
           cout<<"YES"<<endl;
 else
           cout<<"NO"<<endl;
           
}    
return 0;
}

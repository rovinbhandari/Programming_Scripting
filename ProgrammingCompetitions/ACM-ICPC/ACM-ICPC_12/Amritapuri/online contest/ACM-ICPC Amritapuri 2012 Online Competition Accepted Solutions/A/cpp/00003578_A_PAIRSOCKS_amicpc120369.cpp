#include<iostream>
using namespace std;
int main()
{ 
int t;
string s;
cin>>t;
int cntr,cntb,cntg,cntw;
while(t--)
{
  cin>>s;
  cntr=0,cntg=0,cntb=0,cntw=0;
  for(int i=0;i<s.size();i++)
  {  
          if(s[i]=='R')
          cntr++;
          else if(s[i]=='G')
          cntg++;
          else if(s[i]=='B')
          cntb++;
          else if(s[i]=='W')
          cntw++;
          
   }
   if(cntr%2==0 && cntg%2==0 && cntb%2==0 && cntw%2==0)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
}
return 0;
}  

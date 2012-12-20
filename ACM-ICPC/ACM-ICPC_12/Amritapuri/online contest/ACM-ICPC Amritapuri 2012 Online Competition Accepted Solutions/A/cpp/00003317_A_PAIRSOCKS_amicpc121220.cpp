#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{   int t;
    cin>>t;
   while(t--)
{  string s;
    cin>>s;
    int t1=0;
    int R=0,W=0,B=0,G=0;
    while(t1<s.length())
   {
       if(s[t1]=='R')
       R++;
       else if (s[t1]=='B')
       B++;
       else if(s[t1]=='G')
       G++;
       else if(s[t1]=='W')
       W++;

       t1++;
   }
   if((R%2==0)&&(B%2==0)&&(G%2==0)&&(W%2==0))
   cout<<"YES\n";
   else
    cout<<"NO\n";

}
return 0;
}

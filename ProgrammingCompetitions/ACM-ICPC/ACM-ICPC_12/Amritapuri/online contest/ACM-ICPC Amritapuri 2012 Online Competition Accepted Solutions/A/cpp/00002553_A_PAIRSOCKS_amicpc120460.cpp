#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int c1=0,c2=0,c3=0,c4=0;
              string s;
              cin>>s;
              for(int i=0;i<s.length();i++)
              {
                      if(s[i]=='R')
                      c1++;
                      else if(s[i]=='G')
                      c2++;
                      else if(s[i]=='B')
                      c3++;
                      else if(s[i]=='W')
                      c4++;
              }
              if(c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0)
              cout<<"YES"<<endl;
              else
              cout<<"NO"<<endl;
    }
    return 0;
}

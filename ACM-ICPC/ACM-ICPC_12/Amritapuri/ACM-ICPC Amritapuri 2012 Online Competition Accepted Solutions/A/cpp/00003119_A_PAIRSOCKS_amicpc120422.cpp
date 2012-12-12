#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int co[4];
    int t,i,l,flag;
    string s;
    cin>>t;
    while(t--)
    {
              flag=0;
              memset(co,0,sizeof(co));
              cin>>s;
              l=s.length();
              for(i=0;i<l;i++)
              {
                              if(s[i]=='R')
                              co[0]++;
                              else if(s[i]=='G')
                              co[1]++;
                              else if(s[i]=='B')
                              co[2]++;
                              else if(s[i]=='W')
                              co[3]++;
              }
              for(i=0;i<4;i++)
         {     if(co[i]%2!=0)
              {
                            flag=1;
                            cout<<"NO\n";
                            break;
              }
         }    
              if(flag==0)
              {
                          cout<<"YES\n";
              }
    }
    return 0;
}

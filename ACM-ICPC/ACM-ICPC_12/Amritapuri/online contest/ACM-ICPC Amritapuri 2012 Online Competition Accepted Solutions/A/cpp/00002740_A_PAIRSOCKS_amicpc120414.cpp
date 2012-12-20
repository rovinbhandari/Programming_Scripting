#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
              int r=0,g=0,b=0,w=0;
              while(1)
              {
              char ch=getchar();
              if(ch=='\n')
              break;
              if(ch=='R')
              r++;
              else if(ch=='G')
              g++;
              else if(ch=='B')
              b++;
              else
              w++;
              }
              if(r%2==0 && g%2==0 && w%2==0 && b%2==0)
              cout<<"YES\n";
              else
              cout<<"NO\n";
    }
    return 0;
}

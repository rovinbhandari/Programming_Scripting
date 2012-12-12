#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,r,g,b,w;
    string s;
    scanf("%d",&t);
    while(t--)
    { r=0;
    g=0;
    b=0;
    w=0;
              cin>>s;
              for(int i=0;i<s.length();i++)
              {
                      if(s[i]=='R')
                      r++;
                      else if(s[i]=='G')
                      g++;
                      else if(s[i]=='B')
                      b++;
                      else if(s[i]=='W')
                      w++;
                      }
                      if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
                      printf("YES\n");
                      else
                      printf("NO\n");
                     
                      }
                     
                      return 0;
                      }
                      

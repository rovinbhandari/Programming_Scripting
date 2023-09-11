#include<iostream>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
int main()
{
    string st;
    int t,i;
    cin>>t;
    while(t--)
    {
              cin>>st;
              int r,g,b,w;
              r=g=b=w=0;
              for(i=0;i<st.length();i++)
              {
                                        if(st[i]=='G')
                                        g++;
                                        else if(st[i]=='W')
                                        w++;
                                        else if(st[i]=='B')
                                        b++;
                                        else
                                        r++;
              }
              if(g%2==0&&w%2==0&&b%2==0&&r%2==0)
              printf("YES\n");
              else
              printf("NO\n");
    }
    return 0;
}

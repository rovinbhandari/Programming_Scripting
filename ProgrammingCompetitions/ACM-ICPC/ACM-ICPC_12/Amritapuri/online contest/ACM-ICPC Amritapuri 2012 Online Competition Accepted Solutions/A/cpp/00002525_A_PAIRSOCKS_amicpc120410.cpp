#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<cmath>
#include<stdlib.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              string s;
              cin>>s;
              int c1=0,c2=0,c3=0,c4=0;
              
              for(int i=0;i<s.length();i++)
              {
                      if(s[i]=='R')
                      c1++;
                      else if(s[i]=='B')
                      c2++;
                      else if(s[i]=='G')
                      c3++;
                      else
                      c4++;
                      
              }
              if(c1%2==0&&c2%2==0&&c3%2==0&&c4%2==0)
              cout<<"YES"<<endl;
              else
              cout<<"NO"<<endl;
              
    }
    //system("pause");
    return 0;
}

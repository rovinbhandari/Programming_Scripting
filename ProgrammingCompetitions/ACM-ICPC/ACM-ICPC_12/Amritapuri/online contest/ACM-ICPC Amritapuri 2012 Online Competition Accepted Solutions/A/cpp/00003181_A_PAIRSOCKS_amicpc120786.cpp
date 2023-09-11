#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
   string s;
   int n,k,i,l;
   cin>>n;
   int a[27];
   while(n--)
   {
             cin>>s;
             memset(a,0,sizeof(a));
             l= s.size();
             for( i=0; i<l; i++)
             {
               k=(int)s[i];
                a[k-65]++;
                }
                int f=0;
                for(i=0; i<27; i++)
                 if(a[i]%2!=0)
                 {
                  f=1;
                  break;
                  }
                  if(f==0)
                  cout<<"YES\n";
                  else
                  cout<<"NO\n";
                  }
                  return 0;
                  }

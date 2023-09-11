#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=0;ii<t;ii++)
    {
                           int n,m;
                           scanf("%d%d",&n,&m);
                           long long int a[n];
                           for(int i=0;i<n;i++)
                               scanf("%lld",&a[i]);
                           int co=0;
                           long long int b,mb=0;
                           long long int p,q,r;
                           for(int i=0;i<m;i++)
                           {    scanf("%lld%lld%lld",&p,&q,&r);
                                             b=(p*p)+(q*q)+(r*r);
                                             if(b>mb)
                                              mb=b;
                           }
                           for(int i=0;i<n;i++)
                          {
                                   long long int y=a[i]*a[i];
                                   if(y<=mb)
                                      co++;

                          }
                          printf("%d\n",co);
    }
    return 0;
}

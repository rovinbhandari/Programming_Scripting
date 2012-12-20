#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<cmath>
#include<stdlib.h>
using namespace std;

long long a[50001],b[50001],c[50001],d[50001];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int n,m;
              cin>>n>>m;
              for(int i=0;i<n;i++)
              {
              scanf("%lld",&a[i]);
              }
              long long e[m];
              long long max=0;
              for(int i=0;i<m;i++)
              {
                      scanf("%lld%lld%lld",&b[i],&c[i],&d[i]);
                      e[i]=(long long)sqrt((double)(b[i]*b[i]+c[i]*c[i]+d[i]*d[i]));
                      if(e[i]>=max)
                      max=e[i];
              }
              
              long long count=0;
              for(int i=0;i<n;i++)
              {
                      if(a[i]<=max)
                      count++;
                      
              }
              cout<<count<<endl;
              
              
              
    }
    //system("pause");
    return 0;
}

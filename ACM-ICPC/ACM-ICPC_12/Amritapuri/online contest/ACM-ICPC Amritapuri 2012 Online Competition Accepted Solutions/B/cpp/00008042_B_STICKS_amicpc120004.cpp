#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long len[50000];
double max(double a,double b)
{
    return (a>b)?a:b;
}
int main()
{
    long t,n,m,i,j;
    double a,b,c,maxdiag,ans;
    cin>>t;
    while(t--)
     {
         cin>>n>>m;
         maxdiag=-1;
         for(i=0;i<n;i++)
           cin>>len[i];
         while(m--)
          {
              cin>>a>>b>>c;
              double diag = sqrt(a*a+b*b+c*c);
              maxdiag = max(diag,maxdiag);

          }
        sort(len,len+n);
        for(i=0;i<n;i++)
          if(len[i]>maxdiag)
            break;
        cout<<i<<endl;
     }
    return 0;
}

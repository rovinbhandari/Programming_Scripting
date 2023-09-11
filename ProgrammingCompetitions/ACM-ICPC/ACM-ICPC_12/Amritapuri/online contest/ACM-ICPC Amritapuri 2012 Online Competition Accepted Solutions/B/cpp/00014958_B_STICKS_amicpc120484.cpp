#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <cmath>


#define pb(x) push_back(x) 

using namespace std;

typedef long long int ll;

int main()
{
    int t,m,n;
    double h,b,w;
    cin>>t;

    while(t--)
    {
              cin>>n>>m;
              double l[n];
              double d = 0;
              double maxd = 0;
              int count = 0;

              for(int i=0;i<n;i++)
              cin>>l[i];

              for(int i=0;i<m;i++)
              {
                      cin>>h>>b>>w;
                      d = sqrt( h*h + b*b + w*w );
                      if( d > maxd )
                          maxd = d;
              }
              
              for(int i=0;i<n;i++)
              {
                      if(l[i] <= maxd)
                      count++;
              }

              cout<<count<<endl;
    }

    //system("pause");
    return 0;
} 

                            
              
              

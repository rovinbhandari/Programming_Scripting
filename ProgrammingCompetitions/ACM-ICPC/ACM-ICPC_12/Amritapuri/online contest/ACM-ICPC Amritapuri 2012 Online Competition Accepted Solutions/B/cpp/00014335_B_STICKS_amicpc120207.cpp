#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
 
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    int a[n+2];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int mxs=0;
    for(int i=0;i<m;i++)
    {
            int x,y,z;
            double d1,d2,d3,d4,d5,d6;
            cin>>x;
            mxs=max(mxs,x);
            cin>>y;
            mxs=max(mxs,y);
            cin>>z;
            mxs=max(mxs,z);
            d1=sqrt((x*x)+(y*y));
            mxs=max(mxs,(int)(d1));
            d2=sqrt((x*x)+(z*z));
            mxs=max(mxs,(int)d2);
            d3=sqrt((y*y)+(z*z));
            mxs=max(mxs,(int)d3);
            d4=sqrt((d1*d1)+(z*z));
            mxs=max(mxs,(int)d4);
            d5=sqrt((d2*d2)+(y*y));
            mxs=max(mxs,(int)d5);
            d6=sqrt((d3*d3)+(x*x));
            mxs=max(mxs,(int)d6);
    }
  //  cout<<mxs<<endl;
    int count=0;
    for(int i=0;i<n;i++)
    if(a[i]<=mxs)
    count++;
    cout<<count<<endl;
   }    
//system("pause");
return 0;
}
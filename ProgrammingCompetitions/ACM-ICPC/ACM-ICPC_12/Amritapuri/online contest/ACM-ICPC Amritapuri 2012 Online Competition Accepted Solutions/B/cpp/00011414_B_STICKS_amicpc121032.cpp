#include <iostream>
#include <cmath>
float dummy()
{
   return 1.2;
}
using namespace std;
 
main()
{   dummy();
    double l[100000];
    double tm,max,a,b,c;
    int t,count,n,m,i;
    cin>>t;
    while(t--)
    {
          max=0.0;
          count=0;
          cin>>n>>m;
          for(i=0; i<n; i++) cin>>l[i];
        for(i=0; i<m; i++)
        {
            cin>>a>>b>>c;
            tm=sqrt(a*a + b*b + c*c);
            if(tm>max)
            max=tm;
        }
        for(i=0; i<n; i++) if(l[i]<=max)  count++;
        cout<<count<<endl;
    }
    return 0;
}

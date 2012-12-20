#include <iostream>
#include <math.h>
double maxi(double a,double b,double c)
{
    return(sqrt(a*a+b*b+c*c));
}
using namespace std;
int main()
{
    long t,ns,nb;
    double l[50000],m[3][50000],c,ans[10];
    double max,maxtemp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        max=0;
        cin>>ns;
        cin>>nb;
        for(long j=0;j<ns;j++)
        {cin>>l[j];}
        for(long j=0;j<nb;j++)
        {
            cin>>m[0][j];
            cin>>m[1][j];
            cin>>m[2][j];
            maxtemp=maxi(m[0][j],m[1][j],m[2][j]);
            if(maxtemp>max)
            {
                max=maxtemp;
            }
        }
        c=0;
        for(long k=0;k<ns;k++)
        {
            if(l[k]<=max)
            c++;
        }
        ans[i]=c;
    }
    for(long i=0;i<t;i++)
    cout<<ans[i]<<"\n";
    return 0;
}

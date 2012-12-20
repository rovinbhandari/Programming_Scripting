#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    unsigned long long t,m,i,n,l,b,h,c=0,max=0;
    double d;
    
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        while(m--)
        {
            cin>>l>>b>>h;
            d=sqrt(l*l+b*b+h*h);
            if(max<d)
            max=(unsigned long long)d;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]<=max)
            c++;
        }
        cout<<c<<endl;
        c=max=0;
    }
    return 0;
}

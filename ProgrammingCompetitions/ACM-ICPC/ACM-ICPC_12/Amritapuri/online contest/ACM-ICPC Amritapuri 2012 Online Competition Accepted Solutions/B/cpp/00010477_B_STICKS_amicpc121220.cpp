#include<stdio.h>
#include<iostream>
#include<cmath>
#define MAX 500005
using namespace std;
int main()
{

    double max=0,body;
    int t,n,m,count,i;
    double stick[MAX];
    double l,b,h;
    cin>>t;
    while(t--)
    {
        max=0,count=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
        cin>>stick[i];
        for(i=0;i<m;i++)
        {
            cin>>l>>b>>h;
            body=sqrt(l*l+b*b+h*h);
            if(body>max)
            max=body;
        }

        for(i=0;i<n;i++)
        {
            if(stick[i]<=max)
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int T,N,M;
    cin>>T;
    long long int l[50005];
    long long int a[50005],b[50005],c[50005],dia[50005],x;

    for(int i=1;i<=T;i++)
    {
        int count=0,max=0;
        cin>>N>>M;
        for(int j=1;j<=N;j++)
            cin>>l[j];
        for(int j=1;j<=M;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            x=(a[j]*a[j])+(b[j]*b[j])+(c[j]*c[j]);
            dia[j]=sqrt(x);
            if(dia[j]>max)
                max=dia[j];
        }
        for(int j=1;j<=N;j++)
            if(l[j]<=max)
                count++;
        cout<<count<<endl;

    }

}

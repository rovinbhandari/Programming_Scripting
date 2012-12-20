#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
main()
{
    int te;
    cin>>te;
    while(te--)
    {
        int result=0,n,m;
        cin>>n>>m;
        long long int a[50005];
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>a[i];
            getchar();
            long long int l,b,h;
            long long int max=0;
        for(int i=0;i<m;i++)
        {
            cin>>l>>b>>h;
            long long int dia=(int)sqrt((l*l)+(b*b)+(h*h));
            if(max<dia) max=dia;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]<=max) result++;
        }
        cout<<result<<endl;

    }
}

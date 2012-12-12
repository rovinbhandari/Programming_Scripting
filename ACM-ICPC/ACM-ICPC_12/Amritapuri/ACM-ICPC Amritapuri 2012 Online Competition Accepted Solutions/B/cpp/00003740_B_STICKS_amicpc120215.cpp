#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long st[50001],b[50001],h[50001],l[50001];
int main()
{
    int t,n,m;
    long long mx;
    int sum;
    scanf("%d",&t);
    for(;t>0;t--)
    {
                 scanf("%d%d",&n,&m);
                 for(int i=0;i<n;i++)
                 {
                         cin>>st[i];
                 }
                 mx=0;
                 for(int i=0;i<m;i++)
                 {
                         cin>>l[i]>>b[i]>>h[i];
                         mx=max(mx,l[i]*l[i]+b[i]*b[i]+h[i]*h[i]);
                 }
                 sum=0;
                 for(int i=0;i<n;i++)if(st[i]*st[i]<=mx)sum++;
                 cout<<sum<<endl;
    }
}

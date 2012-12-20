#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int t,n,m,i,ct,j;
float num;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&n,&m);
long long int ans,a[n],x,y,z,max=-1;
for(i=0;i<n;i++)
{
scanf("%lld",&a[i]);
}
for(i=0;i<m;i++)
{
scanf("%lld%lld%lld",&x,&y,&z);
ans=(x*x+y*y+z*z);
if(ans>max)
max=ans;
}
ct=0;
for(i=0;i<n;i++)
{
if(a[i]*a[i]<=max)
ct++;
}
printf("%d\n",ct);
getchar();
}
return 0;
}

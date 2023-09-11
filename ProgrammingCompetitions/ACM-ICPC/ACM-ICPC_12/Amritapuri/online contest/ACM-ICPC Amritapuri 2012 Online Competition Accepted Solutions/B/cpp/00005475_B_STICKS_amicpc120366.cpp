#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{int t;
scanf("%d",&t);
while(t--)
{
 int n,m;
scanf("%d%d",&n,&m);
int a[n];int c=0;
long long int x,y,z;
long double ma=0.0,d;
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(int i=0;i<m;i++)
{scanf("%lld%lld%lld",&x,&y,&z);
d=(double)sqrt(x*x+y*y+z*z);
if(d>ma)ma=d;
}
for(int i=0;i<n;i++){

if(ma>=a[i])c=c+1;}
printf("%d\n",c);
}
return 0;
}




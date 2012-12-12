#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
main()
{
double ans;
long long int st[70000],a,b,c;
long long int i=0,t,t1=4,t2=2,n=2,count=0;
double max=0;
scanf("%lld",&t);
while(t--)
{
scanf("%lld%lld",&t1,&t2);
for(max=0,count=0,i=0;i<t1;i++)
scanf("%lld",&st[i]);
for(i=0;i<t2;i++)
{
scanf("%lld%lld%lld",&a,&b,&c);
ans=sqrt(a*a+b*b+c*c);
if(ans>max)
max=ans;
}
for(i=0,count=0;i<t1;i++)
{
if(st[i]<=max)
count++;
}
printf("%lld\n",count);
}
}

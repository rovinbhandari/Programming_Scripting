#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int t;
scanf("%d",&t);
while(t--) 
{
int i,n,m,con=0;
long long int max,item;
scanf("%d %d",&n,&m);
long long int a[50001],b[50001],c[50001],sum[50001],l[50001];
for(i=0;i<n;i++)
{
scanf("%lld",&item);
l[i]=item*item;
}
max=0;
for(i=0;i<m;i++)
{
scanf("%lld   %lld   %lld",&a[i],&b[i],&c[i]);
sum[i]=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
if(max<sum[i])
max=sum[i];
}
for(i=0;i<n;i++)
{
if(l[i]<=max)
con++;
}
printf("%d\n",con);
}
return 0;
}

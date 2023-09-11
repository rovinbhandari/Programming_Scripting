#include<cstdio>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
long int t;
long int l[100001],a[50001],b[50001],c[50001];
scanf("%ld",&t);
while(t--)
{
    long int n,m,i,j;
    long int diag,max=0;
    long int ctr=0;
    scanf("%ld%ld",&n,&m);
    for(i=0;i<n;i++)
       scanf("%ld",&l[i]);
   for( j=0;j<m;j++)
   {
    scanf("%ld%ld%ld",&a[j],&b[j],&c[j]);
    diag=sqrt(a[j]*a[j]+b[j]*b[j]+c[j]*c[j]);
    if(diag>max)
     max=diag;
   }
   for(j=0;j<n;j++)
     if(l[j]<=max)
       ctr++;
   printf("%ld\n",ctr);
}
   return 0;
}

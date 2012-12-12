#include<stdio.h>

int main()
{
long int max=0;
long int n,t,i,j,k,m;
long int l[50000];
long int a[50000],b[50000],c[50000];
unsigned long int size[50000];
long int sum;
unsigned long int length;
scanf("%ld",&t);
for(i=0;i<t;i++)
{
sum = 0;
max = 0;
scanf("%ld",&n);
scanf("%ld",&m);
for(j=0;j<n;j++)
scanf("%ld",&l[j]);
for(j=0;j<m;j++)
scanf("%ld%ld%ld",&a[j],&b[j],&c[j]);
for(j=0;j<m;j++)
{
size[j] = (a[j]*a[j]) + (b[j]*b[j]) + (c[j]*c[j]);
if(size[j] > max || j == 0)
max = size[j];
}
for(j=0;j<n;j++)
{
length = l[j]*l[j];
if(length <= max)
sum++;
}
printf("%ld\n",sum);
}
return 0;
}




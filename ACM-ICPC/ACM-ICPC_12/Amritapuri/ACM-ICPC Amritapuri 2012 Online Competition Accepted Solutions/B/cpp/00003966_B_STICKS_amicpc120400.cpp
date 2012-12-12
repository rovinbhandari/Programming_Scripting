#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int t,i;
char q;
long m,n,k,a,b,c;
long max=0;
long l[50001];
scanf("%d",&t);
while(t--)
{
scanf("%ld %ld",&n,&m);
for(i=0;i<n;i++){
scanf("%ld",&l[i]);}
max=0;
for(i=0;i<m;i++)
{
scanf("%ld %ld %ld",&a,&b,&c);
k=sqrt(a*a+b*b+c*c);
if(k>=max)
max=k;
}
scanf("%c",&q);
k=0;
for(i=0;i<n;i++)
{if(l[i]<=max)
k++;}
printf("%ld\n",k);

}
return 0;}

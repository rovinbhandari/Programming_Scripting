#include<stdio.h>
#include <cmath>
int main () {
int t;
scanf("%d",&t);
while ( t-- ) {
int n,p;
scanf("%d%d",&n,&p);
int a[n+1],i,l,m,k,ma=0,lo1;
double lo;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<p;i++){
scanf("%d%d%d",&l,&m,&k);
lo = sqrt(l*l+m*m);
lo = sqrt(lo*lo + k*k);
lo1 = (int)lo;
// printf("%d\n",lo);
if ( ma< lo )
ma = lo;
}
int count = 0;
for ( i = 0; i < n; i++ ){
if ( a[i] <= ma)//*a[i]*a[i] >ma )
count++;
}
// printf("%d\n",ma);
printf("%d\n",count);
}
return 0;
}

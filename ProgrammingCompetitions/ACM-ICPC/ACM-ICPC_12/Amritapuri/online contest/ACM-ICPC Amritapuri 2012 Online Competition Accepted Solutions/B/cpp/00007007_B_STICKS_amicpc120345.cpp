#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
int main () {
int t;
scanf("%d",&t);
while ( t-- ) {
int n,p;

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
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
if ( ma< lo )
ma = lo;
}

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
int count = 0;
for ( i = 0; i < n; i++ ){
if ( a[i] <= ma)//*a[i]*a[i] >ma )
count++;
}

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/printf("%d\n",count);
}
return 0;
}

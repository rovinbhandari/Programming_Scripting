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
using namespace std;
int x[1000000];
int main () {
int t;
scanf("%d",&t);
while ( t--) {
int n,l,h,j;

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
int i;
memset(x,0,sizeof(x));
scanf("%d",&n);
int a[n+1];

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
scanf("%d%d",&l,&h);
for ( i = 0; i < n; i++)
scanf("%d",&a[i]);
sort(a,a+n);
long long sum = 0;
for ( i = 0; i < n- 2; i++){
for ( j = i + 1; j < n-1; j++ ){
sum +=int(upper_bound(a+j+1,a+n,h-a[i]-a[j])-lower_bound(a+j+1,a+n,l-a[i]-a[j]));
}
}

/*This question is easy.. I can surely do this.
  I am quiet confident about it.
	Lets Roll..
*/
printf("%lld\n",sum);
}
return 0;
}

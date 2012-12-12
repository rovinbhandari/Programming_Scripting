#include<cstdio>
#include<cmath>
using namespace std;

int main() {
  int t;
  int n,m,count;
  long long int diag,max,x,y,z;
  int a[50001];
  int i;
  scanf("%d", &t);
  while(t--) {
    max = 0;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
      scanf("%d", &a[i]);
    }
    for(i=0;i<m;i++) {
      scanf("%lld%lld%lld", &x,&y,&z);
      diag = sqrt(x*x+y*y+z*z);
      if(max<diag)
	max=diag;
    }
    count=0;
    for(i=0;i<n;i++) {
      if(a[i] <= max)
	count++;
    }
    printf("%d\n",count);
  }
}

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//#define INFILE "./input.txt"
//#define OUTFILE "./output.txt"

using namespace std;

int main () {

		long long int tc,n,m,l[60000],diag,maxdiag,count,x,y,z;

//		freopen (INFILE,"r",stdin);
//		freopen (OUTFILE,"w+",stdout);

		for (scanf ("%lld",&tc);tc;tc--) {
				scanf ("%lld %lld",&n,&m);
				count=0;
				maxdiag=0;
				for (int i=0;i<n;i++) {
						scanf ("%lld",&l[i]);
				}
				for (int i=0;i<m;i++) {
						scanf ("%lld %lld %lld",&x,&y,&z);
						diag=sqrt(x*x+z*z+y*y);
						if (diag > maxdiag)
							maxdiag=diag;
				}
				for (int i=0;i<n;i++) {
					if (l[i] <= maxdiag) count++;
					}

					printf ("%lld\n",count);
			}
			return (0);
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include<string.h>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define maX(a,b) (a) > (b) ? (a) : (b)
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
        long long n,m,L[50000],A[50000],B[50000],C[50000],D[50000],ans,k,y;
        scanf("%lld %lld",&n,&m);
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&L[i]);
        }

        for(int i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&A[i],&B[i],&C[i]);
            D[i]=(sqrt(A[i]*A[i] + B[i]*B[i] + C[i]*C[i]));
        }

        y=*max_element(D,D+m);

        for(k=0;k<n;k++)
        {
            if(L[k]<=y)
            {
                ans++;
            }
        }
        printf("%lld\n",ans);
	}
return 0;
}

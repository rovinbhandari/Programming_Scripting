/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n,m,l[50000], a,b,c;
    in_T
    {
        int diag_max = 0;
        in_I(n);in_I(m);
        for(int i=0;i<n;i++)
            in_I(l[i]);

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            int foo = sqrt((long long)a*a + b*b + c*c);
            diag_max = max(diag_max, foo);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(l[i]<=diag_max)
                ans++;
        }
        cout<<ans<<endl;
    }
}

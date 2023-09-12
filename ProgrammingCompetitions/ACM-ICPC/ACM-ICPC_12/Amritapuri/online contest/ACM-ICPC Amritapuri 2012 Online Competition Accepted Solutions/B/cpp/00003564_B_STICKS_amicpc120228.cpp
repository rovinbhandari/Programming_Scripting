#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <fstream>

using namespace std;

#define PB push_back
#define MP make_pair
#define INF (int)1e9
#define F first
#define S second

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int> > TI;

#define LIM 50005

LL L[LIM],B[LIM];
int N,M;
LL u,v,w;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;i++){
            scanf("%lld", &L[i]);
            L[i] *= L[i];
        }
        LL mx=-1;
        for(int i=0;i<M;i++){
            scanf("%lld %lld %lld", &u, &v, &w);
            B[i]=u*u+v*v+w*w;
            mx=max(mx,B[i]);
        }
        int ct=0;
        for(int i=0;i<N;i++) if(L[i] <= mx) ct++;
        printf("%d\n",ct);
    }
    return 0;
}

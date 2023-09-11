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

int* ar;
int n;

int ctT(int num)
{
    int tot = 0;
    for(int i=0;i<(n-2);++i) {
        int a = i;
        int b = i+1;
        int c = n-1;
        while(b<c && c>i && b>i) {
            if(ar[a]+ar[b]+ar[c] > num) --c;
            else {
                tot += (c-b);
                ++b;
            }
        }
    }
    return tot;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int l,h;
        scanf("%d%d%d",&n,&l,&h);
        ar = new int[n];
        for(int i=0;i<n;++i) scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        if(n==1 || n==2) printf("0\n");
        else printf("%d\n",(ctT(h)-ctT(l-1)));
    }
}

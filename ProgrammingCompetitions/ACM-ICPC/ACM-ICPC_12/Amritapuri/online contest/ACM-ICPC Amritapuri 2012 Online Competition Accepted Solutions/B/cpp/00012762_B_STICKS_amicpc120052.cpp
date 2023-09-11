#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cctype>
#include<fstream>

typedef long long LL;

#define FOR(i, a, b) 	for(LL i=a;i<b;i++)
#define REP(i, a) 	FOR(i, 0, a)
#define RFOR(i, a, b) 	for(LL i=a-1;i>=b;i--)
#define RREP(i, a) 	RFOR(i, a, 0)
#define PB(x) 		push_back(x)
#define PP() 		pop_back()
#define SZ 		size()
#define LEN 		length()
#define BG 		begin()
#define ED 		end()

using namespace std;

int main(int argc, char** argv)
{
    LL t, n, m, a, b, c, max;
    vector<LL> vn;
    vector<LL> boxes;

    scanf("%lld", &t);

    REP(z, t){
        scanf("%lld %lld", &n, &m);
        vn.clear();
        vn.resize(n);

        REP(i, n){
            scanf("%lld", &vn[i]);
        }

        max = -1;
        REP(i, m){
            scanf("%lld %lld %lld", &a, &b, &c);

            LL x = ((LL)sqrt(a*a + b*b + c*c));

            if(max < x)
                max = x;
        }

        LL ans = 0;
        REP(i, vn.size()){
            if(vn[i] <= max){
                ans += 1;
            }
        }

        printf("%lld\n", ans);

    }

	return 0;
}

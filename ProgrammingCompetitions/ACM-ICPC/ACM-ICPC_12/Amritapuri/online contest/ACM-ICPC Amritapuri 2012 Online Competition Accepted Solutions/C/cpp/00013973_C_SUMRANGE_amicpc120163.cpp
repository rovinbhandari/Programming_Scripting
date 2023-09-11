#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>

typedef unsigned long long ULL;
typedef long long LL;

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) ((a>0)?a:-a))

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define PII pair<int,int>
#define MOD 1000000007
int sumarr[1000010],ind=0,temp[1000010];
namespace IO
{
const int SIZE = 1 << 19;
char buff[SIZE], *p = buff + SIZE;

char read_char()
{
    if( p == buff + SIZE )
    {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}

inline int read_int()
{
    char c;

    while( !isdigit( c = read_char() ) );

    int r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}
}
using namespace IO;
using namespace std;
int main()
{
    int  t,N,L,H,in;
    cin>>t;

    while(t--)
    {
        scanf("%d %d %d",&N,&L,&H);

        int v[1500];

        ind=0;
        for(int i=0;i<N;i++)
        {
            cin>>v[i];
            //s.push_back(v[i]);
        }
        sort(v,v+N);
        int trip=0,sum;

        for(int i=0;i<N-2;i++){
            for(int j=i+1;j<N-1;j++){
                sum=v[i]+v[j];
                int low=int(lower_bound(v+j+1,v+N,L-sum)-v);
                int high=int(upper_bound(v+j+1,v+N,H-sum)-v);
                trip=trip+high-low;
            }
        }
        printf("%d\n",trip);
    }
    return 0;
}

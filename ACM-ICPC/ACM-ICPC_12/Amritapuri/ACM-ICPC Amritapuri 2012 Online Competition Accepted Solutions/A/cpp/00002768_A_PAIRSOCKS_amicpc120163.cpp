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
#define ABS(a) ((a>0)?a:-a)

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define PII pair<int,int>
#define MOD 1000000007
using namespace std;
int main()
{
    int t;
    char ar[2000];
    scanf("%d",&t);
    int len,i;
    getchar();
    while(t--)
    {
        gets(ar);
        int a[30];
        a['R'-'A']=0;
        a['G'-'A']=0;
        a['B'-'A']=0;
        a['W'-'A']=0;
        len=strlen(ar);
        for(i=0;i<len;i++)
        {
            a[ar[i]-'A']++;
           // cout<<"t";
        }


        if(a['R'-'A']%2==0 && a['G'-'A']%2==0 && a['W'-'A']%2==0 && a['B'-'A']%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

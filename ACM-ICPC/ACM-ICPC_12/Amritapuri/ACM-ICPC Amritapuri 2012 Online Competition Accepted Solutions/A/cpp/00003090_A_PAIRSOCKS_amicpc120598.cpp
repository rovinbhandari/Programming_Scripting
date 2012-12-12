#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>

typedef long long int LL;
typedef vector<int> vi;
typedef vector<LL> vii;
cell dir[4]={cell(0,1), cell(1,0), cell(0,-1), cell(-1,0) };
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    S(t);
    while(t--)
    {
              string s;
              cin>>s;
              int ans = 0,i,r=0,g=0,w=0,b=0;
              REP(i,s.length() )
              {
                               if(s[i]=='R')r++;
                               if(s[i]=='G')g++;
                               if(s[i]=='B')b++;
                               if(s[i]=='W')w++;
              }
              if(r%2==0 && b%2==0 && w%2==0 && g%2==0)
              cout<<"YES"<<endl;
              else
              cout<<"NO"<<endl;
    }
    return 0;
}         

#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<queue>
#include<sstream>
#include<cstring>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

                 
#define oo                                      (int)13e7
#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
 
#define sf(n)                                   scanf("%lf",&n)
#define fill(a,v)                               memset(a, v, sizeof a)
#define ull                                     unsigned long long
#define ll                                              long long
#define bitcount                        __builtin_popcount
#define all(x)                          x.begin(), x.end()
#define pb( z )                                 push_back( z )
#define gcd                                     __gcd
#define FOR(m)                                  for(int i=0;i<m;i++)
#define FORS(n)                                 for(int j=0;j<n;j++)
#define REP(m,n)                                for(int i=m;i<n;i++)
#define REPS(m,n)                               for(int j=m;j<n;j++)
# define PI                         1/acos(-1.0)
#define max(a,b)   a>b?a:b  

#define chk(i,j) i&(1<<j)

using namespace std;


int main()
{
    int t;
    int r=0,g=0,b=0,w=0;
    string s;
    scanf("%d",&t);
    for(int i1=0;i1<t;i1++)
    {
            cin>>s;
            r=0;g=0;b=0;w=0;
            for(int i=0;i<s.length();i++)
            {
                            if(s[i]=='R')
                            r++;
                            else if(s[i]=='B')
                            b++;
                            else if(s[i]=='W')
                            w++;
                            else if(s[i]=='G')
                            g++;
            }
            if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
            
    }
    
    
    return 0;    
}

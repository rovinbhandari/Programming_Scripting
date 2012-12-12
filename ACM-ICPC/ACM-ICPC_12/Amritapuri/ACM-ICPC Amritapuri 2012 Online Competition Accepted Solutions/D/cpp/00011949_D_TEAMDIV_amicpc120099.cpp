
/* Author Piyush */
//STL includes
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <string>
//C includes
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>
//Other includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#pragma comment(linker, "/STACK:16777216")

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define V(x) vector< x >
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define fill(a,v) memset(a, v, sizeof(a))
#define PRINT(x) cout << #x << " " << x << endl
#define S(N) scanf("%lld",&N)
#define gc getchar_unlocked
#define sqr(x) (x*x)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())

//Constants
const long double MPI = 3.14159265358979323846264338;
const long double E = 2.71828182845904523536028747;
const int INF = (int) 1e9;

typedef pair<int,int> PI;
typedef pair<int,PI> TRI;
typedef V( int ) VI;
typedef V( PI ) VII;
typedef V( string ) VS;
typedef long long LL;
typedef long double LD;
#define MOD 1000000007
int dfs(int a , vector <vector <int> > & gr,vector <bool> & vis, vector<int>&col , int c)
{
    vis[a] =  1;
    col[a] = c;
    for (int i = 0 ;i < gr[a].size() ; i++)
    {
        if(vis[gr[a][i]]){
                if(col[gr[a][i]] == c)return 0;
        }
        if (!vis[gr[a][i]])
        {
            int r = dfs(gr[a][i],gr,vis,col,1-c) ;
            if(r==0)return 0;
        }
    }
    return 1;
}

int po(int ans)
{
    int a = 1;
    for (int i = 0 ; i < ans ;i++)
    {
        a = (a*2)% MOD ;
    }
    return a%MOD;
}

int main() {
    int t;
    cin  >> t;
    while(t--) {
        int n;
        cin >> n ;
        vector < vector <int> > gr(n) ;
        for (int i = 0 ; i < n ; i++)
        {
            int k ;
            cin >> k;
            for (int j = 0; j < k ;j++)
            {
                int l ;
                cin >> l;
                gr[i].push_back(l) ;
                gr[l].push_back(i) ;

            }
        }

        int ans = 0;
        vector <bool> vis(n,false) ;
        vector <int> col(n,2);
        for (int i = 0 ; i <  n ;i++)
        {
            if (!vis[i])
            {
                int rr = dfs(i,gr,vis,col,0) ;
                if(rr==0) {
                    ans  = -1;
                    break;
                }
                ans++ ;
            }
        }
        if(ans==-1) {
            cout << 0 << endl;
            continue;
        }
        cout << po(ans) << endl ;
    }
    return 0;

}

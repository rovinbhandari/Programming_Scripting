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

string str;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        cin>>str;
        int sz=str.size();
        int ct[4]={0,0,0,0};
        for(int i=0;i<sz;i++){
            if(str[i]=='R') ct[0]++;
            else if(str[i]=='B') ct[1]++;
            else if(str[i]=='G') ct[2]++;
            else ct[3]++;
        }
        if(ct[0]%2==0 && ct[1]%2==0 && ct[2]%2==0 && ct[3]%2==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

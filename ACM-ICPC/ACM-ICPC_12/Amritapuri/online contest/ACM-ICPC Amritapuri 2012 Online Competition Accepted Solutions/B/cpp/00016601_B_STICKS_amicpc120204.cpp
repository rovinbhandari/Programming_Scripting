#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <limits.h>
#include <signal.h>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    ll t,n,m,a,b,c;
    cin >> t;
    while(t--){
        ll cnt=0;
        cin>>n>>m;
        ll L[n];
        ll d;
        for(ll i=0;i<n;i++){
            cin>>L[i];
        }
        ll max=-1;
        
        for(ll i=0;i<m;i++){
            cin>>a>>b>>c;
            d=(long long)sqrt(a*a+b*b+c*c);
            if(d>max)max=d;
        }
        for(ll j=0;j<n;j++)
            if(L[j]<=max)cnt++;
        cout<<cnt<<endl;
    }
	return 0;
}

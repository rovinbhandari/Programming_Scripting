#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
#define readint(n)      scanf("%d",&n)
#define readull(n)      scanf("%llu",&n)
#define readll(n)       scanf("%lld",&n)
#define readf(n)        scanf("%f",&n)
#define readd(n)        scanf("%lf",&n)
#define init(mem)       memset(mem,0,sizeof(mem))
#define ll              long long int
#define ull             unsigned long long int
using namespace std;


int main(){
    int t;
    string str;
    int c1,c2,c3,c4;
    readint(t);
    while(t--){
        cin>>str;
        c1=0;
        c2=0;
        c3=0;
        c4=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='R'){
                c1++;
            }
            else if(str[i]=='G'){
                c2++;
            }
            else if(str[i]=='B'){
                c3++;
            }
            else{
                c4++;
            }
        }
        if(c1%2==0 and c2%2==0 and c3%2==0 and c4%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
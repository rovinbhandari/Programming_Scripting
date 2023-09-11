#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
#include <string.h>
#define FOR(i,a,b)  for(int i = a;i<=b;i++)
#define REP(i,n) for (int i=0;i<(int)(n);i++)

using namespace std;

void solve();

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    REP(i,t)    solve();
    return 0;
}

void solve()
{
    int a[123] = {0};
    string s;
    cin>>s;
    REP(i,s.size())
    {
        a[s[i]]++;
    }
    if(a['R']%2 == 0 && a['G']%2 == 0 && a['B']%2 == 0 && a['W']%2 == 0)
        cout<<"YES\n";
    else    cout<<"NO\n";
}

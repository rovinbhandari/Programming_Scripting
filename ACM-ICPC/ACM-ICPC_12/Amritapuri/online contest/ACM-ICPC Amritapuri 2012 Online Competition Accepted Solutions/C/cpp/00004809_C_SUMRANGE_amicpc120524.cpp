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
    int n;
    int l,h;
    cin>>n;
    cin>>l>>h;
    int a[1001];
    REP(i,n)    cin>>a[i];
    //cout<<n<<" "<<l<<" "<<h;
    sort(a,a+n);
    //REP(i,n)    cout<<a[i]<<" ";
    long long ans1 = 0,ans2 = 0;
    REP(i,n)
    {
        int j = i+1,k = n-1;
        while(j < k)
        {
            if(a[i] + a[j] + a[k] >= l) k--;
            else
            {
                ans1 += (k - j );
                j++;
            }
        }
    }
    REP(i,n)
    {
        int j = i+1,k = n-1;
        while(j < k)
        {
            if(a[i] + a[j] + a[k] > h) k--;
            else
            {
                ans2 += (k - j );
                j++;

            }
        }
    }
    //cout<<ans2<<" "<<ans1<<"\n";
    cout<<ans2 - ans1<<"\n";
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i,l,n) for(int i=l;i<n;i++)
#define INT(c) int c;scanf("%d",&c);
#define DBL(c) double c;scanf("%lf",&c);
#define LL(c) long long c;scanf("%ll",&c);
#define ULL(c) unsigned long long c;scanf("%llu",&c);
#define MOD 1000000007
#define Ull unsigned long long
#define Ll long long
bool cmp (int i,int j) { return (i<j); }

int main()
{
    INT(t);
    FOR(i,0,t)
    {
        INT(n);
        INT(m);
        int l[n];
        FOR(j,0,n)
        {
            scanf("%d",&l[j]);
        }
        //float len[m];
        double curr=0;
        double max=0;
        FOR(j,0,m)
        {
            curr=0;
            DBL(x);DBL(y);DBL(z)
            curr+=x*x;
            curr+=y*y;
            curr+=z*z;
            curr=sqrt(curr);
            if(curr>max)
                max=curr;
        }
        //std::sort(len, len + m, std::greater<float>());
        int cnt=0;
        FOR(j,0,n)
        {
            if(l[j]<=max)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}








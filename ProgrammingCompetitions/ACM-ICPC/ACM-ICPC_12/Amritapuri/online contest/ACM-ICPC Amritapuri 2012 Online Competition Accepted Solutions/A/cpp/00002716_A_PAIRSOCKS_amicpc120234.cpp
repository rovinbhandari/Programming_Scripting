#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define MUL(a,b) ((a)%MOD*(b)%MOD)%MOD
#define SQR(a) ((a)*(a))
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define f(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main()
{
    int t;si(t);char str[55];int r,g,b,w;
    while(t--)
    {
        cin>>str;r=g=b=w=0;
        int l=strlen(str);
        f(i,0,l)
        {
            if(str[i]=='R')r++;
            else if(str[i]=='G')g++;
            else if(str[i]=='B')b++;
            else w++;
        }
        if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

#include<iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <string>

#define all(i,n) for(i = 0; i < (n); i++)
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mod 1000000007
using namespace std;
int main()
{
    int n,t,l,i,c[5];
    char a[100];
    scanf("%d",&t);
    cin.ignore();
    while(t--)
    {
        gets(a);
        //cout<<a<<endl;
        c[1]=0;
        c[2]=0;
        c[3]=0;
        c[4]=0;
        l=strlen(a);
        all(i,l)
        {if(a[i]=='R')
          c[1]++;
          else if(a[i]=='G')
          c[2]++;
          else if(a[i]=='B')
          c[3]++;
          else if(a[i]=='W')
          c[4]++;
        }
        int flag=0;
        for(i=1;i<=4;i++)
        {if(c[i]%2==1)
        flag=1;}
        if(flag==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;




    }
    return 0;
}

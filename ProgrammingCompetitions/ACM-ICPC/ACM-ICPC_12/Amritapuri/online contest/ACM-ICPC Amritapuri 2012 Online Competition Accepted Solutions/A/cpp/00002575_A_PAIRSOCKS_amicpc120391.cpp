#include <iostream>
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
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)                    scanf("%d",&n)
#define Sl(n)                     scanf("%lld",&n)
#define Sf(n)                     scanf("%lf",&n)
#define Ss(n)                     scanf("%s",n)
using namespace std;
/* template <class T>
inline void r_f(T &p)
{
         char c;
         while ((c=getchar_unlocked()) < 48 | c > 57);
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
} */
int main()
{
    int t,i,j,k,n;
    char s[51];
    #ifndef ONLINE_JUDGE
    //freopen("example.txt","r",stdin);
    #endif
    S(t);
    // r_f(t);
    while(t--)
    {
        cin>>s;
        int r=0,b=0,w=0,g=0;
        for(i=0;i<strlen(s);i++)
        {
        	if(s[i]=='R')
        	r++;
        	else if(s[i]=='G')
        	g++;
        	else if(s[i]=='B')
        	b++;
        	else
        	w++;
        }
        if(g%2||r%2||w%2||b%2)
        cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

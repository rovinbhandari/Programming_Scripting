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

#include <string>


#define all(i,n) for(i = 0; i < (n); i++)

#define SET(p) memset(p,-1,sizeof(p))

#define CLR(p) memset(p,0,sizeof(p))

#define maX(a,b)	((a)>(b)?(a):(b))

#define miN(a,b)	((a)<(b)?(a):(b))

#define S(n)	scanf("%d",&n)

#define P(n)	printf("%d\n",n)

#define Sl(n)	scanf("%lld",&n)

#define Pl(n)	printf("%lld\n",n)

#define Sf(n)   scanf("%lf",&n)

#define Ss(n)   scanf("%s",n)

#define LL long long

#define ULL unsigned long long

#define pb push_back

using namespace std;

char str[10000];

int main()

{

int t,i,l,r,w,g,b;

S(t);

while(t--)

{

    r=0;w=0;g=0;b=0;

    scanf("%s",str);

    l=strlen(str);

    for(i=0;i<l;i++)

    {

        if(str[i]=='R')

            r++;

        else if(str[i]=='G')

            g++;

        else if(str[i]=='B')

            b++;

        else if(str[i]=='W')

            w++;

    }

    if((r%2)==0 && (g%2)==0 && (w%2)==0 && (b%2)==0 )

        printf("YES\n");

    else

        printf("NO\n");

}

return 0;

}


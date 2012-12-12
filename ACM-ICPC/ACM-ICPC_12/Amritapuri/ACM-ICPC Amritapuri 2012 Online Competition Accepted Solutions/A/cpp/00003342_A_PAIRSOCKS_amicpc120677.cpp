#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <limits.h>

using namespace std;

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int N,i,j,T,r,g,b,w;
char str[100];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        N=strlen(str);
        r=g=b=w=0;
        for(i=0;i<N;i++)
        {
            switch(str[i])
            {
                case 'R' : r++; break;
                case 'W' : w++; break;
                case 'G' : g++; break;
                case 'B' : b++; break;
            }
        }
        if(r%2==0 && w%2==0 && g%2==0 && b%2==0)
          printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}

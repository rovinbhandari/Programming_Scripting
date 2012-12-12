# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <deque>
using namespace std;
typedef unsigned long long int ulli;
int main()
{
    //freopen("input.txt","r",stdin);
    int n,T,r,g,b,w,i;
    char c[55];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s", c);
        r=g=b=w=0;
        n=strlen(c);
        for(i=0;i<n;i++)
        {
            if(c[i]=='R')
                r++;
            else if(c[i]=='G')
                g++;
            else if(c[i]=='B')
                b++;
            else if(c[i]=='W')
                w++;
        }
        if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

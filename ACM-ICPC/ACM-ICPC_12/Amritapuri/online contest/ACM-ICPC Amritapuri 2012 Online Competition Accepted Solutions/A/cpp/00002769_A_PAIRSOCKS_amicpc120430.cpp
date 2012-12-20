#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<map>
#include<stack>

#define sf scanf
#define pf printf
#define forn(i,a,n) for(i=a;i<n;i++)

using namespace std;
char s[51];
int main()
{
    int t,i,l;
    int cr,cg,cw,cb;
    sf("%d",&t);
    while(t--)
    {
        cr=cg=cw=cb=0;
        sf("%s",s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
                               if(s[i]=='R')
                               cr++;
                               if(s[i]=='G')
                               cg++;
                               if(s[i]=='B')
                               cb++;
                               if(s[i]=='W')
                               cw++;
        }
        if((cr %2==0 ) && (cg %2==0) && (cb %2==0) && (cw %2==0))  
        pf("YES\n");
        else
        pf("NO\n");    
    }
    //system("pause");
    return 0;
}

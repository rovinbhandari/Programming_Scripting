#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
#define ABS(x) ((x)>0?(x):(-(x)))

#define FL(i,a,b) for(int i=a;i<b;i++)
#define FE(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define SORTF(x) sort(x.begin(),x.end(),func);
#define SORT(x) sort(x.begin(),x.end())
#define PP(x) push_back(x)
using namespace std;
typedef long long int LL;
typedef unsigned long long ULL;
typedef string ST;

#define MOD 1000000007
LL power(LL n,LL po)
{
    LL ans=1;

    while(po>0)
    {
        if(po&1)
        {
            ans=((ans%MOD)*(n%MOD))%MOD;
        }
        n=(n*n)%MOD;
        po/=2;

    }
    return ans;
}
int main()
{
    int i,j,t;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w+",stdout);
    SSD(t);
    int no[20004];
    for(int t1=1; t1<=t; t1++)
    {
        int n;
        int rival;
        SSD(n);
        vector<list<int> > team(n);
        int k;
        for(i=0;i<n;i++)
        {
            no[i]=-1;
            SSD(k);
            for(int j=0;j<k;j++)
            {
                SSD(rival);
                team[i].PP(rival);
                team[rival].PP(i);
             }
        }
        queue<int> q;
        LL coun=0;
        while(1)
        {
            j=0;
            while(no[j]!=-1 &&j<n) j++;
            if(j>=n) break;
            no[j]=0;
            q.push(j);
            while(!q.empty())
            {
                int pres=q.front();
                q.pop();
               // cout<<q.size();
               // cout<<pres<<' '<<no[pres]<<endl;
                for(list<int>::iterator it=team[pres].begin();it!=team[pres].end();it++)
                {
                    rival=*it;
                    //cout<<pres<<' '<<rival<<' '<<no[rival]<<endl;;
                    if(no[rival]==-1)
                    {
                        no[rival]=1-no[pres];
                        q.push(rival);
                    }
                    else if(no[rival]==no[pres])
                    {
                        cout<<0<<endl;
                        goto end;
                    }

                }

            }

            coun++;
        }
        //FOR(i,n) cout<<no[i]<<' ';
        cout<<power(2,coun)<<endl;
        end:;

    }

    return 0;
}




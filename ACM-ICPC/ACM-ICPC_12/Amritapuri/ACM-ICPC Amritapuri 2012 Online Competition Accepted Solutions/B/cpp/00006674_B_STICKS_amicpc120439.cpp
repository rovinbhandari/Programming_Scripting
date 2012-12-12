#include<iostream>
using namespace std;
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<cstdio>
#include<map>
#include<cmath>
typedef long long lli;
typedef long li;

#define fi(i,a,b,d) for(i=a;i<=b;i+=d)
#define fir(i,a,b,d) for(i=a;i>=b;i-=d)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define vi vector<int>
#define all(v) v.begin(), v.end()

#define mp make_pair
#define pushb push_back
#define popb pop_back
#define pushf push_front
#define popf pop_front


#define inpi(i) scanf("%d", &i)
#define inplli(i) scanf("%lld", &i)
#define inpc(ch) scanf("%c", &ch)
#define printi(i) printf("%d\n", i)
#define printlli(i) printf("%lld\n", i)
#define printc(ch) printf("%c\n", ch)
#define inpfl(fl) scanf("%f", &fl)
#define printfl(fl) printf("%f", fl)


lli stick[50001];
//double diag[50001];

int main()
{
    lli t, n, ans, a, b, c,m,i;
    lli temp, max;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        max=0;
        
        fi(i,0,n-1,1)
        {
            cin>>stick[i];
        }
        
        fi(i,0,m-1,1)
        {
            cin>>a>>b>>c;
            
            temp = a*a+b*b+c*c;
            
            if(temp>max)
            max = temp;
        }
        
        //cout<<"max:"<<max<<'\n';
        
        //sort(diag, diag+m);
        
        fi(i,0,n-1,1)
        {
                     temp = stick[i]*stick[i];
                     if(temp <= max)
                     ++ans;
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}

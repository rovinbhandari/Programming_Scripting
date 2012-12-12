#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <map>
#include <stack>
#include <string>
#include <climits>
#include <ctime>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
int main()
{
    int a;
    si(a);
    while(a--)
    {
	    int n,m;
	    cin>>n>>m;
	    LL l[n];
	    FOR(i,0,n)
		    cin>>l[i];
	    LL max=0;
	    LL b[4];
	    FOR(i,0,m)
	    {
		    cin>>b[0]>>b[1]>>b[2];
		    LL diag=b[0]*b[0]+b[1]*b[1]+b[2]*b[2];
		    if(diag>max)
			    max=diag;
	    }
	    int i;
	    int cnt=0;
	    for(i=n-1;i>=0;i--)
	    {
		    if(max>=l[i]*l[i])
			    cnt++;
	    }
	    cout<<cnt<<endl;
    }
    return 0;
}


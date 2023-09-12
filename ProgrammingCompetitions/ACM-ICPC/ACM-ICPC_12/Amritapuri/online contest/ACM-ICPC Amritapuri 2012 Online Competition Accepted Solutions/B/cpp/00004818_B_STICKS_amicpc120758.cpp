
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>

using namespace std;

#define is_leap_year(x) ((x%400 ==0)||((x%4==0)&&(x%100!=0)))
#define fill(arr,value) memset(arr,value,sizeof(arr))
#define rf(i,n,a) for((i)=(n)-1;(i)>=(a);(i)--)
#define fa(i,a,n) for((i)= a;(i)<(n); (i)++)
#define debug(x) cout<<#x<<":= "<<(x)<<"\n"
#define print(x) cout<<x<<"\n";
#define fz(i,n) for((i)= 0;(i)<(n);(i)++)
#define all(X) (X).begin(),(X).end()
#define sqr(x) ((x)*(x))
#define pb push_back
#define cl clear()
#define SZ size()

typedef int I;
typedef string STR;
typedef long long LL;
typedef map<I,I> MII;
typedef vector<I> VI;
typedef long double LD;
typedef vector<LL> VLL;
typedef vector<STR> VS;
typedef vector<VI> VVI;
typedef map<STR,I> MSI;
typedef map<I,MII> MMI;
typedef map<char,I> MCI;
typedef map<STR,STR> MSS;

inline void fast_read(int *a)
{
    register char c = 0;
    while(c < 33) c = getchar();
    *a = 0;
    while (c>33)
    {
        *a = *a*10 + c - '0';
        c = getchar();
    }
}


int L[500001];//,A[500001],B[500001],C[500001];
double B[500001];

bool compare1(int a,int b)
{
	return (a>=b);
}
bool compare2(double a,double b)
{
	return (a>=b);
}
int main()
{
	int i,j,t;
	double l,w,h;
	int n,m;
	int res;
	cin>>t;
	while(t--){
		cin>>n>>m;
		fz(i,n) cin>>L[i];
		fz(i,m){
			cin>>l>>w>>h;
			double d = sqrt( sqr(l)+ sqr(w) + sqr(h) );
			B[i] = d;
		}	
		sort(L,L+n);
		sort(B,B+m);
		double mx = B[m-1];
		res = 0;
		rf(i,n,0){
			if(L[i] <= mx){
				res = i+1;
				break;
			}
		}
		print(res);
	}
	return 0;
}
	

/*************************************************************
 ********                    Vikash Gupta             ********
 ********                     IIT2009088              ********
 ********                   IIIT Allahabad            ********
 ***************************************************************/


/************Header Files****************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<climits>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<numeric>

using namespace std;

/*************** Prototypes ****************/
#define MAX 1e9
#define MIN 1e-9
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define FORR(i,a,b) for(int i=b-1;i>=a;i--) 
#define REPR(i,n) FORR(i,0,n)
#define sz size()
#define all(c) c.begin(),c.end()
#define mp make_pair
#define fill(ar,val) memset(ar,val,sizeof ar)
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define S(n) scanf("%d",&n)
#define SL(n) scanf("%ld",&n)
#define SC(c) scanf("%c",c)
#define SCS(s) scanf("%s",s)
#define SS(s) scanf("%s",s.c_str())
#define SD(d) scanf("%lf",&d)
#define acc(s,n) accumulate(s,s+n,0)
#define pb push_back

typedef long long ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef map<int,string> MIS;
typedef map<string,int> MSI;
typedef pair<int,int> PII;
typedef pair<string,string> PSS;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;

/**************** execution function main is being begin *********************/

int main()
{
	int t;
	S(t);

	while( t-- ) {
		char s[100];
		scanf("%s",s);

		int l = strlen(s);
		int a[4];
		fill(a,0);

		REP(i,l) {
			if( s[i] == 'R' ) a[0]++;
			else if( s[i] == 'G' ) a[1]++;
			else if( s[i] == 'B' ) a[2]++;
			else a[3]++;
		}

		int fl = 0;
		REP(i,4) {
			if( a[i]%2 ) {
				fl=1;
				break;
			}
		}

		if( fl ) printf("NO\n");
		else printf("YES\n");
	}

}

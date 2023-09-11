#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define sample(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) int((a).size())
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define all(c) (c).begin(), (c).end()
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
typedef vector< PII > VPII;
/*Main Code*/
struct box{
	int bidth, length, height;
	bool operator<( const box B) const{
		if(bidth > B.bidth )return false;
		if(length > B.length) return false;
		if(height > B.height) return false;
		return true;
	}
};
int main()
{
	int A,B;
	int test;
	sample(test);
	while(test--){
		sample(A);sample(B);
		VI L(A);
		VI boxes(B);
		VI status(B,-1);
		REP(i,A)sample(L[i]);
		sort(all(L));
		REP(i,B){
			vector<double> temp(3);
			cin>>temp[0]>>temp[1]>>temp[2];
			int dia = int(sqrt(temp[0] * temp[0] + temp[1] * temp[1] + temp[2] * temp[2]) );
			boxes[i] = dia;
			//cout<<dia<<endl;
		}

		sort(all(boxes));
		int cnt = 0;
		REP(i,A){
			 if(L[i]<=boxes[B-1])cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

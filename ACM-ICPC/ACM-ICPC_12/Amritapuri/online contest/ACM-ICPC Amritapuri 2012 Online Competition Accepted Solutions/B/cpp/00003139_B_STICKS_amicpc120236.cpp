/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 2*acos(0.0)

using namespace std;
typedef long long ll;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s){
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}

int main(void){
    int t;
    sf(t);
    while(t--){
	int n,m;
	vector<int> L;
	vector<double> B;
	double maxdist = 0.0;
	ssf(n,m);
	FOR(i,0,n){
	    int a;
	    sf(a);
	    L.PB(a);
	}
	FOR(i,0,m){
	    ll a,b,c;
	    scanf("%lld %lld %lld",&a,&b,&c);
	    double d = sqrt((double)(a*a+b*b+c*c));
	    maxdist = max(maxdist,d);
	}
	int count = 0;
	//int diag = (int)maxdist;
	FOR(i,0,n){
	    if (L[i] <= (maxdist+0.000001))
		count++;
	}
	pf(count);
    }
}


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

int count1[1000001];
int array[1001];

int main(void){
    int t;
    sf(t);
    while(t--){
	int n,L,H;
	CLEAR(count1);
	scanf("%d %d %d",&n,&L,&H);
	FOR(i,0,n){
	    sf(array[i]);
	    count1[array[i]]++;
	}
	sort(array,array+n);
	for(int i=1; i<1000001; i++)
	    count1[i] += count1[i-1];
	ll ans = 0;
	FOR(i,0,n){
	    FOR(j,i+1,n){
		int sum = array[i]+array[j];
		int upper = H-sum;
		int lower = L-sum;
		if (upper >= 0){
		    int cnt = count1[upper] - count1[max(lower-1,0)];
		    if (array[i] >= lower && array[i] <= upper)
			cnt --;
		    if (array[j] >= lower && array[j] <= upper)
			cnt--;
		    cnt = max(cnt,0);
		    ans += cnt;
		}
	    }
	}
	ans = ans/3;
	printf("%lld\n",ans);
    }
}


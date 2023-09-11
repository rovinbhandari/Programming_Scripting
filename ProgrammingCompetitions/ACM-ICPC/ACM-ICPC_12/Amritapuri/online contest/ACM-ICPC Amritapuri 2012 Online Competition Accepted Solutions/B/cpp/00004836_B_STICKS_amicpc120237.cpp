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
using namespace std;
int main()
{
	int t;
cin>>t;
 
while(t--){
	long long n,m;
	cin>>n>>m;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++) { cin>>v[i]; v[i]*=v[i];}
	long long mx = 0;

	for (long long i = 0; i < m; i++) {
		long long a,b,c;
		cin>>a>>b>>c;
		mx = max( mx, ( (a*a) + (b*b) + (c*c) ) );
	}
long long count = 0;
	for (long long i = 0; i < n; i++) {
	if(v[i] <= mx ) count++;
	}
	cout<<count<<endl;
}

}


#include <iostream>
#include <cmath>
#include <algorithm>
#include<cstdio>
using namespace std;
int l[100000],s, n, m, t, maxl, maxb;
int main()
{
	cin >> t;
	while(t--){
//		map<int,int> m;
		cin >> n >> m;
		maxl = 0;			
		for(int i = 0; i < n; i++){
			cin >> l[i];
			if(maxl < l[i])	maxl = l[i];
//			mp[l[i]]++;
		}
//		sort(l, l+n);
		maxb = 0;
		long long int st, x,y, z;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> z;
			st = (long long int)sqrt(x*x+y*y+z*z);
			if(st > maxb)	maxb = st;
		}
	int k = 0;
		for(int  i =0 ;i < n; i++)
			if(l[i] <= maxb)	k++;
		cout << k << endl;
	getchar();
	}
	
	return 0;
}
		
		
		

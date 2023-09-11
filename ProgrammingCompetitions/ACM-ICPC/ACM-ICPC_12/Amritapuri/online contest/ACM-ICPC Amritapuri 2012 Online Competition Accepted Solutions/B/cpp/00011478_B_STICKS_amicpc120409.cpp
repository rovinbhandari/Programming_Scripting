#include<iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	long long int countd = 0,temp,diag;
	string line;
	for(int i=0; i<T; i++) {
		long long int n,m, temp, maxd=0,count=0;
		cin >> n >> m;
		//cout << n << m << endl;
		long long int stick[n];
		for(int j=0; j<n; j++) {
			cin >> temp;
			stick[j] = temp*temp;
			//cout << stick[j] << endl;
		}
		for(int j=0; j<m; j++) {
			long long int a,b,c,d;
			cin >> a >> b >> c;
			d = a*a+b*b+c*c;
			if(d > maxd) maxd = d;
		}
		//cout << maxd << endl;
		for(int j=0; j<n; j++) {
			if(stick[j] <= maxd) count++;
		}
		cout << count << endl;
		getline(cin,line);
	}
}

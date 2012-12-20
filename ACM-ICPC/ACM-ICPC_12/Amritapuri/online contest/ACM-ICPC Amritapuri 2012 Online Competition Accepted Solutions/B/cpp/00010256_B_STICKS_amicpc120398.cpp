#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int p;
	cin>>p;
	while(p--){
		long int n,m;
		cin>>n>>m;
		vector<long int> st(n);
		for(long int i=0;i<n;i++)
			cin>>st[i];
			vector<long int > t(m);
		for(long int i = 0; i<m; i++){

			long int a,b,c;
			cin>>a>>b>>c;
			t[i] = (a*a+b*b+c*c);
		}
		sort(t.begin(),t.end());
		long int co=0;
		//cout<<*(t.end()-1);
		for(long int i = 0; i < n; i++){
			if((st[i]*st[i]) <= *(t.end()-1))
				co++;
		}
		cout<<co<<endl;
	}
	return 0;
}

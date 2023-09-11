#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll s,bx,i,j,k;
		priority_queue <int> pq ;
		vector<long double> v1,v2,v3;
			long double mx = 0,dia;
		cin>>s>>bx;
		for(i = 0;i < s;i++){
			long double p;
			cin>>p;
			v1.push_back(p);
		}
		j=s;
		k=bx;
		long double bt[60009][4];
		for(i = 0;i < bx;i++){
			cin>>bt[i][0]>>bt[i][1]>>bt[i][2];
		}
		for( i = 0;i < bx;i++){
			dia = sqrt(bt[i][0]*bt[i][0]+(bt[i][1]*bt[i][1])+(bt[i][2]*bt[i][2]));
			if(dia > mx){
				mx = dia;
			}
		}
		ll cnt=0;
		for(  i = 0;i < s;i++){
			if(mx >= v1[i]){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

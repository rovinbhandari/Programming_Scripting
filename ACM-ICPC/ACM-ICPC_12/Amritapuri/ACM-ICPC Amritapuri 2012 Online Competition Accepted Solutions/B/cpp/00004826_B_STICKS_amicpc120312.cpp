#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
typedef long long int ll;
int main(){
	int t,n,m,count,i;
	ll max,temp;
	cin>>t;
	while(t--){
		cin>>n>>m;
		count=0;
		vector< ll > l(n);
		vector< ll > a(m),b(m),c(m);
		for(i=0;i<n;i++)
			cin>>l[i];
		cin>>a[0]>>b[0]>>c[0];
		max = a[0]*a[0] + b[0]*b[0] + c[0]*c[0];
		for(i=1;i<m;i++){
			cin>>a[i]>>b[i]>>c[i];
			temp = a[i]*a[i] + b[i]*b[i] + c[i]*c[i]; 
			if(temp>max)
				max = temp;
		}
		for(i=0;i<n;i++){
			if((l[i]*l[i])<=max)
				count++;
		}
		cout<<count<<"\n";
	}
	return 0;
}
			
					

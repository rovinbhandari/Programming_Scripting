#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		long long l[n];
		for(int i=0;i<n;i++)
			cin>>l[i];
		int box[m][3];
		for(int i=0;i<m;i++)
			cin>>box[i][0]>>box[i][1]>>box[i][2];
		int count = 0;
		vector<long long> diag;
		for(int i=0;i<m;i++){
			long long x1 = box[i][0]*box[i][0];
			long long x2=box[i][1]*box[i][1];
			long long x3=box[i][2]*box[i][2];
			x1+=(x2+x3);
			diag.push_back((long long)(sqrt(double(x1))));
			//cout<<diag[i]<<endl;
		}
		long long max = diag[0];
		for(int i=1;i<m;i++)
			if(max<diag[i])
				max=diag[i];
		for(int i=n-1;i>=0;i--){
			if(l[i]<=max){
				count++;
			}
		}			
		cout<<count<<endl;
	}
	return 0;
}
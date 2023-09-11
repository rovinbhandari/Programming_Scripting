#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int T;
	cin>>T;
	int len[50000];
	while(T--){
		int N,M;
		cin>>N>>M;
		int l;
		for(int i=0;i<N;i++){
			cin>>l;
			len[i] = l;
		}
		double x,y,z;
		double max = -1;
		for(int i=0;i<M;i++){
			cin>>x>>y>>z;
			double diag = sqrt(x*x + y*y + z*z);
			if(diag > max)
				max = diag;
		}
		int num = 0;
		for(int i=0;i<N;i++)
			if(len[i]<=max)
				num++;
		cout<<num<<endl;
	}
}

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
	int t,n,m,maxd,sticks[50000],count;
	long long int bl,bb,bh,bd;
	string blank;
	cin>>t;
	while(t--){
		cin>>n>>m;
		maxd=0;
		for(int i=0;i<n;i++)
			cin>>sticks[i];
		for(int i=0;i<m;i++){
			cin>>bl>>bb>>bh;
			bd= sqrt(float(bl*bl+bb*bb+bh*bh));
			if(maxd<bd)
				maxd=bd;
		}
		count =0;
		for(int i=0;i<n;i++)
				if(sticks[i]<=maxd){
					count++;
				}

		cout<<count<<endl;
		//getline(cin,blank);
	}
	return 0;
}


				

#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(;t>0;t--){
		int n,m;
		cin>>n>>m;
		long long  L[50000];
		long long sum[50000];
		for(int i = 0;i < n;i++){
			cin>>L[i];
			L[i] *= L[i];
		}
		long long max = 0; 
		for(int i = 0;i <m;i++){
			long long  temp1,temp2,temp3;
			cin>>temp1>>temp2>>temp3;
			sum[i] = temp1*temp1 + temp2*temp2 +temp3*temp3;
			if(sum[i] > max)
				max = sum[i];
		}
		int count = 0;
		for(int i = 0;i < n;i++){
			if(L[i] <= max)
				count++;
		}
		cout << count <<endl;
		
	}
}

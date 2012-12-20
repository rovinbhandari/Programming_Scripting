#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int test;
	cin>>test;
	while(test--){
		long long int stick,boxes,ct = 0;
			long double max = 0,d;
		cin>>stick>>boxes;
		vector<long double>v;
		long double arr[50002][3];
		for(long long int i = 0;i < stick;i++){
			long double a;
			cin>>a;
			v.push_back(a);
		}
		for(long long int i = 0;i < boxes;i++){
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		}
		for(long long int i = 0;i < boxes;i++){
			d = sqrt(arr[i][0]*arr[i][0]+(arr[i][1]*arr[i][1])+(arr[i][2]*arr[i][2]));
			if(d > max){
				max = d;
			}
		}
		for(long long int i = 0;i < stick;i++){
			if(max >= v[i]){
				ct++;
			}
		}
		cout<<ct<<endl;
	}
	return 0;
}

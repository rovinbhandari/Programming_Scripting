#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cassert>

#define mod 1000000007
using namespace std;

int main(){
	int t,i,j,n;
	vector<int> v;
	cin>>t;
	while(t--){
		int arr[100000]={0};
		string s;
		cin>>s;
		int flag=0;
		int l=s.size();
		for(i=0;i<l;i++){		
			if(s[i]=='R'){
				arr[0]++;
			}
			else if(s[i]=='G'){
				arr[1]++;
			}
			else if(s[i]=='B'){
				arr[2]++;
			}
			else if(s[i]=='W'){
				arr[3]++;
			}
		}
		for(i=0;i<4;i++){
			if(arr[i]%2!=0){
				flag=1;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(flag==0){
			cout<<"YES"<<endl;
		}
	}

	return 0;
}

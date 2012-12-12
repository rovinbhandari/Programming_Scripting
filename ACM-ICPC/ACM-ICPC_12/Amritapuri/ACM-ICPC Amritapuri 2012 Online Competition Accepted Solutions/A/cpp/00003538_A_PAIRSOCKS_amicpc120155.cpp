#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	vector<int> v;
	cin>>t;
	while(t--){
		int a[100000]={0};
		string s;
		cin>>s;
		int flag=0;
		int length=s.size();
		for(int i=0;i<length;i++){		
			if(s[i]=='R'){
				a[0]++;
			}
			else if(s[i]=='G'){
				a[1]++;
			}
			else if(s[i]=='B'){
				a[2]++;
			}
			else if(s[i]=='W'){
				a[3]++;
			}
		}
		for(int j=0;j<4;j++){
			if(a[j]%2!=0){
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

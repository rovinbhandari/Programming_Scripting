#include <iostream>
#include <cassert>

using namespace std;
int main(){
	int N = 0, T = 0, rCount = 0, gCount = 0, bCount = 0, wCount = 0, i, j;
	string c = "";
	cin >> T;
	assert(T >= 0 && T <= 1000);
	
	//O(T*N)
	for(i = 0; i < T ; i++, rCount = 0, gCount = 0, bCount = 0, wCount = 0, c = ""){
		cin >> c;
		N = c.length();
		assert(N <= 50);
		for(j = 0; j < c.length(); j++){
			switch (c[j]) {
				case 'R':
					rCount++;
					break;
				case 'G':
					gCount++;
					break;
				case 'B':
					bCount++;
					break;
				case 'W':
					wCount++;
					break;
				default:
					break;
			}
		}
		
		//Check if all things can be paired
		//(rCount % 2 == 0 && gCount % 2 == 0 && bCount % 2 == 0 && wCount % 2 == 0) condition is modified
		if(not (rCount % 2 || gCount % 2 || bCount % 2 || wCount % 2)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}	
	}
		
	return 0;
}

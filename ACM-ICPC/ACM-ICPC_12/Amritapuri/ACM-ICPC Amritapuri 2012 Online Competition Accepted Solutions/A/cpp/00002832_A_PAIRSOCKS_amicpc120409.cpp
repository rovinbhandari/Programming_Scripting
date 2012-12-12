#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int RNumber, GNumber, BNumber, WNumber;
	string line;
	
	for (int i=0; i<T; i++) {
		RNumber=0; GNumber=0; BNumber=0; WNumber=0;
		cin >> line;
		for (int j=0; j<line.length(); j++) {
			if (line[j] == 'R') RNumber++;
			else if (line[j] == 'G') GNumber++;
			else if (line[j] == 'B') BNumber++;
			else WNumber++;
		}
		if ((RNumber%2==0) && (GNumber%2==0) && (BNumber%2==0) && (WNumber%2==0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

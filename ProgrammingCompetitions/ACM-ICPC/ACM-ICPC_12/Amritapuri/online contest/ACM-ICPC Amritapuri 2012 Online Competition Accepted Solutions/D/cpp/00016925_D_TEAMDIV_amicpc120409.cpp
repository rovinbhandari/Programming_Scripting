#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;


int fillComponent(int* a, int** cE, int node, int k, int* l, int loc) {
	//cout << node << " " << a[node] << " " << l[node] << " " << loc << endl;
	if(a[node]==0) {
		a[node]=1;
		l[node] = loc;
	}
	
	
	int* line = cE[node];
	for(int i=0; i<k; i++) {
		if(line[i] == 1) {
			//cout << i << " " << a[i] << endl;
			if(a[i] == 0) {
				fillComponent(a, cE, i, k, l, 1-loc);
			}
		}
	}
	return 0;
}

int main() {
	int T=0;
	cin >> T;
	for(int f=0; f<T; f++) {
		int k=0;
		cin >> k;
		int numbers[k];
		int** canExchange;
		canExchange = new int*[k];
		for(int i=0; i<k; i++) {
			canExchange[i] = new int[k];
		}
		for(int i=0; i<k; i++) {
			numbers[i] = i;
		}
		
		int nr=0, temp;
		for(int i=0; i<k; i++) {
			cin >> nr;
			for(int j=0; j<nr; j++) {
				cin >> temp;
				
				canExchange[i][temp] = 1;
				canExchange[temp][i] = 1;
			}
		}
	
		/*for(int n=0; n<k; n++) {
			for(int m=0; m<k; m++) {
				cout << canExchange[n][m];
			}
			cout << endl;
		}*/
	
		int numComponents=0;
		int alloted[k];
		for(int i=0; i<k; i++) alloted[i]=0;
		int* classes[k];
		int locations[k];
		for(int i=0; i<k; i++) locations[i] = -1;
	
		for(int i=0; i<k; i++) {
			if(alloted[i] == 0) {
				fillComponent(alloted, canExchange, i, k, locations, 0);
				numComponents++;
			}
		}
		int check=0;
		
		for(int n=0; n<k; n++) {
			for(int m=0; m<k; m++) {
				if((canExchange[n][m] == 1) && (locations[n] == locations[m])) {
						check = -1;
						break;
				}
			}
			if(check == -1) break;
		}
		long long int power=1;
		for(int i=0; i<numComponents; i++) {
			power *= 2;
			power %= 1000000007;
		}
		
		if(check < 0) cout << "0" << endl;
		else cout << power << endl;
	}
}

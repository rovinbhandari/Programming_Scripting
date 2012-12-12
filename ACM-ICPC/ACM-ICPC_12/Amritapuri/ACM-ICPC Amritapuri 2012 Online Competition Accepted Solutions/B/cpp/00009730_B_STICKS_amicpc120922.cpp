#include <iostream>
#include <stdio.h>

//Submitted by - ankit laddha
using namespace std;
int main() {
	int T;
	int N;
	int M;
	unsigned int c_un;
	cin >> T;
	int i=0;
	int j = 0;
	int k = 0;
	int count_total[T];
	int total = 0;
	for(i=0;i<T;i++) {
		cin >> N;
		cin >> M;
		long long stick_length[N];
		long long stick_length1;
		long long box[M][3];
		long long box_diagonal[M];
		long long max_box = 0;
		int count = 0;
		for(j=0;j<N;j++) {
			cin >> stick_length1;
			stick_length[j] = stick_length1*stick_length1;
		}
		//cout << stick_length[0] << endl;
		for(k=0;k<M;k++) {
			cin >> box[k][0];
			cin >> box[k][1];
			cin >> box[k][2];
			
			box_diagonal[k] = box[k][0]*box[k][0] + box[k][1]*box[k][1] + box[k][2]*box[k][2];
			if(max_box <= box_diagonal[k])
				max_box = box_diagonal[k];
		}
		//cout << "max_box = " << max_box << endl; 
		for(j=0;j<N;j++) {
			if(stick_length[j] <= max_box)
				count++;
		}
		count_total[i]  = count;
	}
	for(i=0;i<T;i++) {
		cout << count_total[i] << endl;
	}	
	
	return 0;
}

#include<iostream>
using namespace std;

void sort(int* a, int n) {
	int n1=n/2;
	int n2=n-n1;
	int* b=a+n1;
	if(n==1) return;
	sort(a, n1);
	sort(b, n2);
	int c[n1],d[n2];
	int i,j;
	for(i=0; i<n; i++) {
		if(i<n1) c[i] = a[i];
		else d[(i-n1)] = b[(i-n1)];
	}
	for(i=0, j=0; i+j < n1+n2;) {
		if(i>=n1) {
			a[i+j] = d[j];
			j++;
		}
		else if(j>=n2) {
			a[i+j] = c[i];
			i++;
		}
		else if(c[i] < d[j]) {
			a[i+j] = c[i];
			i++;
		}
		else if(c[i] >= d[j]){
			a[i+j] = d[j];
			j++;
		}
	}
}

int lIndex(int* a,int size, int val) {
	int start=0,last=size-1,i=(start+last)/2;
	while(!(last-start==1)){
		if(a[i]>=val) {
			last = i;
		}
		else {
			start = i;
		}
		i = (last+start)/2;
	}
	if(a[start] >= val) return start;
	return last;
}

int hIndex(int* a,int size, int val) {
	int start=0,last=size-1,i=(start+last)/2;
	while(!(last-start==1)){
		if(a[i]<=val) {
			start = i;
		}
		else {
			last = i;
		}
		i = (last+start)/2;
	}
	if(a[last] <= val) return last;
	return start;
}

int main() {
	int T;
	cin >> T;
	int N,L,H;
	//string line;
	
	for (int i=0; i<T; i++) {
		cin >> N >> L >> H;
		int a[N], temp;
		for(int j=0; j<N; j++) {
			cin >> temp;
			a[j] = temp;
		}
		sort(a, N);
		/*for(int j=0; j<N; j++) {
			cout << a[j] << " ";
		}*/
		int b=0,c=1,d=2, max=0;
		/* while() {
			if(a[b]+a[c]+a[d] > max) max == 
			if(c-b == 1) {
				if(d-c == 1) {
					
				}
			}
		} */
		long long int count=0;
		if(N <= 2) cout << "0" << endl;
		else {
			for(int j=0; j<N-2; j++) {
				for(int k=j+1; k<N-1; k++) {
					int sum = a[j]+a[k];
					int ll = lIndex(a, N, L-sum);
					int hh = hIndex(a, N, H-sum);
					//cout << L-sum << " " << ll << " " << H-sum << " " << hh << endl;
					if(ll<=k && hh<=k)
						continue;
					if(ll<=k)
						ll=k+1;
					//cout << j << " " << ll << " " << k << " " << hh << endl;
					//for(int h=ll; h<=hh; h++) cout << "(" << j << " " << k << " " << h << ")" <<endl;
					int ans = hh - ll + 1;
					count += ans;
				}
			}
			cout << count << endl;
		}
	}
}

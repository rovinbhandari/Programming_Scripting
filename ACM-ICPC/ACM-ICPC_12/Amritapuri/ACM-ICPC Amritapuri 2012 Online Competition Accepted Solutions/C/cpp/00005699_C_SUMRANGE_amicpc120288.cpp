#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, l, h;
		scanf("%d %d %d", &n, &l, &h);
		vector<int> a(n);
		int i, j, k;
		for(i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		int count = 0;
		for(i = 0; i < n - 2; ++i){
			int s1 = a[i];
			if(s1 >= h) continue;
			for(j = i + 1; j < n - 1; ++j){
				int s2 = s1 + a[j];
				if(s2 >= h) continue;
				vector<int>::iterator q = (upper_bound(a.begin(), a.end(), h-s2));
				int q1 = int(q - a.begin()) ;
				if(q1 <= j) continue;
				vector<int>::iterator w = (lower_bound(a.begin(), a.end(), l-s2));
				int w1 = int(w - a.begin());
				if(w1 <= j)
					count += (q1 - j - 1);
				else
					count += (q1 - w1);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

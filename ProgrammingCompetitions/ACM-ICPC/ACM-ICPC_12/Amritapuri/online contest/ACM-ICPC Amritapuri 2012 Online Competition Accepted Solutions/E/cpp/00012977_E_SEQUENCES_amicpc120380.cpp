#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
typedef long long ll;

#define lt(x) (x << 1)
#define rt(x) ((x<<1)+1)

#define TMAX 1000010
string s;
int n;
int ones[TMAX], zeros[TMAX], LIS[TMAX];

struct node {
	int o, z, lis;
};


void init(int b, int e, int idx = 1) {
	if(b == e) {
		ones[idx] = (s[b] == '1');
		zeros[idx] = (s[b] == '0');
		LIS[idx] = 1;
		return;
	}
	
	int mid = (b + e) / 2;
	init(b, mid, lt(idx));
	init(mid+1, e, rt(idx));
	
	ones[idx] = ones[lt(idx)] + ones[rt(idx)];
	zeros[idx] = zeros[lt(idx)] + zeros[rt(idx)];
	
	LIS[idx] = max( LIS[lt(idx)] + ones[rt(idx)] , LIS[rt(idx)] + zeros[lt(idx)] );
	
}

node query(int b, int e, int i, int j, int idx = 1) {
	//cout << b << "," << e << "\t" << i << "," << j << endl;
	
	node ret; 
	
	if (i > e || j < b) {
		ret.o = 0; ret.z = 0; ret.lis = 0;
		return ret;
	}
		
    if (b >= i && e <= j) {
        ret.lis = LIS[idx];
        ret.o = ones[idx]; 
        ret.z = zeros[idx];
        return ret;
    }
        
    int mid = (b + e) / 2;
    node left = query(b, mid, i, j, lt(idx));
    node right = query(mid+1, e, i, j, rt(idx));
    
    ret.lis =  max( left.lis + right.o , right.lis + left.z );
    ret.o = left.o + right.o; 
    ret.z = left.z + right.z;
    
    return ret;
}

int main() {
	//freopen("in.cpp", "r", stdin); freopen("out.cpp", "w", stdout);
	
	int nt; scanf("%d", &nt); while(nt--) {
		scanf("%d", &n); 
		scanf("\n"); cin >> s;
		s = '0' + s;
		memset(LIS, 0, sizeof LIS);
		init(1, n);
		
		int q; int i, j; scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &i, &j); 
			printf("%d\n", query(1, n, i, j).lis);
		}
	}
	
	return 0;
}



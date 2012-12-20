#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define tr(c,it) for (typeof(c.end()) it = c.begin(); it != c.end(); it++)

typedef long long int lli;
using namespace std;

// Range Maximum Query 
const int N = 1<<17;

int A[N]; // remember to fill A[n..N-1] with dummy values which dont affect answer
int Z[2*N], O[2*N], T[2*N]; // need exactly 2*N space (assuming N is a power of 2)

// notation: 1 represents A[0..N)
// its children are 2 and 3
// children of A[a..b) at i are A[a..m) at 2*i and A[m..b) at 2*i + 1 where m = (a+b)/2; 
// a+b might overflow, use a + (b-a)/2 in that case
// If A is [0..N). T needs index upto 2*N-1

void buildTree(int i = 1, int a = 0, int b = N){
  if(b-a < 2){       // b-a is always length of the current interval
    Z[i] = (A[a] == 0)? 1 : 0;
    O[i] = (A[a] == 0)? 0 : 1;
    T[i] = 1;
    //    printf(" %d:[%d,%d) = %d, %d, %d\n", i, a, b, Z[i], O[i], T[i]);
    return;
  }
  int m = (a+b)/2;
  buildTree(2*i,a,m);
  buildTree(2*i+1,m,b);
  Z[i] = Z[2*i] + Z[2*i+1];
  O[i] = O[2*i] + O[2*i+1];
  T[i] = max(T[2*i] + O[2*i+1],max(Z[2*i]+T[2*i+1], Z[2*i]+O[2*i+1]));

  //  printf(" %d:[%d,%d) = %d, %d, %d \n", i, a, b, Z[i], O[i], T[i]);
}

struct qans {
  int z, o, t;
};

//int calls;

// guarantee: [qa,qb) \subset [a,b) and [qa,qb) is not empty
qans intervalQuery(int qa, int qb, int i = 1, int a = 0, int b = N){
   //calls++;
  if(b-a < 2 or (qa == a and qb == b)){
    qans ret = {Z[i], O[i], T[i]};
    //    printf("q:[%d, %d), i,a,b: %d, %d, %d, ret: %d, %d, %d\n", qa,qb,i,a,b,ret.z,ret.o,ret.t);
    return ret;
  }
  int m = (a+b)/2;
  if(qa < m and qb <= m)
    return intervalQuery(qa,qb,2*i,a,m);
  else if(qa >= m and qb > m)
    return intervalQuery(qa,qb,2*i+1,m,b);
  // [qa,qb) intersects both segments
  qans left = intervalQuery(qa,m,2*i,a,m), right = intervalQuery(m,qb,2*i+1,m,b);
  qans ret = {left.z+right.z, left.o+right.o, 0};
  ret.t = max(left.z + right.t, max(left.t + right.o, left.z + right.o));
  //  printf("q:[%d, %d), i,a,b: %d, %d, %d, ret: %d, %d, %d\n", qa,qb,i,a,b,ret.z,ret.o,ret.t);
  return ret;
}
string s;

int main() {
  int Tc, n, Q;

  ios::sync_with_stdio(false);

  cin >> Tc;
  while (Tc--) {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
      A[i] = (s[i] == '0') ? 0 : 1;
    }
    //    for (int i = n; i < N; i++) A[i] = 0;

    buildTree();

    cin >> Q;
    while (Q--) {
      int a,b;
      cin >> a >> b;
      //calls = 0;
      cout << intervalQuery(a-1,b).t << "\n";
      //cout << "Calls = " << calls << "\n";
    }
  }
  
  return 0;
}

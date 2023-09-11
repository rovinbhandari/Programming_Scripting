#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main()
{
int t, l;
string s;
int i, r, b, g, w;
cin >> t;
while (t--) {
r = b = g = w = 0;
cin >> s;
l = s.size();;
for (i = 0; i < l; i++) {
if (s[i] == 'R') {
r++;
} else if (s[i] == 'B') {
b++;
}else if (s[i] == 'G') {
g++;
} else if (s[i] == 'W') {
w++;
}
}
if (r % 2 == 0 && b % 2 == 0 && g % 2 == 0 && w % 2 == 0) {
cout << "YES" << endl;
} else {
cout << "NO" << endl;
}
}
return 0;
}

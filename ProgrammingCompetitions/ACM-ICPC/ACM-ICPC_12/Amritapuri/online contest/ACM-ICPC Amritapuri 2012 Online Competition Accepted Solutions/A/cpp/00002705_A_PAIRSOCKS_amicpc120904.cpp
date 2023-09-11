#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//#define INFILE "./input.txt"
//#define OUTFILE "./output.txt"

using namespace std;

int main () {

//		freopen (INFILE,"r",stdin);
//		freopen (OUTFILE,"w+",stdout);
		int g,w,r,b,tc;
		char s[100];

		for(scanf ("%d",&tc);tc;tc--) {
				r=g=b=w=0;
				scanf ("%s",s);
				for (int i=0;s[i]!='\0';i++) {
						if (s[i]=='R') r++;
						else if (s[i]=='G') g++;
						else if (s[i]=='B') b++;
						else if (s[i]=='W') w++;
				}
				if (r%2 || g%2 || b%2 || w%2)
						cout << "NO" << endl;
				else
						cout << "YES" << endl;
		}

		return (0);
}
						

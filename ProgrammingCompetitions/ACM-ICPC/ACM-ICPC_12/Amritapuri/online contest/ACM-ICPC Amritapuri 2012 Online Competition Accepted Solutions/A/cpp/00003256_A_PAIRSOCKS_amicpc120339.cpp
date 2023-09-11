#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t, r, b, g, w;
	scanf("%d",&t);;
	string s;
	int i = 0;
	while ( t-- ) {
		cin >> s;
		if ( s.size()%2 != 0 ) {
			printf("NO\n");	
		}	
		else {
			r = 0;
			g = 0;
			b = 0;
			w = 0;
			int j = 0;
			while ( j < s.size() ) {
				if ( s[j] == 'R' ) {
					r++;
				}
				else if (s[j] == 'G' ) {
					g++;
				}
				else if ( s[j] == 'B' ) {
					b++;
				}
				else if ( s[j] == 'W' ) {
					w++;
				}
				j++;
			}
			if ( (r%2 == 0) && (b%2 == 0) && ( g%2 == 0 ) && ( w%2 == 0 ) ) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}

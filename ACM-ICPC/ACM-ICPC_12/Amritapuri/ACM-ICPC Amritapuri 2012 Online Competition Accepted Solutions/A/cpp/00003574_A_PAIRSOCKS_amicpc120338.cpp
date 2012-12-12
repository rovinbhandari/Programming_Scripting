# include <iostream>
using namespace std ;
int main ()
{
	int t ;
	cin >> t ;
	for ( int i = 0 ; i < t ; ++i ) {
		string s ;
		cin >> s ;
		int l = s.length() ;
		int r=0, g=0, b=0, w=0 ;
		for ( int j=0 ; j<l ; ++j ) {
			if ( s[j] == 'R' )
				r++ ;
			else if ( s[j] == 'G' )
				g++ ;
			else if ( s[j] == 'B' )
				b++ ;
			else 
				w++ ;
		}
		if ( ((r%2 == 0)&&( b%2==0 )) && ((g%2==0)&&(w%2==0)) )
			cout << "YES\n" ;
		else
			cout << "NO\n" ;
	}
	return 0;

}

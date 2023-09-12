#include <stdio.h>
#include <stdbool.h>

int main ( void )
{
	char str[52];
	unsigned int R, G, B, W;
	
	unsigned int T;
	
	scanf ( "%u", &T );
	
	for ( ; T > 0; T -- )
	{
		scanf ( "%s", str );
	
		R = G = B = W = 0;
	
		unsigned int i;
		for ( i = 0; str[i] != '\0'; i ++ )
		{
			switch ( str[i] )
			{
				case 'R' :	R++; break;
				case 'G' :	G++; break;
				case 'B' :	B++; break;
				case 'W' :	W++; break;
			}
		}
	
		if ( ( ( R % 2 ) == 0 ) && ( ( G % 2 ) == 0 ) && ( ( B % 2 ) == 0 ) && ( ( W % 2 ) == 0 ) && ! ( ( R == 0 ) && ( G == 0 ) && ( B == 0 ) && ( W == 0 ) ) )
		{
			printf ( "YES\n" );
		}
		else
		{
			printf ( "NO\n" );
		}
	}
	
	return 0;
}

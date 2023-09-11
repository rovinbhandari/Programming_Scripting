#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int r,b,w,g;
	char str[52];
	int t , i , j;
	scanf ("%d", &t);
	for (i = 0; i < t; i++) {
		//memset (arr , 0  , 100)
		scanf ("%s" , str);
		r=b=w=g=0;
		for (j = 0; str[j] != '\0'; j++) 
		{
			switch (str[j])
			{
				case 'R' : r = ++r % 2;
					break;
				case 'W' : w = ++w % 2;
					break;
				case 'G' : g = ++g % 2;
					break;
				case 'B' : b = ++b % 2;
					break;
				default: break;
			}
		}
		if ( r || b || g || w )
			printf ( "NO\n" );
		else
			printf ( "YES\n" );
	}
	return 0;
}

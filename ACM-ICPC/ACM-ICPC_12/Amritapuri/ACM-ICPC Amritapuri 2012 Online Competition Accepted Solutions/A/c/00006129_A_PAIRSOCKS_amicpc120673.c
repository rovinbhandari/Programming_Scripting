#include <stdio.h>
//#include <string.h>

int main()
{
	int test,i;
	char str[51];
	int x;
	scanf ( "%d", &test );
	//getchar();
	while(test--){
		getchar();
		int r=0;
		int g = 0;
		int w = 0;
		int b = 0;
		scanf ( "%[^\n]s", str);
//		printf ( "%s\n", str);
		for ( i = 0; str[i] != '\0'; i++) {
			if ( str[i] == 'R'){
				r++;
			}else if ( str[i] == 'G' ) {
				g++;
			}else if ( str[i] == 'W' ) {
				w++;
			}else if ( str[i] == 'B' ) {
				b++;
			}
		}
	//	printf ( "r = %d\tg = %d\tw=%d\tb=%d\n", r,g,w,b);
		if ( (r %2 == 0) && (g%2==0) && (w%2==0)&& (b%2==0)) {
			printf ( "YES\n");
		}else {
			printf ( "NO\n");
		}

		}
	
	return 0;
}


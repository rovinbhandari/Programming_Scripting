#include <stdio.h>
#include <string.h>

int main() {
	int t, r, g, b, w, l, i;
	scanf("%d", &t);
	while(t>0) {
		r=0;
		g=0;
		b=0;
		w=0;
		char str[50];
		scanf("%s", str);
		l = strlen(str);
		if(l%2!=0)
			printf("NO\n");
		else {
			for(i=0;i<l;i++) {
				if(str[i]=='R')
					r++;
				else if(str[i]=='G')
					g++;
				else if(str[i]=='B')
					b++;
				else if(str[i]=='W')
					w++;
			}
			if((r%2==0) && (g%2==0) && (b%2==0) && (w%2==0))
				printf("YES\n");
			else
				printf("NO\n");
		}
		t--;
	}
	return 0;
}

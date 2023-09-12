#include <stdio.h>
#include <math.h>
main()
{
	int c, a, b, z;
	char k;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%c %d %d",&k, &a, &b);
		z = (k == 'a' ? a + b : k == 'b' ? a - b : k == 'c' ? a * b : k == 'd' ? a / b : pow(a, b));
		printf("%d\n", z);
	}
}
		


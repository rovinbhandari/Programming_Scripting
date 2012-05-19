#include <stdio.h>
#include <string.h>

#define asize 10001

int main()
{
	int a[asize] = {0}, maxsum, /*val,*/ t, n, in;
	scanf("%d", &t);
	while(t--)
	{
		maxsum = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &in);
			if(maxsum < (*(a + in) += in))
				maxsum = *(a + in);
			/*
			// assuming register val
			val = *(a + in);
			val += in;
			*(a + in) = val;
			if(maxsum < val)
				maxsum = val;
			*/
		}
		// output maxsum
		printf("%d\n", maxsum);
		// clear off a[]
		memset(a, 0, asize * sizeof(int));
	}
	return 0;
}


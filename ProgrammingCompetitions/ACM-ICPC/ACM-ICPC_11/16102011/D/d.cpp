#include <cstdio>
//#include <algorithm>
#include <cstring>
using namespace std;

#define asize 10001

int main()
{
	int a[asize] = {0}, instsum, maxinstsum, maxsum, curval, val, t, n, in, i, j;
	scanf("%d", &t);
	while(t--)
	{
		maxsum = 0;
		maxinstsum = instsum = 0;
		curval = -1;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &in);
			*(a + in) += in;
			if(maxsum < *(a + in))
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
		
		
		/*	
		// sort the first n values of a[]
		sort(a, a + n);
		// skip the first k zeroes (k >= 0). if k = n, print 0 and continue
		i = -1;
		while(!a[++i] && i < n);		// i is the index of the first non-zero element in a[] after sorting, if any
		if(i == n)
		{
			printf("0\n");
			continue;
		}
		// in a loop, calculate instsum and maxinstsum based on changing curval of a[]
		j = i;
		while(j < n)
		{
			curval = *(a + j);
		// output maxinstsum
		if(mininstsum >= 1)
			printf("1\n");
		else
			printf("%d\n", (mininstsum * (-1) + 1));
		// clear off the first n values of a[]
		*/
	}
	return 0;
}


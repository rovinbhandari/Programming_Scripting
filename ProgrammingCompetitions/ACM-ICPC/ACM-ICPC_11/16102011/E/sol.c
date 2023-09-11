#include <stdio.h>

#define MODULO 1000000007

long long unsigned int next_num(long long unsigned int cur, int div)
{
	cur = cur * 10;
	int tens = 10;
	//fprintf(stderr, "Cur' = %d, div = %d\n", cur, div);
	while(cur < div)
	{
		cur = cur * 10;
		tens = tens * 10;
	}

	if( cur % div == 0 ) 
	{
		return cur % MODULO;
	}

	else
	{
		int mod_dif = div - (cur % div);
//		fprintf(stderr, "Cur = %d , mod_dif = %d mod_dif/cur = %d\n", cur, mod_dif, mod_dif/cur);
		while ( mod_dif / tens )
		{
//			fprintf(stderr, "Cur = %d , mod_diff = %d\n", cur, mod_dif);
			if(cur % div == 0)
			{
				return (cur % MODULO) ;
			}
			cur = cur * 10;
			tens = tens * 10;
			mod_dif = div - (cur % div);
		}

		return (mod_dif + cur) % MODULO;
	}


}

int main()
{
	int t, n;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		unsigned int A[n];

		int i;
		for( i = 0; i < n; i++)
		{
			scanf("%u", &A[i]);
		}

		
		long long unsigned int B[n];
	
		int cur = 1, div = A[0], mod_dif;
		cur = cur * 10;
		while( cur < div ) 
		{
			cur = cur * 10;
		}

		if ( div / (cur/10) == 1)
		{
			B[0] = div;
		}
		else
		{
			
			mod_dif = div - (cur % div);
			while (! (mod_dif / cur) )
			{
				if (cur % div == 0)
				{
					B[0] = cur;
					break;
				}
				cur = cur * 10;
				mod_dif = div - (cur % div);
			}
		}
		
//		fprintf(stderr, "B[0] = %d", B[0]);

		for(i = 1; i < n; i++)
		{
			B[i] = next_num(B[i-1], A[i]);
//			fprintf(stderr,"B[%d] = %d\n", i, B[i]);
		}
	
		printf("%llu\n", B[n-1]);
	}

	return 0;
}

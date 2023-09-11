#include <stdio.h>
#include <math.h>

#define MAXSTICKS 50000
int l[MAXSTICKS];

int SquareRoot(int a_nInput)
{
    int op  = a_nInput;
    int res = 0;
    int one = 1uL << 30; // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for int type


    // "one" starts at the highest power of four <= than the argument.
    while (one > op)
    {
        one >>= 2;
    }

    while (one != 0)
    {
        if (op >= res + one)
        {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

int main (void)
{
  int i, t, n, m, a, b, c, fitting, diag, maxdiag;

  scanf ("%d", &t);

  while (t--)
  {
    scanf("%d", &n);
    scanf("%d", &m);

	for(i = 0; i < n; i++)
		scanf("%d", &l[i]);
	
	maxdiag = -1;

	for(i = 0; i < m; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		//diag = (int) (nearbyint(floor(sqrt((double) (a * a + b * b + c * c)))) + 0.1);
		diag = SquareRoot(a * a + b * b + c * c);
		if(diag > maxdiag)
			maxdiag = diag;
	}

	fitting = 0;
	for(i = 0; i < n; i++)
		if(l[i] <= maxdiag)
			fitting++;

    printf("%d\n", fitting);
  }
  return 0;
}

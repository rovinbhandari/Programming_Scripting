#include <cstdio>
#include <cmath>
using namespace std;

#define MAXSTICKS 50000
int l[MAXSTICKS];

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
		unsigned int temp = a * a + b * b + c * c;
		diag = (int) (sqrt(temp));
		//diag = SquareRoot(a * a + b * b + c * c);
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

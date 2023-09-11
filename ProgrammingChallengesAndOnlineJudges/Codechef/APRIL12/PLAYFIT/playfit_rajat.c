// Program to solve the PLAYFIT problem on CodeChef.
/* The problem is similar to Maximum single-sell profit question. */

#include <stdio.h>

int main (void)
{
  unsigned int t, n, k, min, max_diff, tmp_diff;

  scanf ("%u", &t);

  while (t--)
  {
    scanf ("%u", &n);
    
    min = -1;
    max_diff = 0;

    while (n--)
    {
      scanf ("%u", &k);

      if ( k < min)
      {
        min = k;
      }
      else
      {
        tmp_diff = k - min;
        if ( tmp_diff > max_diff )
        {
          max_diff = tmp_diff;
        }
      }
    }

    if ( max_diff > 0)
      printf ("%u\n", max_diff);
    else
      printf ("UNFIT\n");
  }

  return 0;
}

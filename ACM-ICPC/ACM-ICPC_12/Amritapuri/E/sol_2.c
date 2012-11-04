#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
  int t, n, q, u, l, max, nzeros, last1;
  int *tmp_a;
  scanf ("%d", &t);

  while (t--)
  {
    scanf ("%d", &n);
    int a[n], i, max_l[n];
    getchar();
    for (i = 0; i < n; i++)
    {
      a[i] = getchar() - '0';
    }
    scanf ("%d", &q);
    while (q--)
    {
      scanf ("%d %d", &l, &u);
      max = -1;
      nzeros = 0;
      last1 = -1;
      bzero (max_l, sizeof(int) * n);
      tmp_a = a + l - 1;
      for (i = 0; i < u - l + 1; i++)
      {
        if (tmp_a[i] == 0)
        {
          nzeros++;
          max_l[i] = nzeros;
        }
        else
        {
          max_l[i] = nzeros + 1;
          if (last1 >= 0 && max_l[i] < 1 + max_l[last1])
            max_l[i] = 1 + max_l[last1];
          last1 = i;
        }
        max = max > max_l[i] ? max : max_l[i];
      }
      printf ("%d\n", max);
    }
  }
  return 0;
}

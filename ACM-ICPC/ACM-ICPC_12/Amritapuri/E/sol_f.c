#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int longestSubsequence (int *a, int l, int u)
{
  int max = - 1, nzeros = 0, last1 = -1, i;
  int *tmp_a = a + l - 1;
  int n = u - l + 1;
  int max_l[n];
  memset (max_l, 0, n);
      
  for (i = 0; i < n; i++)
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
  return max;
}

int main()
{
  int t, n, q, u, l, max, nzeros, last1, size, j;
  int *tmp_a;
  int **ans;
  scanf ("%d", &t);

  while (t--)
  {
    scanf ("%d", &n);
    int a[n], i;
    getchar();
    for (i = 0; i < n; i++)
    {
      a[i] = getchar() - '0';
    }
    
    scanf ("%d", &q);
    int Q[q][2], minL = n + 1, maxU = -1;
    for (i = 0; i < q; i++)
    {
      scanf ("%d %d", &l, &u);
      Q[i][0] = l;
      Q[i][1] = u;
      minL = minL > l ? l : minL;
      maxU = maxU > u ? maxU : u;
    }

    int max_l[n];
    ans = malloc (sizeof (int*) * n);
//    assert (ans);
    for (i = 0; i < n; i++)
    {
      size = n - i;
      fprintf (stderr, "BEFORE malloc %d\n", i);
      ans[i] = malloc (sizeof(int) * size);
      fprintf (stderr, "REACHED %d\n", n);
      tmp_a = a + i;
      memset(max_l, 0, sizeof(int) * size);
      memset(ans[i], 0, sizeof(int) * size);
      last1 = -1;
      max = 0;
      nzeros = 0;
      fprintf (stderr, "REACHED before loop %d\n", n);
      for (j = 0; j < size; j++)
      {
        if (tmp_a[j] == 0)
        {
          nzeros++;
          max_l[j] = nzeros;
        }
        else
        {
          max_l[j] = nzeros + 1;
          if (last1 >= 0 && max_l[j] < 1 + max_l[last1])
            max_l[j] = 1 + max_l[last1];
          last1 = j;
        }
        max = max > max_l[j] ? max : max_l[j];
        ans[i][j + i] = max;
 //       printf ("%d\t", ans[i][j + 1]);
      }
 //     printf ("\n");
    }

    for (i = 0; i < q; i++)
    {
      printf ("%d\n", ans[Q[i][0] - 1][Q[i][1] - 1]);
    }
    for (i = 0; i < n; i++)
      free(ans[i]);
    free (ans);
  }     
  return 0;
}

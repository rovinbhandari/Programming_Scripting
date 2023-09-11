#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    
    int max_l[n];
    ans = malloc (sizeof (int*) * n);
    for (i = 0; i < n; i++)
    {
      ans[i] = malloc (sizeof(int) * n);
      size = n - i;
      tmp_a = a + i;
      memset(max_l, 0, sizeof(int) * n);
      memset(ans[i], 0, sizeof(int) * n);
      last1 = -1;
      max = 0;
      nzeros = 0;
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


    scanf ("%d", &q);

    while (q--)
    {
      scanf ("%d %d", &l, &u);
      printf ("%d\n", ans[l - 1][u - 1]);
    }

    for (i = 0; i < n; i++)
      free(ans[i]);
    free(ans);
  }
  return 0;
}

#include <stdio.h>
#include <strings.h>

enum {R, G, B, W};

int main (void)
{
  int t, n;

  scanf ("%d", &t);
  int colors[4], pairs, i;
  char c;
  while (t--)
  {
    scanf("%d", &n);
    bzero (colors, sizeof(int) * 4);
    while ( (c = getchar()) != '\n')
    {
      if (c == EOF)
        break;
      switch (c)
      {
        case 'R': colors[R] += 1; break;
        case 'B': colors[B] += 1; break;
        case 'W': colors[W] += 1; break;
        case 'G': colors[G] += 1; break;
      }
    }
    pairs = 1;
    for (i = 0; i < 4; i++)
    {
      if (colors[i] % 2)
      {
        pairs = 0;
        break;
      }
    }
    printf ("%s\n", pairs?"YES":"NO");
  }
  return 0;
}

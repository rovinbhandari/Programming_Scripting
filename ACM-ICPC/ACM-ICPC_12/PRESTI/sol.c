#include <stdio.h>

typedef long long unsigned int llui;

llui derangements (llui n)
{
  if (n == 0)
    return 1;
  else
    return ((n * derangements(n - 1)) + ((n % 2) ? 1 : 0));
}

llui derangementsArr[] = {1, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841, 2290792932, 32071101049, 481066515734, 7697064251745, 130850092279664, 2355301661033953, 44750731559645106, 895014631192902121};

int main (void)
{
  llui t, n;

  scanf ("%llu", &t);

  while (t--)
  {
    scanf("%llu", &n);

    printf("%llu\n", derangementsArr[n]);
  }
  return 0;
}

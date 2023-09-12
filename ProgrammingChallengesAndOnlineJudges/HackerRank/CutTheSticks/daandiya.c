#include <stdio.h>
#include <stdlib.h>

int compint(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}

int main()
{
  int i, N, remaining, same, temp, *arr;
  scanf("%d", &N);
  arr = (int*) malloc(N * sizeof(int));
  for(i = 0; i < N; i++)
    scanf("%d", arr + i);
  qsort(arr, N, sizeof(int), compint);
  i = 0, remaining = N;
  while(i < N)
  {
    printf("%d\n", remaining);  
    same = 1, temp = arr[i];
    i++;
    while(i < N && temp == arr[i])
      same++, i++;
    remaining -= same;  
  }
  return 0;
}  

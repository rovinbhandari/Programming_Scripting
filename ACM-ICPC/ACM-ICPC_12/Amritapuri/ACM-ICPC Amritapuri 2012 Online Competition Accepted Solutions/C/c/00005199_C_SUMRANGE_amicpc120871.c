#include<stdio.h>
#include<stdlib.h>
int less_than(const void *a, const void *b)
{
	return *((int *)a)-*((int *)b);
}

int main()
{
	int t, N, L, H, c1, c2, c3;
	int done, count;
	int *array;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &N, &L, &H);
		array = malloc(N*sizeof(int));
		for(c1=0;c1<N;c1++)
		{
			scanf("%d", &array[c1]);
		}
		qsort(array, N, sizeof(int), &less_than);
		done=0;
		count=0;
		for(c1=0;c1<N-2;c1++)
		{
			if(array[c1]+array[N-2]+array[N-1]<L)
				continue;
			for(c2=c1+1;c2<N-1;c2++)
			{
				if(array[c1]+array[c2]+array[N-1]<L)
					continue;
				for(c3=c2+1;c3<N;c3++)
				{
					if(array[c1]+array[c2]+array[c3]>=L && array[c1]+array[c2]+array[c3]<=H)	count++;
					if(array[c1]+array[c2]+array[c3]>H)	break;
				}
			}
		}
		printf("%d\n", count);
		free(array);
	}
	return 0;
}
